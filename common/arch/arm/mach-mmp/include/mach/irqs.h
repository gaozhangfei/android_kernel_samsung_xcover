#ifndef __ASM_MACH_IRQS_H
#define __ASM_MACH_IRQS_H

/*
 * Interrupt numbers for PXA168
 */
#define IRQ_PXA168_NONE			(-1)
#define IRQ_PXA168_SSP4			0
#define IRQ_PXA168_SSP3			1
#define IRQ_PXA168_SSP2			2
#define IRQ_PXA168_SSP1			3
#define IRQ_PXA168_PMIC_INT		4
#define IRQ_PXA168_RTC_INT		5
#define IRQ_PXA168_RTC_ALARM		6
#define IRQ_PXA168_TWSI0		7
#define IRQ_PXA168_GPU			8
#define IRQ_PXA168_KEYPAD		9
#define IRQ_PXA168_ONEWIRE		12
#define IRQ_PXA168_TIMER1		13
#define IRQ_PXA168_TIMER2		14
#define IRQ_PXA168_TIMER3		15
#define IRQ_PXA168_CMU			16
#define IRQ_PXA168_SSP5			17
#define IRQ_PXA168_MSP_WAKEUP		19
#define IRQ_PXA168_CF_WAKEUP		20
#define IRQ_PXA168_XD_WAKEUP		21
#define IRQ_PXA168_MFU			22
#define IRQ_PXA168_MSP			23
#define IRQ_PXA168_CF			24
#define IRQ_PXA168_XD			25
#define IRQ_PXA168_DDR_INT		26
#define IRQ_PXA168_UART1		27
#define IRQ_PXA168_UART2		28
#define IRQ_PXA168_UART3		29
#define IRQ_PXA168_WDT			35
#define IRQ_PXA168_MAIN_PMU		36
#define IRQ_PXA168_FRQ_CHANGE		38
#define IRQ_PXA168_SDH1			39
#define IRQ_PXA168_SDH2			40
#define IRQ_PXA168_LCD			41
#define IRQ_PXA168_CI			42
#define IRQ_PXA168_USB1			44
#define IRQ_PXA168_NAND			45
#define IRQ_PXA168_HIFI_DMA		46
#define IRQ_PXA168_DMA_INT0		47
#define IRQ_PXA168_DMA_INT1		48
#define IRQ_PXA168_GPIOX		49
#define IRQ_PXA168_USB2			51
#define IRQ_PXA168_AC97			57
#define IRQ_PXA168_TWSI1		58
#define IRQ_PXA168_AP_PMU		60
#define IRQ_PXA168_SM_INT		63

#define IRQ_PXA910_IPC_AP_DATAACK       16
#define IRQ_PXA910_IPC_AP_SET_CMD       17
#define IRQ_PXA910_IPC_AP_SET_MSG       18

/*
 * Interrupt numbers for PXA910
 */
#define IRQ_PXA910_NONE			(-1)
#define IRQ_PXA910_AIRQ			0
#define IRQ_PXA910_SSP3			1
#define IRQ_PXA910_SSP2			2
#define IRQ_PXA910_SSP1			3
#define IRQ_PXA910_PMIC_INT		4
#define IRQ_PXA910_RTC_INT		5
#define IRQ_PXA910_RTC_ALARM		6
#define IRQ_PXA910_TWSI0		7
#define IRQ_PXA910_GPU			8
#define IRQ_PXA910_KEYPAD		9
#define IRQ_PXA910_ROTARY		10
#define IRQ_PXA910_TRACKBALL		11
#define IRQ_PXA910_ONEWIRE		12
#define IRQ_PXA910_AP1_TIMER1		13
#define IRQ_PXA910_AP1_TIMER2		14
#define IRQ_PXA910_AP1_TIMER3		15
#define IRQ_PXA910_IPC_AP0		16
#define IRQ_PXA910_IPC_AP1		17
#define IRQ_PXA910_IPC_AP2		18
#define IRQ_PXA910_IPC_AP3		19
#define IRQ_PXA910_IPC_AP4		20
#define IRQ_PXA910_IPC_CP0		21
#define IRQ_PXA910_IPC_CP1		22
#define IRQ_PXA910_IPC_CP2		23
#define IRQ_PXA910_IPC_CP3		24
#define IRQ_PXA910_CNM			25
#define IRQ_PXA910_L2_DDR		26
#define IRQ_PXA910_UART0		27
#define IRQ_PXA910_UART1		28
#define IRQ_PXA910_AP2_TIMER1		29
#define IRQ_PXA910_AP2_TIMER2		30
#define IRQ_PXA910_CP2_TIMER1		31
#define IRQ_PXA910_CP2_TIMER2		32
#define IRQ_PXA910_CP2_TIMER3		33
#define IRQ_PXA910_GSSP			34
#define IRQ_PXA910_CP2_WDT		35
#define IRQ_PXA910_MAIN_PMU		36
#define IRQ_PXA910_CP_FREQ_CHG		37
#define IRQ_PXA910_AP_FREQ_CHG		38
#define IRQ_PXA910_MMC			39
#define IRQ_PXA910_AEU			40
#define IRQ_PXA910_LCD			41
#define IRQ_PXA910_CCIC			42
#define IRQ_PXA910_IRE			43
#define IRQ_PXA910_USB1			44
#define IRQ_PXA910_NAND			45
#define IRQ_PXA910_HIFI_DMA		46
#define IRQ_PXA910_DMA_INT0		47
#define IRQ_PXA910_DMA_INT1		48
#define IRQ_PXA910_AP_GPIO		49
#define IRQ_PXA910_AP2_TIMER3		50
#define IRQ_PXA910_USB2			51
#define IRQ_PXA910_TWSI1		54
#define IRQ_PXA910_CP_GPIO		55
#define IRQ_PXA910_UART2		59	/* Slow UART */
#define IRQ_PXA910_AP_PMU		60
#define IRQ_PXA910_SM_INT		63	/* from PinMux */

/*
 * Interrupt numbers for MMP3
 */
#define IRQ_LOCALTIMER			29
#define IRQ_LOCALWDOG			30
#define IRQ_LEGACYIRQ			31

/*
 * Interrupt numbers for MMP2 && MMP3
 */
#ifdef CONFIG_CPU_MMP2
#define IRQ_MMP_START			0
#else
#define IRQ_MMP_START			32
#endif

#define IRQ_MMP2_NONE			(-1)
#define IRQ_MMP2_SSP1			(IRQ_MMP_START + 0)
#define IRQ_MMP2_SSP2			(IRQ_MMP_START + 1)
#define IRQ_MMP2_SSPA1			(IRQ_MMP_START + 2)
#define IRQ_MMP2_SSPA2			(IRQ_MMP_START + 3)
#define IRQ_MMP2_PMIC_MUX		(IRQ_MMP_START + 4)	/* PMIC & Charger */
#define IRQ_MMP2_RTC_MUX		(IRQ_MMP_START + 5)
#define IRQ_MMP2_EPD1			(IRQ_MMP_START + 6)
#define IRQ_MMP2_TWSI1			(IRQ_MMP_START + 7)
#define IRQ_MMP2_GPU			(IRQ_MMP_START + 8)
#define IRQ_MMP2_KEYPAD_MUX		(IRQ_MMP_START + 9)
#define IRQ_MMP2_CAWAKE			(IRQ_MMP_START + 10)
#define IRQ_MMP2_WATCHDOG2		(IRQ_MMP_START + 11)
#define IRQ_MMP2_ONEWIRE		(IRQ_MMP_START + 12)
#define IRQ_MMP2_TIMER1			(IRQ_MMP_START + 13)
#define IRQ_MMP2_TIMER2			(IRQ_MMP_START + 14)
#define IRQ_MMP2_TIMER3			(IRQ_MMP_START + 15)
#define IRQ_MMP2_RIPC			(IRQ_MMP_START + 16)
#define IRQ_MMP2_TWSI_MUX		(IRQ_MMP_START + 17)	/* TWSI2 ~ TWSI6 */
#define IRQ_MMP2_EPD2			(IRQ_MMP_START + 18)
#define IRQ_MMP2_HDMI			(IRQ_MMP_START + 19)
#define IRQ_MMP2_SSP3			(IRQ_MMP_START + 20)
#define IRQ_MMP2_SSP4			(IRQ_MMP_START + 21)
#define IRQ_MMP2_USB_HS1		(IRQ_MMP_START + 22)
#define IRQ_MMP2_USB_HS2		(IRQ_MMP_START + 23)
#define IRQ_MMP2_UART3			(IRQ_MMP_START + 24)
#define IRQ_MMP2_ISP_DMA		(IRQ_MMP_START + 25)
#define IRQ_MMP2_VMETA			(IRQ_MMP_START + 26)
#define IRQ_MMP2_UART1			(IRQ_MMP_START + 27)
#define IRQ_MMP2_UART2			(IRQ_MMP_START + 28)
#define IRQ_MMP2_MIPI_DSI		(IRQ_MMP_START + 29)
#define IRQ_MMP2_CI2			(IRQ_MMP_START + 30)
#define IRQ_MMP2_PMU_TIMER1		(IRQ_MMP_START + 31)
#define IRQ_MMP2_PMU_TIMER2		(IRQ_MMP_START + 32)
#define IRQ_MMP2_PMU_TIMER3		(IRQ_MMP_START + 33)
#define IRQ_MMP2_USB_FS			(IRQ_MMP_START + 34)
#define IRQ_MMP2_MISC_MUX		(IRQ_MMP_START + 35)
#define IRQ_MMP2_WDT1			(IRQ_MMP_START + 36)
#define IRQ_MMP2_NAND_DMA		(IRQ_MMP_START + 37)
#define IRQ_MMP2_USIM			(IRQ_MMP_START + 38)
#define IRQ_MMP2_MMC			(IRQ_MMP_START + 39)
#define IRQ_MMP2_WTM			(IRQ_MMP_START + 40)
#define IRQ_MMP2_LCD			(IRQ_MMP_START + 41)
#define IRQ_MMP2_CI			(IRQ_MMP_START + 42)
#define IRQ_MMP2_IRE			(IRQ_MMP_START + 43)
#define IRQ_MMP2_USB_OTG		(IRQ_MMP_START + 44)
#define IRQ_MMP2_NAND			(IRQ_MMP_START + 45)
#define IRQ_MMP2_UART4			(IRQ_MMP_START + 46)
#define IRQ_MMP2_DMA_FIQ		(IRQ_MMP_START + 47)
#define IRQ_MMP2_DMA_RIQ		(IRQ_MMP_START + 48)
#define IRQ_MMP2_GPIO			(IRQ_MMP_START + 49)
#define IRQ_MMP2_MIPI_HSI1_MUX		(IRQ_MMP_START + 51)
#define IRQ_MMP2_MMC2			(IRQ_MMP_START + 52)
#define IRQ_MMP2_MMC3			(IRQ_MMP_START + 53)
#define IRQ_MMP2_MMC4			(IRQ_MMP_START + 54)
#define IRQ_MMP2_MIPI_HSI0_MUX		(IRQ_MMP_START + 55)
#define IRQ_MMP2_MSP			(IRQ_MMP_START + 58)
#define IRQ_MMP2_MIPI_SLIM_DMA		(IRQ_MMP_START + 59)
#define IRQ_MMP2_PJ4_FREQ_CHG		(IRQ_MMP_START + 60)
#define IRQ_MMP2_MIPI_SLIM		(IRQ_MMP_START + 62)
#define IRQ_MMP2_SM			(IRQ_MMP_START + 63)

#define IRQ_MMP2_MUX_BASE		(IRQ_MMP_START + 64)

/* secondary interrupt of INT #4 */
#define IRQ_MMP2_PMIC_BASE		(IRQ_MMP2_MUX_BASE)
#define IRQ_MMP2_CHARGER		(IRQ_MMP2_PMIC_BASE + 0)
#define IRQ_MMP2_PMIC			(IRQ_MMP2_PMIC_BASE + 1)

/* secondary interrupt of INT #5 */
#define IRQ_MMP2_RTC_BASE		(IRQ_MMP2_PMIC_BASE + 2)
#define IRQ_MMP2_RTC_ALARM		(IRQ_MMP2_RTC_BASE + 0)
#define IRQ_MMP2_RTC			(IRQ_MMP2_RTC_BASE + 1)

/* secondary interrupt of INT #9 */
#define IRQ_MMP2_KEYPAD_BASE		(IRQ_MMP2_RTC_BASE + 2)
#define IRQ_MMP2_KPC			(IRQ_MMP2_KEYPAD_BASE + 0)
#define IRQ_MMP2_ROTARY			(IRQ_MMP2_KEYPAD_BASE + 1)
#define IRQ_MMP2_TBALL			(IRQ_MMP2_KEYPAD_BASE + 2)

/* secondary interrupt of INT #17 */
#define IRQ_MMP2_TWSI_BASE		(IRQ_MMP2_KEYPAD_BASE + 3)
#define IRQ_MMP2_TWSI2			(IRQ_MMP2_TWSI_BASE + 0)
#define IRQ_MMP2_TWSI3			(IRQ_MMP2_TWSI_BASE + 1)
#define IRQ_MMP2_TWSI4			(IRQ_MMP2_TWSI_BASE + 2)
#define IRQ_MMP2_TWSI5			(IRQ_MMP2_TWSI_BASE + 3)
#define IRQ_MMP2_TWSI6			(IRQ_MMP2_TWSI_BASE + 4)

/* secondary interrupt of INT #35 */
#define IRQ_MMP2_MISC_BASE		(IRQ_MMP2_TWSI_BASE + 5)
#define IRQ_MMP2_PERF			(IRQ_MMP2_MISC_BASE + 0)
#define IRQ_MMP2_L2_PA_ECC		(IRQ_MMP2_MISC_BASE + 1)
#define IRQ_MMP2_L2_ECC			(IRQ_MMP2_MISC_BASE + 2)
#define IRQ_MMP2_L2_UECC		(IRQ_MMP2_MISC_BASE + 3)
#define IRQ_MMP2_DDR			(IRQ_MMP2_MISC_BASE + 4)
#define IRQ_MMP2_FAB0_TIMEOUT		(IRQ_MMP2_MISC_BASE + 5)
#define IRQ_MMP2_FAB1_TIMEOUT		(IRQ_MMP2_MISC_BASE + 6)
#define IRQ_MMP2_FAB2_TIMEOUT		(IRQ_MMP2_MISC_BASE + 7)
#define IRQ_MMP2_THERMAL		(IRQ_MMP2_MISC_BASE + 9)
#define IRQ_MMP2_MAIN_PMU		(IRQ_MMP2_MISC_BASE + 10)
#define IRQ_MMP2_WDT2			(IRQ_MMP2_MISC_BASE + 11)
#define IRQ_MMP2_CORESIGHT		(IRQ_MMP2_MISC_BASE + 12)
#define IRQ_MMP2_COMMTX			(IRQ_MMP2_MISC_BASE + 13)
#define IRQ_MMP2_COMMRX			(IRQ_MMP2_MISC_BASE + 14)

/* secondary interrupt of INT #51 */
#define IRQ_MMP2_HSI1_BASE		(IRQ_MMP2_MISC_BASE + 15)
#define IRQ_MMP2_HSI1_CAWAKE		(IRQ_MMP2_HSI1_BASE + 0)
#define IRQ_MMP2_HSI1_INT		(IRQ_MMP2_HSI1_BASE + 1)

/* secondary interrupt of INT #55 */
#define IRQ_MMP2_HSI0_BASE		(IRQ_MMP2_HSI1_BASE + 2)
#define IRQ_MMP2_HSI0_CAWAKE		(IRQ_MMP2_HSI0_BASE + 0)
#define IRQ_MMP2_HSI0_INT		(IRQ_MMP2_HSI0_BASE + 1)

#define IRQ_MMP2_MUX_END		(IRQ_MMP2_HSI0_BASE + 2)

/*
 * Interrupt numbers for MMP3
 */
#define IRQ_LOCALTIMER			29
#define IRQ_LOCALWDOG			30
#define IRQ_LEGACYIRQ			31

#define IRQ_MMP3_START			32
#define IRQ_MMP3_NONE			(-1)
#define IRQ_MMP3_SSP2			(IRQ_MMP3_START + 1)
#define IRQ_MMP3_SSPA1			(IRQ_MMP3_START + 2)
#define IRQ_MMP3_SSPA2			(IRQ_MMP3_START + 3)
#define IRQ_MMP3_PMIC_MUX		(IRQ_MMP3_START + 4)	/* PMIC & Charger */
#define IRQ_MMP3_RTC_MUX		(IRQ_MMP3_START + 5)
#define IRQ_MMP3_HSI3_MUX		(IRQ_MMP3_START + 6)
#define IRQ_MMP3_TWSI1			(IRQ_MMP3_START + 7)
#define IRQ_MMP3_GPU_MUX		(IRQ_MMP3_START + 8)
#define IRQ_MMP3_KEYPAD			(IRQ_MMP3_START + 9)
#define IRQ_MMP3_ROTARY			(IRQ_MMP3_START + 10)
#define IRQ_MMP3_TRACKBALL		(IRQ_MMP3_START + 11)
#define IRQ_MMP3_ONEWIRE		(IRQ_MMP3_START + 12)
#define IRQ_MMP3_TIMER1			(IRQ_MMP3_START + 13)
#define IRQ_MMP3_TIMER2			(IRQ_MMP3_START + 14)
#define IRQ_MMP3_TIMER3			(IRQ_MMP3_START + 15)
#define IRQ_MMP3_RIPC			(IRQ_MMP3_START + 16)
#define IRQ_MMP3_TWSI_MUX		(IRQ_MMP3_START + 17)	/* TWSI2 ~ TWSI6 */
#define IRQ_MMP3_HSI2_MUX		(IRQ_MMP3_START + 18)
#define IRQ_MMP3_HDMI			(IRQ_MMP3_START + 19)
#define IRQ_MMP3_SSP3			(IRQ_MMP3_START + 20)
#define IRQ_MMP3_SSP4			(IRQ_MMP3_START + 21)
#define IRQ_MMP3_USB_HS1		(IRQ_MMP3_START + 22)
#define IRQ_MMP3_USB_HS2		(IRQ_MMP3_START + 23)
#define IRQ_MMP3_UART3			(IRQ_MMP3_START + 24)
#define IRQ_MMP3_VMETA			(IRQ_MMP3_START + 26)
#define IRQ_MMP3_UART1			(IRQ_MMP3_START + 27)
#define IRQ_MMP3_UART2			(IRQ_MMP3_START + 28)
#define IRQ_MMP3_MIPI_DSI		(IRQ_MMP3_START + 29)
#define IRQ_MMP3_DXO_MUX		(IRQ_MMP3_START + 30)
#define IRQ_MMP3_PMU_TIMER1		(IRQ_MMP3_START + 31)
#define IRQ_MMP3_PMU_TIMER2		(IRQ_MMP3_START + 32)
#define IRQ_MMP3_PMU_TIMER3		(IRQ_MMP3_START + 33)
#define IRQ_MMP3_USB_FS			(IRQ_MMP3_START + 34)
#define IRQ_MMP3_MISC1_MUX		(IRQ_MMP3_START + 35)
#define IRQ_MMP3_WDT1			(IRQ_MMP3_START + 36)
#define IRQ_MMP3_NAND_DMA		(IRQ_MMP3_START + 37)
#define IRQ_MMP3_USIM			(IRQ_MMP3_START + 38)
#define IRQ_MMP3_MMC			(IRQ_MMP3_START + 39)
#define IRQ_MMP3_WTM			(IRQ_MMP3_START + 40)
#define IRQ_MMP3_LCD			(IRQ_MMP3_START + 41)
#define IRQ_MMP3_CI_MUX			(IRQ_MMP3_START + 42)
#define IRQ_MMP3_IRE			(IRQ_MMP3_START + 43)
#define IRQ_MMP3_USB_OTG		(IRQ_MMP3_START + 44)
#define IRQ_MMP3_NAND			(IRQ_MMP3_START + 45)
#define IRQ_MMP3_UART4			(IRQ_MMP3_START + 46)
#define IRQ_MMP3_DMA_FIQ		(IRQ_MMP3_START + 47)
#define IRQ_MMP3_DMA_RIQ		(IRQ_MMP3_START + 48)
#define IRQ_MMP3_GPIO			(IRQ_MMP3_START + 49)
#define IRQ_MMP3_SECURITY		(IRQ_MMP3_START + 50)
#define IRQ_MMP3_SSP_MUX		(IRQ_MMP3_START + 51)
#define IRQ_MMP3_MMC2			(IRQ_MMP3_START + 52)
#define IRQ_MMP3_MMC3			(IRQ_MMP3_START + 53)
#define IRQ_MMP3_MMC4			(IRQ_MMP3_START + 54)
#define IRQ_MMP3_HSI1_MUX		(IRQ_MMP3_START + 55)
#define IRQ_MMP3_IPC2			(IRQ_MMP3_START + 56)
#define IRQ_MMP3_MISC2_MUX		(IRQ_MMP3_START + 57)
#define IRQ_MMP3_HSI0_MUX		(IRQ_MMP3_START + 58)
#define IRQ_MMP3_MIPI_SLIM_DMA		(IRQ_MMP3_START + 59)
#define IRQ_MMP3_PJ4_FREQ_CHG		(IRQ_MMP3_START + 60)
#define IRQ_MMP3_MIPI_SLIM		(IRQ_MMP3_START + 62)
#define IRQ_MMP3_SMC			(IRQ_MMP3_START + 63)
#ifdef CONFIG_ARM_GIC
#define IRQ_MMP3_END			(IRQ_MMP3_START + 96)
#else
#define IRQ_MMP3_END			(IRQ_MMP3_START + 64)
#endif

/* secondary interrupt of INT #4 */
#define IRQ_MMP3_PMIC_BASE		(IRQ_MMP3_END)
#define IRQ_MMP3_CHARGER		(IRQ_MMP3_PMIC_BASE + 0)
#define IRQ_MMP3_PMIC			(IRQ_MMP3_PMIC_BASE + 1)
#define IRQ_MMP3_SPMI			(IRQ_MMP3_PMIC_BASE + 2)
#define IRQ_MMP3_CHRG_DTC_OUT		(IRQ_MMP3_PMIC_BASE + 3)

/* secondary interrupt of INT #5 */
#define IRQ_MMP3_RTC_BASE		(IRQ_MMP3_PMIC_BASE + 4)
#define IRQ_MMP3_RTC_ALARM		(IRQ_MMP3_RTC_BASE + 0)
#define IRQ_MMP3_RTC			(IRQ_MMP3_RTC_BASE + 1)

/* secondary interrupt of INT #6 */
#define IRQ_MMP3_HSI3_BASE		(IRQ_MMP3_RTC_BASE + 2)
#define IRQ_MMP3_ETHER			(IRQ_MMP3_HSI3_BASE + 0)
#define IRQ_MMP3_UNIPRO3		(IRQ_MMP3_HSI3_BASE + 1)
#define IRQ_MMP3_HSI3			(IRQ_MMP3_HSI3_BASE + 2)

/* secondary interrupt of INT #8 */
#define IRQ_MMP3_GPU_BASE		(IRQ_MMP3_HSI3_BASE + 3)
#define IRQ_MMP3_GC2000			(IRQ_MMP3_GPU_BASE + 0)
#define IRQ_MMP3_GC360			(IRQ_MMP3_GPU_BASE + 1)
#define IRQ_MMP3_GC300			(IRQ_MMP3_GPU_BASE + 2)

/* secondary interrupt of INT #17 */
#define IRQ_MMP3_TWSI_BASE		(IRQ_MMP3_GPU_BASE + 3)
#define IRQ_MMP3_TWSI2			(IRQ_MMP3_TWSI_BASE + 0)
#define IRQ_MMP3_TWSI3			(IRQ_MMP3_TWSI_BASE + 1)
#define IRQ_MMP3_TWSI4			(IRQ_MMP3_TWSI_BASE + 2)
#define IRQ_MMP3_TWSI5			(IRQ_MMP3_TWSI_BASE + 3)
#define IRQ_MMP3_TWSI6			(IRQ_MMP3_TWSI_BASE + 4)

/* secondary interrupt of INT #18 */
#define IRQ_MMP3_HSI2_BASE		(IRQ_MMP3_TWSI_BASE + 5)
#define IRQ_MMP3_UNIPRO2		(IRQ_MMP3_HSI3_BASE + 0)
#define IRQ_MMP3_HSI2			(IRQ_MMP3_HSI3_BASE + 1)

/* secondary interrupt of INT #30 */
#define IRQ_MMP3_DXO_BASE		(IRQ_MMP3_HSI2_BASE + 2)
#define IRQ_MMP3_ISP_DMA		(IRQ_MMP3_DXO_BASE + 0)
#define IRQ_MMP3_DXO_ISP		(IRQ_MMP3_DXO_BASE + 1)

/* secondary interrupt of INT #35 */
#define IRQ_MMP3_MISC1_BASE		(IRQ_MMP3_DXO_BASE + 2)
#define IRQ_MMP3_MOLTRES_TRIGGER	(IRQ_MMP3_MISC1_BASE + 0)
#define IRQ_MMP3_MOLTRES_SNP_PERR0	(IRQ_MMP3_MISC1_BASE + 1)
#define IRQ_MMP3_MOLTRES_SNP_PERR1	(IRQ_MMP3_MISC1_BASE + 2)
#define IRQ_MMP3_MOLTRES_SNP_PERR2	(IRQ_MMP3_MISC1_BASE + 3)
#define IRQ_MMP3_MOLTRES_L2CCINTR_MASK	(IRQ_MMP3_MISC1_BASE + 4)
#define IRQ_MMP3_MOLTRES_L2C_PA_ERR	(IRQ_MMP3_MISC1_BASE + 5)
#define IRQ_MMP3_MOLTRES_L2C_UERR 	(IRQ_MMP3_MISC1_BASE + 6)
#define IRQ_MMP3_MOLTRES_L2C_CERR	(IRQ_MMP3_MISC1_BASE + 7)
#define IRQ_MMP3_MOLTRES_ECNTRINTR	(IRQ_MMP3_MISC1_BASE + 8)
#define IRQ_MMP3_MOLTRES_PARRTINTR	(IRQ_MMP3_MISC1_BASE + 9)
#define IRQ_MMP3_MOLTRES_PARRDINTR	(IRQ_MMP3_MISC1_BASE + 10)
#define IRQ_MMP3_MOLTRES_ERRWTINTR	(IRQ_MMP3_MISC1_BASE + 11)
#define IRQ_MMP3_MOLTRES_ERRWDINTR	(IRQ_MMP3_MISC1_BASE + 12)
#define IRQ_MMP3_MOLTRES_COMMTX_2_0	(IRQ_MMP3_MISC1_BASE + 13)
#define IRQ_MMP3_MOLTRES_COMMRX_2_0	(IRQ_MMP3_MISC1_BASE + 14)
#define IRQ_MMP3_MOLTRES_ERRRTINTR	(IRQ_MMP3_MISC1_BASE + 15)
#define IRQ_MMP3_MOLTRES_ERRRDINTR	(IRQ_MMP3_MISC1_BASE + 16)
#define IRQ_MMP3_MOLTRES_SLVERRINTR	(IRQ_MMP3_MISC1_BASE + 17)
#define IRQ_MMP3_MOLTRES_DECERRINTR	(IRQ_MMP3_MISC1_BASE + 18)
#define IRQ_MMP3_MOLTRES_CTI_NCTIIRQ_0	(IRQ_MMP3_MISC1_BASE + 19)
#define IRQ_MMP3_MOLTRES_CTI_NCTIIRQ_1	(IRQ_MMP3_MISC1_BASE + 20)
#define IRQ_MMP3_MOLTRES_CTI_NCTIIRQ_2	(IRQ_MMP3_MISC1_BASE + 21)
#define IRQ_MMP3_MOLTRES_NPMUIRQ_0	(IRQ_MMP3_MISC1_BASE + 22)
#define IRQ_MMP3_MOLTRES_NPMUIRQ_1	(IRQ_MMP3_MISC1_BASE + 23)
#define IRQ_MMP3_MOLTRES_NPMUIRQ_2	(IRQ_MMP3_MISC1_BASE + 24)
#define IRQ_MMP3_MOLTRES_DC_PERR	(IRQ_MMP3_MISC1_BASE + 25)
#define IRQ_MMP3_MOLTRES_IC_PERR	(IRQ_MMP3_MISC1_BASE + 26)
#define IRQ_MMP3_PJ4_PMU_INT_0		(IRQ_MMP3_MISC1_BASE + 27)
#define IRQ_MMP3_PJ4_PMU_INT_1		(IRQ_MMP3_MISC1_BASE + 28)
#define IRQ_MMP3_PJ4_PMU_INT_2		(IRQ_MMP3_MISC1_BASE + 29)
#define IRQ_MMP3_USB3_DMA_INTR		(IRQ_MMP3_MISC1_BASE + 30)

/* secondary interrupt of INT #42 */
#define IRQ_MMP3_CI_BASE		(IRQ_MMP3_MISC1_BASE + 31)
#define IRQ_MMP3_CCIC2			(IRQ_MMP3_CI_BASE + 0)
#define IRQ_MMP3_CCIC1			(IRQ_MMP3_CI_BASE + 1)

/* secondary interrupt of INT #51 */
#define IRQ_MMP3_SSP_BASE		(IRQ_MMP3_CI_BASE + 2)
#define IRQ_MMP3_SSP1_SRDY		(IRQ_MMP3_SSP_BASE + 0)
#define IRQ_MMP3_SSP3_SRDY		(IRQ_MMP3_SSP_BASE + 1)

/* secondary interrupt of INT #55 */
#define IRQ_MMP3_HSI1_BASE		(IRQ_MMP3_SSP_BASE + 2)
#define IRQ_MMP3_MMC5			(IRQ_MMP3_HSI1_BASE + 0)
#define IRQ_MMP3_HSI1_RSVD		(IRQ_MMP3_HSI1_BASE + 1)
#define IRQ_MMP3_UNIPRO1		(IRQ_MMP3_HSI1_BASE + 2)
#define IRQ_MMP3_HSI1			(IRQ_MMP3_HSI1_BASE + 3)

/* secondary interrupt of INT #57 */
#define IRQ_MMP3_MISC2_BASE		(IRQ_MMP3_HSI1_BASE + 4)
#define IRQ_MMP3_DSP_AUDIO_0		(IRQ_MMP3_MISC2_BASE + 0)
#define IRQ_MMP3_DSP_AUDIO_1		(IRQ_MMP3_MISC2_BASE + 1)
#define IRQ_MMP3_DSP_AUDIO_2		(IRQ_MMP3_MISC2_BASE + 2)
#define IRQ_MMP3_DSP_AUDIO_3		(IRQ_MMP3_MISC2_BASE + 3)
#define IRQ_MMP3_DSP_AUDIO_4		(IRQ_MMP3_MISC2_BASE + 4)
#define IRQ_MMP3_DSP_AUDIO_5		(IRQ_MMP3_MISC2_BASE + 5)
#define IRQ_MMP3_DSP_AUDIO_6		(IRQ_MMP3_MISC2_BASE + 6)
#define IRQ_MMP3_DSP_AUDIO_7		(IRQ_MMP3_MISC2_BASE + 7)
#define IRQ_MMP3_DSP_AUDIO_8		(IRQ_MMP3_MISC2_BASE + 8)
#define IRQ_MMP3_DSP_AUDIO_9		(IRQ_MMP3_MISC2_BASE + 9)
#define IRQ_MMP3_FABRIC_TIMEOUT		(IRQ_MMP3_MISC2_BASE + 10)
#define IRQ_MMP3_THERMAL_SENSOR		(IRQ_MMP3_MISC2_BASE + 11)
#define IRQ_MMP3_MPMU			(IRQ_MMP3_MISC2_BASE + 12)
#define IRQ_MMP3_WDT2			(IRQ_MMP3_MISC2_BASE + 13)
#define IRQ_MMP3_CORESIGHT		(IRQ_MMP3_MISC2_BASE + 14)
#define IRQ_MMP3_DDR			(IRQ_MMP3_MISC2_BASE + 15)
#define IRQ_MMP3_DDR2			(IRQ_MMP3_MISC2_BASE + 16)
#define IRQ_MMP3_MOLTRES_NHWAFIRQ	(IRQ_MMP3_MISC2_BASE + 17)
#define IRQ_MMP3_MOLTRES_SF_PERR	(IRQ_MMP3_MISC2_BASE + 18)
#define IRQ_MMP3_MOLTRES_MMU_PERR	(IRQ_MMP3_MISC2_BASE + 19)

/* secondary interrupt of INT #58 */
#define IRQ_MMP3_HSI0_BASE		(IRQ_MMP3_MISC2_BASE + 20)
#define IRQ_MMP3_MSP_CARD		(IRQ_MMP3_HSI0_BASE + 0)
#define IRQ_MMP3_KERMIT_INT_0		(IRQ_MMP3_HSI0_BASE + 1)
#define IRQ_MMP3_KERMIT_INT_1		(IRQ_MMP3_HSI0_BASE + 2)
#define IRQ_MMP3_UNIPRO_INT_0		(IRQ_MMP3_HSI0_BASE + 3)
#define IRQ_MMP3_HSI0			(IRQ_MMP3_HSI0_BASE + 4)

#define IRQ_MMP3_MUX_END		(IRQ_MMP3_HSI0_BASE + 5)


#ifdef CONFIG_CPU_MMP3
#define IRQ_GPIO_START			IRQ_MMP3_MUX_END
#else
#define IRQ_GPIO_START			160
#endif
#define IRQ_GPIO_NUM			192
#define IRQ_GPIO(x)			(IRQ_GPIO_START + (x))
#define IRQ_BOARD_START			(IRQ_GPIO_START + IRQ_GPIO_NUM)
#define NR_IRQS				(IRQ_BOARD_START)

#endif /* __ASM_MACH_IRQS_H */