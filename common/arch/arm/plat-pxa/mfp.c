/*
 * linux/arch/arm/plat-pxa/mfp.c
 *
 *   Multi-Function Pin Support
 *
 * Copyright (C) 2007 Marvell Internation Ltd.
 *
 * 2007-08-21: eric miao <eric.miao@marvell.com>
 *             initial version
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/sysdev.h>

#ifdef CONFIG_ARCH_MMP
#include <mach/cputype.h>
#elif defined(CONFIG_ARCH_PXA)
#include <mach/hardware.h>
#endif

#include <plat/mfp.h>

#define MFPR_SIZE	(PAGE_SIZE)

/* MFPR register bit definitions */
#define MFPR_PULL_SEL		(0x1 << 15)
#define MFPR_PULLUP_EN		(0x1 << 14)
#define MFPR_PULLDOWN_EN	(0x1 << 13)
#define MFPR_PULL_MASK	(MFPR_PULLDOWN_EN | MFPR_PULLUP_EN | MFPR_PULL_SEL)
#define MFPR_SLEEP_SEL		(0x1 << 9)
#define MFPR_SLEEP_DATA(x)	(((x) & 0x1) << 8)
#define MFPR_SLEEP_OE_N		(0x1 << 7)
#define MFPR_SLEEP_MASK		(MFPR_SLEEP_DATA(1))
#define MFPR_EDGE_CLEAR		(0x1 << 6)
#define MFPR_EDGE_FALL_EN	(0x1 << 5)
#define MFPR_EDGE_RISE_EN	(0x1 << 4)
#define MFPR_EDGE_MASK		(MFPR_EDGE_RISE_EN | MFPR_EDGE_FALL_EN | MFPR_EDGE_CLEAR)
#define MFPR_SLEEP_SEL2		(0x1 << 3)
#define MFPR_SLEEP_DATA(x)	(((x) & 0x1) << 8)
#define MFPR_DRIVE(x)		(((x) & 0x7) << 10)
#define MFPR_DRIVE_MASK		MFPR_DRIVE(7)
#define MFPR_AF_SEL(x)		(((x) & 0x7) << 0)
#define MFPR_AF_SEL_MASK	MFPR_AF_SEL(7)

#define MFPR_EDGE_NONE		(MFPR_EDGE_CLEAR)
#define MFPR_EDGE_RISE		(MFPR_EDGE_RISE_EN)
#define MFPR_EDGE_FALL		(MFPR_EDGE_FALL_EN)
#define MFPR_EDGE_BOTH		(MFPR_EDGE_RISE | MFPR_EDGE_FALL)

/*
 * Table that determines the low power modes outputs, with actual settings
 * used in parentheses for don't-care values. Except for the float output,
 * the configured driven and pulled levels match, so if there is a need for
 * non-LPM pulled output, the same configuration could probably be used.
 *
 * Output value  sleep_oe_n  sleep_data  pullup_en  pulldown_en  pull_sel
 *                 (bit 7)    (bit 8)    (bit 14)     (bit 13)   (bit 15)
 *
 * Drive 0          0          0           0           X(1)       0
 * Drive 1          0          1           X(1)        0	  0
 * Pull hi (1)      1          X(1)        1           0	  0
 * Pull lo (0)      1          X(0)        0           1	  0
 * Z (float)        1          X(0)        0           0	  0
 */
#define MFPR_LPM_INPUT		(0)
#define MFPR_LPM_DRIVE_LOW	(MFPR_SLEEP_DATA(0) | MFPR_PULLDOWN_EN)
#define MFPR_LPM_DRIVE_HIGH    	(MFPR_SLEEP_DATA(1) | MFPR_PULLUP_EN)
#define MFPR_LPM_PULL_LOW      	(MFPR_LPM_DRIVE_LOW  | MFPR_SLEEP_OE_N)
#define MFPR_LPM_PULL_HIGH     	(MFPR_LPM_DRIVE_HIGH | MFPR_SLEEP_OE_N)
#define MFPR_LPM_FLOAT         	(MFPR_SLEEP_OE_N)
#define MFPR_LPM_MASK		(0xe080)

/*
 * The pullup and pulldown state of the MFP pin at run mode is by default
 * determined by the selected alternate function. In case that some buggy
 * devices need to override this default behavior,  the definitions below
 * indicates the setting of corresponding MFPR bits
 *
 * Definition       pull_sel  pullup_en  pulldown_en
 * MFPR_PULL_NONE       0         0        0
 * MFPR_PULL_LOW        1         0        1
 * MFPR_PULL_HIGH       1         1        0
 * MFPR_PULL_BOTH       1         1        1
 * MFPR_PULL_FLOAT	1         0        0
 */
#define MFPR_PULL_NONE		(0)
#define MFPR_PULL_LOW		(MFPR_PULL_SEL | MFPR_PULLDOWN_EN)
#define MFPR_PULL_BOTH		(MFPR_PULL_LOW | MFPR_PULLUP_EN)
#define MFPR_PULL_HIGH		(MFPR_PULL_SEL | MFPR_PULLUP_EN)
#define MFPR_PULL_FLOAT		(MFPR_PULL_SEL)

/* mfp_spin_lock is used to ensure that MFP register configuration
 * (most likely a read-modify-write operation) is atomic, and that
 * mfp_table[] is consistent
 */
static DEFINE_SPINLOCK(mfp_spin_lock);

static void __iomem *mfpr_mmio_base;

struct mfp_pin {
	unsigned long	config;		/* -1 for not configured */
	unsigned long	mfpr_off;	/* MFPRxx Register offset */
	unsigned long	mfpr_run;	/* Run-Mode Register Value */
	unsigned long	mfpr_lpm;	/* Low Power Mode Register Value */
};

static struct mfp_pin mfp_table[MFP_PIN_MAX];

/* mapping of MFP_LPM_* definitions to MFPR_LPM_* register bits */
static const unsigned long mfpr_lpm[] = {
	MFPR_LPM_INPUT,
	MFPR_LPM_DRIVE_LOW,
	MFPR_LPM_DRIVE_HIGH,
	MFPR_LPM_PULL_LOW,
	MFPR_LPM_PULL_HIGH,
	MFPR_LPM_FLOAT,
};

/* mapping of MFP_PULL_* definitions to MFPR_PULL_* register bits */
static const unsigned long mfpr_pull[] = {
	MFPR_PULL_NONE,
	MFPR_PULL_LOW,
	MFPR_PULL_HIGH,
	MFPR_PULL_BOTH,
	MFPR_PULL_FLOAT,
};

/* mapping of MFP_LPM_EDGE_* definitions to MFPR_EDGE_* register bits */
static const unsigned long mfpr_edge[] = {
	MFPR_EDGE_NONE,
	MFPR_EDGE_RISE,
	MFPR_EDGE_FALL,
	MFPR_EDGE_BOTH,
};

#define mfpr_readl(off)			\
	__raw_readl(mfpr_mmio_base + (off))

#define mfpr_writel(off, val)		\
	__raw_writel(val, mfpr_mmio_base + (off))

#define mfp_configured(p)	((p)->config != -1)

/*
 * perform a read-back of any valid MFPR register to make sure the
 * previous writings are finished
 */
static unsigned long mfpr_off_readback;
#define mfpr_sync()	(void)__raw_readl(mfpr_mmio_base + mfpr_off_readback)

static inline void __mfp_config_run(struct mfp_pin *p)
{
	if (mfp_configured(p))
		mfpr_writel(p->mfpr_off, p->mfpr_run);
}

static inline void __mfp_config_lpm(struct mfp_pin *p)
{
	if (mfp_configured(p)) {
		unsigned long mfpr_clr = (p->mfpr_run & ~MFPR_EDGE_BOTH) | MFPR_EDGE_CLEAR;
		if (mfpr_clr != p->mfpr_run)
			mfpr_writel(p->mfpr_off, mfpr_clr);
		if (p->mfpr_lpm != mfpr_clr)
			mfpr_writel(p->mfpr_off, p->mfpr_lpm);
	}
}

void mfp_config(unsigned long *mfp_cfgs, int num)
{
	unsigned long flags;
	int i, drv_b11 = 0, no_lpm = 0;

#ifdef CONFIG_ARCH_MMP
	if (cpu_is_pxa910() || cpu_is_mmp2() || cpu_is_mmp3())
		drv_b11 = 1;
	if (cpu_is_pxa168() || cpu_is_pxa910())
		no_lpm = 1;
#elif defined(CONFIG_ARCH_PXA)
	if (cpu_is_pxa95x())
		drv_b11 = 1;
#endif
	spin_lock_irqsave(&mfp_spin_lock, flags);

	for (i = 0; i < num; i++, mfp_cfgs++) {
		unsigned long tmp, c = *mfp_cfgs;
		struct mfp_pin *p;
		int pin, af, drv, lpm, edge, pull;

		pin = MFP_PIN(c);
		BUG_ON(pin >= MFP_PIN_MAX);
		p = &mfp_table[pin];

		tmp = mfpr_readl(p->mfpr_off);

		af  = MFP_AF(c);
		drv = MFP_DS(c);
		lpm = MFP_LPM_STATE(c);
		edge = MFP_LPM_EDGE(c);
		pull = MFP_PULL(c);
		if (drv_b11)
			drv = drv << 1;
		if (no_lpm)
			lpm = 0;
		if (c & MFP_AF_VALID) {
			tmp &= ~MFPR_AF_SEL_MASK;
			tmp |= MFPR_AF_SEL(af);
		}
		if (c & MFP_DS_VALID) {
			tmp &= ~MFPR_DRIVE_MASK;
			tmp |= MFPR_DRIVE(drv);
		}

		if (c & MFP_LPM_VALID) {
			tmp &= ~MFPR_PULL_MASK;
			tmp &= ~MFPR_SLEEP_MASK;
			tmp &= ~MFPR_LPM_MASK;
			tmp |= mfpr_lpm[lpm];
		}

		if (c & MFP_LPM_EDGE_VALID) {
			tmp &= ~MFPR_EDGE_MASK;
			/* assert EDGE_CLEAR to clear wake up status after LPM exit */
			if (edge == (~MFP_LPM_EDGE_VALID & MFP_LPM_EDGE_NONE))
				tmp |= MFPR_EDGE_CLEAR;

			tmp |= mfpr_edge[edge];
		}

		if (unlikely(pull != (~MFP_PULL_VALID & MFP_PULL_NONE))) {
			printk(KERN_WARNING "MFP setting MPF_PULL_XX, which may conflict with MFP_LPM_XXX setting\n");
		}
		/* run-mode pull settings will conflict with MFPR bits of
		 * low power mode state,  calculate mfpr_run and mfpr_lpm
		 * individually if pull != MFP_PULL_NONE
		 */
#ifdef CONFIG_ARCH_MMP
		if (cpu_is_pxa910())
			tmp |= MFPR_SLEEP_OE_N;
#endif
		p->mfpr_run = tmp;
		p->mfpr_lpm = p->mfpr_run;

		p->config = c; __mfp_config_run(p);
	}

	mfpr_sync();
	spin_unlock_irqrestore(&mfp_spin_lock, flags);
}
EXPORT_SYMBOL(mfp_config);

unsigned long mfp_read(int mfp)
{
	unsigned long val, flags;

	BUG_ON(mfp < 0 || mfp >= MFP_PIN_MAX);

	spin_lock_irqsave(&mfp_spin_lock, flags);
	val = mfpr_readl(mfp_table[mfp].mfpr_off);
	spin_unlock_irqrestore(&mfp_spin_lock, flags);

	return val;
}
EXPORT_SYMBOL(mfp_read);

void mfp_write(int mfp, unsigned long val)
{
	unsigned long flags;

	BUG_ON(mfp < 0 || mfp >= MFP_PIN_MAX);

	spin_lock_irqsave(&mfp_spin_lock, flags);
	mfpr_writel(mfp_table[mfp].mfpr_off, val);
	mfpr_sync();
	spin_unlock_irqrestore(&mfp_spin_lock, flags);
}
EXPORT_SYMBOL(mfp_write);

void __init mfp_init_base(unsigned long mfpr_base)
{
	int i;

	/* initialize the table with default - unconfigured */
	for (i = 0; i < ARRAY_SIZE(mfp_table); i++)
		mfp_table[i].config = -1;

	mfpr_mmio_base = (void __iomem *)mfpr_base;
}

void __init mfp_init_addr(struct mfp_addr_map *map)
{
	struct mfp_addr_map *p;
	unsigned long offset, flags;
	int i;

	spin_lock_irqsave(&mfp_spin_lock, flags);

	/* mfp offset for readback */
	mfpr_off_readback = map[0].offset;

	for (p = map; p->start != MFP_PIN_INVALID; p++) {
		offset = p->offset;
		i = p->start;

		do {
			mfp_table[i].mfpr_off = offset;
			mfp_table[i].mfpr_run = 0;
			mfp_table[i].mfpr_lpm = 0;
			offset += 4; i++;
		} while ((i <= p->end) && (p->end != -1));
	}

	spin_unlock_irqrestore(&mfp_spin_lock, flags);
}

void mfp_config_lpm(void)
{
	struct mfp_pin *p = &mfp_table[0];
	int pin;

#ifdef CONFIG_ARCH_MMP
	if (cpu_is_pxa168() || cpu_is_pxa910())
		return;
#endif
	for (pin = 0; pin < ARRAY_SIZE(mfp_table); pin++, p++)
		__mfp_config_lpm(p);
}

void mfp_config_run(void)
{
	struct mfp_pin *p = &mfp_table[0];
	int pin;

	for (pin = 0; pin < ARRAY_SIZE(mfp_table); pin++, p++)
		__mfp_config_run(p);
}
