/**************************************************************************//**
 * @file     system_fm33lr0xx.h
 * @brief    CMSIS Cortex-M0 Device Peripheral Access Layer Header File for
 *           Device FM33LR0XX
 * @version  V1.0.5
 * @date     29. June 2025
 *
 * @note
 *
 ******************************************************************************/
#ifndef SYSTEM_FM33LR0XX_H
#define SYSTEM_FM33LR0XX_H

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief CMSIS Device version number
  */
#define __FM33LR0xx_CMSIS_VERSION_MAIN      (0x01) /*!< [31:24] main version */
#define __FM33LR0xx_CMSIS_VERSION_SUB1      (0x00) /*!< [23:16] sub1 version */
#define __FM33LR0xx_CMSIS_VERSION_SUB2      (0x00) /*!< [15:0]  sub2 version */
#define __FM33LR0xx_CMSIS_VERSION           ((__FM33LR0xx_CMSIS_VERSION_MAIN  << 24)\
                                             |(__FM33LR0xx_CMSIS_VERSION_SUB1 << 16)\
                                             |(__FM33LR0xx_CMSIS_VERSION_SUB2))

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Device Includes -----------------------------------------------------------*/
#include "fm33lr0xx.h"

/* Trim Values ---------------------------------------------------------------*/
/* Validate Function */
#define LDT_CHECK(_N_VALUE_, _T_VALUE_)                         \
                            ((((_N_VALUE_ >> 16) & 0xffff) ==   \
                            ((~_N_VALUE_) & 0xffff)) ? _N_VALUE_ : _T_VALUE_)

/* Trim Values Address */
#define RCLP_LDT_TRIM       (*(uint32_t *)0x1FFFFD20)   // RCLP 常温校准值
#define RCHF8M_LDT_TRIM     (*(uint32_t *)0x1FFFFD40)   // RC8M 常温校准值
#define RCHF16M_LDT_TRIM    (*(uint32_t *)0x1FFFFD44)   // RC16M 常温校准值
#define RCHF24M_LDT_TRIM    (*(uint32_t *)0x1FFFFD48)   // RC24M 常温校准值
#define RCHF32M_LDT_TRIM    (*(uint32_t *)0x1FFFFD4C)   // RC32M 常温校准值

/* Trim Values */
#define RCLP_TRIM           (LDT_CHECK(RCLP_LDT_TRIM, 0x80) & 0xff)
#define RCHF8M_TRIM         (LDT_CHECK(RCHF8M_LDT_TRIM, 0x80) & 0xff)
#define RCHF16M_TRIM        (LDT_CHECK(RCHF16M_LDT_TRIM, 0x80) & 0xff)
#define RCHF24M_TRIM        (LDT_CHECK(RCHF24M_LDT_TRIM, 0x80) & 0xff)
#define RCHF32M_TRIM        (LDT_CHECK(RCHF32M_LDT_TRIM, 0x80) & 0xff)

/**
  * @}
  */

//BIT MAP======================================================
#define BIT0            0x00000001U
#define BIT1            0x00000002U
#define BIT2            0x00000004U
#define BIT3            0x00000008U
#define BIT4            0x00000010U
#define BIT5            0x00000020U
#define BIT6            0x00000040U
#define BIT7            0x00000080U
#define BIT8            0x00000100U
#define BIT9            0x00000200U
#define BIT10           0x00000400U
#define BIT11           0x00000800U
#define BIT12           0x00001000U
#define BIT13           0x00002000U
#define BIT14           0x00004000U
#define BIT15           0x00008000U
#define BIT16           0x00010000U
#define BIT17           0x00020000U
#define BIT18           0x00040000U
#define BIT19           0x00080000U
#define BIT20           0x00100000U
#define BIT21           0x00200000U
#define BIT22           0x00400000U
#define BIT23           0x00800000U
#define BIT24           0x01000000U
#define BIT25           0x02000000U
#define BIT26           0x04000000U
#define BIT27           0x08000000U
#define BIT28           0x10000000U
#define BIT29           0x20000000U
#define BIT30           0x40000000U
#define BIT31           0x80000000U
#define BITNO           0x00000000U    

/**
  * @}
  */

/* Bitfield macro definitions for various peripherals --------------------------------------------*/
/* CMU start --------------------------------------------*/
#define    CMU_SYSCLKCR_SYSC_SWLOC_Pos                            (31U)
#define    CMU_SYSCLKCR_SYSC_SWLOC_Msk                            (0x1U << CMU_SYSCLKCR_SYSC_SWLOC_Pos)
#define    CMU_SYSCLKCR_SYSC_SWLOC                                CMU_SYSCLKCR_SYSC_SWLOC_Msk

#define    CMU_SYSCLKCR_SLP_ENEXTI_Pos                            (25U)
#define    CMU_SYSCLKCR_SLP_ENEXTI_Msk                            (0x1U << CMU_SYSCLKCR_SLP_ENEXTI_Pos)
#define    CMU_SYSCLKCR_SLP_ENEXTI                                CMU_SYSCLKCR_SLP_ENEXTI_Msk

#define    CMU_SYSCLKCR_CKSAFE_CFG_Pos                            (24U)
#define    CMU_SYSCLKCR_CKSAFE_CFG_Msk                            (0x1U << CMU_SYSCLKCR_CKSAFE_CFG_Pos)
#define    CMU_SYSCLKCR_CKSAFE_CFG                                CMU_SYSCLKCR_CKSAFE_CFG_Msk

#define    CMU_SYSCLKCR_APBPRES_Pos                               (16U)
#define    CMU_SYSCLKCR_APBPRES_Msk                               (0x7U << CMU_SYSCLKCR_APBPRES_Pos)
#define    CMU_SYSCLKCR_APBPRES                                   CMU_SYSCLKCR_APBPRES_Msk

#define    CMU_SYSCLKCR_AHBPRES_WKUPRST_Pos                       (12U)
#define    CMU_SYSCLKCR_AHBPRES_WKUPRST_Msk                       (0x1U << CMU_SYSCLKCR_AHBPRES_WKUPRST_Pos)
#define    CMU_SYSCLKCR_AHBPRES_WKUPRST                           CMU_SYSCLKCR_AHBPRES_WKUPRST_Msk

#define    CMU_SYSCLKCR_AHBPRES_Pos                               (8U)
#define    CMU_SYSCLKCR_AHBPRES_Msk                               (0x7U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    CMU_SYSCLKCR_AHBPRES                                   CMU_SYSCLKCR_AHBPRES_Msk

#define    CMU_SYSCLKCR_STCLKSEL_Pos                              (6U)
#define    CMU_SYSCLKCR_STCLKSEL_Msk                              (0x3U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define    CMU_SYSCLKCR_STCLKSEL                                  CMU_SYSCLKCR_STCLKSEL_Msk

#define    CMU_SYSCLKCR_SYSCLKSEL_Pos                             (0U)
#define    CMU_SYSCLKCR_SYSCLKSEL_Msk                             (0x7U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    CMU_SYSCLKCR_SYSCLKSEL                                 CMU_SYSCLKCR_SYSCLKSEL_Msk

#define    CMU_RCHFCR_FSEL_Pos                                    (16U)
#define    CMU_RCHFCR_FSEL_Msk                                    (0xfU << CMU_RCHFCR_FSEL_Pos)
#define    CMU_RCHFCR_FSEL                                        CMU_RCHFCR_FSEL_Msk

#define    CMU_RCHFCR_EN_Pos                                      (0U)
#define    CMU_RCHFCR_EN_Msk                                      (0x1U << CMU_RCHFCR_EN_Pos)
#define    CMU_RCHFCR_EN                                          CMU_RCHFCR_EN_Msk

#define    CMU_RCHFTR_TRIM_Pos                                    (0U)
#define    CMU_RCHFTR_TRIM_Msk                                    (0xffU << CMU_RCHFTR_TRIM_Pos)
#define    CMU_RCHFTR_TRIM                                        CMU_RCHFTR_TRIM_Msk

#define    CMU_PLLCR_OPSC_Pos                                     (24)
#define    CMU_PLLCR_OPSC_Msk                                     (0x7U << CMU_PLLCR_OPSC_Pos)
#define    CMU_PLLCR_OPSC                                         CMU_PLLCR_OPSC_Msk

#define    CMU_PLLCR_DB_Pos                                       (16U)
#define    CMU_PLLCR_DB_Msk                                       (0x7fU << CMU_PLLCR_DB_Pos)
#define    CMU_PLLCR_DB                                           CMU_PLLCR_DB_Msk

#define    CMU_PLLCR_ICFG_Pos                                     (12U)
#define    CMU_PLLCR_ICFG_Msk                                     (0xfU << CMU_PLLCR_ICFG_Pos)
#define    CMU_PLLCR_ICFG                                         CMU_PLLCR_ICFG_Msk

#define    CMU_PLLCR_RTRIM_Pos                                    (8U)
#define    CMU_PLLCR_RTRIM_Msk                                    (0xfU << CMU_PLLCR_RTRIM_Pos)
#define    CMU_PLLCR_RTRIM                                        CMU_PLLCR_RTRIM_Msk

#define    CMU_PLLCR_LOCKED_Pos                                   (7U)
#define    CMU_PLLCR_LOCKED_Msk                                   (0x1U << CMU_PLLCR_LOCKED_Pos)
#define    CMU_PLLCR_LOCKED                                       CMU_PLLCR_LOCKED_Msk

#define    CMU_PLLCR_REFPRSC_Pos                                  (4U)
#define    CMU_PLLCR_REFPRSC_Msk                                  (0x7U << CMU_PLLCR_REFPRSC_Pos)
#define    CMU_PLLCR_REFPRSC                                      CMU_PLLCR_REFPRSC_Msk

#define    CMU_PLLCR_INSEL_Pos                                    (1U)
#define    CMU_PLLCR_INSEL_Msk                                    (0x1U << CMU_PLLCR_INSEL_Pos)
#define    CMU_PLLCR_INSEL                                        CMU_PLLCR_INSEL_Msk

#define    CMU_PLLCR_EN_Pos                                       (0U)
#define    CMU_PLLCR_EN_Msk                                       (0x1U << CMU_PLLCR_EN_Pos)
#define    CMU_PLLCR_EN                                           CMU_PLLCR_EN_Msk

#define    CMU_RCLPTR_TRIM_Pos                                    (0U)
#define    CMU_RCLPTR_TRIM_Msk                                    (0xffU << CMU_RCLPTR_TRIM_Pos)
#define    CMU_RCLPTR_TRIM                                        CMU_RCLPTR_TRIM_Msk

#define    CMU_XTHFCR_WAIT_Pos                                    (13U)
#define    CMU_XTHFCR_WAIT_Msk                                    (0x7U << CMU_XTHFCR_WAIT_Pos)
#define    CMU_XTHFCR_WAIT                                        CMU_XTHFCR_WAIT_Msk

#define    CMU_XTHFCR_CFG_Pos                                     (8U)
#define    CMU_XTHFCR_CFG_Msk                                     (0xfU << CMU_XTHFCR_CFG_Pos)
#define    CMU_XTHFCR_CFG                                         CMU_XTHFCR_CFG_Msk

#define    CMU_XTHFCR_BYPASS_Pos                                  (4U)
#define    CMU_XTHFCR_BYPASS_Msk                                  (0x1U << CMU_XTHFCR_BYPASS_Pos)
#define    CMU_XTHFCR_BYPASS                                      CMU_XTHFCR_BYPASS_Msk

#define    CMU_XTHFCR_RDY_Pos                                     (1U)
#define    CMU_XTHFCR_RDY_Msk                                     (0x1U << CMU_XTHFCR_RDY_Pos)
#define    CMU_XTHFCR_RDY                                         CMU_XTHFCR_RDY_Msk

#define    CMU_XTHFCR_EN_Pos                                      (0U)
#define    CMU_XTHFCR_EN_Msk                                      (0x1U << CMU_XTHFCR_EN_Pos)
#define    CMU_XTHFCR_EN                                          CMU_XTHFCR_EN_Msk

#define    CMU_IER_SYSCKE_IE_Pos                                  (2U)
#define    CMU_IER_SYSCKE_IE_Msk                                  (0x1U << CMU_IER_SYSCKE_IE_Pos)
#define    CMU_IER_SYSCKE_IE                                      CMU_IER_SYSCKE_IE_Msk

#define    CMU_IER_HFDET_IE_Pos                                   (1U)
#define    CMU_IER_HFDET_IE_Msk                                   (0x1U << CMU_IER_HFDET_IE_Pos)
#define    CMU_IER_HFDET_IE                                       CMU_IER_HFDET_IE_Msk

#define    CMU_ISR_HFDETO_Pos                                     (9U)
#define    CMU_ISR_HFDETO_Msk                                     (0x1U << CMU_ISR_HFDETO_Pos)
#define    CMU_ISR_HFDETO                                         CMU_ISR_HFDETO_Msk

#define    CMU_ISR_SYSCSE_IF_Pos                                  (2U)
#define    CMU_ISR_SYSCSE_IF_Msk                                  (0x1U << CMU_ISR_SYSCSE_IF_Pos)
#define    CMU_ISR_SYSCSE_IF                                      CMU_ISR_SYSCSE_IF_Msk

#define    CMU_ISR_HFDET_IF_Pos                                   (1U)
#define    CMU_ISR_HFDET_IF_Msk                                   (0x1U << CMU_ISR_HFDET_IF_Pos)
#define    CMU_ISR_HFDET_IF                                       CMU_ISR_HFDET_IF_Msk

#define    CMU_OPCCR1_EXTICKS_Pos                                 (30U)
#define    CMU_OPCCR1_EXTICKS_Msk                                 (0x1U << CMU_OPCCR1_EXTICKS_Pos)
#define    CMU_OPCCR1_EXTICKS                                     CMU_OPCCR1_EXTICKS_Msk

#define    CMU_OPCCR1_BT16CKS_Pos                                 (14U)
#define    CMU_OPCCR1_BT16CKS_Msk                                 (0x3U << CMU_OPCCR1_BT16CKS_Pos)
#define    CMU_OPCCR1_BT16CKS                                     CMU_OPCCR1_BT16CKS_Msk

#define    CMU_OPCCR1_LPT16CKS_Pos                                (10U)
#define    CMU_OPCCR1_LPT16CKS_Msk                                (0x3U << CMU_OPCCR1_LPT16CKS_Pos)
#define    CMU_OPCCR1_LPT16CKS                                    CMU_OPCCR1_LPT16CKS_Msk

#define    CMU_OPCCR1_ATCKS_Pos                                   (7U)
#define    CMU_OPCCR1_ATCKS_Msk                                   (0x1U << CMU_OPCCR1_ATCKS_Pos)
#define    CMU_OPCCR1_ATCKS                                       CMU_OPCCR1_ATCKS_Msk

#define    CMU_OPCCR1_UART1CKS_Pos                                (2U)
#define    CMU_OPCCR1_UART1CKS_Msk                                (0x3U << CMU_OPCCR1_UART1CKS_Pos)
#define    CMU_OPCCR1_UART1CKS                                    CMU_OPCCR1_UART1CKS_Msk

#define    CMU_AMCR_MPRIL_Pos                                     (0U)
#define    CMU_AMCR_MPRIL_Msk                                     (0x1U << CMU_AMCR_MPRIL_Pos)
#define    CMU_AMCR_MPRIL                                         CMU_AMCR_MPRIL_Msk

#define    FL_CMU_GROUP1_BUSCLK_LPTIM16                           (0x1U << 1U)
#define    FL_CMU_GROUP1_BUSCLK_PMU                               (0x1U << 3U)
#define    FL_CMU_GROUP1_BUSCLK_SCU                               (0x1U << 4U)
#define    FL_CMU_GROUP1_BUSCLK_IWDT                              (0x1U << 5U)
#define    FL_CMU_GROUP1_BUSCLK_ANAC                              (0x1U << 6U)
#define    FL_CMU_GROUP1_BUSCLK_PAD                               (0x1U << 7U)
#define    FL_CMU_GROUP1_BUSCLK_SVD                               (0x1U << 8U)
#define    FL_CMU_GROUP1_BUSCLK_COMP                              (0x1U << 9U)
#define    FL_CMU_GROUP2_BUSCLK_CRC                               (0x1U << 0U)
#define    FL_CMU_GROUP2_BUSCLK_DMA                               (0x1U << 4U)
#define    FL_CMU_GROUP2_BUSCLK_FLASH                             (0x1U << 5U)
#define    FL_CMU_GROUP2_BUSCLK_RAMBIST                           (0x1U << 6U)
#define    FL_CMU_GROUP2_BUSCLK_WWDT                              (0x1U << 7U)
#define    FL_CMU_GROUP2_BUSCLK_ADC                               (0x1U << 8U)
#define    FL_CMU_GROUP2_BUSCLK_DIVAS                             (0x1U << 9U)
#define    FL_CMU_GROUP2_BUSCLK_PGL                               (0x1U << 11U)
#define    FL_CMU_GROUP3_BUSCLK_SPI0                              (0x1U << 0U)
#define    FL_CMU_GROUP3_BUSCLK_SPI1                              (0x1U << 1U)
#define    FL_CMU_GROUP3_BUSCLK_UART1                             (0x1U << 9U)
#define    FL_CMU_GROUP3_BUSCLK_UART2                             (0x1U << 10U)
#define    FL_CMU_GROUP3_BUSCLK_UART4                             (0x1U << 12U)
#define    FL_CMU_GROUP3_BUSCLK_UART5                             (0x1U << 13U)
#define    FL_CMU_GROUP3_BUSCLK_UARTIR                            (0x1U << 14U)
#define    FL_CMU_GROUP3_BUSCLK_I2C0                              (0x1U << 24U)
#define    FL_CMU_GROUP3_BUSCLK_I2C1                              (0x1U << 25U)
#define    FL_CMU_GROUP4_BUSCLK_ATIM                              (0x1U << 0U)
#define    FL_CMU_GROUP4_BUSCLK_TAU0                              (0x1U << 4U)
#define    FL_CMU_GROUP4_BUSCLK_TAU1                              (0x1U << 5U)
#define    FL_CMU_GROUP4_BUSCLK_BSTIM16                           (0x1U << 8U)
#define    FL_CMU_GROUP4_BUSCLK_GPTIM                             (0x1U << 12U)
#define    FL_CMU_OPCLK_EXTI                                      (0x1U << 31U)
#define    FL_CMU_OPCLK_FLASH                                     (0x1U << 30U)
#define    FL_CMU_OPCLK_ATIM                                      (0x1U << 15U)
#define    FL_CMU_OPCLK_LIN                                       (0x1U << 10U)
#define    FL_CMU_OPCLK_UART1                                     (0x1U << 9U)
#define    FL_CMU_OPCLK_BSTIM16                                   (0x1U << 3U)
#define    FL_CMU_OPCLK_LPTIM16                                   (0x1U << 1U)

#define    FL_CMU_APBCLK_PSC_DIV1                                 (0x0U << CMU_SYSCLKCR_APBPRES_Pos)
#define    FL_CMU_APBCLK_PSC_DIV2                                 (0x4U << CMU_SYSCLKCR_APBPRES_Pos)
#define    FL_CMU_APBCLK_PSC_DIV4                                 (0x5U << CMU_SYSCLKCR_APBPRES_Pos)
#define    FL_CMU_APBCLK_PSC_DIV8                                 (0x6U << CMU_SYSCLKCR_APBPRES_Pos)
#define    FL_CMU_APBCLK_PSC_DIV16                                (0x7U << CMU_SYSCLKCR_APBPRES_Pos)

#define    FL_CMU_AHBCLK_PSC_DIV1                                 (0x0U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV2                                 (0x4U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV4                                 (0x5U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV8                                 (0x6U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV16                                (0x7U << CMU_SYSCLKCR_AHBPRES_Pos)

#define    FL_CMU_SYSTICK_CLK_SOURCE_SCLK                         (0x0U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define    FL_CMU_SYSTICK_CLK_SOURCE_RCLP                         (0x1U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define    FL_CMU_SYSTICK_CLK_SOURCE_SYSCLK                       (0x3U << CMU_SYSCLKCR_STCLKSEL_Pos)

#define    FL_CMU_SYSTEM_CLK_SOURCE_RCHF                          (0x0U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_XTHF                          (0x1U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_PLL                           (0x2U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_RCLP                          (0x6U << CMU_SYSCLKCR_SYSCLKSEL_Pos)

#define    FL_CMU_RCHF_FREQUENCY_8MHZ                             (0x0U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_16MHZ                            (0x1U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_24MHZ                            (0x2U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_32MHZ                            (0x3U << CMU_RCHFCR_FSEL_Pos)

#define    FL_CMU_PLL_PSC_DIV1                                    (0x0U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV2                                    (0x1U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV3                                    (0x2U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV4                                    (0x3U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV6                                    (0x4U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV8                                    (0x5U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV10                                   (0x6U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV12                                   (0x7U << CMU_PLLCR_REFPRSC_Pos)

#define    FL_CMU_PLL_CLK_SOURCE_RCHF                             (0x0U << CMU_PLLCR_INSEL_Pos)
#define    FL_CMU_PLL_CLK_SOURCE_XTHF                             (0x1U << CMU_PLLCR_INSEL_Pos)

#define    FL_CMU_XTHF_START_WAIT_CYCLE_128                       (0x0U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_256                       (0x1U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_512                       (0x2U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_1024                      (0x3U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_2048                      (0x4U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_4096                      (0x5U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_8192                      (0x6U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_16384                     (0x7U << CMU_XTHFCR_WAIT_Pos)

#define    FL_CMU_EXTI_CLK_SOURCE_RCLP                            (0x1U << CMU_OPCCR1_EXTICKS_Pos)
#define    FL_CMU_EXTI_CLK_SOURCE_HCLK                            (0x0U << CMU_OPCCR1_EXTICKS_Pos)

#define    FL_CMU_BSTIM16_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_BT16CKS_Pos)
#define    FL_CMU_BSTIM16_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_BT16CKS_Pos)

#define    FL_CMU_LPTIM16_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_LPT16CKS_Pos)
#define    FL_CMU_LPTIM16_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_LPT16CKS_Pos)

#define    FL_CMU_ATIM_CLK_SOURCE_APBCLK                          (0x0U << CMU_OPCCR1_ATCKS_Pos)

#define    FL_CMU_UART1_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART1CKS_Pos)

#define    FL_CMU_AHB_MASTER_PRIORITY_DMA                         (0x0U << CMU_AMCR_MPRIL_Pos)
#define    FL_CMU_AHB_MASTER_PRIORITY_CPU                         (0x1U << CMU_AMCR_MPRIL_Pos)
/* CMU end --------------------------------------------*/

/* ADC start --------------------------------------------*/
#define    ADC_ISR_EOC_Pos                                        (0U)
#define    ADC_ISR_EOC_Msk                                        (0x1U << ADC_ISR_EOC_Pos)
#define    ADC_ISR_EOC                                            ADC_ISR_EOC_Msk

#define    ADC_ISR_EOS_Pos                                        (1U)
#define    ADC_ISR_EOS_Msk                                        (0x1U << ADC_ISR_EOS_Pos)
#define    ADC_ISR_EOS                                            ADC_ISR_EOS_Msk

#define    ADC_ISR_OVR_Pos                                        (2U)
#define    ADC_ISR_OVR_Msk                                        (0x1U << ADC_ISR_OVR_Pos)
#define    ADC_ISR_OVR                                            ADC_ISR_OVR_Msk

#define    ADC_ISR_BUSY_Pos                                       (3U)
#define    ADC_ISR_BUSY_Msk                                       (0x1U << ADC_ISR_BUSY_Pos)
#define    ADC_ISR_BUSY                                           ADC_ISR_BUSY_Msk

#define    ADC_ISR_EOCAL_Pos                                      (4U)
#define    ADC_ISR_EOCAL_Msk                                      (0x1U << ADC_ISR_EOCAL_Pos)
#define    ADC_ISR_EOCAL                                          ADC_ISR_EOCAL_Msk

#define    ADC_ISR_RDY_Pos                                      	(7U)
#define    ADC_ISR_RDY_Msk                                        (0x1U << ADC_ISR_RDY_Pos)
#define    ADC_ISR_RDY                                            ADC_ISR_RDY_Msk

#define    ADC_IER_EOCIE_Pos                                      (0U)
#define    ADC_IER_EOCIE_Msk                                      (0x1U << ADC_IER_EOCIE_Pos)
#define    ADC_IER_EOCIE                                          ADC_IER_EOCIE_Msk

#define    ADC_IER_EOSIE_Pos                                      (1U)
#define    ADC_IER_EOSIE_Msk                                      (0x1U << ADC_IER_EOSIE_Pos)
#define    ADC_IER_EOSIE                                          ADC_IER_EOSIE_Msk

#define    ADC_IER_OVRIE_Pos                                      (2U)
#define    ADC_IER_OVRIE_Msk                                      (0x1U << ADC_IER_OVRIE_Pos)
#define    ADC_IER_OVRIE                                          ADC_IER_OVRIE_Msk

#define    ADC_IER_EOCALIE_Pos                                    (4U)
#define    ADC_IER_EOCALIE_Msk                                    (0x1U << ADC_IER_EOCALIE_Pos)
#define    ADC_IER_EOCALIE                                        ADC_IER_EOCALIE_Msk

#define    ADC_CR1_ADEN_Pos                                       (0U)
#define    ADC_CR1_ADEN_Msk                                       (0x1U << ADC_CR1_ADEN_Pos)
#define    ADC_CR1_ADEN                                           ADC_CR1_ADEN_Msk

#define    ADC_CR1_SWTRIG_Pos                                     (1U)
#define    ADC_CR1_SWTRIG_Msk                                     (0x1U << ADC_CR1_SWTRIG_Pos)
#define    ADC_CR1_SWTRIG                                         ADC_CR1_SWTRIG_Msk

#define    ADC_CR2_TRGCFG_Pos                                     (0U)
#define    ADC_CR2_TRGCFG_Msk                                     (0x3U << ADC_CR2_TRGCFG_Pos)
#define    ADC_CR2_TRGCFG                                         ADC_CR2_TRGCFG_Msk

#define    ADC_CALCR_CALEN_Pos                                     (0U)
#define    ADC_CALCR_CALEN_Msk                                     (0x1U << ADC_CALCR_CALEN_Pos)
#define    ADC_CALCR_CALEN                                         ADC_CALCR_CALEN_Msk

#define    ADC_CFGR1_RPTLEN_Pos                                   (16U)
#define    ADC_CFGR1_RPTLEN_Msk                                   (0xffffU << ADC_CFGR1_RPTLEN_Pos)
#define    ADC_CFGR1_RPTLEN                                       ADC_CFGR1_RPTLEN_Msk

#define    ADC_CFGR1_APBCLK_PSC_Pos                               (5U)
#define    ADC_CFGR1_APBCLK_PSC_Msk                               (0x7U << ADC_CFGR1_APBCLK_PSC_Pos)
#define    ADC_CFGR1_APBCLK_PSC                                   ADC_CFGR1_APBCLK_PSC_Msk

#define    ADC_CFGR2_DMAEN_Pos                                    (0U)
#define    ADC_CFGR2_DMAEN_Msk                                    (0x1U << ADC_CFGR2_DMAEN_Pos)
#define    ADC_CFGR2_DMAEN                                        ADC_CFGR2_DMAEN_Msk

#define    ADC_CFGR2_SCANDIR_Pos                                  (2U)
#define    ADC_CFGR2_SCANDIR_Msk                                  (0x1U << ADC_CFGR2_SCANDIR_Pos)
#define    ADC_CFGR2_SCANDIR                                      ADC_CFGR2_SCANDIR_Msk

#define    ADC_CFGR2_EXTS_Pos                                     (4U)
#define    ADC_CFGR2_EXTS_Msk                                     (0xfU << ADC_CFGR2_EXTS_Pos)
#define    ADC_CFGR2_EXTS                                         ADC_CFGR2_EXTS_Msk

#define    ADC_CFGR2_OVRM_Pos                                     (8U)
#define    ADC_CFGR2_OVRM_Msk                                     (0x1U << ADC_CFGR2_OVRM_Pos)
#define    ADC_CFGR2_OVRM                                         ADC_CFGR2_OVRM_Msk

#define    ADC_CFGR2_CONT_Pos                                     (9U)
#define    ADC_CFGR2_CONT_Msk                                     (0x1U << ADC_CFGR2_CONT_Pos)
#define    ADC_CFGR2_CONT                                         ADC_CFGR2_CONT_Msk

#define    ADC_CFGR2_WAIT_Pos                                     (10U)
#define    ADC_CFGR2_WAIT_Msk                                     (0x1U << ADC_CFGR2_WAIT_Pos)
#define    ADC_CFGR2_WAIT                                         ADC_CFGR2_WAIT_Msk

#define    ADC_CFGR2_SEMI_Pos                                     (11U)
#define    ADC_CFGR2_SEMI_Msk                                     (0x1U << ADC_CFGR2_SEMI_Pos)
#define    ADC_CFGR2_SEMI                                         ADC_CFGR2_SEMI_Msk

#define    ADC_CFGR2_IOTRFEN_Pos                                  (14U)
#define    ADC_CFGR2_IOTRFEN_Msk                                  (0x1U << ADC_CFGR2_IOTRFEN_Pos)
#define    ADC_CFGR2_IOTRFEN                                      ADC_CFGR2_IOTRFEN_Msk

#define    ADC_CFGR2_OVSEN_Pos                                    (16U)
#define    ADC_CFGR2_OVSEN_Msk                                    (0x1U << ADC_CFGR2_OVSEN_Pos)
#define    ADC_CFGR2_OVSEN                                        ADC_CFGR2_OVSEN_Msk

#define    ADC_CFGR2_OVSR_Pos                                     (17U)
#define    ADC_CFGR2_OVSR_Msk                                     (0x7U << ADC_CFGR2_OVSR_Pos)
#define    ADC_CFGR2_OVSR                                         ADC_CFGR2_OVSR_Msk

#define    ADC_CFGR2_OVSS_Pos                                     (20U)
#define    ADC_CFGR2_OVSS_Msk                                     (0xfU << ADC_CFGR2_OVSS_Pos)
#define    ADC_CFGR2_OVSS                                         ADC_CFGR2_OVSS_Msk

#define    ADC_SMTR_SMTS_Pos                                      (0U)
#define    ADC_SMTR_SMTS_Msk                                      (0xfU << ADC_SMTR_SMTS_Pos)
#define    ADC_SMTR_SMTS                                          ADC_SMTR_SMTS_Msk

#define    ADC_DR_DATA_Pos                                        (0U)
#define    ADC_DR_DATA_Msk                                        (0xffffU << ADC_DR_DATA_Pos)
#define    ADC_DR_DATA                                            ADC_DR_DATA_Msk

#define    FL_ADC_EXTERNAL_CH0                                    (0x1U << 0U)
#define    FL_ADC_EXTERNAL_CH1                                    (0x1U << 1U)
#define    FL_ADC_EXTERNAL_CH2                                    (0x1U << 2U)
#define    FL_ADC_EXTERNAL_CH3                                    (0x1U << 3U)
#define    FL_ADC_EXTERNAL_CH4                                    (0x1U << 4U)
#define    FL_ADC_EXTERNAL_CH5                                    (0x1U << 5U)
#define    FL_ADC_EXTERNAL_CH6                                    (0x1U << 6U)
#define    FL_ADC_EXTERNAL_CH7                                    (0x1U << 7U)
#define    FL_ADC_EXTERNAL_CH8                                    (0x1U << 8U)
#define    FL_ADC_EXTERNAL_CH9                                    (0x1U << 9U)
#define    FL_ADC_EXTERNAL_CH10                                   (0x1U << 10U)
#define    FL_ADC_EXTERNAL_CH11                                   (0x1U << 11U)
#define    FL_ADC_EXTERNAL_CH12                                   (0x1U << 12U)
#define    FL_ADC_EXTERNAL_CH13                                   (0x1U << 13U)
#define    FL_ADC_EXTERNAL_CH14                                   (0x1U << 14U)
#define    FL_ADC_EXTERNAL_CH15                                   (0x1U << 15U)
#define    FL_ADC_EXTERNAL_CH16                                   (0x1U << 16U)
#define    FL_ADC_INTERNAL_TS                                     (0x1U << 25U)
#define    FL_ADC_INTERNAL_AVREF                                  (0x1U << 26U)
#define    FL_ADC_ALL_CHANNEL                                     (0xffffffffU << 0U)
#define    FL_ADC_DIFFERENTIAL_GROUP0                             (0x1U << 0U)
#define    FL_ADC_DIFFERENTIAL_GROUP1                             (0x1U << 1U)
#define    FL_ADC_DIFFERENTIAL_GROUP2                             (0x1U << 2U)
#define    FL_ADC_DIFFERENTIAL_GROUP3                             (0x1U << 3U)
#define    FL_ADC_DIFFERENTIAL_GROUP4                             (0x1U << 4U)
#define    FL_ADC_DIFFERENTIAL_GROUP5                             (0x1U << 5U)
#define    FL_ADC_DIFFERENTIAL_GROUP6                             (0x1U << 6U)

#define    FL_ADC_TRIGGER_EDGE_NONE                               (0x0U << ADC_CR2_TRGCFG_Pos)
#define    FL_ADC_TRIGGER_EDGE_RISING                             (0x1U << ADC_CR2_TRGCFG_Pos)
#define    FL_ADC_TRIGGER_EDGE_FALLING                            (0x2U << ADC_CR2_TRGCFG_Pos)
#define    FL_ADC_TRIGGER_EDGE_BOTH                               (0x3U << ADC_CR2_TRGCFG_Pos)

#define    FL_ADC_APBCLK_PSC_DIV1                                 (0x0U << ADC_CFGR1_APBCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV2                                 (0x1U << ADC_CFGR1_APBCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV4                                 (0x2U << ADC_CFGR1_APBCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV8                                 (0x3U << ADC_CFGR1_APBCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV3                                 (0x4U << ADC_CFGR1_APBCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV5                                 (0x5U << ADC_CFGR1_APBCLK_PSC_Pos)
#define    FL_ADC_APBCLK_PSC_DIV6                                 (0x6U << ADC_CFGR1_APBCLK_PSC_Pos)

#define    FL_ADC_SEQ_SCAN_DIR_FORWARD                            (0x0U << ADC_CFGR2_SCANDIR_Pos)
#define    FL_ADC_SEQ_SCAN_DIR_BACKWARD                           (0x1U << ADC_CFGR2_SCANDIR_Pos)

#define    FL_ADC_TRGI_LUT0                                       (0x0U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_LUT1                                       (0x1U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_LUT2                                       (0x2U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_ATIM                                       (0x3U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_TAU01                                      (0x4U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_ATIM_TRGO2                                 (0x5U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_BSTIM16                                    (0x6U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_LPTIM16                                    (0x7U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_COMP1                                      (0x8U << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_LUT3                                       (0xbU << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_TAU00                                      (0xcU << ADC_CFGR2_EXTS_Pos)
#define    FL_ADC_TRGI_GPTIM                                      (0xdU << ADC_CFGR2_EXTS_Pos)

#define    FL_ADC_CONV_MODE_SINGLE                                (0x0U << ADC_CFGR2_CONT_Pos)
#define    FL_ADC_CONV_MODE_CONTINUOUS                            (0x1U << ADC_CFGR2_CONT_Pos)

#define    FL_ADC_SINGLE_CONV_MODE_AUTO                           (0x0U << ADC_CFGR2_SEMI_Pos)
#define    FL_ADC_SINGLE_CONV_MODE_SEMIAUTO                       (0x1U << ADC_CFGR2_SEMI_Pos)

#define    FL_ADC_OVERSAMPLING_MUL_2X                             (0x0U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_4X                             (0x1U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_8X                             (0x2U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_16X                            (0x3U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_32X                            (0x4U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_64X                            (0x5U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_128X                           (0x6U << ADC_CFGR2_OVSR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_256X                           (0x7U << ADC_CFGR2_OVSR_Pos)

#define    FL_ADC_OVERSAMPLING_SHIFT_0B                           (0x0U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_1B                           (0x1U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_2B                           (0x2U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_3B                           (0x3U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_4B                           (0x4U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_5B                           (0x5U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_6B                           (0x6U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_7B                           (0x7U << ADC_CFGR2_OVSS_Pos)
#define    FL_ADC_OVERSAMPLING_SHIFT_8B                           (0x8U << ADC_CFGR2_OVSS_Pos)

#define    FL_ADC_AWDG_ALL_CHANNEL                                (0x0U << ADC_CFGR2_AWDSC_Pos)
#define    FL_ADC_AWDG_SINGLE_CHANNEL                             (0x1U << ADC_CFGR2_AWDSC_Pos)

#define    FL_ADC_CH_SAMPLING_TIME_4_ADCCLK                       (0x0U << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_6_ADCCLK                       (0x1U << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_8_ADCCLK                       (0x2U << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_12_ADCCLK                      (0x3U << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_16_ADCCLK                      (0x4U << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_32_ADCCLK                      (0x5U << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_64_ADCCLK                      (0x6U << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_80_ADCCLK                      (0x7U << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_96_ADCCLK                      (0x8U << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_128_ADCCLK                     (0x9U << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_160_ADCCLK                     (0xaU << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_192_ADCCLK                     (0xbU << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_256_ADCCLK                     (0xcU << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_320_ADCCLK                     (0xdU << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_384_ADCCLK                     (0xeU << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_512_ADCCLK                     (0xfU << ADC_SMTR_SMTS_Pos)
/* ADC end --------------------------------------------*/

/* BSTIM start --------------------------------------------*/
#define    BSTIM16_CR1_ARPE_Pos                                   (7U)
#define    BSTIM16_CR1_ARPE_Msk                                   (0x1U << BSTIM16_CR1_ARPE_Pos)
#define    BSTIM16_CR1_ARPE                                       BSTIM16_CR1_ARPE_Msk

#define    BSTIM16_CR1_OPM_Pos                                    (3U)
#define    BSTIM16_CR1_OPM_Msk                                    (0x1U << BSTIM16_CR1_OPM_Pos)
#define    BSTIM16_CR1_OPM                                        BSTIM16_CR1_OPM_Msk

#define    BSTIM16_CR1_URS_Pos                                    (2U)
#define    BSTIM16_CR1_URS_Msk                                    (0x1U << BSTIM16_CR1_URS_Pos)
#define    BSTIM16_CR1_URS                                        BSTIM16_CR1_URS_Msk

#define    BSTIM16_CR1_UDIS_Pos                                   (1U)
#define    BSTIM16_CR1_UDIS_Msk                                   (0x1U << BSTIM16_CR1_UDIS_Pos)
#define    BSTIM16_CR1_UDIS                                       BSTIM16_CR1_UDIS_Msk

#define    BSTIM16_CR1_CEN_Pos                                    (0U)
#define    BSTIM16_CR1_CEN_Msk                                    (0x1U << BSTIM16_CR1_CEN_Pos)
#define    BSTIM16_CR1_CEN                                        BSTIM16_CR1_CEN_Msk

#define    BSTIM16_CR2_MMS_Pos                                    (4U)
#define    BSTIM16_CR2_MMS_Msk                                    (0x7U << BSTIM16_CR2_MMS_Pos)
#define    BSTIM16_CR2_MMS                                        BSTIM16_CR2_MMS_Msk

#define    BSTIM16_IER_UIE_Pos                                    (0U)
#define    BSTIM16_IER_UIE_Msk                                    (0x1U << BSTIM16_IER_UIE_Pos)
#define    BSTIM16_IER_UIE                                        BSTIM16_IER_UIE_Msk

#define    BSTIM16_ISR_UIF_Pos                                    (0U)
#define    BSTIM16_ISR_UIF_Msk                                    (0x1U << BSTIM16_ISR_UIF_Pos)
#define    BSTIM16_ISR_UIF                                        BSTIM16_ISR_UIF_Msk

#define    BSTIM16_EGR_UG_Pos                                     (0U)
#define    BSTIM16_EGR_UG_Msk                                     (0x1U << BSTIM16_EGR_UG_Pos)
#define    BSTIM16_EGR_UG                                         BSTIM16_EGR_UG_Msk

#define    FL_BSTIM16_ONE_PULSE_MODE_CONTINUOUS                   (0x0U << BSTIM16_CR1_OPM_Pos)
#define    FL_BSTIM16_ONE_PULSE_MODE_SINGLE                       (0x1U << BSTIM16_CR1_OPM_Pos)


#define    FL_BSTIM16_UPDATE_SOURCE_REGULAR                       (0x0U << BSTIM16_CR1_URS_Pos)
#define    FL_BSTIM16_UPDATE_SOURCE_COUNTER                       (0x1U << BSTIM16_CR1_URS_Pos)

#define    FL_BSTIM16_TRGO_UG                                     (0x0U << BSTIM16_CR2_MMS_Pos)
#define    FL_BSTIM16_TRGO_ENABLE                                 (0x1U << BSTIM16_CR2_MMS_Pos)
#define    FL_BSTIM16_TRGO_UPDATE                                 (0x2U << BSTIM16_CR2_MMS_Pos)
/* BSTIM end --------------------------------------------*/

/* FLASH start --------------------------------------------*/
#define    FLASH_RDCR_CODE_WAIT_Pos                               (0U)
#define    FLASH_RDCR_CODE_WAIT_Msk                               (0x3U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FLASH_RDCR_CODE_WAIT                                   FLASH_RDCR_CODE_WAIT_Msk

#define    FLASH_PFTCON_EN_Pos                                    (0U)
#define    FLASH_PFTCON_EN_Msk                                    (0x1U << FLASH_PFTCON_EN_Pos)
#define    FLASH_PFTCON_EN                                        FLASH_PFTCON_EN_Msk

#define    FLASH_OPTBR_IWDTSLP_Pos                                (31U)
#define    FLASH_OPTBR_IWDTSLP_Msk                                (0x1U << FLASH_OPTBR_IWDTSLP_Pos)
#define    FLASH_OPTBR_IWDTSLP                                    FLASH_OPTBR_IWDTSLP_Msk

#define    FLASH_OPTBR_IWDTEN_Pos                                 (30U)
#define    FLASH_OPTBR_IWDTEN_Msk                                 (0x1U << FLASH_OPTBR_IWDTEN_Pos)
#define    FLASH_OPTBR_IWDTEN                                     FLASH_OPTBR_IWDTEN_Msk

#define    FLASH_OPTBR_ACLOCKEN_Pos                               (2U)
#define    FLASH_OPTBR_ACLOCKEN_Msk                               (0x3U << FLASH_OPTBR_ACLOCKEN_Pos)
#define    FLASH_OPTBR_ACLOCKEN                                   FLASH_OPTBR_ACLOCKEN_Msk

#define    FLASH_OPTBR_DBRDPEN_Pos                                (0U)
#define    FLASH_OPTBR_DBRDPEN_Msk                                (0x3U << FLASH_OPTBR_DBRDPEN_Pos)
#define    FLASH_OPTBR_DBRDPEN                                    FLASH_OPTBR_DBRDPEN_Msk

#define    FLASH_EPCR_ERTYPE_Pos                                  (8U)
#define    FLASH_EPCR_ERTYPE_Msk                                  (0x3U << FLASH_EPCR_ERTYPE_Pos)
#define    FLASH_EPCR_ERTYPE                                      FLASH_EPCR_ERTYPE_Msk

#define    FLASH_EPCR_PREQ_Pos                                    (1U)
#define    FLASH_EPCR_PREQ_Msk                                    (0x1U << FLASH_EPCR_PREQ_Pos)
#define    FLASH_EPCR_PREQ                                        FLASH_EPCR_PREQ_Msk

#define    FLASH_EPCR_EREQ_Pos                                    (0U)
#define    FLASH_EPCR_EREQ_Msk                                    (0x1U << FLASH_EPCR_EREQ_Pos)
#define    FLASH_EPCR_EREQ                                        FLASH_EPCR_EREQ_Msk

#define    FLASH_IER_AUTHIE_Pos                                   (10U)
#define    FLASH_IER_AUTHIE_Msk                                   (0x1U << FLASH_IER_AUTHIE_Pos)
#define    FLASH_IER_AUTHIE                                       FLASH_IER_AUTHIE_Msk

#define    FLASH_IER_KEYIE_Pos                                    (9U)
#define    FLASH_IER_KEYIE_Msk                                    (0x1U << FLASH_IER_KEYIE_Pos)
#define    FLASH_IER_KEYIE                                        FLASH_IER_KEYIE_Msk

#define    FLASH_IER_CKIE_Pos                                     (8U)
#define    FLASH_IER_CKIE_Msk                                     (0x1U << FLASH_IER_CKIE_Pos)
#define    FLASH_IER_CKIE                                         FLASH_IER_CKIE_Msk

#define    FLASH_IER_PRDIE_Pos                                    (1U)
#define    FLASH_IER_PRDIE_Msk                                    (0x1U << FLASH_IER_PRDIE_Pos)
#define    FLASH_IER_PRDIE                                        FLASH_IER_PRDIE_Msk

#define    FLASH_IER_ERDIE_Pos                                    (0U)
#define    FLASH_IER_ERDIE_Msk                                    (0x1U << FLASH_IER_ERDIE_Pos)
#define    FLASH_IER_ERDIE                                        FLASH_IER_ERDIE_Msk

#define    FLASH_ISR_KEYSTA_Pos                                   (17U)
#define    FLASH_ISR_KEYSTA_Msk                                   (0x7U << FLASH_ISR_KEYSTA_Pos)
#define    FLASH_ISR_KEYSTA                                       FLASH_ISR_KEYSTA_Msk

#define    FLASH_ISR_AUTHERR_Pos                                  (10U)
#define    FLASH_ISR_AUTHERR_Msk                                  (0x1U << FLASH_ISR_AUTHERR_Pos)
#define    FLASH_ISR_AUTHERR                                      FLASH_ISR_AUTHERR_Msk

#define    FLASH_ISR_KEYERR_Pos                                   (9U)
#define    FLASH_ISR_KEYERR_Msk                                   (0x1U << FLASH_ISR_KEYERR_Pos)
#define    FLASH_ISR_KEYERR                                       FLASH_ISR_KEYERR_Msk

#define    FLASH_ISR_CKERR_Pos                                    (8U)
#define    FLASH_ISR_CKERR_Msk                                    (0x1U << FLASH_ISR_CKERR_Pos)
#define    FLASH_ISR_CKERR                                        FLASH_ISR_CKERR_Msk

#define    FLASH_ISR_PRD_Pos                                      (1U)
#define    FLASH_ISR_PRD_Msk                                      (0x1U << FLASH_ISR_PRD_Pos)
#define    FLASH_ISR_PRD                                          FLASH_ISR_PRD_Msk

#define    FLASH_ISR_ERD_Pos                                      (0U)
#define    FLASH_ISR_ERD_Msk                                      (0x1U << FLASH_ISR_ERD_Pos)
#define    FLASH_ISR_ERD                                          FLASH_ISR_ERD_Msk

#define    FLASH_ERRIER_IE_Pos                                    (2U)
#define    FLASH_ERRIER_IE_Msk                                    (0x1U << FLASH_ERRIER_IE_Pos)
#define    FLASH_ERRIER_IE                                        FLASH_ERRIER_IE_Msk


#define    FLASH_ECCSR_PERDD_Pos                                  (31U)
#define    FLASH_ECCSR_PERDD_Msk                                  (0x1U << FLASH_ECCSR_PERDD_Pos)
#define    FLASH_ECCSR_PERDD                                      FLASH_ECCSR_PERDD_Msk

#define    FLASH_ECCSR_DC_Pos                                     (29U)
#define    FLASH_ECCSR_DC_Msk                                     (0x1U << FLASH_ECCSR_DC_Pos)
#define    FLASH_ECCSR_DC                                         FLASH_ECCSR_DC_Msk

#define    FLASH_ECCSR_CC_Pos                                     (28U)
#define    FLASH_ECCSR_CC_Msk                                     (0x1U << FLASH_ECCSR_CC_Pos)
#define    FLASH_ECCSR_CC                                         FLASH_ECCSR_CC_Msk

#define    FLASH_ECCSR_BE_Pos                                     (27U)
#define    FLASH_ECCSR_BE_Msk                                     (0x1U << FLASH_ECCSR_BE_Pos)
#define    FLASH_ECCSR_BE                                         FLASH_ECCSR_BE_Msk

#define    FLASH_ECCSR_CIE_Pos                                    (24U)
#define    FLASH_ECCSR_CIE_Msk                                    (0x1U << FLASH_ECCSR_CIE_Pos)
#define    FLASH_ECCSR_CIE                                        FLASH_ECCSR_CIE_Msk

#define    FLASH_ECCSR_FLS_SEL_Pos                                (15U)
#define    FLASH_ECCSR_FLS_SEL_Msk                                (0x1U << FLASH_ECCSR_FLS_SEL_Pos)
#define    FLASH_ECCSR_FLS_SEL                                     FLASH_ECCSR_FLS_SEL_Msk

#define    FLASH_ECCSR_ADDR_Pos                                   (0U)
#define    FLASH_ECCSR_ADDR_Msk                                   (0x7fffU << FLASH_ECCSR_ADDR_Pos)
#define    FLASH_ECCSR_ADDR                                       FLASH_ECCSR_ADDR_Msk

#define    FL_FLASH_ERASE_KEY                                    (0x96969696U)
#define    FL_FLASH_CHIP_ERASE_KEY                               (0x7D7D7D7DU)
#define    FL_FLASH_PAGE_ERASE_KEY                               (0xEAEAEAEAU)
#define    FL_FLASH_SECTOR_ERASE_KEY                             (0x3C3C3C3CU)
#define    FL_FLASH_ERASE_REQUEST                                (0x1234ABCDU)
#define    FL_FLASH_PROGRAM_KEY1                                 (0xA5A5A5A5U)
#define    FL_FLASH_PROGRAM_KEY2                                 (0xF1F1F1F1U)

#define    FL_FLASH_ERASE_TIMEOUT                                (0x0000FFFFU)
#define    FL_FLASH_ADDRS_ALIGN                                  (0x00000004U)

#define    FL_FLASH_MAX_PAGE_NUM                                 (0x00000100U)
#define    FL_FLASH_MAX_SECTOR_NUM                               (0x00000040U)
#define    FL_FLASH_SECTOR_SIZE_BYTE                             (0x00000800U)
#define    FL_FLASH_PAGE_SIZE_BYTE                               (0x00000200U)
#define    FL_FLASH_ADDR_MAXPROGRAM                              (0x0005FFFFU)

#define    FL_CODE_FLASH_MAX_PAGE_NUM                            (0x00000300U)
#define    FL_CODE_FLASH_MAX_SECTOR_NUM                          (0x000000C0U)
#define    FL_CODE_FLASH_SECTOR_SIZE_BYTE                        (0x00000800U)
#define    FL_CODE_FLASH_PAGE_SIZE_BYTE                          (0x00000200U)
#define    FL_CODE_FLASH_ADDR_MAXPROGRAM                         (0x0001FFFFU)

#define    FL_DATA_FLASH_MAX_PAGE_NUM                            (0x0050001DU)
#define    FL_DATA_FLASH_MIN_PAGE_NUM                            (0x00500000U)
#define    FL_DATA_FLASH_MAX_SECTOR_NUM                          (0x00140008U)
#define    FL_DATA_FLASH_MIN_SECTOR_NUM                          (0x00140000U)
#define    FL_DATA_FLASH_SECTOR_SIZE_BYTE                        (0x00000800U)
#define    FL_DATA_FLASH_PAGE_SIZE_BYTE                          (0x00000200U)
#define    FL_DATA_FLASH_ADDR_MAXPROGRAM                         (0xA0003A00U)
#define    FL_DATA_FLASH_ADDR_MINPROGRAM                         (0xA0000000U)

#define    FL_FLASH_INFORMATION1_REGIN                            (0x1U << 17U)
#define    FL_FLASH_INFORMATION2_REGIN                            (0x1U << 18U)
#define    FL_FLASH_BLOCK_0                                       (0x1U << 0U)
#define    FL_FLASH_BLOCK_1                                       (0x1U << 1U)
#define    FL_FLASH_BLOCK_2                                       (0x1U << 2U)
#define    FL_FLASH_BLOCK_3                                       (0x1U << 3U)
#define    FL_FLASH_BLOCK_4                                       (0x1U << 4U)
#define    FL_FLASH_BLOCK_5                                       (0x1U << 5U)
#define    FL_FLASH_BLOCK_6                                       (0x1U << 6U)
#define    FL_FLASH_BLOCK_7                                       (0x1U << 7U)
#define    FL_FLASH_BLOCK_8                                       (0x1U << 8U)
#define    FL_FLASH_BLOCK_9                                       (0x1U << 9U)
#define    FL_FLASH_BLOCK_10                                      (0x1U << 10U)
#define    FL_FLASH_BLOCK_11                                      (0x1U << 11U)
#define    FL_FLASH_BLOCK_12                                      (0x1U << 12U)
#define    FL_FLASH_BLOCK_13                                      (0x1U << 13U)
#define    FL_FLASH_BLOCK_14                                      (0x1U << 14U)
#define    FL_FLASH_BLOCK_15                                      (0x1U << 15U)
#define    FL_FLASH_LOCK_ALL                                      (0x0U << 0U)
#define    FL_FLASH_LOCK_SOFTWARE                                 (0x2U << 0U)
#define    FL_FLASH_LOCK_NONE                                     (0x3U << 0U)
#define    FL_FLASH_APPCODE_LOCK_ENABLE                           (0x2U << 2U)
#define    FL_FLASH_APPCODE_LOCK_DISABLE                          (0x0U << 2U)
#define    FL_FLASH_DEBUG_READ_ENABLE                             (0x2U << 0U)
#define    FL_FLASH_DEBUG_READ_DISABLE                            (0x0U << 0U)

#define    FL_FLASH_READ_CODEWAIT_0CYCLE                          (0x0U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_1CYCLE                          (0x1U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_2CYCLE                          (0x2U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_3CYCLE                          (0x3U << FLASH_RDCR_CODE_WAIT_Pos)

#define    FL_FLASH_IWDT_STOP_UNDER_SLEEP                         (0x0U << FLASH_OPTBR_IWDTSLP_Pos)
#define    FL_FLASH_IWDT_WORK_UNDER_SLEEP                         (0x1U << FLASH_OPTBR_IWDTSLP_Pos)

#define    FL_FLASH_IWDT_STOP_AFTERPOWERON                        (0x0U << FLASH_OPTBR_IWDTEN_Pos)
#define    FL_FLASH_IWDT_WORK_AFTERPOWERON                        (0x1U << FLASH_OPTBR_IWDTEN_Pos)

#define    FL_FLASH_FLASH_LOCK_DISABLE                            (0x0U << FLASH_OPTBR_ACLOCKEN_Pos)
#define    FL_FLASH_FLASH_LOCK_ENABLE                             (0x2U << FLASH_OPTBR_ACLOCKEN_Pos)

#define    FL_FLASH_SWD_READ_PEOTECTION_DISABLE                   (0x0U << FLASH_OPTBR_DBRDPEN_Pos)
#define    FL_FLASH_SWD_READ_PEOTECTION_ENABLE                    (0x2U << FLASH_OPTBR_DBRDPEN_Pos)

#define    FL_FLASH_ERASE_TYPE_PAGE                               (0x0U << FLASH_EPCR_ERTYPE_Pos)
#define    FL_FLASH_ERASE_TYPE_SECTOR                             (0x1U << FLASH_EPCR_ERTYPE_Pos)

#define    FL_FLASH_KEY_STATUS_LOCK                               (0x0U << FLASH_ISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_ALL_ERASE                          (0x1U << FLASH_ISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_PAGE_ERASE                         (0x2U << FLASH_ISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_PROGRAM                            (0x3U << FLASH_ISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_ERROR                              (0x4U << FLASH_ISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_SECTOR_ERASE                       (0x5U << FLASH_ISR_KEYSTA_Pos)
/* FLASH end --------------------------------------------*/

/* GPIO start --------------------------------------------*/
#define    GPIO_PUDEN_PUD_Pos                                     (16U)
#define    GPIO_PUDEN_PUD_Msk                                     (0x1U << GPIO_PUDEN_PUD_Pos)
#define    GPIO_PUDEN_PUD                                         GPIO_PUDEN_PUD_Msk

#define    GPIO_PUDEN_PUDEN_Pos                                   (0U)
#define    GPIO_PUDEN_PUDEN_Msk                                   (0x1U << GPIO_PUDEN_PUDEN_Pos)
#define    GPIO_PUDEN_PUDEN                                       GPIO_PUDEN_PUDEN_Msk

#define    GPIO_FCR_Pos                                           (0U)
#define    GPIO_FCR_Msk                                           (0x3U << GPIO_FCR_Pos)
#define    GPIO_FCR                                               GPIO_FCR_Msk

#define    GPIO_DFS_Pos                                           (0U)
#define    GPIO_DFS_Msk                                           (0x3U << GPIO_DFS_Pos)
#define    GPIO_DFS                                               GPIO_DFS_Msk

#define    GPIO_SRDR_DR_Pos                                       (0U)
#define    GPIO_SRDR_DR_Msk                                       (0x1U << GPIO_SRDR_DR_Pos)
#define    GPIO_SRDR_DR                                            GPIO_SRDR_DR_Msk

#define    GPIO_SRDR_SR_Pos                                       (16U)
#define    GPIO_SRDR_SR_Msk                                       (0x1U << GPIO_SRDR_SR_Pos)
#define    GPIO_SRDR_SR                                            GPIO_SRDR_SR_Msk

#define    GPIO_TMUXR_PC7TMUX_Pos                                 (14U)
#define    GPIO_TMUXR_PC7TMUX_Msk                                 (0x3U << GPIO_TMUXR_PC7TMUX_Pos)
#define    GPIO_TMUXR_PC7TMUX                                     GPIO_TMUXR_PC7TMUX_Msk

#define    GPIO_TMUXR_PC6TMUX_Pos                                 (12U)
#define    GPIO_TMUXR_PC6TMUX_Msk                                 (0x3U << GPIO_TMUXR_PC6TMUX_Pos)
#define    GPIO_TMUXR_PC6TMUX                                     GPIO_TMUXR_PC6TMUX_Msk

#define    GPIO_TMUXR_PC5TMUX_Pos                                 (10U)
#define    GPIO_TMUXR_PC5TMUX_Msk                                 (0x3U << GPIO_TMUXR_PC5TMUX_Pos)
#define    GPIO_TMUXR_PC5TMUX                                     GPIO_TMUXR_PC5TMUX_Msk

#define    GPIO_TMUXR_PC4TMUX_Pos                                 (8U)
#define    GPIO_TMUXR_PC4TMUX_Msk                                 (0x3U << GPIO_TMUXR_PC4TMUX_Pos)
#define    GPIO_TMUXR_PC4TMUX                                     GPIO_TMUXR_PC4TMUX_Msk

#define    GPIO_TMUXR_PC3TMUX_Pos                                 (6U)
#define    GPIO_TMUXR_PC3TMUX_Msk                                 (0x3U << GPIO_TMUXR_PC3TMUX_Pos)
#define    GPIO_TMUXR_PC3TMUX                                     GPIO_TMUXR_PC3TMUX_Msk

#define    GPIO_TMUXR_PC2TMUX_Pos                                 (4U)
#define    GPIO_TMUXR_PC2TMUX_Msk                                 (0x3U << GPIO_TMUXR_PC2TMUX_Pos)
#define    GPIO_TMUXR_PC2TMUX                                     GPIO_TMUXR_PC2TMUX_Msk

#define    GPIO_TMUXR_PC1TMUX_Pos                                 (2U)
#define    GPIO_TMUXR_PC1TMUX_Msk                                 (0x3U << GPIO_TMUXR_PC1TMUX_Pos)
#define    GPIO_TMUXR_PC1TMUX                                     GPIO_TMUXR_PC1TMUX_Msk

#define    GPIO_EXTIEDS0_Pos                                      (0U)
#define    GPIO_EXTIEDS0_Msk                                      (0x3U << GPIO_EXTIEDS0_Pos)
#define    GPIO_EXTIEDS0                                          GPIO_EXTIEDS0_Msk

#define    GPIO_EXTIEDS1_Pos                                      (0U)
#define    GPIO_EXTIEDS1_Msk                                      (0x3U << GPIO_EXTIEDS1_Pos)
#define    GPIO_EXTIEDS1                                          GPIO_EXTIEDS1_Msk

#define    GPIO_FOUTSEL_FOUT0_Pos                                 (0U)
#define    GPIO_FOUTSEL_FOUT0_Msk                                 (0xfU << GPIO_FOUTSEL_FOUT0_Pos)
#define    GPIO_FOUTSEL_FOUT0                                     GPIO_FOUTSEL_FOUT0_Msk

#define    GPIO_FOUTSEL_FOUT1_Pos                                 (4U)
#define    GPIO_FOUTSEL_FOUT1_Msk                                 (0xfU << GPIO_FOUTSEL_FOUT1_Pos)
#define    GPIO_FOUTSEL_FOUT1                                     GPIO_FOUTSEL_FOUT1_Msk

#define    GPIO_EXTISEL0_EXTI0_Pos                                (0U)
#define    GPIO_EXTISEL0_EXTI0_Msk                                (0x3U << GPIO_EXTISEL0_EXTI0_Pos)
#define    GPIO_EXTISEL0_EXTI0                                    GPIO_EXTISEL0_EXTI0_Msk

#define    GPIO_EXTISEL0_EXTI1_Pos                                (2U)
#define    GPIO_EXTISEL0_EXTI1_Msk                                (0x3U << GPIO_EXTISEL0_EXTI1_Pos)
#define    GPIO_EXTISEL0_EXTI1                                    GPIO_EXTISEL0_EXTI1_Msk

#define    GPIO_EXTISEL0_EXTI2_Pos                                (4U)
#define    GPIO_EXTISEL0_EXTI2_Msk                                (0x3U << GPIO_EXTISEL0_EXTI2_Pos)
#define    GPIO_EXTISEL0_EXTI2                                    GPIO_EXTISEL0_EXTI2_Msk

#define    GPIO_EXTISEL0_EXTI3_Pos                                (6U)
#define    GPIO_EXTISEL0_EXTI3_Msk                                (0x3U << GPIO_EXTISEL0_EXTI3_Pos)
#define    GPIO_EXTISEL0_EXTI3                                    GPIO_EXTISEL0_EXTI3_Msk

#define    GPIO_EXTISEL0_EXTI4_Pos                                (8U)
#define    GPIO_EXTISEL0_EXTI4_Msk                                (0x3U << GPIO_EXTISEL0_EXTI4_Pos)
#define    GPIO_EXTISEL0_EXTI4                                    GPIO_EXTISEL0_EXTI4_Msk

#define    GPIO_EXTISEL0_EXTI5_Pos                                (10U)
#define    GPIO_EXTISEL0_EXTI5_Msk                                (0x3U << GPIO_EXTISEL0_EXTI5_Pos)
#define    GPIO_EXTISEL0_EXTI5                                    GPIO_EXTISEL0_EXTI5_Msk

#define    GPIO_EXTISEL0_EXTI6_Pos                                (12U)
#define    GPIO_EXTISEL0_EXTI6_Msk                                (0x3U << GPIO_EXTISEL0_EXTI6_Pos)
#define    GPIO_EXTISEL0_EXTI6                                    GPIO_EXTISEL0_EXTI6_Msk

#define    GPIO_EXTISEL0_EXTI7_Pos                                (14U)
#define    GPIO_EXTISEL0_EXTI7_Msk                                (0x3U << GPIO_EXTISEL0_EXTI7_Pos)
#define    GPIO_EXTISEL0_EXTI7                                    GPIO_EXTISEL0_EXTI7_Msk

#define    GPIO_EXTISEL0_EXTI8_Pos                                (16U)
#define    GPIO_EXTISEL0_EXTI8_Msk                                (0x3U << GPIO_EXTISEL0_EXTI8_Pos)
#define    GPIO_EXTISEL0_EXTI8                                    GPIO_EXTISEL0_EXTI8_Msk

#define    GPIO_EXTISEL0_EXTI9_Pos                                (18U)
#define    GPIO_EXTISEL0_EXTI9_Msk                                (0x3U << GPIO_EXTISEL0_EXTI9_Pos)
#define    GPIO_EXTISEL0_EXTI9                                    GPIO_EXTISEL0_EXTI9_Msk

#define    GPIO_EXTISEL0_EXTI10_Pos                               (20U)
#define    GPIO_EXTISEL0_EXTI10_Msk                               (0x3U << GPIO_EXTISEL0_EXTI10_Pos)
#define    GPIO_EXTISEL0_EXTI10                                   GPIO_EXTISEL0_EXTI10_Msk

#define    GPIO_EXTISEL0_EXTI11_Pos                               (22U)
#define    GPIO_EXTISEL0_EXTI11_Msk                               (0x3U << GPIO_EXTISEL0_EXTI11_Pos)
#define    GPIO_EXTISEL0_EXTI11                                   GPIO_EXTISEL0_EXTI11_Msk

#define    GPIO_EXTISEL0_EXTI12_Pos                               (24U)
#define    GPIO_EXTISEL0_EXTI12_Msk                               (0x3U << GPIO_EXTISEL0_EXTI12_Pos)
#define    GPIO_EXTISEL0_EXTI12                                   GPIO_EXTISEL0_EXTI12_Msk

#define    GPIO_EXTISEL0_EXTI13_Pos                               (26U)
#define    GPIO_EXTISEL0_EXTI13_Msk                               (0x3U << GPIO_EXTISEL0_EXTI13_Pos)
#define    GPIO_EXTISEL0_EXTI13                                   GPIO_EXTISEL0_EXTI13_Msk

#define    GPIO_EXTISEL0_EXTI14_Pos                               (28U)
#define    GPIO_EXTISEL0_EXTI14_Msk                               (0x3U << GPIO_EXTISEL0_EXTI14_Pos)
#define    GPIO_EXTISEL0_EXTI14                                   GPIO_EXTISEL0_EXTI14_Msk

#define    GPIO_EXTISEL0_EXTI15_Pos                               (30U)
#define    GPIO_EXTISEL0_EXTI15_Msk                               (0x3U << GPIO_EXTISEL0_EXTI15_Pos)
#define    GPIO_EXTISEL0_EXTI15                                   GPIO_EXTISEL0_EXTI15_Msk

#define    GPIO_EXTISEL1_EXTI16_Pos                               (0U)
#define    GPIO_EXTISEL1_EXTI16_Msk                               (0x3U << GPIO_EXTISEL1_EXTI16_Pos)
#define    GPIO_EXTISEL1_EXTI16                                   GPIO_EXTISEL1_EXTI16_Msk

#define    GPIO_EXTISEL1_EXTI17_Pos                               (2U)
#define    GPIO_EXTISEL1_EXTI17_Msk                               (0x3U << GPIO_EXTISEL1_EXTI17_Pos)
#define    GPIO_EXTISEL1_EXTI17                                   GPIO_EXTISEL1_EXTI17_Msk

#define    GPIO_EXTISEL1_EXTI18_Pos                               (4U)
#define    GPIO_EXTISEL1_EXTI18_Msk                               (0x3U << GPIO_EXTISEL1_EXTI18_Pos)
#define    GPIO_EXTISEL1_EXTI18                                   GPIO_EXTISEL1_EXTI18_Msk

#define    GPIO_PINWKEN_EN_Pos                                    (0U)
#define    GPIO_PINWKEN_EN_Msk                                    (0x3fU << GPIO_PINWKEN_EN_Pos)
#define    GPIO_PINWKEN_EN                                        GPIO_PINWKEN_EN_Msk

#define    GPIO_PINWKEN_WKSEL_Pos                                 (31U)
#define    GPIO_PINWKEN_WKSEL_Msk                                 (0x1U << GPIO_PINWKEN_WKSEL_Pos)
#define    GPIO_PINWKEN_WKSEL                                     GPIO_PINWKEN_WKSEL_Msk

#define    GPIO_PINWKEN_SEL_Pos                                   (10U)
#define    GPIO_PINWKEN_SEL_Msk                                   (0x3U << GPIO_PINWKEN_SEL_Pos)
#define    GPIO_PINWKEN_SEL                                       GPIO_PINWKEN_SEL_Msk



#define    FL_GPIO_PIN_0                                          (0x1U << 0U)
#define    FL_GPIO_PIN_1                                          (0x1U << 1U)
#define    FL_GPIO_PIN_2                                          (0x1U << 2U)
#define    FL_GPIO_PIN_3                                          (0x1U << 3U)
#define    FL_GPIO_PIN_4                                          (0x1U << 4U)
#define    FL_GPIO_PIN_5                                          (0x1U << 5U)
#define    FL_GPIO_PIN_6                                          (0x1U << 6U)
#define    FL_GPIO_PIN_7                                          (0x1U << 7U)
#define    FL_GPIO_PIN_8                                          (0x1U << 8U)
#define    FL_GPIO_PIN_9                                          (0x1U << 9U)
#define    FL_GPIO_PIN_10                                         (0x1U << 10U)
#define    FL_GPIO_PIN_11                                         (0x1U << 11U)
#define    FL_GPIO_PIN_12                                         (0x1U << 12U)
#define    FL_GPIO_PIN_13                                         (0x1U << 13U)
#define    FL_GPIO_PIN_14                                         (0x1U << 14U)
#define    FL_GPIO_PIN_15                                         (0x1U << 15U)
#define    FL_GPIO_PIN_ALL                                        (0xffffU << 0U)
#define    FL_GPIO_PIN_ALL_EXCEPTSWD                              0xFFE7U

#define    FL_GPIO_EXTI_LINE_0                                    (0x1U << 0U)
#define    FL_GPIO_EXTI_LINE_1                                    (0x1U << 1U)
#define    FL_GPIO_EXTI_LINE_2                                    (0x1U << 2U)
#define    FL_GPIO_EXTI_LINE_3                                    (0x1U << 3U)
#define    FL_GPIO_EXTI_LINE_4                                    (0x1U << 4U)
#define    FL_GPIO_EXTI_LINE_5                                    (0x1U << 5U)
#define    FL_GPIO_EXTI_LINE_6                                    (0x1U << 6U)
#define    FL_GPIO_EXTI_LINE_7                                    (0x1U << 7U)
#define    FL_GPIO_EXTI_LINE_8                                    (0x1U << 8U)
#define    FL_GPIO_EXTI_LINE_9                                    (0x1U << 9U)
#define    FL_GPIO_EXTI_LINE_10                                   (0x1U << 10U)
#define    FL_GPIO_EXTI_LINE_11                                   (0x1U << 11U)
#define    FL_GPIO_EXTI_LINE_12                                   (0x1U << 12U)
#define    FL_GPIO_EXTI_LINE_13                                   (0x1U << 13U)
#define    FL_GPIO_EXTI_LINE_14                                   (0x1U << 14U)
#define    FL_GPIO_EXTI_LINE_15                                   (0x1U << 15U)
#define    FL_GPIO_EXTI_LINE_16                                   (0x1U << 16U)
#define    FL_GPIO_EXTI_LINE_17                                   (0x1U << 17U)
#define    FL_GPIO_EXTI_LINE_18                                   (0x1U << 18U)
#define    FL_GPIO_EXTI_LINE_ALL                                  (0x3fffffU << 0U)

#define    FL_GPIO_EXTI_LINE_0_PA0                                (0x0U << 0U)
#define    FL_GPIO_EXTI_LINE_0_PA1                                (0x1U << 0U)
#define    FL_GPIO_EXTI_LINE_0_PA2                                (0x2U << 0U)
#define    FL_GPIO_EXTI_LINE_0_PA3                                (0x3U << 0U)
#define    FL_GPIO_EXTI_LINE_1_PA4                                (0x0U << 2U)
#define    FL_GPIO_EXTI_LINE_1_PA5                                (0x1U << 2U)
#define    FL_GPIO_EXTI_LINE_1_PA6                                (0x2U << 2U)
#define    FL_GPIO_EXTI_LINE_1_PA7                                (0x3U << 2U)
#define    FL_GPIO_EXTI_LINE_2_PA8                                (0x0U << 4U)
#define    FL_GPIO_EXTI_LINE_2_PA9                                (0x1U << 4U)
#define    FL_GPIO_EXTI_LINE_2_PA10                               (0x2U << 4U)
#define    FL_GPIO_EXTI_LINE_2_PA11                               (0x3U << 4U)
#define    FL_GPIO_EXTI_LINE_3_PA12                               (0x0U << 6U)
#define    FL_GPIO_EXTI_LINE_3_PA13                               (0x1U << 6U)
#define    FL_GPIO_EXTI_LINE_3_PA14                               (0x2U << 6U)
#define    FL_GPIO_EXTI_LINE_3_PA15                               (0x3U << 6U)
#define    FL_GPIO_EXTI_LINE_4_PB0                                (0x0U << 8U)
#define    FL_GPIO_EXTI_LINE_4_PB1                                (0x1U << 8U)
#define    FL_GPIO_EXTI_LINE_4_PB2                                (0x2U << 8U)
#define    FL_GPIO_EXTI_LINE_4_PB3                                (0x3U << 8U)
#define    FL_GPIO_EXTI_LINE_5_PB4                                (0x0U << 10U)
#define    FL_GPIO_EXTI_LINE_5_PB5                                (0x1U << 10U)
#define    FL_GPIO_EXTI_LINE_5_PB6                                (0x2U << 10U)
#define    FL_GPIO_EXTI_LINE_5_PB7                                (0x3U << 10U)
#define    FL_GPIO_EXTI_LINE_6_PB8                                (0x0U << 12U)
#define    FL_GPIO_EXTI_LINE_6_PB9                                (0x1U << 12U)
#define    FL_GPIO_EXTI_LINE_6_PB10                               (0x2U << 12U)
#define    FL_GPIO_EXTI_LINE_6_PB11                               (0x3U << 12U)
#define    FL_GPIO_EXTI_LINE_7_PB12                               (0x0U << 14U)
#define    FL_GPIO_EXTI_LINE_7_PB13                               (0x1U << 14U)
#define    FL_GPIO_EXTI_LINE_7_PB14                               (0x2U << 14U)
#define    FL_GPIO_EXTI_LINE_7_PB15                               (0x3U << 14U)
#define    FL_GPIO_EXTI_LINE_8_PC0                                (0x0U << 16U)
#define    FL_GPIO_EXTI_LINE_8_PC1                                (0x1U << 16U)
#define    FL_GPIO_EXTI_LINE_8_PC2                                (0x2U << 16U)
#define    FL_GPIO_EXTI_LINE_8_PC3                                (0x3U << 16U)
#define    FL_GPIO_EXTI_LINE_9_PC4                                (0x0U << 18U)
#define    FL_GPIO_EXTI_LINE_9_PC5                                (0x1U << 18U)
#define    FL_GPIO_EXTI_LINE_9_PC6                                (0x2U << 18U)
#define    FL_GPIO_EXTI_LINE_9_PC7                                (0x3U << 18U)
#define    FL_GPIO_EXTI_LINE_10_PC8                               (0x0U << 20U)
#define    FL_GPIO_EXTI_LINE_10_PC9                               (0x1U << 20U)
#define    FL_GPIO_EXTI_LINE_10_PC10                              (0x2U << 20U)
#define    FL_GPIO_EXTI_LINE_10_PC11                              (0x3U << 20U)
#define    FL_GPIO_EXTI_LINE_11_PC12                              (0x0U << 22U)
#define    FL_GPIO_EXTI_LINE_12_PD0                               (0x0U << 24U)
#define    FL_GPIO_EXTI_LINE_12_PD1                               (0x1U << 24U)
#define    FL_GPIO_EXTI_LINE_12_PD2                               (0x2U << 24U)
#define    FL_GPIO_EXTI_LINE_12_PD3                               (0x3U << 24U)
#define    FL_GPIO_EXTI_LINE_13_PD4                               (0x0U << 26U)
#define    FL_GPIO_EXTI_LINE_13_PD5                               (0x1U << 26U)
#define    FL_GPIO_EXTI_LINE_13_PD6                               (0x2U << 26U)
#define    FL_GPIO_EXTI_LINE_13_PD7                               (0x3U << 26U)
#define    FL_GPIO_EXTI_LINE_14_PD8                               (0x0U << 28U)
#define    FL_GPIO_EXTI_LINE_14_PD9                               (0x1U << 28U)
#define    FL_GPIO_EXTI_LINE_14_PD10                              (0x2U << 28U)
#define    FL_GPIO_EXTI_LINE_14_PD11                              (0x3U << 28U)
#define    FL_GPIO_EXTI_LINE_15_PD12                              (0x0U << 30U)
#define    FL_GPIO_EXTI_LINE_16_PE0                               (0x0U << 0U)
#define    FL_GPIO_EXTI_LINE_16_PE1                               (0x1U << 0U)
#define    FL_GPIO_EXTI_LINE_16_PE2                               (0x2U << 0U)
#define    FL_GPIO_EXTI_LINE_16_PE3                               (0x3U << 0U)
#define    FL_GPIO_EXTI_LINE_17_PE4                               (0x0U << 2U)
#define    FL_GPIO_EXTI_LINE_17_PE5                               (0x1U << 2U)
#define    FL_GPIO_EXTI_LINE_17_PE6                               (0x2U << 2U)
#define    FL_GPIO_EXTI_LINE_17_PE7                               (0x3U << 2U)
#define    FL_GPIO_EXTI_LINE_18_PE8                               (0x0U << 4U)
#define    FL_GPIO_EXTI_LINE_18_PE9                               (0x1U << 4U)
#define    FL_GPIO_EXTI_LINE_18_PE10                              (0x2U << 4U)
#define    FL_GPIO_EXTI_LINE_18_PE11                              (0x3U << 4U)
#define    FL_GPIO_WAKEUP_0                                       (0x1U << 0U)
#define    FL_GPIO_WAKEUP_1                                       (0x1U << 1U)
#define    FL_GPIO_WAKEUP_2                                       (0x1U << 2U)
#define    FL_GPIO_WAKEUP_3                                       (0x1U << 3U)
#define    FL_GPIO_WAKEUP_4                                       (0x1U << 4U)
#define    FL_GPIO_WAKEUP_5                                       (0x1U << 5U)

#define    FL_GPIO_OUTPUT_PUSHPULL                                0x0U
#define    FL_GPIO_OUTPUT_OPENDRAIN                               0x1U

#define    FL_GPIO_PULLUP_ENABLE                                  (0x0U << GPIO_PUDEN_PUD_Pos)
#define    FL_GPIO_PULLDOWN_ENABLE                                (0x1U << GPIO_PUDEN_PUD_Pos)
#define    FL_GPIO_BOTH_DISABLE                                   0x2U

#define    FL_GPIO_MODE_INPUT                                     (0x0U << GPIO_FCR_Pos)
#define    FL_GPIO_MODE_OUTPUT                                    (0x1U << GPIO_FCR_Pos)
#define    FL_GPIO_MODE_DIGITAL                                   (0x2U << GPIO_FCR_Pos)
#define    FL_GPIO_MODE_ANALOG                                    (0x3U << GPIO_FCR_Pos)


#define    FL_GPIO_PINREMAP_FUNCTON1                              (0x0U << GPIO_DFS_Pos)
#define    FL_GPIO_PINREMAP_FUNCTON2                              (0x1U << GPIO_DFS_Pos)
#define    FL_GPIO_PINREMAP_FUNCTON3                              (0x2U << GPIO_DFS_Pos)
#define    FL_GPIO_PINREMAP_FUNCTON4                              (0x3U << GPIO_DFS_Pos)


#define    FL_GPIO_DRIVESTRENGTH_HIGH                             (0x0U << GPIO_SRDR_DR_Pos)
#define    FL_GPIO_DRIVESTRENGTH_LOW                              (0x1U << GPIO_SRDR_DR_Pos)

#define    FL_GPIO_SLEWRATE_HIGH                                  (0x0U << GPIO_SRDR_SR_Pos)
#define    FL_GPIO_SLEWRATE_LOW                                   (0x1U << GPIO_SRDR_SR_Pos)


#define    FL_GPIO_CHSEL_ATIM_CH4N                                (0x0U << GPIO_TMUXR_PC8TMUX_Pos)
#define    FL_GPIO_CHSEL_TI07                                     (0x1U << GPIO_TMUXR_PC8TMUX_Pos)
#define    FL_GPIO_CHSEL_TO07                                     (0x2U << GPIO_TMUXR_PC8TMUX_Pos)


#define    FL_GPIO_CHSEL_ATIM_CH3N                                (0x0U << GPIO_TMUXR_PC7TMUX_Pos)
#define    FL_GPIO_CHSEL_TI06                                     (0x1U << GPIO_TMUXR_PC7TMUX_Pos)
#define    FL_GPIO_CHSEL_TO06                                     (0x2U << GPIO_TMUXR_PC7TMUX_Pos)


#define    FL_GPIO_CHSEL_ATIM_CH2N                                (0x0U << GPIO_TMUXR_PC6TMUX_Pos)
#define    FL_GPIO_CHSEL_TI05                                     (0x1U << GPIO_TMUXR_PC6TMUX_Pos)
#define    FL_GPIO_CHSEL_TO05                                     (0x2U << GPIO_TMUXR_PC6TMUX_Pos)


#define    FL_GPIO_CHSEL_ATIM_CH1N                                (0x0U << GPIO_TMUXR_PC5TMUX_Pos)
#define    FL_GPIO_CHSEL_TI04                                     (0x1U << GPIO_TMUXR_PC5TMUX_Pos)
#define    FL_GPIO_CHSEL_TO04                                     (0x2U << GPIO_TMUXR_PC5TMUX_Pos)


#define    FL_GPIO_CHSEL_ATIM_CH4                                 (0x0U << GPIO_TMUXR_PC4TMUX_Pos)
#define    FL_GPIO_CHSEL_TI03                                     (0x1U << GPIO_TMUXR_PC4TMUX_Pos)
#define    FL_GPIO_CHSEL_TO03                                     (0x2U << GPIO_TMUXR_PC4TMUX_Pos)


#define    FL_GPIO_CHSEL_ATIM_CH3                                 (0x0U << GPIO_TMUXR_PC3TMUX_Pos)
#define    FL_GPIO_CHSEL_TI02                                     (0x1U << GPIO_TMUXR_PC3TMUX_Pos)
#define    FL_GPIO_CHSEL_TO02                                     (0x2U << GPIO_TMUXR_PC3TMUX_Pos)


#define    FL_GPIO_CHSEL_ATIM_CH2                                 (0x0U << GPIO_TMUXR_PC2TMUX_Pos)
#define    FL_GPIO_CHSEL_TI01                                     (0x1U << GPIO_TMUXR_PC2TMUX_Pos)
#define    FL_GPIO_CHSEL_TO01                                     (0x2U << GPIO_TMUXR_PC2TMUX_Pos)


#define    FL_GPIO_CHSEL_ATIM_CH1                                 (0x0U << GPIO_TMUXR_PC1TMUX_Pos)
#define    FL_GPIO_CHSEL_TI00                                     (0x1U << GPIO_TMUXR_PC1TMUX_Pos)
#define    FL_GPIO_CHSEL_TO00                                     (0x2U << GPIO_TMUXR_PC1TMUX_Pos)


#define    FL_GPIO_EXTI_TRIGGER_EDGE_RISING                       (0x0U << GPIO_EXTIEDS0_Pos)
#define    FL_GPIO_EXTI_TRIGGER_EDGE_FALLING                      (0x1U << GPIO_EXTIEDS0_Pos)
#define    FL_GPIO_EXTI_TRIGGER_EDGE_BOTH                         (0x2U << GPIO_EXTIEDS0_Pos)
#define    FL_GPIO_EXTI_TRIGGER_EDGE_DISABLE                      (0x3U << GPIO_EXTIEDS0_Pos)


#define    FL_GPIO_FOUT0_SELECT_ADC_SOC                           (0x0U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_RCLP                              (0x1U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_RCHF_DIV64                        (0x2U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_ADCCLK                            (0x3U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_AHBCLK_DIV64                      (0x4U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_PLLOUTPUT_DIV64                   (0x6U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_EOC                               (0x7U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_APBCLK_DIV64                      (0x8U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_PLLOUTPUT                         (0x9U << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_RCHF                              (0xbU << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_XTHF_DIV64                        (0xcU << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_CLK_8K                            (0xeU << GPIO_FOUTSEL_FOUT0_Pos)
#define    FL_GPIO_FOUT0_SELECT_APBCLK                            (0xfU << GPIO_FOUTSEL_FOUT0_Pos)


#define    FL_GPIO_FOUT1_SELECT_ADCCLK                            (0x0U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_RCLP                              (0x1U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_APBCLK                            (0x2U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_EOC                               (0x4U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_PLLOUTPUT_DIV64                   (0x6U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_SOC                               (0x7U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_APBCLK_DIV64                      (0x8U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_PLLOUTPUT                         (0x9U << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_RCHF                              (0xbU << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_XTHF_DIV64                        (0xcU << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_ADCCLK_DIV64                      (0xdU << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_CLK_8K                            (0xeU << GPIO_FOUTSEL_FOUT1_Pos)
#define    FL_GPIO_FOUT1_SELECT_XTHF                              (0xfU << GPIO_FOUTSEL_FOUT1_Pos)


#define    FL_GPIO_WAKEUP_INT_ENTRY_NMI                           (0x0U << GPIO_PINWKEN_WKSEL_Pos)
#define    FL_GPIO_WAKEUP_INT_ENTRY_39                            (0x1U << GPIO_PINWKEN_WKSEL_Pos)


#define    FL_GPIO_WAKEUP_TRIGGER_FALLING                         (0x0U << GPIO_PINWKEN_SEL_Pos)
#define    FL_GPIO_WAKEUP_TRIGGER_RISING                          (0x1U << GPIO_PINWKEN_SEL_Pos)
#define    FL_GPIO_WAKEUP_TRIGGER_BOTH                            (0x2U << GPIO_PINWKEN_SEL_Pos)
/* GPIO end --------------------------------------------*/

/* INTMUX start --------------------------------------------*/
#define    INTMUX_CR_MUX13SEL_Pos                                 (26U)
#define    INTMUX_CR_MUX13SEL_Msk                                 (0x3U << INTMUX_CR_MUX13SEL_Pos)
#define    INTMUX_CR_MUX13SEL                                     INTMUX_CR_MUX13SEL_Msk

#define    INTMUX_CR_MUX12SEL_Pos                                 (24U)
#define    INTMUX_CR_MUX12SEL_Msk                                 (0x3U << INTMUX_CR_MUX12SEL_Pos)
#define    INTMUX_CR_MUX12SEL                                     INTMUX_CR_MUX12SEL_Msk

#define    INTMUX_CR_MUX11SEL_Pos                                 (22U)
#define    INTMUX_CR_MUX11SEL_Msk                                 (0x3U << INTMUX_CR_MUX11SEL_Pos)
#define    INTMUX_CR_MUX11SEL                                     INTMUX_CR_MUX11SEL_Msk

#define    INTMUX_CR_MUX10SEL_Pos                                 (20U)
#define    INTMUX_CR_MUX10SEL_Msk                                 (0x3U << INTMUX_CR_MUX10SEL_Pos)
#define    INTMUX_CR_MUX10SEL                                     INTMUX_CR_MUX10SEL_Msk

#define    INTMUX_CR_MUX9SEL_Pos                                  (18U)
#define    INTMUX_CR_MUX9SEL_Msk                                  (0x3U << INTMUX_CR_MUX9SEL_Pos)
#define    INTMUX_CR_MUX9SEL                                      INTMUX_CR_MUX9SEL_Msk

#define    INTMUX_CR_MUX8SEL_Pos                                  (16U)
#define    INTMUX_CR_MUX8SEL_Msk                                  (0x3U << INTMUX_CR_MUX8SEL_Pos)
#define    INTMUX_CR_MUX8SEL                                      INTMUX_CR_MUX8SEL_Msk

#define    INTMUX_CR_MUX7SEL_Pos                                  (14U)
#define    INTMUX_CR_MUX7SEL_Msk                                  (0x3U << INTMUX_CR_MUX7SEL_Pos)
#define    INTMUX_CR_MUX7SEL                                      INTMUX_CR_MUX7SEL_Msk

#define    INTMUX_CR_MUX6SEL_Pos                                  (12U)
#define    INTMUX_CR_MUX6SEL_Msk                                  (0x3U << INTMUX_CR_MUX6SEL_Pos)
#define    INTMUX_CR_MUX6SEL                                      INTMUX_CR_MUX6SEL_Msk

#define    INTMUX_CR_MUX5SEL_Pos                                  (10U)
#define    INTMUX_CR_MUX5SEL_Msk                                  (0x3U << INTMUX_CR_MUX5SEL_Pos)
#define    INTMUX_CR_MUX5SEL                                      INTMUX_CR_MUX5SEL_Msk

#define    INTMUX_CR_MUX4SEL_Pos                                  (8U)
#define    INTMUX_CR_MUX4SEL_Msk                                  (0x3U << INTMUX_CR_MUX4SEL_Pos)
#define    INTMUX_CR_MUX4SEL                                      INTMUX_CR_MUX4SEL_Msk

#define    INTMUX_CR_MUX3SEL_Pos                                  (6U)
#define    INTMUX_CR_MUX3SEL_Msk                                  (0x3U << INTMUX_CR_MUX3SEL_Pos)
#define    INTMUX_CR_MUX3SEL                                      INTMUX_CR_MUX3SEL_Msk

#define    INTMUX_CR_MUX2SEL_Pos                                  (4U)
#define    INTMUX_CR_MUX2SEL_Msk                                  (0x3U << INTMUX_CR_MUX2SEL_Pos)
#define    INTMUX_CR_MUX2SEL                                      INTMUX_CR_MUX2SEL_Msk

#define    INTMUX_CR_MUX1SEL_Pos                                  (2U)
#define    INTMUX_CR_MUX1SEL_Msk                                  (0x3U << INTMUX_CR_MUX1SEL_Pos)
#define    INTMUX_CR_MUX1SEL                                      INTMUX_CR_MUX1SEL_Msk

#define    INTMUX_CR_MUX0SEL_Pos                                  (0U)
#define    INTMUX_CR_MUX0SEL_Msk                                  (0x3U << INTMUX_CR_MUX0SEL_Pos)
#define    INTMUX_CR_MUX0SEL                                      INTMUX_CR_MUX0SEL_Msk



#define    FL_INTMUX_MUX13SEL_TAU00                               (0x0U << INTMUX_CR_MUX13SEL_Pos)
#define    FL_INTMUX_MUX13SEL_UART1                               (0x1U << INTMUX_CR_MUX13SEL_Pos)
#define    FL_INTMUX_MUX13SEL_UART2                               (0x2U << INTMUX_CR_MUX13SEL_Pos)
#define    FL_INTMUX_MUX13SEL_CAN1                                (0x3U << INTMUX_CR_MUX13SEL_Pos)


#define    FL_INTMUX_MUX12SEL_SPI3                                (0x0U << INTMUX_CR_MUX12SEL_Pos)
#define    FL_INTMUX_MUX12SEL_TAU13                               (0x1U << INTMUX_CR_MUX12SEL_Pos)
#define    FL_INTMUX_MUX12SEL_TAU05                               (0x2U << INTMUX_CR_MUX12SEL_Pos)
#define    FL_INTMUX_MUX12SEL_TAU07                               (0x3U << INTMUX_CR_MUX12SEL_Pos)


#define    FL_INTMUX_MUX11SEL_SPI2                                (0x0U << INTMUX_CR_MUX11SEL_Pos)
#define    FL_INTMUX_MUX11SEL_TAU11                               (0x1U << INTMUX_CR_MUX11SEL_Pos)
#define    FL_INTMUX_MUX11SEL_TAU04                               (0x2U << INTMUX_CR_MUX11SEL_Pos)
#define    FL_INTMUX_MUX11SEL_TAU03                               (0x3U << INTMUX_CR_MUX11SEL_Pos)


#define    FL_INTMUX_MUX10SEL_LUT                                 (0x0U << INTMUX_CR_MUX10SEL_Pos)
#define    FL_INTMUX_MUX10SEL_TAU03                               (0x1U << INTMUX_CR_MUX10SEL_Pos)
#define    FL_INTMUX_MUX10SEL_TAU04                               (0x2U << INTMUX_CR_MUX10SEL_Pos)
#define    FL_INTMUX_MUX10SEL_TAU07                               (0x3U << INTMUX_CR_MUX10SEL_Pos)


#define    FL_INTMUX_MUX9SEL_CCL                                  (0x0U << INTMUX_CR_MUX9SEL_Pos)
#define    FL_INTMUX_MUX9SEL_TAU05                                (0x1U << INTMUX_CR_MUX9SEL_Pos)
#define    FL_INTMUX_MUX9SEL_TAU06                                (0x2U << INTMUX_CR_MUX9SEL_Pos)
#define    FL_INTMUX_MUX9SEL_TAU03                                (0x3U << INTMUX_CR_MUX9SEL_Pos)


#define    FL_INTMUX_MUX8SEL_UART5                                (0x0U << INTMUX_CR_MUX8SEL_Pos)
#define    FL_INTMUX_MUX8SEL_TAU05                                (0x1U << INTMUX_CR_MUX8SEL_Pos)
#define    FL_INTMUX_MUX8SEL_TAU06                                (0x2U << INTMUX_CR_MUX8SEL_Pos)
#define    FL_INTMUX_MUX8SEL_TAU12                                (0x3U << INTMUX_CR_MUX8SEL_Pos)


#define    FL_INTMUX_MUX7SEL_UART4                                (0x0U << INTMUX_CR_MUX7SEL_Pos)
#define    FL_INTMUX_MUX7SEL_TAU12                                (0x1U << INTMUX_CR_MUX7SEL_Pos)
#define    FL_INTMUX_MUX7SEL_TAU13                                (0x2U << INTMUX_CR_MUX7SEL_Pos)
#define    FL_INTMUX_MUX7SEL_TAU04                                (0x3U << INTMUX_CR_MUX7SEL_Pos)


#define    FL_INTMUX_MUX6SEL_UART3                                (0x0U << INTMUX_CR_MUX6SEL_Pos)
#define    FL_INTMUX_MUX6SEL_TAU12                                (0x1U << INTMUX_CR_MUX6SEL_Pos)
#define    FL_INTMUX_MUX6SEL_TAU13                                (0x2U << INTMUX_CR_MUX6SEL_Pos)
#define    FL_INTMUX_MUX6SEL_TAU02                                (0x3U << INTMUX_CR_MUX6SEL_Pos)

#define    FL_INTMUX_MUX5SEL_UART2                                (0x0U << INTMUX_CR_MUX5SEL_Pos)
#define    FL_INTMUX_MUX5SEL_TAU03                                (0x1U << INTMUX_CR_MUX5SEL_Pos)
#define    FL_INTMUX_MUX5SEL_TAU04                                (0x2U << INTMUX_CR_MUX5SEL_Pos)
#define    FL_INTMUX_MUX5SEL_TAU11                                (0x3U << INTMUX_CR_MUX5SEL_Pos)


#define    FL_INTMUX_MUX4SEL_UART1                                (0x0U << INTMUX_CR_MUX4SEL_Pos)
#define    FL_INTMUX_MUX4SEL_TAU00                                (0x1U << INTMUX_CR_MUX4SEL_Pos)
#define    FL_INTMUX_MUX4SEL_TAU01                                (0x2U << INTMUX_CR_MUX4SEL_Pos)
#define    FL_INTMUX_MUX4SEL_TAU10                                (0x3U << INTMUX_CR_MUX4SEL_Pos)


#define    FL_INTMUX_MUX3SEL_UART0                                (0x0U << INTMUX_CR_MUX3SEL_Pos)
#define    FL_INTMUX_MUX3SEL_TAU10                                (0x1U << INTMUX_CR_MUX3SEL_Pos)
#define    FL_INTMUX_MUX3SEL_TAU11                                (0x2U << INTMUX_CR_MUX3SEL_Pos)
#define    FL_INTMUX_MUX3SEL_TAU01                                (0x3U << INTMUX_CR_MUX3SEL_Pos)


#define    FL_INTMUX_MUX2SEL_SPI1                                 (0x0U << INTMUX_CR_MUX2SEL_Pos)
#define    FL_INTMUX_MUX2SEL_TAU12                                (0x1U << INTMUX_CR_MUX2SEL_Pos)
#define    FL_INTMUX_MUX2SEL_TAU01                                (0x2U << INTMUX_CR_MUX2SEL_Pos)
#define    FL_INTMUX_MUX2SEL_TAU02                                (0x3U << INTMUX_CR_MUX2SEL_Pos)


#define    FL_INTMUX_MUX1SEL_SPI0                                 (0x0U << INTMUX_CR_MUX1SEL_Pos)
#define    FL_INTMUX_MUX1SEL_TAU10                                (0x1U << INTMUX_CR_MUX1SEL_Pos)
#define    FL_INTMUX_MUX1SEL_TAU11                                (0x2U << INTMUX_CR_MUX1SEL_Pos)
#define    FL_INTMUX_MUX1SEL_TAU06                                (0x3U << INTMUX_CR_MUX1SEL_Pos)


#define    FL_INTMUX_MUX0SEL_FLASH                                (0x0U << INTMUX_CR_MUX0SEL_Pos)
#define    FL_INTMUX_MUX0SEL_TAU00                                (0x1U << INTMUX_CR_MUX0SEL_Pos)
#define    FL_INTMUX_MUX0SEL_TAU01                                (0x2U << INTMUX_CR_MUX0SEL_Pos)
#define    FL_INTMUX_MUX0SEL_TAU02                                (0x3U << INTMUX_CR_MUX0SEL_Pos)
/* INTMUX end --------------------------------------------*/

/* IWDT start --------------------------------------------*/
#define    IWDT_CR_FREEZE_Pos                                     (11U)
#define    IWDT_CR_FREEZE_Msk                                     (0x1U << IWDT_CR_FREEZE_Pos)
#define    IWDT_CR_FREEZE                                         IWDT_CR_FREEZE_Msk

#define    IWDT_CR_CFG_Pos                                        (0U)
#define    IWDT_CR_CFG_Msk                                        (0x7U << IWDT_CR_CFG_Pos)
#define    IWDT_CR_CFG                                            IWDT_CR_CFG_Msk

#define    IWDT_IER_IE_Pos                                        (0U)
#define    IWDT_IER_IE_Msk                                        (0x1U << IWDT_IER_IE_Pos)
#define    IWDT_IER_IE                                            IWDT_IER_IE_Msk

#define    IWDT_ISR_WINF_Pos                                      (0U)
#define    IWDT_ISR_WINF_Msk                                      (0x1U << IWDT_ISR_WINF_Pos)
#define    IWDT_ISR_WINF                                          IWDT_ISR_WINF_Msk

#define    FL_IWDT_RELOAD_KEY                                     0x12345A5AU

#define    FL_IWDT_PERIOD_125MS                                   (0x0U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_250MS                                   (0x1U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_500MS                                   (0x2U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_1000MS                                  (0x3U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_2000MS                                  (0x4U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_4000MS                                  (0x5U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_8000MS                                  (0x6U << IWDT_CR_CFG_Pos)
#define    FL_IWDT_PERIOD_16000MS                                 (0x7U << IWDT_CR_CFG_Pos)
/* IWDT end --------------------------------------------*/

/* LPTIM start --------------------------------------------*/
#define    LPTIM16_CR_EN_Pos                                      (0U)
#define    LPTIM16_CR_EN_Msk                                      (0x1U << LPTIM16_CR_EN_Pos)
#define    LPTIM16_CR_EN                                          LPTIM16_CR_EN_Msk

#define    LPTIM16_CFGR_ETR_AFEN_Pos                              (24U)
#define    LPTIM16_CFGR_ETR_AFEN_Msk                              (0x1U << LPTIM16_CFGR_ETR_AFEN_Pos)
#define    LPTIM16_CFGR_ETR_AFEN                                  LPTIM16_CFGR_ETR_AFEN_Msk

#define    LPTIM16_CFGR_MMS_Pos                                   (16U)
#define    LPTIM16_CFGR_MMS_Msk                                   (0x7U << LPTIM16_CFGR_MMS_Pos)
#define    LPTIM16_CFGR_MMS                                       LPTIM16_CFGR_MMS_Msk

#define    LPTIM16_CFGR_PSCSEL_Pos                                (14U)
#define    LPTIM16_CFGR_PSCSEL_Msk                                (0x1U << LPTIM16_CFGR_PSCSEL_Pos)
#define    LPTIM16_CFGR_PSCSEL                                    LPTIM16_CFGR_PSCSEL_Msk

#define    LPTIM16_CFGR_DIVSEL_Pos                                (10U)
#define    LPTIM16_CFGR_DIVSEL_Msk                                (0x7U << LPTIM16_CFGR_DIVSEL_Pos)
#define    LPTIM16_CFGR_DIVSEL                                    LPTIM16_CFGR_DIVSEL_Msk

#define    LPTIM16_CFGR_EDGESEL_Pos                               (7U)
#define    LPTIM16_CFGR_EDGESEL_Msk                               (0x1U << LPTIM16_CFGR_EDGESEL_Pos)
#define    LPTIM16_CFGR_EDGESEL                                   LPTIM16_CFGR_EDGESEL_Msk

#define    LPTIM16_CFGR_TRIGCFG_Pos                               (5U)
#define    LPTIM16_CFGR_TRIGCFG_Msk                               (0x3U << LPTIM16_CFGR_TRIGCFG_Pos)
#define    LPTIM16_CFGR_TRIGCFG                                   LPTIM16_CFGR_TRIGCFG_Msk

#define    LPTIM16_CFGR_QEMD_Pos                                  (3U)
#define    LPTIM16_CFGR_QEMD_Msk                                  (0x3U << LPTIM16_CFGR_QEMD_Pos)
#define    LPTIM16_CFGR_QEMD                                      LPTIM16_CFGR_QEMD_Msk

#define    LPTIM16_CFGR_ONST_Pos                                  (2U)
#define    LPTIM16_CFGR_ONST_Msk                                  (0x1U << LPTIM16_CFGR_ONST_Pos)
#define    LPTIM16_CFGR_ONST                                      LPTIM16_CFGR_ONST_Msk

#define    LPTIM16_CFGR_TMODE_Pos                                 (0U)
#define    LPTIM16_CFGR_TMODE_Msk                                 (0x3U << LPTIM16_CFGR_TMODE_Pos)
#define    LPTIM16_CFGR_TMODE                                     LPTIM16_CFGR_TMODE_Msk

#define    LPTIM16_IER_OVRIE_Pos                                  (8U)
#define    LPTIM16_IER_OVRIE_Msk                                  (0x3U << LPTIM16_IER_OVRIE_Pos)
#define    LPTIM16_IER_OVRIE                                      LPTIM16_IER_OVRIE_Msk

#define    LPTIM16_IER_TRIGIE_Pos                                 (7U)
#define    LPTIM16_IER_TRIGIE_Msk                                 (0x1U << LPTIM16_IER_TRIGIE_Pos)
#define    LPTIM16_IER_TRIGIE                                     LPTIM16_IER_TRIGIE_Msk

#define    LPTIM16_IER_OVIE_Pos                                   (6U)
#define    LPTIM16_IER_OVIE_Msk                                   (0x1U << LPTIM16_IER_OVIE_Pos)
#define    LPTIM16_IER_OVIE                                       LPTIM16_IER_OVIE_Msk

#define    LPTIM16_IER_QDCIE_Pos                                  (5U)
#define    LPTIM16_IER_QDCIE_Msk                                  (0x1U << LPTIM16_IER_QDCIE_Pos)
#define    LPTIM16_IER_QDCIE                                      LPTIM16_IER_QDCIE_Msk

#define    LPTIM16_IER_CCIE_Pos                                   (0U)
#define    LPTIM16_IER_CCIE_Msk                                   (0x3U << LPTIM16_IER_CCIE_Pos)
#define    LPTIM16_IER_CCIE                                       LPTIM16_IER_CCIE_Msk

#define    LPTIM16_ISR_QDIR_Pos                                   (13U)
#define    LPTIM16_ISR_QDIR_Msk                                   (0x1U << LPTIM16_ISR_QDIR_Pos)
#define    LPTIM16_ISR_QDIR                                       LPTIM16_ISR_QDIR_Msk

#define    LPTIM16_ISR_OVRIF_Pos                                  (8U)
#define    LPTIM16_ISR_OVRIF_Msk                                  (0x3U << LPTIM16_ISR_OVRIF_Pos)
#define    LPTIM16_ISR_OVRIF                                      LPTIM16_ISR_OVRIF_Msk

#define    LPTIM16_ISR_TRIGIF_Pos                                 (7U)
#define    LPTIM16_ISR_TRIGIF_Msk                                 (0x1U << LPTIM16_ISR_TRIGIF_Pos)
#define    LPTIM16_ISR_TRIGIF                                     LPTIM16_ISR_TRIGIF_Msk

#define    LPTIM16_ISR_OVIF_Pos                                   (6U)
#define    LPTIM16_ISR_OVIF_Msk                                   (0x1U << LPTIM16_ISR_OVIF_Pos)
#define    LPTIM16_ISR_OVIF                                       LPTIM16_ISR_OVIF_Msk


#define    LPTIM16_ISR_QDCIF_Pos                                  (5U)
#define    LPTIM16_ISR_QDCIF_Msk                                  (0x1U << LPTIM16_ISR_QDCIF_Pos)
#define    LPTIM16_ISR_QDCIF                                      LPTIM16_ISR_QDCIF_Msk

#define    LPTIM16_ISR_CCIF_Pos                                   (0U)
#define    LPTIM16_ISR_CCIF_Msk                                   (0x3U << LPTIM16_ISR_CCIF_Pos)
#define    LPTIM16_ISR_CCIF                                       LPTIM16_ISR_CCIF_Msk

#define    LPTIM16_CCSR_CAP1PSC_Pos                               (26U)
#define    LPTIM16_CCSR_CAP1PSC_Msk                               (0x3fU << LPTIM16_CCSR_CAP1PSC_Pos)
#define    LPTIM16_CCSR_CAP1PSC                                   LPTIM16_CCSR_CAP1PSC_Msk

#define    LPTIM16_CCSR_CAP1SSEL_Pos                              (24U)
#define    LPTIM16_CCSR_CAP1SSEL_Msk                              (0x3U << LPTIM16_CCSR_CAP1SSEL_Pos)
#define    LPTIM16_CCSR_CAP1SSEL                                  LPTIM16_CCSR_CAP1SSEL_Msk

#define    LPTIM16_CCSR_CAPEDGE_Pos                               (20U)
#define    LPTIM16_CCSR_CAPEDGE_Msk                               (0x1U << LPTIM16_CCSR_CAPEDGE_Pos)
#define    LPTIM16_CCSR_CAPEDGE                                   LPTIM16_CCSR_CAPEDGE_Msk

#define    LPTIM16_CCSR_CCP_Pos                                   (16U)
#define    LPTIM16_CCSR_CCP_Msk                                   (0x1U << LPTIM16_CCSR_CCP_Pos)
#define    LPTIM16_CCSR_CCP                                       LPTIM16_CCSR_CCP_Msk

#define    LPTIM16_CCSR_CAPCFG_Pos                                (8U)
#define    LPTIM16_CCSR_CAPCFG_Msk                                (0x3U << LPTIM16_CCSR_CAPCFG_Pos)
#define    LPTIM16_CCSR_CAPCFG                                    LPTIM16_CCSR_CAPCFG_Msk

#define    LPTIM16_CCSR_CCS_Pos                                   (0U)
#define    LPTIM16_CCSR_CCS_Msk                                   (0x3U << LPTIM16_CCSR_CCS_Pos)
#define    LPTIM16_CCSR_CCS                                       LPTIM16_CCSR_CCS_Msk


#define    FL_LPTIM16_CHANNEL_1                                   (0x1U << 0U)
#define    FL_LPTIM16_CHANNEL_2                                   (0x1U << 1U)


#define    FL_LPTIM16_CLK_SOURCE_INTERNAL                         (0x0U << LPTIM16_CFGR_PSCSEL_Pos)
#define    FL_LPTIM16_CLK_SOURCE_EXTERNAL                         (0x1U << LPTIM16_CFGR_PSCSEL_Pos)


#define    FL_LPTIM16_PSC_DIV1                                    (0x0U << LPTIM16_CFGR_DIVSEL_Pos)
#define    FL_LPTIM16_PSC_DIV2                                    (0x1U << LPTIM16_CFGR_DIVSEL_Pos)
#define    FL_LPTIM16_PSC_DIV4                                    (0x2U << LPTIM16_CFGR_DIVSEL_Pos)
#define    FL_LPTIM16_PSC_DIV8                                    (0x3U << LPTIM16_CFGR_DIVSEL_Pos)
#define    FL_LPTIM16_PSC_DIV16                                   (0x4U << LPTIM16_CFGR_DIVSEL_Pos)
#define    FL_LPTIM16_PSC_DIV32                                   (0x5U << LPTIM16_CFGR_DIVSEL_Pos)
#define    FL_LPTIM16_PSC_DIV64                                   (0x6U << LPTIM16_CFGR_DIVSEL_Pos)
#define    FL_LPTIM16_PSC_DIV128                                  (0x7U << LPTIM16_CFGR_DIVSEL_Pos)


#define    FL_LPTIM16_ETR_COUNT_EDGE_RISING                       (0x0U << LPTIM16_CFGR_EDGESEL_Pos)
#define    FL_LPTIM16_ETR_COUNT_EDGE_FALLING                      (0x1U << LPTIM16_CFGR_EDGESEL_Pos)


#define    FL_LPTIM16_ETR_TRIGGER_EDGE_RISING                     (0x0U << LPTIM16_CFGR_TRIGCFG_Pos)
#define    FL_LPTIM16_ETR_TRIGGER_EDGE_FALLING                    (0x1U << LPTIM16_CFGR_TRIGCFG_Pos)
#define    FL_LPTIM16_ETR_TRIGGER_EDGE_BOTH                       (0x2U << LPTIM16_CFGR_TRIGCFG_Pos)


#define    FL_LPTIM16_ENCODER_MODE_DISABLE                        (0x0U << LPTIM16_CFGR_QEMD_Pos)
#define    FL_LPTIM16_ENCODER_MODE_TI1FP1_TI2FP2_CNT              (0x1U << LPTIM16_CFGR_QEMD_Pos)
#define    FL_LPTIM16_ENCODER_MODE_TI2FP2_TI1FP1_CNT              (0x2U << LPTIM16_CFGR_QEMD_Pos)
#define    FL_LPTIM16_ENCODER_MODE_TI2FP2_CNT_TI1FP1_CNT          (0x3U << LPTIM16_CFGR_QEMD_Pos)


#define    FL_LPTIM16_TRGO_ENABLE                                 (0x1U << LPTIM16_CFGR_MMS_Pos)
#define    FL_LPTIM16_TRGO_UPDATE                                 (0x2U << LPTIM16_CFGR_MMS_Pos)
#define    FL_LPTIM16_TRGO_CCIF                                   (0x3U << LPTIM16_CFGR_MMS_Pos)
#define    FL_LPTIM16_TRGO_OC1REF                                 (0x4U << LPTIM16_CFGR_MMS_Pos)
#define    FL_LPTIM16_TRGO_OC2REF                                 (0x5U << LPTIM16_CFGR_MMS_Pos)


#define    FL_LPTIM16_ONE_PULSE_MODE_CONTINUOUS                   (0x0U << LPTIM16_CFGR_ONST_Pos)
#define    FL_LPTIM16_ONE_PULSE_MODE_SINGLE                       (0x1U << LPTIM16_CFGR_ONST_Pos)


#define    FL_LPTIM16_OPERATION_MODE_NORMAL                       (0x0U << LPTIM16_CFGR_TMODE_Pos)
#define    FL_LPTIM16_OPERATION_MODE_EXTERNAL_TRIGGER_CNT         (0x1U << LPTIM16_CFGR_TMODE_Pos)
#define    FL_LPTIM16_OPERATION_MODE_EXTERNAL_ASYNC_PULSE_CNT     (0x2U << LPTIM16_CFGR_TMODE_Pos)
#define    FL_LPTIM16_OPERATION_MODE_TIMEOUT                      (0x3U << LPTIM16_CFGR_TMODE_Pos)


#define    FL_LPTIM16_IC_EDGE_RISING                              (0x0U << LPTIM16_CCSR_CAPCFG_Pos)
#define    FL_LPTIM16_IC_EDGE_FALLING                             (0x1U << LPTIM16_CCSR_CAPCFG_Pos)
#define    FL_LPTIM16_IC_EDGE_BOTH                                (0x2U << LPTIM16_CCSR_CAPCFG_Pos)


#define    FL_LPTIM16_OC_POLARITY_NORMAL                          (0x0U << LPTIM16_CCSR_CCP_Pos)
#define    FL_LPTIM16_OC_POLARITY_INVERT                          (0x1U << LPTIM16_CCSR_CCP_Pos)


#define    FL_LPTIM16_IC_POLARITY_NORMAL                          (0x0U << LPTIM16_CCSR_CCP_Pos)
#define    FL_LPTIM16_IC_POLARITY_INVERT                          (0x1U << LPTIM16_CCSR_CCP_Pos)


#define    FL_LPTIM16_CHANNEL_MODE_DISABLE                        (0x0U << LPTIM16_CCSR_CCS_Pos)
#define    FL_LPTIM16_CHANNEL_MODE_INPUT                          (0x1U << LPTIM16_CCSR_CCS_Pos)
#define    FL_LPTIM16_CHANNEL_MODE_OUTPUT                         (0x2U << LPTIM16_CCSR_CCS_Pos)


#define    FL_LPTIM16_IC_CAPCTURED_EDGE_RISING                    (0x0U << LPTIM16_CCSR_CAPEDGE_Pos)
#define    FL_LPTIM16_IC_CAPCTURED_EDGE_FALLING                   (0x1U << LPTIM16_CCSR_CAPEDGE_Pos)

#define    FL_LPTIM16_ENCODER_DIR_CH1_BEFORE_CH2                  (0x0U << LPTIM16_ISR_QDIR_Pos)
#define    FL_LPTIM16_ENCODER_DIR_CH1_BEHIND_CH2                  (0x1U << LPTIM16_ISR_QDIR_Pos)

#define    FL_LPTIM16_IC1_CAPTURE_SOURCE_GROUP0                   (0x0U << LPTIM16_CCSR_CAP1SSEL_Pos)
#define    FL_LPTIM16_IC1_CAPTURE_SOURCE_GROUP1                   (0x1U << LPTIM16_CCSR_CAP1SSEL_Pos)
#define    FL_LPTIM16_IC1_CAPTURE_SOURCE_GROUP2                   (0x2U << LPTIM16_CCSR_CAP1SSEL_Pos)
#define    FL_LPTIM16_IC1_CAPTURE_SOURCE_GROUP3                   (0x3U << LPTIM16_CCSR_CAP1SSEL_Pos)
/* LPTIM end --------------------------------------------*/

/* PMU start --------------------------------------------*/
#define    PMU_CR_WKFSEL_Pos                                      (10U)
#define    PMU_CR_WKFSEL_Msk                                      (0x3U << PMU_CR_WKFSEL_Pos)
#define    PMU_CR_WKFSEL                                          PMU_CR_WKFSEL_Msk

#define    PMU_CR_SLPDP_Pos                                       (9U)
#define    PMU_CR_SLPDP_Msk                                       (0x1U << PMU_CR_SLPDP_Pos)
#define    PMU_CR_SLPDP                                           PMU_CR_SLPDP_Msk

#define    PMU_CR_PMOD_Pos                                        (0U)
#define    PMU_CR_PMOD_Msk                                        (0x3U << PMU_CR_PMOD_Pos)
#define    PMU_CR_PMOD                                            PMU_CR_PMOD_Msk

#define    PMU_WKTR_T2A_Pos                                       (6U)
#define    PMU_WKTR_T2A_Msk                                       (0x3U << PMU_WKTR_T2A_Pos)
#define    PMU_WKTR_T2A                                           PMU_WKTR_T2A_Msk

#define    PMU_WKTR_T1A_Pos                                       (0U)
#define    PMU_WKTR_T1A_Msk                                       (0x3U << PMU_WKTR_T1A_Pos)
#define    PMU_WKTR_T1A                                           PMU_WKTR_T1A_Msk

#define    PMU_WKFR_UART5WKF_Pos                                  (31U)
#define    PMU_WKFR_UART5WKF_Msk                                  (0x1U << PMU_WKFR_UART5WKF_Pos)
#define    PMU_WKFR_UART5WKF                                      PMU_WKFR_UART5WKF_Msk

#define    PMU_WKFR_UART1WKF_Pos                                  (30U)
#define    PMU_WKFR_UART1WKF_Msk                                  (0x1U << PMU_WKFR_UART1WKF_Pos)
#define    PMU_WKFR_UART1WKF                                      PMU_WKFR_UART1WKF_Msk

#define    PMU_WKFR_SVDWKF_Pos                                    (27U)
#define    PMU_WKFR_SVDWKF_Msk                                    (0x1U << PMU_WKFR_SVDWKF_Pos)
#define    PMU_WKFR_SVDWKF                                        PMU_WKFR_SVDWKF_Msk

#define    PMU_WKFR_IOWKF_Pos                                     (24U)
#define    PMU_WKFR_IOWKF_Msk                                     (0x1U << PMU_WKFR_IOWKF_Pos)
#define    PMU_WKFR_IOWKF                                         PMU_WKFR_IOWKF_Msk

#define    PMU_WKFR_UART4WKF_Pos                                  (23U)
#define    PMU_WKFR_UART4WKF_Msk                                  (0x1U << PMU_WKFR_UART4WKF_Pos)
#define    PMU_WKFR_UART4WKF                                      PMU_WKFR_UART4WKF_Msk

#define    PMU_WKFR_UART2WKF_Pos                                  (22U)
#define    PMU_WKFR_UART2WKF_Msk                                  (0x1U << PMU_WKFR_UART2WKF_Pos)
#define    PMU_WKFR_UART2WKF                                      PMU_WKFR_UART2WKF_Msk

#define    PMU_WKFR_COMP1WKF_Pos                                  (16U)
#define    PMU_WKFR_COMP1WKF_Msk                                  (0x1U << PMU_WKFR_COMP1WKF_Pos)
#define    PMU_WKFR_COMP1WKF                                      PMU_WKFR_COMP1WKF_Msk

#define    PMU_WKFR_UARTLIN1WKF_Pos                               (15U)
#define    PMU_WKFR_UARTLIN1WKF_Msk                               (0x1U << PMU_WKFR_UARTLIN1WKF_Pos)
#define    PMU_WKFR_UARTLIN1WKF                                   PMU_WKFR_UARTLIN1WKF_Msk

#define    PMU_WKFR_LPT16WKF_Pos                                  (12U)
#define    PMU_WKFR_LPT16WKF_Msk                                  (0x1U << PMU_WKFR_LPT16WKF_Pos)
#define    PMU_WKFR_LPT16WKF                                      PMU_WKFR_LPT16WKF_Msk

#define    PMU_WKFR_BST16WKF_Pos                                  (10U)
#define    PMU_WKFR_BST16WKF_Msk                                  (0x1U << PMU_WKFR_BST16WKF_Pos)
#define    PMU_WKFR_BST16WKF                                      PMU_WKFR_BST16WKF_Msk

#define    PMU_WKFR_DBGWKF_Pos                                    (9U)
#define    PMU_WKFR_DBGWKF_Msk                                    (0x1U << PMU_WKFR_DBGWKF_Pos)
#define    PMU_WKFR_DBGWKF                                        PMU_WKFR_DBGWKF_Msk

#define    PMU_WKFR_WKPXF_Pos                                     (0U)
#define    PMU_WKFR_WKPXF_Msk                                     (0x3fU << PMU_WKFR_WKPXF_Pos)
#define    PMU_WKFR_WKPXF                                         PMU_WKFR_WKPXF_Msk

#define    PMU_IER_SLPEIE_Pos                                     (1U)
#define    PMU_IER_SLPEIE_Msk                                     (0x1U << PMU_IER_SLPEIE_Pos)
#define    PMU_IER_SLPEIE                                         PMU_IER_SLPEIE_Msk

#define    PMU_IER_LPREIE_Pos                                     (0U)
#define    PMU_IER_LPREIE_Msk                                     (0x1U << PMU_IER_LPREIE_Pos)
#define    PMU_IER_LPREIE                                         PMU_IER_LPREIE_Msk

#define    PMU_ISR_SLPEIF_Pos                                     (1U)
#define    PMU_ISR_SLPEIF_Msk                                     (0x1U << PMU_ISR_SLPEIF_Pos)
#define    PMU_ISR_SLPEIF                                         PMU_ISR_SLPEIF_Msk

#define    PMU_ISR_LPREIF_Pos                                     (0U)
#define    PMU_ISR_LPREIF_Msk                                     (0x1U << PMU_ISR_LPREIF_Pos)
#define    PMU_ISR_LPREIF                                         PMU_ISR_LPREIF_Msk

#define    PMU_BUFCR_AVREFBUF_OUTEN_Pos                           (5U)
#define    PMU_BUFCR_AVREFBUF_OUTEN_Msk                           (0x1U << PMU_BUFCR_AVREFBUF_OUTEN_Pos)
#define    PMU_BUFCR_AVREFBUF_OUTEN                               PMU_BUFCR_AVREFBUF_OUTEN_Msk

#define    PMU_BUFCR_AVREFBUF_EN_Pos                              (4U)
#define    PMU_BUFCR_AVREFBUF_EN_Msk                              (0x1U << PMU_BUFCR_AVREFBUF_EN_Pos)
#define    PMU_BUFCR_AVREFBUF_EN                                  PMU_BUFCR_AVREFBUF_EN_Msk

#define    PMU_BUFCR_VPTATBUFFER_OUTEN_Pos                        (3U)
#define    PMU_BUFCR_VPTATBUFFER_OUTEN_Msk                        (0x1U << PMU_BUFCR_VPTATBUFFER_OUTEN_Pos)
#define    PMU_BUFCR_VPTATBUFFER_OUTEN                            PMU_BUFCR_VPTATBUFFER_OUTEN_Msk

#define    PMU_BUFCR_VPTATBUFFER_EN_Pos                           (2U)
#define    PMU_BUFCR_VPTATBUFFER_EN_Msk                           (0x1U << PMU_BUFCR_VPTATBUFFER_EN_Pos)
#define    PMU_BUFCR_VPTATBUFFER_EN                               PMU_BUFCR_VPTATBUFFER_EN_Msk

#define    PMU_PTATCR_PTAT_EN_Pos                                 (0U)
#define    PMU_PTATCR_PTAT_EN_Msk                                 (0x1U << PMU_PTATCR_PTAT_EN_Pos)
#define    PMU_PTATCR_PTAT_EN                                     PMU_PTATCR_PTAT_EN_Msk

#define    FL_PMU_WAKEUP0_PIN                                     (0x1U << 0U)
#define    FL_PMU_WAKEUP1_PIN                                     (0x1U << 1U)
#define    FL_PMU_WAKEUP2_PIN                                     (0x1U << 2U)
#define    FL_PMU_WAKEUP3_PIN                                     (0x1U << 3U)
#define    FL_PMU_WAKEUP4_PIN                                     (0x1U << 4U)
#define    FL_PMU_WAKEUP5_PIN                                     (0x1U << 5U)

#define    FL_PMU_RCHF_WAKEUP_FREQ_8MHZ                           (0x0U << PMU_CR_WKFSEL_Pos)
#define    FL_PMU_RCHF_WAKEUP_FREQ_16MHZ                          (0x1U << PMU_CR_WKFSEL_Pos)
#define    FL_PMU_RCHF_WAKEUP_FREQ_24MHZ                          (0x2U << PMU_CR_WKFSEL_Pos)

#define    FL_PMU_SLEEP_MODE_DEEP                                 (0x1U << PMU_CR_SLPDP_Pos)
#define    FL_PMU_SLEEP_MODE_NORMAL                               (0x0U << PMU_CR_SLPDP_Pos)


#define    FL_PMU_POWER_MODE_ACTIVE                               (0x0U << PMU_CR_PMOD_Pos)
#define    FL_PMU_POWER_MODE_LPRUN_ONLY                           (0x1U << PMU_CR_PMOD_Pos)
#define    FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP                   (0x2U << PMU_CR_PMOD_Pos)

#define    FL_PMU_WAKEUP_DELAYT2A_20US                            (0x0U << PMU_WKTR_T2A_Pos)
#define    FL_PMU_WAKEUP_DELAYT2A_30US                            (0x1U << PMU_WKTR_T2A_Pos)
#define    FL_PMU_WAKEUP_DELAYT2A_40US                            (0x2U << PMU_WKTR_T2A_Pos)
#define    FL_PMU_WAKEUP_DELAYT2A_50US                            (0x3U << PMU_WKTR_T2A_Pos)

#define    FL_PMU_WAKEUP_DELAYT1A_10US                            (0x0U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAYT1A_12US                            (0x1U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAYT1A_16US                            (0x2U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAYT1A_20US                            (0x3U << PMU_WKTR_T1A_Pos)
/* PMU end --------------------------------------------*/

/* RMU start --------------------------------------------*/
#define    RMU_PDRCR_EN_Pos                                       (0U)
#define    RMU_PDRCR_EN_Msk                                       (0x1U << RMU_PDRCR_EN_Pos)
#define    RMU_PDRCR_EN                                           RMU_PDRCR_EN_Msk

#define    RMU_BORCR_CFG_Pos                                      (2U)
#define    RMU_BORCR_CFG_Msk                                      (0x7U << RMU_BORCR_CFG_Pos)
#define    RMU_BORCR_CFG                                          RMU_BORCR_CFG_Msk

#define    RMU_BORCR_ENB_Pos                                      (0U)
#define    RMU_BORCR_ENB_Msk                                      (0x1U << RMU_BORCR_ENB_Pos)
#define    RMU_BORCR_ENB                                          RMU_BORCR_ENB_Msk

#define    RMU_LKPCR_EN_Pos                                       (1U)
#define    RMU_LKPCR_EN_Msk                                       (0x1U << RMU_LKPCR_EN_Pos)
#define    RMU_LKPCR_EN                                           RMU_LKPCR_EN_Msk

#define    RMU_RSTFR_RAMP_FLAG_Pos                                (14U)
#define    RMU_RSTFR_RAMP_FLAG_Msk                                (0x1U << RMU_RSTFR_RAMP_FLAG_Pos)
#define    RMU_RSTFR_RAMP_FLAG                                    RMU_RSTFR_RAMP_FLAG_Msk

#define    RMU_RSTFR_MAP_FLAG_Pos                                 (13U)
#define    RMU_RSTFR_MAP_FLAG_Msk                                 (0x1U << RMU_RSTFR_MAP_FLAG_Pos)
#define    RMU_RSTFR_MAP_FLAG                                     RMU_RSTFR_MAP_FLAG_Msk

#define    RMU_RSTFR_MDFN_FLAG_Pos                                (12U)
#define    RMU_RSTFR_MDFN_FLAG_Msk                                (0x1U << RMU_RSTFR_MDFN_FLAG_Pos)
#define    RMU_RSTFR_MDFN_FLAG                                    RMU_RSTFR_MDFN_FLAG_Msk

#define    RMU_RSTFR_NRSTN_FLAG_Pos                               (11U)
#define    RMU_RSTFR_NRSTN_FLAG_Msk                               (0x1U << RMU_RSTFR_NRSTN_FLAG_Pos)
#define    RMU_RSTFR_NRSTN_FLAG                                   RMU_RSTFR_NRSTN_FLAG_Msk

#define    RMU_RSTFR_PODRN_FLAG_Pos                               (8U)
#define    RMU_RSTFR_PODRN_FLAG_Msk                               (0x1U << RMU_RSTFR_PODRN_FLAG_Pos)
#define    RMU_RSTFR_PODRN_FLAG                                   RMU_RSTFR_PODRN_FLAG_Msk

#define    RMU_RSTFR_SVDN_FLAG_Pos                                (7U)
#define    RMU_RSTFR_SVDN_FLAG_Msk                                (0x1U << RMU_RSTFR_SVDN_FLAG_Pos)
#define    RMU_RSTFR_SVDN_FLAG                                    RMU_RSTFR_SVDN_FLAG_Msk

#define    RMU_RSTFR_TESTN_FLAG_Pos                               (6U)
#define    RMU_RSTFR_TESTN_FLAG_Msk                               (0x1U << RMU_RSTFR_TESTN_FLAG_Pos)
#define    RMU_RSTFR_TESTN_FLAG                                   RMU_RSTFR_TESTN_FLAG_Msk

#define    RMU_RSTFR_SOFTN_FLAG_Pos                               (5U)
#define    RMU_RSTFR_SOFTN_FLAG_Msk                               (0x1U << RMU_RSTFR_SOFTN_FLAG_Pos)
#define    RMU_RSTFR_SOFTN_FLAG                                   RMU_RSTFR_SOFTN_FLAG_Msk

#define    RMU_RSTFR_IWDTN_FLAG_Pos                               (4U)
#define    RMU_RSTFR_IWDTN_FLAG_Msk                               (0x1U << RMU_RSTFR_IWDTN_FLAG_Pos)
#define    RMU_RSTFR_IWDTN_FLAG                                   RMU_RSTFR_IWDTN_FLAG_Msk

#define    RMU_RSTFR_WWDTN_FLAG_Pos                               (2U)
#define    RMU_RSTFR_WWDTN_FLAG_Msk                               (0x1U << RMU_RSTFR_WWDTN_FLAG_Pos)
#define    RMU_RSTFR_WWDTN_FLAG                                   RMU_RSTFR_WWDTN_FLAG_Msk

#define    RMU_RSTFR_LKUPN_FLAG_Pos                               (1U)
#define    RMU_RSTFR_LKUPN_FLAG_Msk                               (0x1U << RMU_RSTFR_LKUPN_FLAG_Pos)
#define    RMU_RSTFR_LKUPN_FLAG                                   RMU_RSTFR_LKUPN_FLAG_Msk

#define    RMU_RSTFR_NVICN_FLAG_Pos                               (0U)
#define    RMU_RSTFR_NVICN_FLAG_Msk                               (0x1U << RMU_RSTFR_NVICN_FLAG_Pos)
#define    RMU_RSTFR_NVICN_FLAG                                   RMU_RSTFR_NVICN_FLAG_Msk

#define    PERHRSTEN_KEY                                          (0x13579BDFUL)
#define    SOFTWARERESET_KEY                                      (0x5C5CAABBUL)

#define    FL_RMU_RSTAHB_DMA                                      (0x1U << 0U)
#define    FL_RMU_RSTAPB_UART5                                    (0x1fU << 0U)
#define    FL_RMU_RSTAPB_UART4                                    (0x1eU << 0U)
#define    FL_RMU_RSTAPB_UART2                                    (0x1cU << 0U)
#define    FL_RMU_RSTAPB_UART1                                    (0x1bU << 0U)
#define    FL_RMU_RSTAPB_UCIR                                     (0x19U << 0U)
#define    FL_RMU_RSTAPB_LPUART                                   (0x18U << 0U)
#define    FL_RMU_RSTAPB_SPI1                                     (0x15U << 0U)
#define    FL_RMU_RSTAPB_SPI0                                     (0x14U << 0U)
#define    FL_RMU_RSTAPB_INTMUX                                   (0xfU << 0U)
#define    FL_RMU_RSTAPB_I2C1                                     (0x9U << 0U)
#define    FL_RMU_RSTAPB_I2C0                                     (0x8U << 0U)
#define    FL_RMU_RSTAPB_PGL                                      (0x5U << 0U)
#define    FL_RMU_RSTAPB_ATIM                                     (0x4U << 0U)
#define    FL_RMU_RSTAPB_TAU1                                     (0x3U << 0U)
#define    FL_RMU_RSTAPB_TAU0                                     (0x2U << 0U)
#define    FL_RMU_RSTAPB_LPTIM16                                  (0x1U << 0U)
#define    FL_RMU_RSTAPB_BTIM16                                   (0x0U << 0U)
#define    FL_RMU_RSTAPB_ADCCR                                    (0x38U << 0U)
#define    FL_RMU_RSTAPB_ADC                                      (0x37U << 0U)
#define    FL_RMU_RSTAPB_CRC                                      (0x31U << 0U)
#define    FL_RMU_RSTAPB_GPTIM                                    (0x27U << 0U)
#define    FL_RMU_RSTAPB_DIVAS                                    (0x23U << 0U)
#define    FL_RMU_RSTAPB_SVD                                      (0x21U << 0U)
#define    FL_RMU_RSTAPB_COMP                                     (0x20U << 0U)


#define    FL_RMU_BOR_THRESHOLD_2P4V                             (0x0U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_2P7V                             (0x4U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_3P0V                             (0x5U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_3P6V                             (0x6U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_4P0V                             (0x7U << RMU_BORCR_CFG_Pos)
/* RMU end --------------------------------------------*/

/* SVD start --------------------------------------------*/
#define    SVD_CFGR_LVL_Pos                                       (4U)
#define    SVD_CFGR_LVL_Msk                                       (0x7U << SVD_CFGR_LVL_Pos)
#define    SVD_CFGR_LVL                                           SVD_CFGR_LVL_Msk

#define    SVD_CFGR_DFEN_Pos                                      (3U)
#define    SVD_CFGR_DFEN_Msk                                      (0x1U << SVD_CFGR_DFEN_Pos)
#define    SVD_CFGR_DFEN                                          SVD_CFGR_DFEN_Msk

#define    SVD_CFGR_MOD_Pos                                       (2U)
#define    SVD_CFGR_MOD_Msk                                       (0x1U << SVD_CFGR_MOD_Pos)
#define    SVD_CFGR_MOD                                           SVD_CFGR_MOD_Msk

#define    SVD_CFGR_ITVL_Pos                                      (0U)
#define    SVD_CFGR_ITVL_Msk                                      (0x3U << SVD_CFGR_ITVL_Pos)
#define    SVD_CFGR_ITVL                                          SVD_CFGR_ITVL_Msk

#define    SVD_CR_EN_Pos                                          (0U)
#define    SVD_CR_EN_Msk                                          (0x3U << SVD_CR_EN_Pos)
#define    SVD_CR_EN                                              SVD_CR_EN_Msk

#define    SVD_IER_PFIE_Pos                                       (1U)
#define    SVD_IER_PFIE_Msk                                       (0x1U << SVD_IER_PFIE_Pos)
#define    SVD_IER_PFIE                                           SVD_IER_PFIE_Msk

#define    SVD_IER_PRIE_Pos                                       (0U)
#define    SVD_IER_PRIE_Msk                                       (0x1U << SVD_IER_PRIE_Pos)
#define    SVD_IER_PRIE                                           SVD_IER_PRIE_Msk

#define    SVD_ISR_SVDO_Pos                                       (8U)
#define    SVD_ISR_SVDO_Msk                                       (0x1U << SVD_ISR_SVDO_Pos)
#define    SVD_ISR_SVDO                                           SVD_ISR_SVDO_Msk

#define    SVD_ISR_SVDR_Pos                                       (7U)
#define    SVD_ISR_SVDR_Msk                                       (0x1U << SVD_ISR_SVDR_Pos)
#define    SVD_ISR_SVDR                                           SVD_ISR_SVDR_Msk

#define    SVD_ISR_PFF_Pos                                        (1U)
#define    SVD_ISR_PFF_Msk                                        (0x1U << SVD_ISR_PFF_Pos)
#define    SVD_ISR_PFF                                            SVD_ISR_PFF_Msk

#define    SVD_ISR_PRF_Pos                                        (0U)
#define    SVD_ISR_PRF_Msk                                        (0x1U << SVD_ISR_PRF_Pos)
#define    SVD_ISR_PRF                                            SVD_ISR_PRF_Msk

#define    SVD_VSR_EN_Pos                                         (0U)
#define    SVD_VSR_EN_Msk                                         (0x7U << SVD_VSR_EN_Pos)
#define    SVD_VSR_EN                                             SVD_VSR_EN_Msk

#define    FL_SVD_REFERENCE_1P0V                                  (0x1U << 2U)

#define    FL_SVD_WARNING_THRESHOLD_GROUP0                        (0x0U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP1                        (0x1U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP2                        (0x2U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP3                        (0x3U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP4                        (0x4U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP5                        (0x5U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP6                        (0x6U << SVD_CFGR_LVL_Pos)
#define    FL_SVD_WARNING_THRESHOLD_GROUP7                        (0x7U << SVD_CFGR_LVL_Pos)

#define    FL_SVD_WORK_MODE_CONTINUOUS                            (0x0U << SVD_CFGR_MOD_Pos)
#define    FL_SVD_WORK_MODE_PERIODIC                              (0x1U << SVD_CFGR_MOD_Pos)

#define    FL_SVD_ENABLE_PERIOD_62P5MS                            (0x0U << SVD_CFGR_ITVL_Pos)
#define    FL_SVD_ENABLE_PERIOD_256MS                             (0x1U << SVD_CFGR_ITVL_Pos)
#define    FL_SVD_ENABLE_PERIOD_1000MS                            (0x2U << SVD_CFGR_ITVL_Pos)
#define    FL_SVD_ENABLE_PERIOD_4000MS                            (0x3U << SVD_CFGR_ITVL_Pos)

#define    FL_SVD_Mode_DISABLE                                    (0x0U << SVD_CR_EN_Pos)
#define    FL_SVD_Mode_LOWVOLTAGE_WARNING                         (0x1U << SVD_CR_EN_Pos)
#define    FL_SVD_Mode_UNDERVOLTAGE_RESET                         (0x2U << SVD_CR_EN_Pos)

#define    FL_SVD_CR_DISABLE                                      (0x0U << SVD_CR_EN_Pos)

#define    FL_SVD_POWER_STATUS_FALLING                            (0x0U << SVD_ISR_SVDO_Pos)
#define    FL_SVD_POWER_STATUS_RISING                             (0x1U << SVD_ISR_SVDO_Pos)

#define    FL_SVD_LATCHED_POWER_STATUS_FALLING                    (0x0U << SVD_ISR_SVDR_Pos)
#define    FL_SVD_LATCHED_POWER_STATUS_RISING                     (0x1U << SVD_ISR_SVDR_Pos)
/* SVD end --------------------------------------------*/

/* TAU start --------------------------------------------*/
#define    TAU_CR_EN_Pos                                          (0U)
#define    TAU_CR_EN_Msk                                          (0xffU << TAU_CR_EN_Pos)
#define    TAU_CR_EN                                              TAU_CR_EN_Msk

#define    TAU_EGR_UG_Pos                                         (0U)
#define    TAU_EGR_UG_Msk                                         (0xffU << TAU_EGR_UG_Pos)
#define    TAU_EGR_UG                                             TAU_EGR_UG_Msk

#define    TAU_CFGR_ARPE_Pos                                      (31U)
#define    TAU_CFGR_ARPE_Msk                                      (0x1U << TAU_CFGR_ARPE_Pos)
#define    TAU_CFGR_ARPE                                          TAU_CFGR_ARPE_Msk

#define    TAU_CFGR_CAPCLR_Pos                                    (30U)
#define    TAU_CFGR_CAPCLR_Msk                                    (0x1U << TAU_CFGR_CAPCLR_Pos)
#define    TAU_CFGR_CAPCLR                                        TAU_CFGR_CAPCLR_Msk

#define    TAU_CFGR_CAPONCE_Pos                                   (29U)
#define    TAU_CFGR_CAPONCE_Msk                                   (0x1U << TAU_CFGR_CAPONCE_Pos)
#define    TAU_CFGR_CAPONCE                                       TAU_CFGR_CAPONCE_Msk

#define    TAU_CFGR_NF_Pos                                        (28U)
#define    TAU_CFGR_NF_Msk                                        (0x1U << TAU_CFGR_NF_Pos)
#define    TAU_CFGR_NF                                            TAU_CFGR_NF_Msk

#define    TAU_CFGR_CAPEDGE_Pos                                   (26U)
#define    TAU_CFGR_CAPEDGE_Msk                                   (0x3U << TAU_CFGR_CAPEDGE_Pos)
#define    TAU_CFGR_CAPEDGE                                       TAU_CFGR_CAPEDGE_Msk

#define    TAU_CFGR_CNTEDGE_Pos                                   (24U)
#define    TAU_CFGR_CNTEDGE_Msk                                   (0x3U << TAU_CFGR_CNTEDGE_Pos)
#define    TAU_CFGR_CNTEDGE                                       TAU_CFGR_CNTEDGE_Msk

#define    TAU_CFGR_PRESCALE1_Pos                                 (16U)
#define    TAU_CFGR_PRESCALE1_Msk                                 (0xffU << TAU_CFGR_PRESCALE1_Pos)
#define    TAU_CFGR_PRESCALE1                                     TAU_CFGR_PRESCALE1_Msk

#define    TAU_CFGR_PRESCALE2_Pos                                 (8U)
#define    TAU_CFGR_PRESCALE2_Msk                                 (0xffU << TAU_CFGR_PRESCALE2_Pos)
#define    TAU_CFGR_PRESCALE2                                     TAU_CFGR_PRESCALE2_Msk

#define    TAU_CFGR_OPOL_Pos                                      (7U)
#define    TAU_CFGR_OPOL_Msk                                      (0x1U << TAU_CFGR_OPOL_Pos)
#define    TAU_CFGR_OPOL                                          TAU_CFGR_OPOL_Msk

#define    TAU_CFGR_TS_Pos                                        (5U)
#define    TAU_CFGR_TS_Msk                                        (0x3U << TAU_CFGR_TS_Pos)
#define    TAU_CFGR_TS                                            TAU_CFGR_TS_Msk

#define    TAU_CFGR_CAPSEL_Pos                                    (2U)
#define    TAU_CFGR_CAPSEL_Msk                                    (0x7U << TAU_CFGR_CAPSEL_Pos)
#define    TAU_CFGR_CAPSEL                                        TAU_CFGR_CAPSEL_Msk

#define    TAU_CFGR_CNTSEL_Pos                                    (0U)
#define    TAU_CFGR_CNTSEL_Msk                                    (0x3U << TAU_CFGR_CNTSEL_Pos)
#define    TAU_CFGR_CNTSEL                                        TAU_CFGR_CNTSEL_Msk

#define    TAU_MDR_URS_Pos                                        (5U)
#define    TAU_MDR_URS_Msk                                        (0x1U << TAU_MDR_URS_Pos)
#define    TAU_MDR_URS                                            TAU_MDR_URS_Msk

#define    TAU_MDR_SLVMD_Pos                                      (4U)
#define    TAU_MDR_SLVMD_Msk                                      (0x1U << TAU_MDR_SLVMD_Pos)
#define    TAU_MDR_SLVMD                                          TAU_MDR_SLVMD_Msk

#define    TAU_MDR_SLV_Pos                                        (2U)
#define    TAU_MDR_SLV_Msk                                        (0x1U << TAU_MDR_SLV_Pos)
#define    TAU_MDR_SLV                                            TAU_MDR_SLV_Msk

#define    TAU_MDR_TOEN_Pos                                       (3U)
#define    TAU_MDR_TOEN_Msk                                       (0x1U << TAU_MDR_TOEN_Pos)
#define    TAU_MDR_TOEN                                            TAU_MDR_TOEN_Msk

#define    TAU_MDR_MD_Pos                                         (0U)
#define    TAU_MDR_MD_Msk                                         (0x3U << TAU_MDR_MD_Pos)
#define    TAU_MDR_MD                                             TAU_MDR_MD_Msk

#define    TAU_ARR_ARR_Pos                                         (0U)
#define    TAU_ARR_ARR_Msk                                         (0xffffU << TAU_ARR_ARR_Pos)
#define    TAU_ARR_ARR                                             TAU_ARR_ARR_Msk

#define    TAU_CCR_CCR_Pos                                         (0U)
#define    TAU_CCR_CCR_Msk                                         (0xffffU << TAU_CCR_CCR_Pos)
#define    TAU_CCR_CCR                                             TAU_CCR_CCR_Msk

#define    TAU_IER_CMPIE_Pos                                      (2U)
#define    TAU_IER_CMPIE_Msk                                      (0x1U << TAU_IER_CMPIE_Pos)
#define    TAU_IER_CMPIE                                          TAU_IER_CMPIE_Msk

#define    TAU_IER_CAPIE_Pos                                      (1U)
#define    TAU_IER_CAPIE_Msk                                      (0x1U << TAU_IER_CAPIE_Pos)
#define    TAU_IER_CAPIE                                          TAU_IER_CAPIE_Msk

#define    TAU_IER_OVIE_Pos                                       (0U)
#define    TAU_IER_OVIE_Msk                                       (0x1U << TAU_IER_OVIE_Pos)
#define    TAU_IER_OVIE                                           TAU_IER_OVIE_Msk

#define    TAU_ISR_EDGESTA_Pos                                    (3U)
#define    TAU_ISR_EDGESTA_Msk                                    (0x1U << TAU_ISR_EDGESTA_Pos)
#define    TAU_ISR_EDGESTA                                        TAU_ISR_EDGESTA_Msk

#define    TAU_ISR_CMPIF_Pos                                      (2U)
#define    TAU_ISR_CMPIF_Msk                                      (0x1U << TAU_ISR_CMPIF_Pos)
#define    TAU_ISR_CMPIF                                          TAU_ISR_CMPIF_Msk

#define    TAU_ISR_CAPIF_Pos                                      (1U)
#define    TAU_ISR_CAPIF_Msk                                      (0x1U << TAU_ISR_CAPIF_Pos)
#define    TAU_ISR_CAPIF                                          TAU_ISR_CAPIF_Msk

#define    TAU_ISR_OVIF_Pos                                       (0U)
#define    TAU_ISR_OVIF_Msk                                       (0x1U << TAU_ISR_OVIF_Pos)
#define    TAU_ISR_OVIF                                           TAU_ISR_OVIF_Msk

#define    FL_TAU_TIMER0                                          (0x1U << 0U)
#define    FL_TAU_TIMER1                                          (0x1U << 1U)
#define    FL_TAU_TIMER2                                          (0x1U << 2U)
#define    FL_TAU_TIMER3                                          (0x1U << 3U)
#define    FL_TAU_TIMER4                                          (0x1U << 4U)
#define    FL_TAU_TIMER5                                          (0x1U << 5U)
#define    FL_TAU_TIMER6                                          (0x1U << 6U)
#define    FL_TAU_TIMER7                                          (0x1U << 7U)
#define    FL_TAU_GROUP0                                          (0x0U)
#define    FL_TAU_GROUP1                                          (0x1U)

#define    FL_TAU_IC_MODE_NORMAL                                  (0x0U << TAU_CFGR_CAPCLR_Pos)
#define    FL_TAU_IC_MODE_RESET                                   (0x1U << TAU_CFGR_CAPCLR_Pos)

#define    FL_TAU_IC_EDGE_BOTH                                    (0x0U << TAU_CFGR_CAPEDGE_Pos)
#define    FL_TAU_IC_EDGE_RISING                                  (0x1U << TAU_CFGR_CAPEDGE_Pos)
#define    FL_TAU_IC_EDGE_FALLING                                 (0x2U << TAU_CFGR_CAPEDGE_Pos)


#define    FL_TAU_COUNTER_EDGE_BOTH                               (0x0U << TAU_CFGR_CNTEDGE_Pos)
#define    FL_TAU_COUNTER_EDGE_RISING                             (0x1U << TAU_CFGR_CNTEDGE_Pos)
#define    FL_TAU_COUNTER_EDGE_FALLING                            (0x2U << TAU_CFGR_CNTEDGE_Pos)


#define    FL_TAU_OC_POLARITY_NORMAL                              (0x0U << TAU_CFGR_OPOL_Pos)
#define    FL_TAU_OC_POLARITY_INVERT                              (0x1U << TAU_CFGR_OPOL_Pos)


#define    FL_TAU_TRGI_GROUP0                                     (0x0U << TAU_CFGR_TS_Pos)
#define    FL_TAU_TRGI_GROUP1                                     (0x1U << TAU_CFGR_TS_Pos)
#define    FL_TAU_TRGI_GROUP2                                     (0x2U << TAU_CFGR_TS_Pos)
#define    FL_TAU_TRGI_GROUP3                                     (0x3U << TAU_CFGR_TS_Pos)


#define    FL_TAU_IC_SOURCE_GROUP0                                (0x0U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP1                                (0x1U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP2                                (0x2U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP3                                (0x3U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP4                                (0x4U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP5                                (0x5U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP6                                (0x6U << TAU_CFGR_CAPSEL_Pos)
#define    FL_TAU_IC_SOURCE_GROUP7                                (0x7U << TAU_CFGR_CAPSEL_Pos)

#define    FL_TAU_UPDATE_SOURCE_REGULAR                           (0x0U <<TAU_MDR_URS_Pos)
#define    FL_TAU_UPDATE_SOURCE_COUNTER                           (0x1U <<TAU_MDR_URS_Pos)

#define    FL_TAU_COUNTER_SOURCE_INTERNAL                         (0x0U << TAU_CFGR_CNTSEL_Pos)
#define    FL_TAU_COUNTER_SOURCE_EXTERNAL                         (0x1U << TAU_CFGR_CNTSEL_Pos)
#define    FL_TAU_COUNTER_SOURCE_CAPTURE_INPUT                    (0x2U << TAU_CFGR_CNTSEL_Pos)


#define    FL_TAU_SLAVE_MODE_TRIG_CNT                             (0x0U << TAU_MDR_SLVMD_Pos)
#define    FL_TAU_SLAVE_MODE_TRIG_START                           (0x1U << TAU_MDR_SLVMD_Pos)


#define    FL_TAU_OPERATION_MODE_NORMAL                           (0x0U << TAU_MDR_MD_Pos)
#define    FL_TAU_OPERATION_MODE_OC                               (0x1U << TAU_MDR_MD_Pos)
#define    FL_TAU_OPERATION_MODE_IC_PERIOD                        (0x2U << TAU_MDR_MD_Pos)
#define    FL_TAU_OPERATION_MODE_IC_WIDTH                         (0x3U << TAU_MDR_MD_Pos)


#define    FL_TAU_IC_CAPTURED_EDGE_RISING                         (0x0U << TAU_ISR_EDGESTA_Pos)
#define    FL_TAU_IC_CAPTURED_EDGE_FALLING                        (0x1U << TAU_ISR_EDGESTA_Pos)

#define    FL_TAU_CASCADE_MODE_DISABLE                            (0U)
#define    FL_TAU_CASCADE_MODE_MASTER                             (1U)
#define    FL_TAU_CASCADE_MODE_SLAVE                              (2U)
/* TAU end --------------------------------------------*/

/* UART start --------------------------------------------*/
#define    FL_UART_DIRECTION_NONE                                 0x00000000U
#define    FL_UART_DIRECTION_RX                                   UART_CSR_RXEN
#define    FL_UART_DIRECTION_TX                                   UART_CSR_TXEN
#define    FL_UART_DIRECTION_TX_RX                               (UART_CSR_RXEN | UART_CSR_TXEN)

#define    UART_IRCR_IRFLAG_Pos                                   (15U)
#define    UART_IRCR_IRFLAG_Msk                                   (0x1U << UART_IRCR_IRFLAG_Pos)
#define    UART_IRCR_IRFLAG                                       UART_IRCR_IRFLAG_Msk

#define    UART_IRCR_TH_Pos                                       (11U)
#define    UART_IRCR_TH_Msk                                       (0xfU << UART_IRCR_TH_Pos)
#define    UART_IRCR_TH                                           UART_IRCR_TH_Msk

#define    UART_IRCR_TZBRG_Pos                                    (0U)
#define    UART_IRCR_TZBRG_Msk                                    (0x7ffU << UART_IRCR_TZBRG_Pos)
#define    UART_IRCR_TZBRG                                        UART_IRCR_TZBRG_Msk

#define    UART_MCR_HDSEL_Pos                                     (2U)
#define    UART_MCR_HDSEL_Msk                                     (0x1U << UART_MCR_HDSEL_Pos)
#define    UART_MCR_HDSEL                                         UART_MCR_HDSEL_Msk

#define    UART_MCR_LINMD_Pos                                     (1U)
#define    UART_MCR_LINMD_Msk                                     (0x1U << UART_MCR_LINMD_Pos)
#define    UART_MCR_LINMD                                         UART_MCR_LINMD_Msk

#define    UART_MCR_MODE_Pos                                      (0U)
#define    UART_MCR_MODE_Msk                                      (0x1U << UART_MCR_MODE_Pos)
#define    UART_MCR_MODE                                          UART_MCR_MODE_Msk

#define    UART_LINCR_BERS_Pos                                    (16U)
#define    UART_LINCR_BERS_Msk                                    (0x1U << UART_LINCR_BERS_Pos)
#define    UART_LINCR_BERS                                        UART_LINCR_BERS_Msk

#define    UART_LINCR_WKUP_LEN_Pos                                (8U)
#define    UART_LINCR_WKUP_LEN_Msk                                (0xffU << UART_LINCR_WKUP_LEN_Pos)
#define    UART_LINCR_WKUP_LEN                                    UART_LINCR_WKUP_LEN_Msk

#define    UART_LINCR_SYNCEN_Pos                                  (7U)
#define    UART_LINCR_SYNCEN_Msk                                  (0x1U << UART_LINCR_SYNCEN_Pos)
#define    UART_LINCR_SYNCEN                                      UART_LINCR_SYNCEN_Msk

#define    UART_LINCR_FTOEN_Pos                                   (6U)
#define    UART_LINCR_FTOEN_Msk                                   (0x1U << UART_LINCR_FTOEN_Pos)
#define    UART_LINCR_FTOEN                                       UART_LINCR_FTOEN_Msk

#define    UART_LINCR_BREM_Pos                                    (4U)
#define    UART_LINCR_BREM_Msk                                    (0x3U << UART_LINCR_BREM_Pos)
#define    UART_LINCR_BREM                                        UART_LINCR_BREM_Msk

#define    UART_LINCR_NDET_EN_Pos                                 (3U)
#define    UART_LINCR_NDET_EN_Msk                                 (0x1U << UART_LINCR_NDET_EN_Pos)
#define    UART_LINCR_NDET_EN                                     UART_LINCR_NDET_EN_Msk

#define    UART_LINCR_WKDET_EN_Pos                                (2U)
#define    UART_LINCR_WKDET_EN_Msk                                (0x1U << UART_LINCR_WKDET_EN_Pos)
#define    UART_LINCR_WKDET_EN                                    UART_LINCR_WKDET_EN_Msk

#define    UART_LINCR_TX_BF_Pos                                   (1U)
#define    UART_LINCR_TX_BF_Msk                                   (0x1U << UART_LINCR_TX_BF_Pos)
#define    UART_LINCR_TX_BF                                       UART_LINCR_TX_BF_Msk

#define    UART_LINCR_TX_WKUP_Pos                                 (0U)
#define    UART_LINCR_TX_WKUP_Msk                                 (0x1U << UART_LINCR_TX_WKUP_Pos)
#define    UART_LINCR_TX_WKUP                                     UART_LINCR_TX_WKUP_Msk

#define    UART_LINBSR_BAUD_SYNC_Pos                              (0U)
#define    UART_LINBSR_BAUD_SYNC_Msk                              (0xfffffU << UART_LINBSR_BAUD_SYNC_Pos)
#define    UART_LINBSR_BAUD_SYNC                                  UART_LINBSR_BAUD_SYNC_Msk

#define    UART_LINFTR_FTO_Pos                                    (0U)
#define    UART_LINFTR_FTO_Msk                                    (0xfffU << UART_LINFTR_FTO_Pos)
#define    UART_LINFTR_FTO                                        UART_LINFTR_FTO_Msk

#define    UART_LINTTR_IBS_Pos                                    (12U)
#define    UART_LINTTR_IBS_Msk                                    (0x3U << UART_LINTTR_IBS_Pos)
#define    UART_LINTTR_IBS                                        UART_LINTTR_IBS_Msk

#define    UART_LINTTR_RSS_Pos                                    (8U)
#define    UART_LINTTR_RSS_Msk                                    (0x7U << UART_LINTTR_RSS_Pos)
#define    UART_LINTTR_RSS                                        UART_LINTTR_RSS_Msk

#define    UART_LINTTR_BDT_Pos                                    (4U)
#define    UART_LINTTR_BDT_Msk                                    (0x3U << UART_LINTTR_BDT_Pos)
#define    UART_LINTTR_BDT                                        UART_LINTTR_BDT_Msk

#define    UART_LINTTR_BLT_Pos                                    (0U)
#define    UART_LINTTR_BLT_Msk                                    (0xfU << UART_LINTTR_BLT_Pos)
#define    UART_LINTTR_BLT                                        UART_LINTTR_BLT_Msk

#define    UART_LINPSR_PRE_SYNC_Pos                               (0U)
#define    UART_LINPSR_PRE_SYNC_Msk                               (0xfffffU << UART_LINPSR_PRE_SYNC_Pos)
#define    UART_LINPSR_PRE_SYNC                                   UART_LINPSR_PRE_SYNC_Msk

#define    UART_LINBKR_BREAK_LEN_Pos                              (0U)
#define    UART_LINBKR_BREAK_LEN_Msk                              (0xfffU << UART_LINBKR_BREAK_LEN_Pos)
#define    UART_LINBKR_BREAK_LEN                                  UART_LINBKR_BREAK_LEN_Msk

#define    UART_CSR_BUSY_Pos                                      (24U)
#define    UART_CSR_BUSY_Msk                                      (0x1U << UART_CSR_BUSY_Pos)
#define    UART_CSR_BUSY                                          UART_CSR_BUSY_Msk

#define    UART_CSR_TXIREN_Pos                                    (17U)
#define    UART_CSR_TXIREN_Msk                                    (0x1U << UART_CSR_TXIREN_Pos)
#define    UART_CSR_TXIREN                                        UART_CSR_TXIREN_Msk

#define    UART_CSR_RXTOEN_Pos                                    (16U)
#define    UART_CSR_RXTOEN_Msk                                    (0x1U << UART_CSR_RXTOEN_Pos)
#define    UART_CSR_RXTOEN                                        UART_CSR_RXTOEN_Msk

#define    UART_CSR_CKOEN_Pos                                     (14U)
#define    UART_CSR_CKOEN_Msk                                     (0x1U << UART_CSR_CKOEN_Pos)
#define    UART_CSR_CKOEN                                         UART_CSR_CKOEN_Msk

#define    UART_CSR_OVSM_Pos                                      (13U)
#define    UART_CSR_OVSM_Msk                                      (0x1U << UART_CSR_OVSM_Pos)
#define    UART_CSR_OVSM                                          UART_CSR_OVSM_Msk

#define    UART_CSR_IOSWAP_Pos                                    (12U)
#define    UART_CSR_IOSWAP_Msk                                    (0x1U << UART_CSR_IOSWAP_Pos)
#define    UART_CSR_IOSWAP                                        UART_CSR_IOSWAP_Msk

#define    UART_CSR_NEWUP_Pos                                     (11U)
#define    UART_CSR_NEWUP_Msk                                     (0x1U << UART_CSR_NEWUP_Pos)
#define    UART_CSR_NEWUP                                         UART_CSR_NEWUP_Msk

#define    UART_CSR_DMATXIFCFG_Pos                                (10U)
#define    UART_CSR_DMATXIFCFG_Msk                                (0x1U << UART_CSR_DMATXIFCFG_Pos)
#define    UART_CSR_DMATXIFCFG                                    UART_CSR_DMATXIFCFG_Msk

#define    UART_CSR_BITORD_Pos                                    (9U)
#define    UART_CSR_BITORD_Msk                                    (0x1U << UART_CSR_BITORD_Pos)
#define    UART_CSR_BITORD                                        UART_CSR_BITORD_Msk

#define    UART_CSR_STOPCFG_Pos                                   (8U)
#define    UART_CSR_STOPCFG_Msk                                   (0x1U << UART_CSR_STOPCFG_Pos)
#define    UART_CSR_STOPCFG                                       UART_CSR_STOPCFG_Msk

#define    UART_CSR_PDSEL_Pos                                     (6U)
#define    UART_CSR_PDSEL_Msk                                     (0x3U << UART_CSR_PDSEL_Pos)
#define    UART_CSR_PDSEL                                         UART_CSR_PDSEL_Msk

#define    UART_CSR_PARITY_Pos                                    (4U)
#define    UART_CSR_PARITY_Msk                                    (0x3U << UART_CSR_PARITY_Pos)
#define    UART_CSR_PARITY                                        UART_CSR_PARITY_Msk

#define    UART_CSR_RXPOL_Pos                                     (3U)
#define    UART_CSR_RXPOL_Msk                                     (0x1U << UART_CSR_RXPOL_Pos)
#define    UART_CSR_RXPOL                                         UART_CSR_RXPOL_Msk

#define    UART_CSR_TXPOL_Pos                                     (2U)
#define    UART_CSR_TXPOL_Msk                                     (0x1U << UART_CSR_TXPOL_Pos)
#define    UART_CSR_TXPOL                                         UART_CSR_TXPOL_Msk

#define    UART_CSR_RXEN_Pos                                      (1U)
#define    UART_CSR_RXEN_Msk                                      (0x1U << UART_CSR_RXEN_Pos)
#define    UART_CSR_RXEN                                          UART_CSR_RXEN_Msk

#define    UART_CSR_TXEN_Pos                                      (0U)
#define    UART_CSR_TXEN_Msk                                      (0x1U << UART_CSR_TXEN_Pos)
#define    UART_CSR_TXEN                                          UART_CSR_TXEN_Msk

#define    UART_IER_TOERIE_Pos                                    (31U)
#define    UART_IER_TOERIE_Msk                                    (0x1U << UART_IER_TOERIE_Pos)
#define    UART_IER_TOERIE                                        UART_IER_TOERIE_Msk

#define    UART_IER_SERIE_Pos                                     (30U)
#define    UART_IER_SERIE_Msk                                     (0x1U << UART_IER_SERIE_Pos)
#define    UART_IER_SERIE                                         UART_IER_SERIE_Msk

#define    UART_IER_BERIE_Pos                                     (28U)
#define    UART_IER_BERIE_Msk                                     (0x1U << UART_IER_BERIE_Pos)
#define    UART_IER_BERIE                                         UART_IER_BERIE_Msk

#define    UART_IER_NFIE_Pos                                      (27U)
#define    UART_IER_NFIE_Msk                                      (0x1U << UART_IER_NFIE_Pos)
#define    UART_IER_NFIE                                          UART_IER_NFIE_Msk

#define    UART_IER_LINSYNCIE_Pos                                 (26U)
#define    UART_IER_LINSYNCIE_Msk                                 (0x1U << UART_IER_LINSYNCIE_Pos)
#define    UART_IER_LINSYNCIE                                     UART_IER_LINSYNCIE_Msk

#define    UART_IER_LINBIE_Pos                                    (25U)
#define    UART_IER_LINBIE_Msk                                    (0x1U << UART_IER_LINBIE_Pos)
#define    UART_IER_LINBIE                                        UART_IER_LINBIE_Msk

#define    UART_IER_LINWKIE_Pos                                   (24U)
#define    UART_IER_LINWKIE_Msk                                   (0x1U << UART_IER_LINWKIE_Pos)
#define    UART_IER_LINWKIE                                       UART_IER_LINWKIE_Msk

#define    UART_IER_LINWKTFIE_Pos                                 (23U)
#define    UART_IER_LINWKTFIE_Msk                                 (0x1U << UART_IER_LINWKTFIE_Pos)
#define    UART_IER_LINWKTFIE                                     UART_IER_LINWKTFIE_Msk

#define    UART_IER_LINBEFIE_Pos                                  (22U)
#define    UART_IER_LINBEFIE_Msk                                  (0x1U << UART_IER_LINBEFIE_Pos)
#define    UART_IER_LINBEFIE                                      UART_IER_LINBEFIE_Msk

#define    UART_IER_LINBERIE_Pos                                  (21U)
#define    UART_IER_LINBERIE_Msk                                  (0x1U << UART_IER_LINBERIE_Pos)
#define    UART_IER_LINBERIE                                      UART_IER_LINBERIE_Msk

#define    UART_IER_PERRIE_Pos                                    (18U)
#define    UART_IER_PERRIE_Msk                                    (0x1U << UART_IER_PERRIE_Pos)
#define    UART_IER_PERRIE                                        UART_IER_PERRIE_Msk

#define    UART_IER_FERRIE_Pos                                    (17U)
#define    UART_IER_FERRIE_Msk                                    (0x1U << UART_IER_FERRIE_Pos)
#define    UART_IER_FERRIE                                        UART_IER_FERRIE_Msk

#define    UART_IER_OERRIE_Pos                                    (16U)
#define    UART_IER_OERRIE_Msk                                    (0x1U << UART_IER_OERRIE_Pos)
#define    UART_IER_OERRIE                                        UART_IER_OERRIE_Msk

#define    UART_IER_RXTOIE_Pos                                    (11U)
#define    UART_IER_RXTOIE_Msk                                    (0x1U << UART_IER_RXTOIE_Pos)
#define    UART_IER_RXTOIE                                        UART_IER_RXTOIE_Msk

#define    UART_IER_RXERRIE_Pos                                   (10U)
#define    UART_IER_RXERRIE_Msk                                   (0x1U << UART_IER_RXERRIE_Pos)
#define    UART_IER_RXERRIE                                       UART_IER_RXERRIE_Msk

#define    UART_IER_RXBFIE_Pos                                    (8U)
#define    UART_IER_RXBFIE_Msk                                    (0x1U << UART_IER_RXBFIE_Pos)
#define    UART_IER_RXBFIE                                        UART_IER_RXBFIE_Msk

#define    UART_IER_NEWUPIE_Pos                                   (7U)
#define    UART_IER_NEWUPIE_Msk                                   (0x1U << UART_IER_NEWUPIE_Pos)
#define    UART_IER_NEWUPIE                                       UART_IER_NEWUPIE_Msk

#define    UART_IER_TXBEIE_Pos                                    (1U)
#define    UART_IER_TXBEIE_Msk                                    (0x1U << UART_IER_TXBEIE_Pos)
#define    UART_IER_TXBEIE                                        UART_IER_TXBEIE_Msk

#define    UART_IER_TXSEIE_Pos                                    (0U)
#define    UART_IER_TXSEIE_Msk                                    (0x1U << UART_IER_TXSEIE_Pos)
#define    UART_IER_TXSEIE                                        UART_IER_TXSEIE_Msk

#define    UART_ISR_TOER_Pos                                      (31U)
#define    UART_ISR_TOER_Msk                                      (0x1U << UART_ISR_TOER_Pos)
#define    UART_ISR_TOER                                          UART_ISR_TOER_Msk

#define    UART_ISR_SER_Pos                                       (30U)
#define    UART_ISR_SER_Msk                                       (0x1U << UART_ISR_SER_Pos)
#define    UART_ISR_SER                                           UART_ISR_SER_Msk

#define    UART_ISR_BER_Pos                                       (28U)
#define    UART_ISR_BER_Msk                                       (0x1U << UART_ISR_BER_Pos)
#define    UART_ISR_BER                                           UART_ISR_BER_Msk

#define    UART_ISR_NF_Pos                                        (27U)
#define    UART_ISR_NF_Msk                                        (0x1U << UART_ISR_NF_Pos)
#define    UART_ISR_NF                                            UART_ISR_NF_Msk

#define    UART_ISR_LINSYNCF_Pos                                  (26U)
#define    UART_ISR_LINSYNCF_Msk                                  (0x1U << UART_ISR_LINSYNCF_Pos)
#define    UART_ISR_LINSYNCF                                      UART_ISR_LINSYNCF_Msk

#define    UART_ISR_LINBF_Pos                                     (25U)
#define    UART_ISR_LINBF_Msk                                     (0x1U << UART_ISR_LINBF_Pos)
#define    UART_ISR_LINBF                                         UART_ISR_LINBF_Msk

#define    UART_ISR_LINWKDF_Pos                                   (24U)
#define    UART_ISR_LINWKDF_Msk                                   (0x1U << UART_ISR_LINWKDF_Pos)
#define    UART_ISR_LINWKDF                                       UART_ISR_LINWKDF_Msk

#define    UART_ISR_LINWKTF_Pos                                   (23U)
#define    UART_ISR_LINWKTF_Msk                                   (0x1U << UART_ISR_LINWKTF_Pos)
#define    UART_ISR_LINWKTF                                       UART_ISR_LINWKTF_Msk

#define    UART_ISR_LINBEF_Pos                                    (22U)
#define    UART_ISR_LINBEF_Msk                                    (0x1U << UART_ISR_LINBEF_Pos)
#define    UART_ISR_LINBEF                                        UART_ISR_LINBEF_Msk

#define    UART_ISR_LINBER_Pos                                    (21U)
#define    UART_ISR_LINBER_Msk                                    (0x1U << UART_ISR_LINBER_Pos)
#define    UART_ISR_LINBER                                        UART_ISR_LINBER_Msk

#define    UART_ISR_PERR_Pos                                      (18U)
#define    UART_ISR_PERR_Msk                                      (0x1U << UART_ISR_PERR_Pos)
#define    UART_ISR_PERR                                          UART_ISR_PERR_Msk

#define    UART_ISR_FERR_Pos                                      (17U)
#define    UART_ISR_FERR_Msk                                      (0x1U << UART_ISR_FERR_Pos)
#define    UART_ISR_FERR                                          UART_ISR_FERR_Msk

#define    UART_ISR_OERR_Pos                                      (16U)
#define    UART_ISR_OERR_Msk                                      (0x1U << UART_ISR_OERR_Pos)
#define    UART_ISR_OERR                                          UART_ISR_OERR_Msk

#define    UART_ISR_RXTO_Pos                                      (11U)
#define    UART_ISR_RXTO_Msk                                      (0x1U << UART_ISR_RXTO_Pos)
#define    UART_ISR_RXTO                                          UART_ISR_RXTO_Msk

#define    UART_ISR_RXBF_Pos                                      (8U)
#define    UART_ISR_RXBF_Msk                                      (0x1U << UART_ISR_RXBF_Pos)
#define    UART_ISR_RXBF                                          UART_ISR_RXBF_Msk

#define    UART_ISR_NEWKF_Pos                                     (7U)
#define    UART_ISR_NEWKF_Msk                                     (0x1U << UART_ISR_NEWKF_Pos)
#define    UART_ISR_NEWKF                                         UART_ISR_NEWKF_Msk

#define    UART_ISR_TXOERR_Pos                                    (2U)
#define    UART_ISR_TXOERR_Msk                                    (0x1U << UART_ISR_TXOERR_Pos)
#define    UART_ISR_TXOERR                                        UART_ISR_TXOERR_Msk

#define    UART_ISR_TXBE_Pos                                      (1U)
#define    UART_ISR_TXBE_Msk                                      (0x1U << UART_ISR_TXBE_Pos)
#define    UART_ISR_TXBE                                          UART_ISR_TXBE_Msk

#define    UART_ISR_TXSE_Pos                                      (0U)
#define    UART_ISR_TXSE_Msk                                      (0x1U << UART_ISR_TXSE_Pos)
#define    UART_ISR_TXSE                                          UART_ISR_TXSE_Msk

#define    UART_TODR_TXDLY_LEN_Pos                                (8U)
#define    UART_TODR_TXDLY_LEN_Msk                                (0xffU << UART_TODR_TXDLY_LEN_Pos)
#define    UART_TODR_TXDLY_LEN                                    UART_TODR_TXDLY_LEN_Msk

#define    UART_TODR_RXTO_LEN_Pos                                 (0U)
#define    UART_TODR_RXTO_LEN_Msk                                 (0xffU << UART_TODR_RXTO_LEN_Pos)
#define    UART_TODR_RXTO_LEN                                     UART_TODR_RXTO_LEN_Msk

#define    UART_FFCR_ERSW_Pos                                      (9U)
#define    UART_FFCR_ERSW_Msk                                      (0x3U << UART_FFCR_ERSW_Pos)
#define    UART_FFCR_ERSW                                          UART_FFCR_ERSW_Msk

#define    UART_FFCR_ERSGD_Pos                                     (8U)
#define    UART_FFCR_ERSGD_Msk                                     (0x1U << UART_FFCR_ERSGD_Pos)
#define    UART_FFCR_ERSGD                                         UART_FFCR_ERSGD_Msk

#define    UART_FFCR_BGTEN_Pos                                     (7U)
#define    UART_FFCR_BGTEN_Msk                                     (0x1U << UART_FFCR_BGTEN_Pos)
#define    UART_FFCR_BGTEN                                         UART_FFCR_BGTEN_Msk

#define    UART_FFCR_REP_T_Pos                                     (6U)
#define    UART_FFCR_REP_T_Msk                                     (0x1U << UART_FFCR_REP_T_Pos)
#define    UART_FFCR_REP_T                                         UART_FFCR_REP_T_Msk

#define    UART_FFCR_PAR_Pos                                       (4U)
#define    UART_FFCR_PAR_Msk                                       (0x3U << UART_FFCR_PAR_Pos)
#define    UART_FFCR_PAR                                           UART_FFCR_PAR_Msk

#define    UART_FFCR_RFREN_Pos                                     (3U)
#define    UART_FFCR_RFREN_Msk                                     (0x1U << UART_FFCR_RFREN_Pos)
#define    UART_FFCR_RFREN                                         UART_FFCR_RFREN_Msk

#define    UART_FFCR_TREPEN_Pos                                    (2U)
#define    UART_FFCR_TREPEN_Msk                                    (0x1U << UART_FFCR_TREPEN_Pos)
#define    UART_FFCR_TREPEN                                        UART_FFCR_TREPEN_Msk

#define    UART_FFCR_RREPEN_Pos                                    (1U)
#define    UART_FFCR_RREPEN_Msk                                    (0x1U << UART_FFCR_RREPEN_Pos)
#define    UART_FFCR_RREPEN                                        UART_FFCR_RREPEN_Msk

#define    UART_FFCR_DICONV_Pos                                    (0U)
#define    UART_FFCR_DICONV_Msk                                    (0x1U << UART_FFCR_DICONV_Pos)
#define    UART_FFCR_DICONV                                        UART_FFCR_DICONV_Msk

#define    UART_SCIER_RXIE_Pos                                    (2U)
#define    UART_SCIER_RXIE_Msk                                    (0x1U << UART_SCIER_RXIE_Pos)
#define    UART_SCIER_RXIE                                        UART_SCIER_RXIE_Msk

#define    UART_SCIER_TXIE_Pos                                    (1U)
#define    UART_SCIER_TXIE_Msk                                    (0x1U << UART_SCIER_TXIE_Pos)
#define    UART_SCIER_TXIE                                        UART_SCIER_TXIE_Msk

#define    UART_SCIER_LSIE_Pos                                    (0U)
#define    UART_SCIER_LSIE_Msk                                    (0x1U << UART_SCIER_LSIE_Pos)
#define    UART_SCIER_LSIE                                        UART_SCIER_LSIE_Msk

#define    UART_SCISR_WAIT_RPT_Pos                                (18U)
#define    UART_SCISR_WAIT_RPT_Msk                                (0x1U << UART_SCISR_WAIT_RPT_Pos)
#define    UART_SCISR_WAIT_RPT                                    UART_SCISR_WAIT_RPT_Msk

#define    UART_SCISR_TXBUSY_Pos                                  (17U)
#define    UART_SCISR_TXBUSY_Msk                                  (0x1U << UART_SCISR_TXBUSY_Pos)
#define    UART_SCISR_TXBUSY                                      UART_SCISR_TXBUSY_Msk

#define    UART_SCISR_RXBUSY_Pos                                  (16U)
#define    UART_SCISR_RXBUSY_Msk                                  (0x1U << UART_SCISR_RXBUSY_Pos)
#define    UART_SCISR_RXBUSY                                      UART_SCISR_RXBUSY_Msk

#define    UART_SCISR_TPARERR_Pos                                 (11U)
#define    UART_SCISR_TPARERR_Msk                                 (0x1U << UART_SCISR_TPARERR_Pos)
#define    UART_SCISR_TPARERR                                     UART_SCISR_TPARERR_Msk

#define    UART_SCISR_RPARERR_Pos                                 (10U)
#define    UART_SCISR_RPARERR_Msk                                 (0x1U << UART_SCISR_RPARERR_Pos)
#define    UART_SCISR_RPARERR                                     UART_SCISR_RPARERR_Msk

#define    UART_SCISR_FRERR_Pos                                   (9U)
#define    UART_SCISR_FRERR_Msk                                   (0x1U << UART_SCISR_FRERR_Pos)
#define    UART_SCISR_FRERR                                       UART_SCISR_FRERR_Msk

#define    UART_SCISR_OVERR_Pos                                   (8U)
#define    UART_SCISR_OVERR_Msk                                   (0x1U << UART_SCISR_OVERR_Pos)
#define    UART_SCISR_OVERR                                       UART_SCISR_OVERR_Msk

#define    UART_SCISR_RXIF_Pos                                    (2U)
#define    UART_SCISR_RXIF_Msk                                    (0x1U << UART_SCISR_RXIF_Pos)
#define    UART_SCISR_RXIF                                        UART_SCISR_RXIF_Msk

#define    UART_SCISR_TXIF_Pos                                    (1U)
#define    UART_SCISR_TXIF_Msk                                    (0x1U << UART_SCISR_TXIF_Pos)
#define    UART_SCISR_TXIF                                        UART_SCISR_TXIF_Msk

#define    UART_SCISR_ERRIF_Pos                                   (0U)
#define    UART_SCISR_ERRIF_Msk                                   (0x1U << UART_SCISR_ERRIF_Pos)
#define    UART_SCISR_ERRIF                                       UART_SCISR_ERRIF_Msk


#define    FL_UART_INFRARED_POLARITY_NORMAL                       (0x0U << UART_IRCR_IRFLAG_Pos)
#define    FL_UART_INFRARED_POLARITY_INVERT                       (0x1U << UART_IRCR_IRFLAG_Pos)

#define    FL_UART_UART_MODESEL_FULL_DUPLEX                       (0x0U << UART_MCR_HDSEL_Pos)
#define    FL_UART_UART_MODESEL_HALF_DUPLEX                       (0x1U << UART_MCR_HDSEL_Pos)

#define    FL_UART_LIN_MODESEL_MASTER                             (0x0U << UART_MCR_LINMD_Pos)
#define    FL_UART_LIN_MODESEL_SLAVE                              (0x1U << UART_MCR_LINMD_Pos)

#define    FL_UART_MODESEL_UART                                   (0x0U << UART_MCR_MODE_Pos)
#define    FL_UART_MODESEL_NON_UART                               (0x1U << UART_MCR_MODE_Pos)


#define    FL_UART_LIN_TRANSCONFLIC_MODE_CONTINUE                 (0x0U << UART_LINCR_BERS_Pos)
#define    FL_UART_LIN_TRANSCONFLIC_MODE_ABORT                    (0x1U << UART_LINCR_BERS_Pos)

#define    FL_UART_BER_MODE_NONE                                  (0x0U << UART_LINCR_BREM_Pos)
#define    FL_UART_BER_MODE_EN_BIT9                               (0x1U << UART_LINCR_BREM_Pos)
#define    FL_UART_BER_MODE_EN_BIT13                              (0x2U << UART_LINCR_BREM_Pos)

#define    FL_UART_OVERSAMPLING_16                                (0x0U << UART_CSR_OVSM_Pos)
#define    FL_UART_OVERSAMPLING_8                                 (0x1U << UART_CSR_OVSM_Pos)

#define    FL_UART_TXIF_MODE_ALWAYS                               (0x0U << UART_CSR_DMATXIFCFG_Pos)
#define    FL_UART_TXIF_MODE_AFTER_DMA                            (0x1U << UART_CSR_DMATXIFCFG_Pos)

#define    FL_UART_BIT_ORDER_LSB_FIRST                            (0x0U << UART_CSR_BITORD_Pos)
#define    FL_UART_BIT_ORDER_MSB_FIRST                            (0x1U << UART_CSR_BITORD_Pos)


#define    FL_UART_STOP_BIT_WIDTH_1B                              (0x0U << UART_CSR_STOPCFG_Pos)
#define    FL_UART_STOP_BIT_WIDTH_2B                              (0x1U << UART_CSR_STOPCFG_Pos)

#define    FL_UART_DATA_WIDTH_7B                                  (0x0U << UART_CSR_PDSEL_Pos)
#define    FL_UART_DATA_WIDTH_8B                                  (0x1U << UART_CSR_PDSEL_Pos)
#define    FL_UART_DATA_WIDTH_9B                                  (0x2U << UART_CSR_PDSEL_Pos)
#define    FL_UART_DATA_WIDTH_6B                                  (0x3U << UART_CSR_PDSEL_Pos)

#define    FL_UART_PARITY_NONE                                    (0x0U << UART_CSR_PARITY_Pos)
#define    FL_UART_PARITY_EVEN                                    (0x1U << UART_CSR_PARITY_Pos)
#define    FL_UART_PARITY_ODD                                     (0x2U << UART_CSR_PARITY_Pos)


#define    FL_UART_RX_POLARITY_NORMAL                             (0x0U << UART_CSR_RXPOL_Pos)
#define    FL_UART_RX_POLARITY_INVERT                             (0x1U << UART_CSR_RXPOL_Pos)


#define    FL_UART_TX_POLARITY_NORMAL                             (0x0U << UART_CSR_TXPOL_Pos)
#define    FL_UART_TX_POLARITY_INVERT                             (0x1U << UART_CSR_TXPOL_Pos)

#define    FL_UART_U7816_ERROR_SIGNAL_WIDTH_2ETU                  (0x1U << UART_FFCR_ERSW_Pos)
#define    FL_UART_U7816_ERROR_SIGNAL_WIDTH_1P5ETU                (0x2U << UART_FFCR_ERSW_Pos)
#define    FL_UART_U7816_ERROR_SIGNAL_WIDTH_1ETU                  (0x3U << UART_FFCR_ERSW_Pos)

#define    FL_UART_U7816_ERROR_GUARD_TIME_2ETU                    (0x0U << UART_FFCR_ERSGD_Pos)
#define    FL_UART_U7816_ERROR_GUARD_TIME_1ETU                    (0x1U << UART_FFCR_ERSGD_Pos)

#define    FL_UART_U7816_RETRY_COUNT_1                            (0x0U << UART_FFCR_REP_T_Pos)
#define    FL_UART_U7816_RETRY_COUNT_3                            (0x1U << UART_FFCR_REP_T_Pos)

#define    FL_UART_U7816_PARITY_SEL_EVEN                          (0x0U << UART_FFCR_PAR_Pos)
#define    FL_UART_U7816_PARITY_SEL_ODD                           (0x1U << UART_FFCR_PAR_Pos)
#define    FL_UART_U7816_PARITY_SEL_ALWAYS_1                      (0x2U << UART_FFCR_PAR_Pos)
#define    FL_UART_U7816_PARITY_SEL_NONE                          (0x3U << UART_FFCR_PAR_Pos)

#define    FL_UART_U7816_RX_GUARD_TIME_2ETU                       (0x0U << UART_FFCR_RFREN_Pos)
#define    FL_UART_U7816_RX_GUARD_TIME_1ETU                       (0x1U << UART_FFCR_RFREN_Pos)

#define    FL_UART_U7816_BIT_ORDER_LSB_FIRST                      (0x0U << UART_FFCR_DICONV_Pos)
#define    FL_UART_U7816_BIT_ORDER_MSB_FIRST                      (0x1U << UART_FFCR_DICONV_Pos)
/* UART end --------------------------------------------*/



/**
 * @brief  Function Declaration
 */
void SystemInit(void);


#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_FM33LR0XX_H */
