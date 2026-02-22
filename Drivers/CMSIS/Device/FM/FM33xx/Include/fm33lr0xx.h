/**************************************************************************************************** 
 * @file     FM33LR0XX.h
 *
 * @brief    CMSIS CORTEX-M0 Peripheral Access Layer Header File for
 *           FM33LR0XX from Keil.
 *
 * @version  V1.0.6
 * @date     08 August 2025
 *
 * @note     Generated with SVDConv V2.87e 
 *           from CMSIS SVD File 'FM33LR0XX.SVD' Version 1.0,
 *
 * @par      ARM Limited (ARM) is supplying this software for use with Cortex-M
 *           processor based microcontroller, but can be equally used for other
 *           suitable processor architectures. This file can be freely distributed.
 *           Modifications to this file shall be clearly marked.
 *
 *           THIS SOFTWARE IS PROVIDED “AS IS”. NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *           OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *           MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *           ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *           CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *******************************************************************************************************/


/** @addtogroup Keil
  * @{
  */

/** @addtogroup FM33LR0XX
  * @{
  */

#ifndef FM33LR0XX_H
#define FM33LR0XX_H

#ifdef __cplusplus
extern "C" {
#endif

#define __RCHF_INITIAL_CLOCK        (8000000)        /* Value of the Internal RC HIGH oscillator in Hz */
#define __RCLP_CLOCK                (32000)          /* Value of the Internal RC LOW oscillator in Hz */
#define __XTHF_CLOCK                (8000000)        /* Value of the EXTERNAL oscillator in Hz */
#define __XTLF_CLOCK                (32768)          /* Value of the EXTERNAL oscillator in Hz */


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {

/* ---------------------  CORTEX-M0 Processor Exceptions Numbers  --------------------- */
  Reset_IRQn                    = -15,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
  NMI_IRQn           			= -14,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = -13,              /*!<   3  Hard Fault, all classes of Fault                                 */
  SVCall_IRQn                   =  -5,              /*!<  11  System Service Call via SVC instruction                          */

  PendSV_IRQn                   =  -2,              /*!<  14  Pendable request for system service                              */
  SysTick_IRQn                  =  -1,              /*!<  15  System Tick Timer                                                */
/* --------------------  FM33LR0XX Specific Interrupt Numbers  -------------------- */
  WDT_IRQn                      =   0,              /*!<   0  WDT interrupt                                                    */
  SVD_IRQn                      =   1,              /*!<   1  SVD interrupt                                                    */
  MUX0_IRQn                     =   3,              /*!<   3  MUX0 interrupt                                                   */
  ADC_IRQn                      =   5,              /*!<   5  ADC interrupt                                                    */
  MUX1_IRQn                     =   7,              /*!<   7  MUX1 interrupt                                                   */
  MUX2_IRQn                     =   8,              /*!<   8  MUX2 interrupt                                                   */
  MUX3_IRQn                     =   9,              /*!<   9  MUX3 interrupt                                                   */
  MUX4_IRQn                     =  10,              /*!<  10  MUX4 interrupt                                                   */
  MUX5_IRQn                     =  11,              /*!<  11  MUX5 interrupt                                                   */
  MUX6_IRQn                     =  12,              /*!<  12  MUX6 interrupt                                                   */
  MUX7_IRQn                     =  13,              /*!<  13  MUX7 interrupt                                                   */
  MUX8_IRQn                     =  14,              /*!<  14  MUX8 interrupt                                                   */
  I2CMX_IRQn                    =  15,              /*!<  15  I2CMx interrupt                                                  */
  GPTIM_IRQn                    =  17,              /*!<  17  GPTIM interrupt                                                  */
  MUX9_IRQn                     =  18,              /*!<  18  MUX9 interrupt                                                   */
  LPTIM_IRQn                    =  20,              /*!<  20  LPTIM interrupt                                                  */
  DMA_IRQn                      =  21,              /*!<  21  DMA interrupt                                                    */
  WKUPX_IRQn                    =  22,              /*!<  22  WKUPx interrupt                                                  */
  MUX10_IRQn                    =  23,              /*!<  23  MUX10 interrupt                                                  */
  BSTIM_IRQn                    =  24,              /*!<  24  BSTIM interrupt                                                  */
  COMPX_IRQn                    =  25,              /*!<  25  COMPx interrupt                                                  */
  MUX11_IRQn                    =  26,              /*!<  26  MUX11 interrupt                                                  */
  MUX12_IRQn                    =  27,              /*!<  27  MUX12 interrupt                                                  */
  ATIM_IRQn                     =  28,              /*!<  28  ATIM interrupt                                                   */
  MUX13_IRQn                    =  29,              /*!<  29  MUX13 interrupt                                                  */
  GPIO_IRQn                     =  30,              /*!<  30  EXTI interrupt                                                   */
  ECCC_RAMP_FDET_IRQn           =  31               /*!<  31  ECCC_RAMP_FDET interrupt                                         */
} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the CORTEX-M0 Processor and Core Peripherals---------------- */
#define __CM0_REV                 0x0100            /*!< CORTEX-M0 Core Revision                                               */
#define __MPU_PRESENT                  0            /*!< MPU present or not                                                    */
#define __VTOR_PRESENT                 1            /*!< VTOR present or not                                                    */
#define __NVIC_PRIO_BITS               2            /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0            /*!< Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm0plus.h"                            /*!< Cortex-M0 processor and core peripherals */
#include "system_fm33lr0xx.h"                        /*!< FM33LR0XX System */

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */

/** @addtogroup Device_Peripheral_Registers
  * @{
  */

/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif



/* ================================================================================ */
/* ================                       ADC                      ================ */
/* ================================================================================ */


/**
  * @brief ADC module information (ADC)
  */

typedef struct {                                    /*!< ADC Structure                                                         */
  __IO uint32_t  ISR;                               /*!< ADC_ISR Register                                                      */
  __IO uint32_t  IER;                               /*!< ADC_IER Register                                                      */
  __IO uint32_t  CR1;                               /*!< ADC_CR1 Register                                                      */
  __IO uint32_t  CR2;                               /*!< ADC_CR2 Register                                                      */
  __IO uint32_t  CALCR;                             /*!< ADC_CALCR Register                                                    */
  __IO uint32_t  CFGR1;                             /*!< ADC_CFGR1 Register                                                    */
  __IO uint32_t  CFGR2;                             /*!< ADC_CFGR2 Register                                                    */
  __IO uint32_t  SMTR;                              /*!< ADC_SMTR Register                                                     */
  __IO uint32_t  CHER;                              /*!< ADC_CHER Register                                                     */
  __I  uint32_t  RESERVED;
  __IO uint32_t  DR;                                /*!< ADC_DR Register                                                       */
} ADC_Type;



/* ================================================================================ */
/* ================                      ATIM                      ================ */
/* ================================================================================ */


/**
  * @brief ATIM module information (ATIM)
  */

typedef struct {                                    /*!< ATIM Structure                                                        */
  __IO uint32_t  CR1;                               /*!< ATIM_CR1 Register                                                     */
  __IO uint32_t  CR2;                               /*!< ATIM_CR2 Register                                                     */
  __IO uint32_t  SMCR;                              /*!< ATIM_SMCR Register                                                    */
  __IO uint32_t  DIER;                              /*!< ATIM_DIER Register                                                    */
  __IO uint32_t  ISR;                               /*!< ATIM_ISR Register                                                     */
  __IO uint32_t  EGR;                               /*!< ATIM_EGR Register                                                     */
  __IO uint32_t  CCMR1;                             /*!< ATIM_CCMR1 Register                                                   */
  __IO uint32_t  CCMR2;                             /*!< ATIM_CCMR2 Register                                                   */
  __IO uint32_t  CCER;                              /*!< ATIM_CCER Register                                                    */
  __IO uint32_t  CNT;                               /*!< ATIM_CNT Register                                                     */
  __IO uint32_t  PSC;                               /*!< ATIM_PSC Register                                                     */
  __IO uint32_t  ARR;                               /*!< ATIM_ARR Register                                                     */
  __IO uint32_t  RCR;                               /*!< ATIM_RCR Register                                                     */
  __IO uint32_t  CCR1;                              /*!< ATIM_CCR1 Register                                                    */
  __IO uint32_t  CCR2;                              /*!< ATIM_CCR2 Register                                                    */
  __IO uint32_t  CCR3;                              /*!< ATIM_CCR3 Register                                                    */
  __IO uint32_t  CCR4;                              /*!< ATIM_CCR4 Register                                                    */
  __IO uint32_t  BDTR;                              /*!< ATIM_BDTR Register                                                    */
  __IO uint32_t  CCMR3;                             /*!< ATIM_CCMR3 Register                                                   */
  __IO uint32_t  CCR5;                              /*!< ATIM_CCR5 Register                                                    */
  __IO uint32_t  CCR6;                              /*!< ATIM_CCR6 Register                                                    */
  __IO uint32_t  ECR;                               /*!< ATIM_ECR Register                                                     */
  __IO uint32_t  TISEL;                             /*!< ATIM_TISEL Register                                                   */
  __IO uint32_t  AFR;                               /*!< ATIM_AFR Register                                                     */
  __IO uint32_t  BRKISR;                            /*!< ATIM_BRKISR Register                                                  */
  __I  uint32_t  RESERVED[37];
} ATIM_Type;


/* ================================================================================ */
/* ================                     BSTIM16                    ================ */
/* ================================================================================ */


/**
  * @brief BSTIM16 module information (BSTIM16)
  */

typedef struct {                                    /*!< BSTIM16 Structure                                                     */
  __IO uint32_t  CR1;                               /*!< BSTIM16_CR1 Register                                                  */
  __IO uint32_t  CR2;                               /*!< BSTIM16_CR2 Register                                                  */
  __I  uint32_t  RESERVED;
  __IO uint32_t  IER;                               /*!< BSTIM16_IER Register                                                  */
  __IO uint32_t  ISR;                               /*!< BSTIM16_ISR Register                                                  */
  __IO uint32_t  EGR;                               /*!< BSTIM16_EGR Register                                                  */
  __I  uint32_t  RESERVED1[3];
  __IO uint32_t  CNT;                               /*!< BSTIM16_CNT Register                                                  */
  __IO uint32_t  PSC;                               /*!< BSTIM16_PSC Register                                                  */
  __IO uint32_t  ARR;                               /*!< BSTIM16_ARR Register                                                  */
} BSTIM16_Type;


/* ================================================================================ */
/* ================                       CMU                      ================ */
/* ================================================================================ */


/**
  * @brief CMU module information (CMU)
  */

typedef struct {                                    /*!< CMU Structure                                                         */
  __IO uint32_t  SYSCLKCR;                          /*!< CMU_SYSCLKCR Register                                                 */
  __IO uint32_t  RCHFCR;                            /*!< CMU_RCHFCR Register                                                   */
  __IO uint32_t  RCHFTR;                            /*!< CMU_RCHFTR Register                                                   */
  __IO uint32_t  PLLCR;                             /*!< CMU_PLLCR Register                                                    */
  __I  uint32_t  RESERVED;
  __IO uint32_t  RCLPTR;                            /*!< CMU_RCLPTR Register                                                   */
  __I  uint32_t  RESERVED1[2];
  __IO uint32_t  XTHFCR;                            /*!< CMU_XTHFCR Register                                                   */
  __I  uint32_t  RESERVED2[2];
  __IO uint32_t  IER;                               /*!< CMU_IER Register                                                      */
  __IO uint32_t  ISR;                               /*!< CMU_ISR Register                                                      */
  __IO uint32_t  PCLKCR1;                           /*!< CMU_PCLKCR1 Register                                                  */
  __IO uint32_t  PCLKCR2;                           /*!< CMU_PCLKCR2 Register                                                  */
  __IO uint32_t  PCLKCR3;                           /*!< CMU_PCLKCR3 Register                                                  */
  __IO uint32_t  PCLKCR4;                           /*!< CMU_PCLKCR4 Register                                                  */
  __IO uint32_t  OPCCR1;                            /*!< CMU_OPCCR1 Register                                                   */
  __I  uint32_t  RESERVED3;
  __IO uint32_t  OPCCR3;                            /*!< CMU_OPCCR3 Register                                                   */
  __IO uint32_t  AHBMCR;                            /*!< CMU_AHBMCR Register                                                   */
} CMU_Type;


/* ================================================================================ */
/* ================                      COMP                      ================ */
/* ================================================================================ */


/**
  * @brief COMP module information (COMP)
  */

typedef struct {                                    /*!< COMP Structure                                                        */
  __IO uint32_t  CR;                                /*!< COMP_CR Register                                                      */
} COMP_Type;


/* ================================================================================ */
/* ================                   COMP_COMMON                  ================ */
/* ================================================================================ */


/**
  * @brief COMP_COMMON module information (COMP_COMMON)
  */

typedef struct {                                    /*!< COMP_COMMON Structure                                                 */
  __IO uint32_t  ICR;                               /*!< COMP_COMMON_ICR Register                                              */
  __IO uint32_t  ISR;                               /*!< COMP_COMMON_ISR Register                                              */
  __IO uint32_t  BUFCR;                             /*!< COMP_COMMON_BUFCR Register                                            */
} COMP_COMMON_Type;


/* ================================================================================ */
/* ================                       CRC                      ================ */
/* ================================================================================ */


/**
  * @brief CRC module information (CRC)
  */

typedef struct {                                    /*!< CRC Structure                                                         */
  __IO uint32_t  DR;                                /*!< CRC_DR Register                                                       */
  __IO uint32_t  CR;                                /*!< CRC_CR Register                                                       */
  __IO uint32_t  LFSR;                              /*!< CRC_LFSR Register                                                     */
  __IO uint32_t  XOR;                               /*!< CRC_XOR Register                                                      */
  __I  uint32_t  RESERVED[3];
  __IO uint32_t  POLY;                              /*!< CRC_POLY Register                                                     */
} CRC_Type;


/* ================================================================================ */
/* ================                       DBG                      ================ */
/* ================================================================================ */

typedef struct
{
  __IO uint32_t SYSCON;                            /*!<  Address offset: 0x00 */
  __IO uint32_t CR;                                /*!<  Address offset: 0x04 */
  __IO uint32_t HDFR;                              /*!<  Address offset: 0x08 */
}DBG_Type;



/* ================================================================================ */
/* ================                      DIVAS                     ================ */
/* ================================================================================ */


/**
  * @brief DIVAS module information (DIVAS)
  */

typedef struct {                                    /*!< DIVAS Structure                                                       */
  __IO uint32_t  END;                               /*!< DIVAS_END Register                                                    */
  __IO uint32_t  SOR;                               /*!< DIVAS_SOR Register                                                    */
  __IO uint32_t  QUOT;                              /*!< DIVAS_QUOT Register                                                   */
  __IO uint32_t  REMD;                              /*!< DIVAS_REMD Register                                                   */
  __IO uint32_t  SR;                                /*!< DIVAS_SR Register                                                     */
} DIVAS_Type;


/* ================================================================================ */
/* ================                       DMA                      ================ */
/* ================================================================================ */


/**
  * @brief DMA module information (DMA)
  */

typedef struct {                                    /*!< DMA Structure                                                         */
  __IO uint32_t  GCR;                               /*!< DMA_GCR Register                                                      */
  __IO uint32_t  CH0CR;                             /*!< DMA_CH0CR Register                                                    */
  __IO uint32_t  CH0MAR;                            /*!< DMA_CH0MAR Register                                                   */
  __IO uint32_t  CH1CR;                             /*!< DMA_CH1CR Register                                                    */
  __IO uint32_t  CH1MAR;                            /*!< DMA_CH1MAR Register                                                   */
  __I  uint32_t  RESERVED[10];
  __IO uint32_t  CH7CR;                             /*!< DMA_CH7CR Register                                                    */
  __IO uint32_t  CH7FLSAD;                          /*!< DMA_CH7FLSAD Register                                                 */
  __IO uint32_t  CH7RAMAD;                          /*!< DMA_CH7RAMAD Register                                                 */
  __IO uint32_t  ISR;                               /*!< DMA_ISR Register                                                      */
  __IO uint32_t  CH0TFSADDR;                        /*!< DMA_CH0TFSADDR Register                                               */
  __IO uint32_t  CH1TFSADDR;                        /*!< DMA_CH1TFSADDR Register                                               */
} DMA_Type;


/* ================================================================================ */
/* ================                       FLS                      ================ */
/* ================================================================================ */


/**
  * @brief FLS module information (FLS)
  */

typedef struct {                                    /*!< FLS Structure                                                         */
  __IO uint32_t  RDCR;                              /*!< FLS_RDCR Register                                                     */
  __IO uint32_t  PFTCON;                            /*!< FLS_PFTCON Register                                                   */
  __IO uint32_t  OPTBR;                             /*!< FLS_OPTBR Register                                                    */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  EPCR;                              /*!< FLS_EPCR Register                                                     */
  __IO uint32_t  KEY;                               /*!< FLS_KEY Register                                                      */
  __IO uint32_t  IER;                               /*!< FLS_IER Register                                                      */
  __IO uint32_t  ISR;                               /*!< FLS_ISR Register                                                      */
  __IO uint32_t  ERRIER;                            /*!< FLS_ERRIER Register                                                   */
  __IO uint32_t  ECCSR;                             /*!< FLS_ECCSR Register                                                    */
  __I  uint32_t  RESERVED1[13];
  __IO uint32_t  ACLOCK1;                           /*!< FLS_ACLOCK1 Register                                                  */
} FLASH_Type;


/* ================================================================================ */
/* ================                   GPIO_COMMON                  ================ */
/* ================================================================================ */


/**
  * @brief GPIO_COMMON module information (GPIO_COMMON)
  */

typedef struct {                                    /*!< GPIO_COMMON Structure                                                 */
  __IO uint32_t  EXTISEL0;                          /*!< EXTI_SEL0 Register                                                    */
  __IO uint32_t  EXTISEL1;                          /*!< EXTI_SEL1 Register                                                    */
  __IO uint32_t  EXTIEDS0;                          /*!< EXTI_EDS0 Register                                                    */
  __IO uint32_t  EXTIEDS1;                          /*!< EXTI_EDS1 Register                                                    */
  __IO uint32_t  EXTIDF;                            /*!< EXTI_DF Register                                                      */
  __IO uint32_t  EXTIISR;                           /*!< EXTI_ISR Register                                                     */
  __IO uint32_t  EXTIDI;                            /*!< EXTI_DI Register                                                      */
  __I  uint32_t  RESERVED[9];
  __IO uint32_t  FOUTSEL;                           /*!< FOUTSEL Register                                                      */
  __I  uint32_t  RESERVED1[63];
  __IO uint32_t  PINWKEN;                           /*!< PINWKEN Register                                                      */
} GPIO_COMMON_Type;


/* ================================================================================ */
/* ================                      GPIO                      ================ */
/* ================================================================================ */


/**
  * @brief GPIOA module information (GPIO)
  */

typedef struct {                                    /*!< GPIO Structure                                                        */
  __IO uint32_t  INEN;                              /*!< GPIO_INEN Register                                                    */
  __IO uint32_t  PUDEN;                             /*!< GPIO_PUDEN Register                                                   */
  __IO uint32_t  ODEN;                              /*!< GPIO_ODEN Register                                                    */
  __IO uint32_t  FCR;                               /*!< GPIO_FCR Register                                                     */
  __IO uint32_t  DO;                                /*!< GPIO_DO Register                                                      */
  __IO uint32_t  DSET;                              /*!< GPIO_DSET Register                                                    */
  __IO uint32_t  DRST;                              /*!< GPIO_DRST Register                                                    */
  __IO uint32_t  DIN;                               /*!< GPIO_DIN Register                                                     */
  __IO uint32_t  DFS;                               /*!< GPIO_DFS Register                                                     */
  __IO uint32_t  SRDR;                              /*!< GPIO_SRDR Register                                                    */
  __IO uint32_t  RESERVED[2];                       /*!<  RESERVED REGISTER,,                                                  */
  __IO uint32_t TMUXR;                              /*!<  GPIOC Timer Mux Register,                                            */
} GPIO_Type;


/* ================================================================================ */
/* ================                   GPIOC_TMUX                   ================ */
/* ================================================================================ */





/* ================================================================================ */
/* ================                      GPTIM                     ================ */
/* ================================================================================ */


/**
  * @brief GPTIM module information (GPTIM)
  */

typedef struct {                                    /*!< GPTIM Structure                                                       */
  __IO uint32_t  CR1;                               /*!< GPTIM_CR1 Register                                                    */
  __IO uint32_t  CR2;                               /*!< GPTIM_CR2 Register                                                    */
  __IO uint32_t  SMCR;                              /*!< GPTIM_SMCR Register                                                   */
  __IO uint32_t  DIER;                              /*!< GPTIM_DIER Register                                                   */
  __IO uint32_t  ISR;                               /*!< GPTIM_ISR Register                                                    */
  __IO uint32_t  EGR;                               /*!< GPTIM_EGR Register                                                    */
  __IO uint32_t  CCMR1;                             /*!< GPTIM_CCMR1 Register                                                  */
  __IO uint32_t  CCMR2;                             /*!< GPTIM_CCMR2 Register                                                  */
  __IO uint32_t  CCER;                              /*!< GPTIM_CCER Register                                                   */
  __IO uint32_t  CNT;                               /*!< GPTIM_CNT Register                                                    */
  __IO uint32_t  PSC;                               /*!< GPTIM_PSC Register                                                    */
  __IO uint32_t  ARR;                               /*!< GPTIM_ARR Register                                                    */
  __I  uint32_t  RESERVED;
  __IO uint32_t  CCR1;                              /*!< GPTIM_CCR1 Register                                                   */
  __IO uint32_t  CCR2;                              /*!< GPTIM_CCR2 Register                                                   */
  __IO uint32_t  CCR3;                              /*!< GPTIM_CCR3 Register                                                   */
  __IO uint32_t  CCR4;                              /*!< GPTIM_CCR4 Register                                                   */
  __I  uint32_t  RESERVED1[4];
  __IO uint32_t  ECR;                               /*!< GPTIM_ECR Register                                                    */
  __IO uint32_t  TISEL;                             /*!< GPTIM_TISEL Register                                                  */
  __IO uint32_t  AFR;                               /*!< GPTIM_AFR Register                                                    */
  __I  uint32_t  RESERVED2[38];
} GPTIM_Type;


/* ================================================================================ */
/* ================                       I2C                      ================ */
/* ================================================================================ */


/**
  * @brief I2C0 module information (I2C)
  */

typedef struct {                                    /*!< I2C Structure                                                         */
  __IO uint32_t  MSPCFGR;                           /*!< I2C_MSPCFGR Register                                                  */
  __IO uint32_t  MSPCR;                             /*!< I2C_MSPCR Register                                                    */
  __IO uint32_t  MSPIER;                            /*!< I2C_MSPIER Register                                                   */
  __IO uint32_t  MSPISR;                            /*!< I2C_MSPISR Register                                                   */
  __IO uint32_t  MSPSR;                             /*!< I2C_MSPSR Register                                                    */
  __IO uint32_t  MSPBGR;                            /*!< I2C_MSPBGR Register                                                   */
  __IO uint32_t  MSPBUF;                            /*!< I2C_MSPBUF Register                                                   */
  __IO uint32_t  MSPTCR;                            /*!< I2C_MSPTCR Register                                                   */
  __IO uint32_t  MSPTOR;                            /*!< I2C_MSPTOR Register                                                   */
} I2C_Type;


/* ================================================================================ */
/* ================                     INTMUX                     ================ */
/* ================================================================================ */


/**
  * @brief INTMUX module information (INTMUX)
  */

typedef struct {                                    /*!< INTMUX Structure                                                      */
  __IO uint32_t  CR;                                /*!< INTMUX_CR Register                                                    */
} INTMUX_Type;


/* ================================================================================ */
/* ================                      IWDT                      ================ */
/* ================================================================================ */


/**
  * @brief IWDT module information (IWDT)
  */

typedef struct {                                    /*!< IWDT Structure                                                        */
  __IO uint32_t  SERV;                              /*!< IWDT_SERV Register                                                    */
  __IO uint32_t  CR;                                /*!< IWDT_CR Register                                                      */
  __IO uint32_t  CNT;                               /*!< IWDT_CNT Register                                                     */
  __IO uint32_t  WIN;                               /*!< IWDT_WIN Register                                                     */
  __IO uint32_t  IER;                               /*!< IWDT_IER Register                                                     */
  __IO uint32_t  ISR;                               /*!< IWDT_ISR Register                                                     */
} IWDT_Type;


/* ================================================================================ */
/* ================                     LPTIM16                    ================ */
/* ================================================================================ */


/**
  * @brief LPTIM16 module information (LPTIM16)
  */

typedef struct {                                    /*!< LPTIM16 Structure                                                     */
  __IO uint32_t  CFGR;                              /*!< LPTIM16_CFGR Register                                                 */
  __IO uint32_t  CNT;                               /*!< LPTIM16_CNT Register                                                  */
  __IO uint32_t  CCSR;                              /*!< LPTIM16_CCSR Register                                                 */
  __IO uint32_t  ARR;                               /*!< LPTIM16_ARR Register                                                  */
  __IO uint32_t  IER;                               /*!< LPTIM16_IER Register                                                  */
  __IO uint32_t  ISR;                               /*!< LPTIM16_ISR Register                                                  */
  __IO uint32_t  CR;                                /*!< LPTIM16_CR Register                                                   */
  __I  uint32_t  RESERVED;
  __IO uint32_t  CCR1;                              /*!< LPTIM16_CCR1 Register                                                 */
  __IO uint32_t  CCR2;                              /*!< LPTIM16_CCR2 Register                                                 */
} LPTIM16_Type;


/* ================================================================================ */
/* ================                       PGL                      ================ */
/* ================================================================================ */


/**
  * @brief PGL module information (PGL)
  */

typedef struct {                                    /*!< PGL Structure                                                         */
  __IO uint32_t  CR;                                /*!< PGL_CR Register                                                       */
  __IO uint32_t  CFGR0;                             /*!< PGL_CFGR0 Register                                                    */
  __IO uint32_t  CFGR1;                             /*!< PGL_CFGR1 Register                                                    */
  __IO uint32_t  CFGR2;                             /*!< PGL_CFGR2 Register                                                    */
  __IO uint32_t  CFGR3;                             /*!< PGL_CFGR3 Register                                                    */
  __IO uint32_t  IER;                               /*!< PGL_IER Register                                                      */
  __IO uint32_t  ISR;                               /*!< PGL_ISR Register                                                      */
  __IO uint32_t  LUT0;                              /*!< PGL_LUT0 Register                                                     */
  __IO uint32_t  LUT1;                              /*!< PGL_LUT1 Register                                                     */
  __IO uint32_t  LUT2;                              /*!< PGL_LUT2 Register                                                     */
  __IO uint32_t  LUT3;                              /*!< PGL_LUT3 Register                                                     */
} PGL_Type;


/* ================================================================================ */
/* ================                       PMU                      ================ */
/* ================================================================================ */


/**
  * @brief PMU module information (PMU)
  */

typedef struct {                                    /*!< PMU Structure                                                         */
  __IO uint32_t  CR;                                /*!< PMU_CR Register                                                       */
  __IO uint32_t  WKTR;                              /*!< PMU_WKTR Register                                                     */
  __IO uint32_t  WKFR;                              /*!< PMU_WKFR Register                                                     */
  __IO uint32_t  IER;                               /*!< PMU_IER Register                                                      */
  __IO uint32_t  ISR;                               /*!< PMU_ISR Register                                                      */
  __I  uint32_t  RESERVED[10];
  __IO uint32_t  BUFCR;                             /*!< PMU_BUFCR Register                                                    */
  __I  uint32_t  RESERVED1[4];
  __IO uint32_t  PTATCR;                            /*!< PMU_PTAT_CR Register                                                  */
} PMU_Type;





/* ================================================================================ */
/* ================                       RMU                      ================ */
/* ================================================================================ */


/**
  * @brief RMU module information (RMU)
  */

typedef struct {                                    /*!< RMU Structure                                                         */
  __I  uint32_t  RESERVED;
  __IO uint32_t  BORCR;                             /*!< RMU_BORCR Register                                                    */
  __IO uint32_t  LKPCR;                             /*!< RMU_LKPCR Register                                                    */
  __IO uint32_t  SOFTRST;                           /*!< RMU_SOFTRST Register                                                  */
  __IO uint32_t  RSTFR;                             /*!< RMU_RSTFR Register                                                    */
  __IO uint32_t  PRSTEN;                            /*!< RMU_PRSTEN Register                                                   */
  __IO uint32_t  AHBRSTCR;                          /*!< RMU_AHBRSTCR Register                                                 */
  __IO uint32_t  APBRSTCR1;                         /*!< RMU_APBRSTCR1 Register                                                */
  __IO uint32_t  APBRSTCR2;                         /*!< RMU_APBRSTCR2 Register                                                */
} RMU_Type;




/* ================================================================================ */
/* ================                       SFU                      ================ */
/* ================================================================================ */


/**
  * @brief SFU module information (SFU)
  */

typedef struct {                                    /*!< SFU Structure                                                         */
  __IO uint32_t  RAMPCR;                            /*!< SFU_RAMP_CR Register                                                  */
  __IO uint32_t  RAMPSR;                            /*!< SFU_RAMP_SR Register                                                  */
  __IO uint32_t  MAPCR;                             /*!< SFU_MAP_CR Register                                                   */
  __IO uint32_t  MAPSR;                             /*!< SFU_MAP_SR Register                                                   */
  __IO uint32_t  BKR;                               /*!< SFU_BKR Register                                                      */
} SFU_Type;


/* ================================================================================ */
/* ================                       SPI                      ================ */
/* ================================================================================ */


/**
  * @brief SPI0 module information (SPI)
  */

typedef struct {                                    /*!< SPI Structure                                                         */
  __IO uint32_t  CR1;                               /*!< SPI_CR1 Register                                                      */
  __IO uint32_t  CR2;                               /*!< SPI_CR2 Register                                                      */
  __IO uint32_t  CR3;                               /*!< SPI_CR3 Register                                                      */
  __IO uint32_t  IER;                               /*!< SPI_IER Register                                                      */
  __IO uint32_t  ISR;                               /*!< SPI_ISR Register                                                      */
  __IO uint32_t  TXBUF;                             /*!< SPI_TXBUF Register                                                    */
  __IO uint32_t  RXBUF;                             /*!< SPI_RXBUF Register                                                    */
} SPI_Type;


/* ================================================================================ */
/* ================                       SVD                      ================ */
/* ================================================================================ */


/**
  * @brief SVD module information (SVD)
  */

typedef struct {                                    /*!< SVD Structure                                                         */
  __IO uint32_t  CFGR;                              /*!< SVD_CFGR Register                                                     */
  __IO uint32_t  CR;                                /*!< SVD_CR Register                                                       */
  __IO uint32_t  IER;                               /*!< SVD_IER Register                                                      */
  __IO uint32_t  ISR;                               /*!< SVD_ISR Register                                                      */
  __IO uint32_t  VSR;                               /*!< SVD_VSR Register                                                      */
} SVD_Type;


/* ================================================================================ */
/* ================                      TAU0                      ================ */
/* ================================================================================ */


/**
  * @brief TAU0 module information (TAU0)
  */

typedef struct {                                    /*!< TAU0 Structure                                                        */
  __IO uint32_t  T0CFGR;                            /*!< TAU0_T0CFGR Register                                                  */
  __IO uint32_t  T1CFGR;                            /*!< TAU0_T1CFGR Register                                                  */
  __IO uint32_t  T2CFGR;                            /*!< TAU0_T2CFGR Register                                                  */
  __IO uint32_t  T3CFGR;                            /*!< TAU0_T3CFGR Register                                                  */
  __IO uint32_t  T4CFGR;                            /*!< TAU0_T4CFGR Register                                                  */
  __IO uint32_t  T5CFGR;                            /*!< TAU0_T5CFGR Register                                                  */
  __IO uint32_t  T6CFGR;                            /*!< TAU0_T6CFGR Register                                                  */
  __IO uint32_t  T7CFGR;                            /*!< TAU0_T7CFGR Register                                                  */
  __IO uint32_t  T0MDR;                             /*!< TAU0_T0MDR Register                                                   */
  __IO uint32_t  T1MDR;                             /*!< TAU0_T1MDR Register                                                   */
  __IO uint32_t  T2MDR;                             /*!< TAU0_T2MDR Register                                                   */
  __IO uint32_t  T3MDR;                             /*!< TAU0_T3MDR Register                                                   */
  __IO uint32_t  T4MDR;                             /*!< TAU0_T4MDR Register                                                   */
  __IO uint32_t  T5MDR;                             /*!< TAU0_T5MDR Register                                                   */
  __IO uint32_t  T6MDR;                             /*!< TAU0_T6MDR Register                                                   */
  __IO uint32_t  T7MDR;                             /*!< TAU0_T7MDR Register                                                   */
  __IO uint32_t  T0ARR;                             /*!< TAU0_T0ARR Register                                                   */
  __IO uint32_t  T1ARR;                             /*!< TAU0_T1ARR Register                                                   */
  __IO uint32_t  T2ARR;                             /*!< TAU0_T2ARR Register                                                   */
  __IO uint32_t  T3ARR;                             /*!< TAU0_T3ARR Register                                                   */
  __IO uint32_t  T4ARR;                             /*!< TAU0_T4ARR Register                                                   */
  __IO uint32_t  T5ARR;                             /*!< TAU0_T5ARR Register                                                   */
  __IO uint32_t  T6ARR;                             /*!< TAU0_T6ARR Register                                                   */
  __IO uint32_t  T7ARR;                             /*!< TAU0_T7ARR Register                                                   */
  __IO uint32_t  T0CCR;                             /*!< TAU0_T0CCR Register                                                   */
  __IO uint32_t  T1CCR;                             /*!< TAU0_T1CCR Register                                                   */
  __IO uint32_t  T2CCR;                             /*!< TAU0_T2CCR Register                                                   */
  __IO uint32_t  T3CCR;                             /*!< TAU0_T3CCR Register                                                   */
  __IO uint32_t  T4CCR;                             /*!< TAU0_T4CCR Register                                                   */
  __IO uint32_t  T5CCR;                             /*!< TAU0_T5CCR Register                                                   */
  __IO uint32_t  T6CCR;                             /*!< TAU0_T6CCR Register                                                   */
  __IO uint32_t  T7CCR;                             /*!< TAU0_T7CCR Register                                                   */
  __IO uint32_t  T0IER;                             /*!< TAU0_T0IER Register                                                   */
  __IO uint32_t  T1IER;                             /*!< TAU0_T1IER Register                                                   */
  __IO uint32_t  T2IER;                             /*!< TAU0_T2IER Register                                                   */
  __IO uint32_t  T3IER;                             /*!< TAU0_T3IER Register                                                   */
  __IO uint32_t  T4IER;                             /*!< TAU0_T4IER Register                                                   */
  __IO uint32_t  T5IER;                             /*!< TAU0_T5IER Register                                                   */
  __IO uint32_t  T6IER;                             /*!< TAU0_T6IER Register                                                   */
  __IO uint32_t  T7IER;                             /*!< TAU0_T7IER Register                                                   */
  __IO uint32_t  T0ISR;                             /*!< TAU0_T0ISR Register                                                   */
  __IO uint32_t  T1ISR;                             /*!< TAU0_T1ISR Register                                                   */
  __IO uint32_t  T2ISR;                             /*!< TAU0_T2ISR Register                                                   */
  __IO uint32_t  T3ISR;                             /*!< TAU0_T3ISR Register                                                   */
  __IO uint32_t  T4ISR;                             /*!< TAU0_T4ISR Register                                                   */
  __IO uint32_t  T5ISR;                             /*!< TAU0_T5ISR Register                                                   */
  __IO uint32_t  T6ISR;                             /*!< TAU0_T6ISR Register                                                   */
  __IO uint32_t  T7ISR;                             /*!< TAU0_T7ISR Register                                                   */
  __IO uint32_t  T0CNTR;                            /*!< TAU0_T0CNTR Register                                                  */
  __IO uint32_t  T1CNTR;                            /*!< TAU0_T1CNTR Register                                                  */
  __IO uint32_t  T2CNTR;                            /*!< TAU0_T2CNTR Register                                                  */
  __IO uint32_t  T3CNTR;                            /*!< TAU0_T3CNTR Register                                                  */
  __IO uint32_t  T4CNTR;                            /*!< TAU0_T4CNTR Register                                                  */
  __IO uint32_t  T5CNTR;                            /*!< TAU0_T5CNTR Register                                                  */
  __IO uint32_t  T6CNTR;                            /*!< TAU0_T6CNTR Register                                                  */
  __IO uint32_t  T7CNTR;                            /*!< TAU0_T7CNTR Register                                                  */
} TAU0_Type;


/* ================================================================================ */
/* ================                      TAU1                      ================ */
/* ================================================================================ */


/**
  * @brief TAU1 module information (TAU1)
  */

typedef struct {                                    /*!< TAU1 Structure                                                        */
  __IO uint32_t  T0CFGR;                            /*!< TAU1_T0CFGR Register                                                  */
  __IO uint32_t  T1CFGR;                            /*!< TAU1_T1CFGR Register                                                  */
  __IO uint32_t  T2CFGR;                            /*!< TAU1_T2CFGR Register                                                  */
  __IO uint32_t  T3CFGR;                            /*!< TAU1_T3CFGR Register                                                  */
  __IO uint32_t  T0MDR;                             /*!< TAU1_T0MDR Register                                                   */
  __IO uint32_t  T1MDR;                             /*!< TAU1_T1MDR Register                                                   */
  __IO uint32_t  T2MDR;                             /*!< TAU1_T2MDR Register                                                   */
  __IO uint32_t  T3MDR;                             /*!< TAU1_T3MDR Register                                                   */
  __IO uint32_t  T0ARR;                             /*!< TAU1_T0ARR Register                                                   */
  __IO uint32_t  T1ARR;                             /*!< TAU1_T1ARR Register                                                   */
  __IO uint32_t  T2ARR;                             /*!< TAU1_T2ARR Register                                                   */
  __IO uint32_t  T3ARR;                             /*!< TAU1_T3ARR Register                                                   */
  __IO uint32_t  T0CCR;                             /*!< TAU1_T0CCR Register                                                   */
  __IO uint32_t  T1CCR;                             /*!< TAU1_T1CCR Register                                                   */
  __IO uint32_t  T2CCR;                             /*!< TAU1_T2CCR Register                                                   */
  __IO uint32_t  T3CCR;                             /*!< TAU1_T3CCR Register                                                   */
  __IO uint32_t  T0IER;                             /*!< TAU1_T0IER Register                                                   */
  __IO uint32_t  T1IER;                             /*!< TAU1_T1IER Register                                                   */
  __IO uint32_t  T2IER;                             /*!< TAU1_T2IER Register                                                   */
  __IO uint32_t  T3IER;                             /*!< TAU1_T3IER Register                                                   */
  __IO uint32_t  T0ISR;                             /*!< TAU1_T0ISR Register                                                   */
  __IO uint32_t  T1ISR;                             /*!< TAU1_T1ISR Register                                                   */
  __IO uint32_t  T2ISR;                             /*!< TAU1_T2ISR Register                                                   */
  __IO uint32_t  T3ISR;                             /*!< TAU1_T3ISR Register                                                   */
  __IO uint32_t  T0CNTR;                            /*!< TAU1_T0CNTR Register                                                  */
  __IO uint32_t  T1CNTR;                            /*!< TAU1_T1CNTR Register                                                  */
  __IO uint32_t  T2CNTR;                            /*!< TAU1_T2CNTR Register                                                  */
  __IO uint32_t  T3CNTR;                            /*!< TAU1_T3CNTR Register                                                  */
} TAU1_Type;


/* ================================================================================ */
/* ================                   TAU_COMMON                   ================ */
/* ================================================================================ */


/**
  * @brief TAU_COMMON module information (TAU_COMMON)
  */

typedef struct {                                    /*!< TAU_COMMON Structure                                                  */
  __IO uint32_t  TAU0CR;                            /*!< TAU0_CR Register                                                      */
  __IO uint32_t  TAU1CR;                            /*!< TAU1_CR Register                                                      */
  __IO uint32_t  TAU0EGR;                           /*!< TAU0_EGR Register                                                     */
  __IO uint32_t  TAU1EGR;                           /*!< TAU1_EGR Register                                                     */
} TAU_COMMON_Type;


/* ================================================================================ */
/* ================                      UARTL                     ================ */
/* ================================================================================ */


/**
  * @brief UART module information (UART)
  */

typedef struct {                                    /*!< UARTL Structure                                                       */
  __IO uint32_t  CSR;                               /*!< UARTL_CSR Register                                                    */
  __IO uint32_t  IER;                               /*!< UARTL_IER Register                                                    */
  __IO uint32_t  ISR;                               /*!< UARTL_ISR Register                                                    */
  __IO uint32_t  TODR;                              /*!< UARTL_TODR Register                                                   */
  __IO uint32_t  RXBUF;                             /*!< UARTL_RXBUF Register                                                  */
  __IO uint32_t  TXBUF;                             /*!< UARTL_TXBUF Register                                                  */
  __IO uint32_t  BGR;                               /*!< UARTL_BGR Register                                                    */
  __I  uint32_t  RESERVED;
  __IO uint32_t  MCR;                               /*!< UARTL_MCR Register                                                    */
  __IO uint32_t  LINCR;                             /*!< UARTL_LINCR Register                                                  */
  __IO uint32_t  LINBSR;                            /*!< UARTL_LINBSR Register                                                 */
  __IO uint32_t  LINFTR;                            /*!< UARTL_LINFTR Register                                                 */
  __IO uint32_t  LINTTR;                            /*!< UARTL_LINTTR Register                                                 */
  __IO uint32_t  LINPSR;                            /*!< UARTL_LINPSR Register                                                 */
  __IO uint32_t  LINBKR;                            /*!< UARTL_LINBKR Register                                                 */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  SCISR;                             /*!< USART_SCISR Register                                                  */
  __IO uint32_t  SCIER;                             /*!< USART_SCIER Register                                                  */
  __IO uint32_t  FFCR;                              /*!< USART_FFCR Register                                                   */
  __IO uint32_t  EGTR;                              /*!< USART_EGTR Register                                                   */
  __IO uint32_t  CODR;                              /*!< USART_CODR Register                                                   */
} UART_Type;


/* ================================================================================ */
/* ================                   UART_COMMON                  ================ */
/* ================================================================================ */


/**
  * @brief UART_COMMON module information (UART_COMMON)
  */

typedef struct {                                    /*!< UART_COMMON Structure                                                 */
  __IO uint32_t  IRCR;                              /*!< UART_COMMON_IRCR Register                                             */
} UART_COMMON_Type;


/* ================================================================================ */
/* ================                      WWDT                      ================ */
/* ================================================================================ */


/**
  * @brief WWDT module information (WWDT)
  */

typedef struct {                                    /*!< WWDT Structure                                                        */
  __IO uint32_t  CR;                                /*!< WWDT_CR Register                                                      */
  __IO uint32_t  CFGR;                              /*!< WWDT_CFGR Register                                                    */
  __IO uint32_t  CNT;                               /*!< WWDT_CNT Register                                                     */
  __IO uint32_t  IER;                               /*!< WWDT_IER Register                                                     */
  __IO uint32_t  ISR;                               /*!< WWDT_ISR Register                                                     */
  __IO uint32_t  PSC;                               /*!< WWDT_PSC Register                                                     */
} WWDT_Type;





/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif




/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define ADC_BASE                        0x4001AC00UL
#define ATIM_BASE                       0x4001B000UL
#define BSTIM16_BASE                    0x4001B400UL
#define CMU_BASE                        0x40002400UL
#define COMP1_BASE                      0x40019C00UL
#define COMPCOMMON_BASE                 0x40019C0CUL
#define CRC_BASE                        0x40018000UL
#define DBG_BASE                        0x40000000UL
#define DIVAS_BASE                      0x40013000UL
#define DMA_BASE                        0x40000400UL
#define FLASH_BASE                      0x40001000UL
#define GPIOCOMMON_BASE                 0x40000DC0UL
#define GPIOA_BASE                      0x40000C00UL
#define GPIOB_BASE                      0x40000C40UL
#define GPIOC_BASE                      0x40000C80UL
#define GPIOD_BASE                      0x40000CC0UL
#define GPIOE_BASE                      0x40000D00UL
#define GPTIM_BASE                      0x40014C00UL
#define I2C0_BASE                       0x40015000UL
#define I2C1_BASE                       0x40015400UL
#define INTMUX_BASE                     0x40016000UL
#define IWDT_BASE                       0x40011400UL
#define LPTIM16_BASE                    0x40013400UL
#define PGL_BASE                        0x40013800UL
#define PMU_BASE                        0x40002000UL
#define RMU_BASE                        0x40002800UL
#define SFU_BASE                        0x40001C00UL
#define SPI0_BASE                       0x40019000UL
#define SPI1_BASE                       0x40018C00UL
#define SVD_BASE                        0x4001A800UL
#define TAU0_BASE                       0x40013C10UL
#define TAU1_BASE                       0x40013CF0UL
#define TAUCOMMON_BASE                  0x40013C00UL
#define UART1_BASE                      0x40012000UL
#define UART2_BASE                      0x40017400UL
#define UART4_BASE                      0x4001A000UL
#define UART5_BASE                      0x4001A400UL
#define UARTCOMMON_BASE                 0x40017C00UL
#define WWDT_BASE                       0x40011800UL


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */
#define ADC                             ((ADC_Type          *) ADC_BASE         )
#define ATIM                            ((ATIM_Type         *) ATIM_BASE        )
#define BSTIM16                         ((BSTIM16_Type      *) BSTIM16_BASE     )
#define CMU                             ((CMU_Type          *) CMU_BASE         )
#define COMP1                           ((COMP_Type         *) COMP1_BASE       )
#define COMP                            ((COMP_COMMON_Type  *) COMPCOMMON_BASE  )
#define CRC                             ((CRC_Type          *) CRC_BASE         )
#define DBG                             ((DBG_Type          *) DBG_BASE         )
#define DIVAS                           ((DIVAS_Type        *) DIVAS_BASE       )
#define DMA                             ((DMA_Type          *) DMA_BASE         )
#define FLASH                           ((FLASH_Type        *) FLASH_BASE       )
#define GPIO                            ((GPIO_COMMON_Type  *) GPIOCOMMON_BASE  )
#define GPIOA                           ((GPIO_Type         *) GPIOA_BASE       )
#define GPIOB                           ((GPIO_Type         *) GPIOB_BASE       )
#define GPIOC                           ((GPIO_Type         *) GPIOC_BASE       )
#define GPIOD                           ((GPIO_Type         *) GPIOD_BASE       )
#define GPIOE                           ((GPIO_Type         *) GPIOE_BASE       )
#define GPTIM                           ((GPTIM_Type        *) GPTIM_BASE       )
#define I2C0                            ((I2C_Type          *) I2C0_BASE        )
#define I2C1                            ((I2C_Type          *) I2C1_BASE        )
#define INTMUX                          ((INTMUX_Type       *) INTMUX_BASE      )
#define IWDT                            ((IWDT_Type         *) IWDT_BASE        )
#define LPTIM16                         ((LPTIM16_Type      *) LPTIM16_BASE     )
#define PGL                             ((PGL_Type          *) PGL_BASE         )
#define PMU                             ((PMU_Type          *) PMU_BASE         )
#define RMU                             ((RMU_Type          *) RMU_BASE         )
#define SFU                             ((SFU_Type          *) SFU_BASE         )
#define SPI0                            ((SPI_Type          *) SPI0_BASE        )
#define SPI1                            ((SPI_Type          *) SPI1_BASE        )
#define SVD                             ((SVD_Type          *) SVD_BASE         )
#define TAU0                            ((TAU0_Type         *) TAU0_BASE        )
#define TAU1                            ((TAU1_Type         *) TAU1_BASE        )
#define TAU                             ((TAU_COMMON_Type   *) TAUCOMMON_BASE   )
#define UART1                           ((UART_Type         *) UART1_BASE       )
#define UART2                           ((UART_Type         *) UART2_BASE       )
#define UART4                           ((UART_Type         *) UART4_BASE       )
#define UART5                           ((UART_Type         *) UART5_BASE       )
#define UART                            ((UART_COMMON_Type  *) UARTCOMMON_BASE )
#define WWDT                            ((WWDT_Type         *) WWDT_BASE        )


/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group FM33LR0XX */
/** @} */ /* End of group Keil */

#ifdef __cplusplus
}
#endif

#endif  /* FM33LR0XX_H */

