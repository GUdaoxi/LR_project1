/**
  *******************************************************************************************************
  * @file    fm33lr0xx_fl_adc.h
  * @author  FMSH Application Team
  * @brief   Head file of ADC FL Module
  * @version  V1.0.7
  * @date     20 October 2025
  ****************************************************************************************************
  * @attention
  * Copyright 2024 SHANGHAI FUDAN MICROELECTRONICS GROUP CO., LTD.(FUDAN MICRO.)
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met: 
  *
  * 1. Redistributions of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  *
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  *
  * 3. Neither the name of the copyright holder nor the names of its contributors
  *    may be used to endorse or promote products derived from this software without
  *    specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS"AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ****************************************************************************************************
  */


/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33LR0XX_FL_ADC_H
#define __FM33LR0XX_FL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33lr0xx_fl_def.h"
/** @addtogroup FM33LR0XX_FL_Driver
  * @{
  */

/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_ES_INIT ADC Exported Init structures
  * @{
  */
#define ADC_VREF    (*((uint16_t *)(0x1FFFFD0C)))    /*  vref1P0电压值（*10000） */
#define ADC_TS      (*((uint16_t *)(0x1FFFFD10)))    /*  PTAT电压值（*10000） */

/**
  * @brief FL ADC Init Sturcture definition
  */
typedef struct
{
    /** ADC工作时钟源选择 */
    uint32_t clockSource;
    /** ADCCLK预分频配置 */
    uint32_t clockPrescaler;
    /** ADC基准源选择 */
    uint32_t referenceSource;
    /** ADC数据位选择 */
    uint32_t bitWidth;

} FL_ADC_CommonInitTypeDef;

typedef struct
{
    /** 连续转换模式配置 */
    uint32_t conversionMode;
    /** 单次自动转换模式配置 */
    uint32_t autoMode;
    /** 等待模式配置 */
    FL_FunState waitMode;
    /** 覆盖模式配置 */
    FL_FunState overrunMode;
    /** 通道扫描顺序配置 */
    uint32_t scanDirection;
    /** 触发信号使能配置 */
    uint32_t externalTrigConv;
    /** 触发源选择 */
    uint32_t triggerSource;
    /** 通道采样时间配置 */
    uint32_t ChannelSamplingTime;
    /** 过采样使能配置 */
    FL_FunState oversamplingMode;
    /** 过采样率配置 */
    uint32_t overSampingMultiplier;
    /** 过采样移位配置 */
    uint32_t oversamplingShift;

} FL_ADC_InitTypeDef;

/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_Exported_Constants ADC Exported Constants
  * @{
  */

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

#define    FL_ADC_CH_SAMPLING_TIME_2_ADCCLK                       (0x0U << ADC_SMTR_SMTS_Pos)
#define    FL_ADC_CH_SAMPLING_TIME_4_ADCCLK                       (0x1U << ADC_SMTR_SMTS_Pos)
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

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_Exported_Functions ADC Exported Functions
  * @{
  */

/**
  * @brief    Get ADC End Of Conversion Flag
  * @rmtoll   ISR    EOC    FL_ADC_IsActiveFlag_EndOfConversion
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_EndOfConversion(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_EOC_Msk) == (ADC_ISR_EOC_Msk));
}

/**
  * @brief    Clear ADC End Of Conversion Flag
  * @rmtoll   ISR    EOC    FL_ADC_ClearFlag_EndOfConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_EndOfConversion(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_EOC_Msk);
}

/**
  * @brief    Get ADC End Of Sequence Flag
  * @rmtoll   ISR    EOS    FL_ADC_IsActiveFlag_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_EndOfSequence(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_EOS_Msk) == (ADC_ISR_EOS_Msk));
}

/**
  * @brief    Clear ADC End Of Sequence Flag
  * @rmtoll   ISR    EOS    FL_ADC_ClearFlag_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_EndOfSequence(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_EOS_Msk);
}

/**
  * @brief    Get ADC Data Overrun Flag
  * @rmtoll   ISR    OVR    FL_ADC_IsActiveFlag_Overrun
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Overrun(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_OVR_Msk) == (ADC_ISR_OVR_Msk));
}

/**
  * @brief    Get ADC RDY Flag
  * @rmtoll   ISR    RDY    FL_ADC_IsActiveFlag_Ready
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Ready(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_RDY_Msk) == (ADC_ISR_RDY_Msk));
}

/**
  * @brief    Clear ADC  Data Overrun Flag
  * @rmtoll   ISR    OVR    FL_ADC_ClearFlag_Overrun
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_Overrun(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_OVR_Msk);
}

/**
  * @brief    Get ADC Busy Flag
  * @rmtoll   ISR    BUSY    FL_ADC_IsActiveFlag_Busy
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Busy(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_BUSY_Msk) == (ADC_ISR_BUSY_Msk));
}

/**
  * @brief    Get ADC End Of Calibration Flag
  * @rmtoll   ISR    EOCAL    FL_ADC_IsActiveFlag_EndOfCalibration
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_EndOfCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ISR, ADC_ISR_EOCAL_Msk) == (ADC_ISR_EOCAL_Msk));
}

/**
  * @brief    Clear ADC End Of Calibration Flag
  * @rmtoll   ISR    EOCAL    FL_ADC_ClearFlag_EndOfCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_EndOfCalibration(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->ISR, ADC_ISR_EOCAL_Msk);
}

/**
  * @brief    Enable ADC End 0f Conversion interrupt
  * @rmtoll   IER    EOCIE    FL_ADC_EnableIT_EndOfConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_EndOfConversion(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_EOCIE_Msk);
}

/**
  * @brief    Disable ADC End 0f Conversion interrupt
  * @rmtoll   IER    EOCIE    FL_ADC_DisableIT_EndOfConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_EndOfConversion(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_EOCIE_Msk);
}

/**
  * @brief    Get ADC End 0f Conversion interrupt Enable Status
  * @rmtoll   IER    EOCIE    FL_ADC_IsEnabledIT_EndOfConversion
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_EndOfConversion(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_EOCIE_Msk) == ADC_IER_EOCIE_Msk);
}

/**
  * @brief    Enable ADC End Of Sequence interrupt
  * @rmtoll   IER    EOSIE    FL_ADC_EnableIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_EndOfSequence(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_EOSIE_Msk);
}

/**
  * @brief    Disable ADC End Of Sequence interrupt
  * @rmtoll   IER    EOSIE    FL_ADC_DisableIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_EndOfSequence(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_EOSIE_Msk);
}

/**
  * @brief    Get ADC End Of Sequence interrupt Enable Status
  * @rmtoll   IER    EOSIE    FL_ADC_IsEnabledIT_EndOfSequence
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_EndOfSequence(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_EOSIE_Msk) == ADC_IER_EOSIE_Msk);
}

/**
  * @brief    Enable ADC Data Overrun interrupt
  * @rmtoll   IER    OVRIE    FL_ADC_EnableIT_Overrun
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_Overrun(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_OVRIE_Msk);
}

/**
  * @brief    Disable ADC Data Overrun interrupt
  * @rmtoll   IER    OVRIE    FL_ADC_DisableIT_Overrun
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_Overrun(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_OVRIE_Msk);
}

/**
  * @brief    Get ADC Data Overrun interrupt Enable Status
  * @rmtoll   IER    OVRIE    FL_ADC_IsEnabledIT_Overrun
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_Overrun(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_OVRIE_Msk) == ADC_IER_OVRIE_Msk);
}

/**
  * @brief    Enable ADC End Of Calibration interrupt
  * @rmtoll   IER    EOCALIE    FL_ADC_EnableIT_EndOfCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_EndOfCalibration(ADC_Type *ADCx)
{
    SET_BIT(ADCx->IER, ADC_IER_EOCALIE_Msk);
}

/**
  * @brief    Disable ADC End Of Calibration interrupt
  * @rmtoll   IER    EOCALIE    FL_ADC_DisableIT_EndOfCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_EndOfCalibration(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->IER, ADC_IER_EOCALIE_Msk);
}

/**
  * @brief    Get ADC End Of Calibration interrupt Enable Status
  * @rmtoll   IER    EOCALIE    FL_ADC_IsEnabledIT_EndOfCalibration
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_EndOfCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->IER, ADC_IER_EOCALIE_Msk) == ADC_IER_EOCALIE_Msk);
}


/**
  * @brief    Enable ADC
  * @rmtoll   CR1    ADEN    FL_ADC_Enable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Enable(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Disable ADC
  * @rmtoll   CR1    ADEN    FL_ADC_Disable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Disable(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Get ADC Enable Status
  * @rmtoll   CR1    ADEN    FL_ADC_IsEnabled
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabled(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk) == ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Enable ADC Sofeware Triggered Conversion
  * @rmtoll   CR1    SWTRIG    FL_ADC_EnableSWConversion
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableSWConversion(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_SWTRIG_Msk);
}

/**
  * @brief    Set ADC Trigger Edge
  * @rmtoll   CR2    TRGCFG    FL_ADC_SetTriggerEdge
  * @param    ADCx ADC instance
  * @param    edge This parameter can be one of the following values:
  *           @arg @ref FL_ADC_TRIGGER_EDGE_NONE
  *           @arg @ref FL_ADC_TRIGGER_EDGE_RISING
  *           @arg @ref FL_ADC_TRIGGER_EDGE_FALLING
  *           @arg @ref FL_ADC_TRIGGER_EDGE_BOTH
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetTriggerEdge(ADC_Type *ADCx, uint32_t edge)
{
    MODIFY_REG(ADCx->CR2, ADC_CR2_TRGCFG_Msk, edge);
}

/**
  * @brief    Read ADC Trigger Edge
  * @rmtoll   CR2    TRGCFG    FL_ADC_GetTriggerEdge
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_TRIGGER_EDGE_NONE
  *           @arg @ref FL_ADC_TRIGGER_EDGE_RISING
  *           @arg @ref FL_ADC_TRIGGER_EDGE_FALLING
  *           @arg @ref FL_ADC_TRIGGER_EDGE_BOTH
  */
__STATIC_INLINE uint32_t FL_ADC_GetTriggerEdge(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_TRGCFG_Msk));
}

/**
  * @brief    Enable ADC Calibration
  * @rmtoll   CALR    CALEN    FL_ADC_EnableCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableCalibration(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CALCR, ADC_CALCR_CALEN_Msk);
}

/**
  * @brief    Disable ADC Calibration
  * @rmtoll   CALR    CALEN    FL_ADC_DisableCalibration
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableCalibration(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CALCR, ADC_CALCR_CALEN_Msk);
}

/**
  * @brief    Get ADC Calibration Enable Status
  * @rmtoll   CALR    CALEN    FL_ADC_IsEnabledCalibration
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CALCR, ADC_CALCR_CALEN_Msk) == ADC_CALCR_CALEN_Msk);
}

/**
  * @brief    Set ADC APBCLK Prescaler
  * @rmtoll   CFGR1    APBCLK_PSC    FL_ADC_SetAPBPrescaler
  * @param    ADCx ADC instance
  * @param    psc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV1
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV2
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV4
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV8
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV3
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV6
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV5
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetAPBPrescaler(ADC_Type *ADCx, uint32_t psc)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_APBCLK_PSC_Msk, psc);
}

/**
  * @brief    Read ADC APBCLK Prescaler
  * @rmtoll   CFGR1    APBCLK_PSC    FL_ADC_GetAPBPrescaler
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV1
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV2
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV4
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV8
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV3
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV6
  *           @arg @ref FL_ADC_APBCLK_PSC_DIV5
  */
__STATIC_INLINE uint32_t FL_ADC_GetAPBPrescaler(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_APBCLK_PSC_Msk));
}

/**
  * @brief    Enable ADC DMA
  * @rmtoll   CFGR2    DMAEN    FL_ADC_EnableDMAReq
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableDMAReq(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Disable ADC DMA
  * @rmtoll   CFGR2    DMAEN    FL_ADC_DisableDMAReq
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableDMAReq(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Get ADC DMA Enable Status
  * @rmtoll   CFGR2    DMAEN    FL_ADC_IsEnabledDMAReq
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledDMAReq(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk) == ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Set ADC Channel Scan Direction
  * @rmtoll   CFGR2    SCANDIR    FL_ADC_SetSequenceScanDirection
  * @param    ADCx ADC instance
  * @param    dir This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SEQ_SCAN_DIR_FORWARD
  *           @arg @ref FL_ADC_SEQ_SCAN_DIR_BACKWARD
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSequenceScanDirection(ADC_Type *ADCx, uint32_t dir)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_SCANDIR_Msk, dir);
}

/**
  * @brief    Get ADC Channel Scan Direction
  * @rmtoll   CFGR2    SCANDIR    FL_ADC_GetSequenceScanDirection
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SEQ_SCAN_DIR_FORWARD
  *           @arg @ref FL_ADC_SEQ_SCAN_DIR_BACKWARD
  */
__STATIC_INLINE uint32_t FL_ADC_GetSequenceScanDirection(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_SCANDIR_Msk));
}

/**
  * @brief    Set ADC Trigger Source
  * @rmtoll   CFGR2    EXTS    FL_ADC_SetTriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_TRGI_LUT0
  *           @arg @ref FL_ADC_TRGI_LUT1
  *           @arg @ref FL_ADC_TRGI_LUT2
  *           @arg @ref FL_ADC_TRGI_TAU01
  *           @arg @ref FL_ADC_TRGI_BSTIM16
  *           @arg @ref FL_ADC_TRGI_LPTIM16
  *           @arg @ref FL_ADC_TRGI_COMP1
  *           @arg @ref FL_ADC_TRGI_COMP2
  *           @arg @ref FL_ADC_TRGI_RTCA
  *           @arg @ref FL_ADC_TRGI_LUT3
  *           @arg @ref FL_ADC_TRGI_TAU00
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetTriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_EXTS_Msk, source);
}

/**
  * @brief    Get ADC Trigger Source
  * @rmtoll   CFGR2    EXTS    FL_ADC_GetTriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_TRGI_LUT0
  *           @arg @ref FL_ADC_TRGI_LUT1
  *           @arg @ref FL_ADC_TRGI_LUT2
  *           @arg @ref FL_ADC_TRGI_TAU01
  *           @arg @ref FL_ADC_TRGI_BSTIM16
  *           @arg @ref FL_ADC_TRGI_LPTIM16
  *           @arg @ref FL_ADC_TRGI_COMP1
  *           @arg @ref FL_ADC_TRGI_COMP2
  *           @arg @ref FL_ADC_TRGI_RTCA
  *           @arg @ref FL_ADC_TRGI_LUT3
  *           @arg @ref FL_ADC_TRGI_TAU00
  */
__STATIC_INLINE uint32_t FL_ADC_GetTriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_EXTS_Msk));
}

/**
  * @brief    Enable ADC Overrun Mode
  * @rmtoll   CFGR2    OVRM    FL_ADC_EnableOverrunMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableOverrunMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Disable ADC Overrun Mode
  * @rmtoll   CFGR2    OVRM    FL_ADC_DisableOverrunMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableOverrunMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Get ADC Overrun Mode Enable Status
  * @rmtoll   CFGR2    OVRM    FL_ADC_IsEnabledOverrunMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledOverrunMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk) == ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Set ADC Conversion Mode
  * @rmtoll   CFGR2    CONT    FL_ADC_SetConversionMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_CONV_MODE_SINGLE
  *           @arg @ref FL_ADC_CONV_MODE_CONTINUOUS
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetConversionMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_CONT_Msk, mode);
}

/**
  * @brief    Get ADC Conversion Mode
  * @rmtoll   CFGR2    CONT    FL_ADC_GetConversionMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_CONV_MODE_SINGLE
  *           @arg @ref FL_ADC_CONV_MODE_CONTINUOUS
  */
__STATIC_INLINE uint32_t FL_ADC_GetConversionMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_CONT_Msk));
}

/**
  * @brief    Enable ADC Wait Mode
  * @rmtoll   CFGR2    WAIT    FL_ADC_EnableWaitMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableWaitMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_Msk);
}

/**
  * @brief    Disable ADC Wait Mode
  * @rmtoll   CFGR2    WAIT    FL_ADC_DisableWaitMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableWaitMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_Msk);
}

/**
  * @brief    Get ADC Wait Mode Enable Status
  * @rmtoll   CFGR2    WAIT    FL_ADC_IsEnabledWaitMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledWaitMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_Msk) == ADC_CFGR2_WAIT_Msk);
}

/**
  * @brief    Set ADC Single Conversion Mode
  * @rmtoll   CFGR2    SEMI    FL_ADC_SetSingleConversionAutoMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SINGLE_CONV_MODE_AUTO
  *           @arg @ref FL_ADC_SINGLE_CONV_MODE_SEMIAUTO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetSingleConversionAutoMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_SEMI_Msk, mode);
}

/**
  * @brief    Get ADC Single Conversion Mode
  * @rmtoll   CFGR2    SEMI    FL_ADC_GetSingleConversionAutoMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SINGLE_CONV_MODE_AUTO
  *           @arg @ref FL_ADC_SINGLE_CONV_MODE_SEMIAUTO
  */
__STATIC_INLINE uint32_t FL_ADC_GetSingleConversionAutoMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_SEMI_Msk));
}

/**
  * @brief    Enable ADC Trigger Filter
  * @rmtoll   CFGR2    IOTRFEN    FL_ADC_EnableTriggerFilter
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableTriggerFilter(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_IOTRFEN_Msk);
}

/**
  * @brief    Disable ADC Trigger Filter
  * @rmtoll   CFGR2    IOTRFEN    FL_ADC_DisableTriggerFilter
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableTriggerFilter(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_IOTRFEN_Msk);
}

/**
  * @brief    Get ADC Trigger Filter Enable Status
  * @rmtoll   CFGR2    IOTRFEN    FL_ADC_IsEnabledTriggerFilter
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledTriggerFilter(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_IOTRFEN_Msk) == ADC_CFGR2_IOTRFEN_Msk);
}

/**
  * @brief    Enable ADC OverSampling
  * @rmtoll   CFGR2    OVSEN    FL_ADC_EnableOverSampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableOverSampling(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_OVSEN_Msk);
}

/**
  * @brief    Disable ADC OverSampling
  * @rmtoll   CFGR2    OVSEN    FL_ADC_DisableOverSampling
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableOverSampling(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_OVSEN_Msk);
}

/**
  * @brief    Get ADC OverSampling Enable Status
  * @rmtoll   CFGR2    OVSEN    FL_ADC_IsEnabledOverSampling
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledOverSampling(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVSEN_Msk) == ADC_CFGR2_OVSEN_Msk);
}

/**
  * @brief    Set ADC OverSampling Multiplier
  * @rmtoll   CFGR2    OVSR    FL_ADC_SetOverSamplingMultiplier
  * @param    ADCx ADC instance
  * @param    mul This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_16X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_32X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_64X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_128X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_256X
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingMultiplier(ADC_Type *ADCx, uint32_t mul)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_OVSR_Msk, mul);
}

/**
  * @brief    Read ADC OverSampling Multiplier
  * @rmtoll   CFGR2    OVSR    FL_ADC_GetOverSamplingMultiplier
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_16X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_32X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_64X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_128X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_256X
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingMultiplier(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVSR_Msk));
}

/**
  * @brief    Set ADC OverSampling Shift
  * @rmtoll   CFGR2    OVSS    FL_ADC_SetOverSamplingShift
  * @param    ADCx ADC instance
  * @param    shift This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_0B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_1B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_2B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_3B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_4B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_5B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_6B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_7B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_8B
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingShift(ADC_Type *ADCx, uint32_t shift)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_OVSS_Msk, shift);
}

/**
  * @brief    Read ADC OverSampling Shift
  * @rmtoll   CFGR2    OVSS    FL_ADC_GetOverSamplingShift
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_0B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_1B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_2B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_3B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_4B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_5B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_6B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_7B
  *           @arg @ref FL_ADC_OVERSAMPLING_SHIFT_8B
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingShift(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVSS_Msk));
}


/**
  * @brief    Set ADC Channel Sampling Time
  * @rmtoll   SMTR    SMTS    FL_ADC_SetSlowChannelSamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_384_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetChannelSamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->SMTR, ADC_SMTR_SMTS_Msk, time);
}

/**
  * @brief    Read ADC Channel Sampling Time
  * @rmtoll   SMTR    SMTS    FL_ADC_GetSlowChannelSamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_384_ADCCLK
  *           @arg @ref FL_ADC_CH_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GetChannelSamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SMTR, ADC_SMTR_SMTS_Msk));
}

/**
  * @brief    Enable ADC Channel
  * @rmtoll   CHER        FL_ADC_EnableSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_EXTERNAL_CH0
  *           @arg @ref FL_ADC_EXTERNAL_CH1
  *           @arg @ref FL_ADC_EXTERNAL_CH2
  *           @arg @ref FL_ADC_EXTERNAL_CH3
  *           @arg @ref FL_ADC_EXTERNAL_CH4
  *           @arg @ref FL_ADC_EXTERNAL_CH5
  *           @arg @ref FL_ADC_EXTERNAL_CH6
  *           @arg @ref FL_ADC_EXTERNAL_CH7
  *           @arg @ref FL_ADC_EXTERNAL_CH8
  *           @arg @ref FL_ADC_EXTERNAL_CH9
  *           @arg @ref FL_ADC_EXTERNAL_CH10
  *           @arg @ref FL_ADC_EXTERNAL_CH11
  *           @arg @ref FL_ADC_EXTERNAL_CH12
  *           @arg @ref FL_ADC_EXTERNAL_CH13
  *           @arg @ref FL_ADC_EXTERNAL_CH14
  *           @arg @ref FL_ADC_EXTERNAL_CH15
  *           @arg @ref FL_ADC_EXTERNAL_CH16
  *           @arg @ref FL_ADC_INTERNAL_TS
  *           @arg @ref FL_ADC_INTERNAL_AVREF
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    SET_BIT(ADCx->CHER, ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable ADC Channel
  * @rmtoll   CHER        FL_ADC_DisableSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_EXTERNAL_CH0
  *           @arg @ref FL_ADC_EXTERNAL_CH1
  *           @arg @ref FL_ADC_EXTERNAL_CH2
  *           @arg @ref FL_ADC_EXTERNAL_CH3
  *           @arg @ref FL_ADC_EXTERNAL_CH4
  *           @arg @ref FL_ADC_EXTERNAL_CH5
  *           @arg @ref FL_ADC_EXTERNAL_CH6
  *           @arg @ref FL_ADC_EXTERNAL_CH7
  *           @arg @ref FL_ADC_EXTERNAL_CH8
  *           @arg @ref FL_ADC_EXTERNAL_CH9
  *           @arg @ref FL_ADC_EXTERNAL_CH10
  *           @arg @ref FL_ADC_EXTERNAL_CH11
  *           @arg @ref FL_ADC_EXTERNAL_CH12
  *           @arg @ref FL_ADC_EXTERNAL_CH13
  *           @arg @ref FL_ADC_EXTERNAL_CH14
  *           @arg @ref FL_ADC_EXTERNAL_CH15
  *           @arg @ref FL_ADC_EXTERNAL_CH16
  *           @arg @ref FL_ADC_INTERNAL_TS
  *           @arg @ref FL_ADC_INTERNAL_AVREF
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    CLEAR_BIT(ADCx->CHER, ((channel & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get ADC Channel Enable Status
  * @rmtoll   CHER        FL_ADC_IsEnabledSequencerChannel
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_EXTERNAL_CH0
  *           @arg @ref FL_ADC_EXTERNAL_CH1
  *           @arg @ref FL_ADC_EXTERNAL_CH2
  *           @arg @ref FL_ADC_EXTERNAL_CH3
  *           @arg @ref FL_ADC_EXTERNAL_CH4
  *           @arg @ref FL_ADC_EXTERNAL_CH5
  *           @arg @ref FL_ADC_EXTERNAL_CH6
  *           @arg @ref FL_ADC_EXTERNAL_CH7
  *           @arg @ref FL_ADC_EXTERNAL_CH8
  *           @arg @ref FL_ADC_EXTERNAL_CH9
  *           @arg @ref FL_ADC_EXTERNAL_CH10
  *           @arg @ref FL_ADC_EXTERNAL_CH11
  *           @arg @ref FL_ADC_EXTERNAL_CH12
  *           @arg @ref FL_ADC_EXTERNAL_CH13
  *           @arg @ref FL_ADC_EXTERNAL_CH14
  *           @arg @ref FL_ADC_EXTERNAL_CH15
  *           @arg @ref FL_ADC_EXTERNAL_CH16
  *           @arg @ref FL_ADC_INTERNAL_TS
  *           @arg @ref FL_ADC_INTERNAL_AVREF
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledSequencerChannel(ADC_Type *ADCx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(ADCx->CHER, ((channel & 0xffffffff) << 0x0U)) == ((channel & 0xffffffff) << 0x0U));
}


/**
  * @brief    Get ADC Conversion Data
  * @rmtoll   DR    DATA    FL_ADC_ReadConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DR, (0xffffU << 0U)) >> 0U);
}


/**
  * @}
  */

/** @defgroup ADC_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_ADC_CommonDeInit(void);
FL_ErrorStatus  FL_ADC_DeInit(ADC_Type *ADCx);
uint32_t GetActualVddaVoltage(ADC_Type *ADCx);
void FL_ADC_StructInit(FL_ADC_InitTypeDef *ADC_InitStruct);
FL_ErrorStatus FL_ADC_Init(ADC_Type *ADCx, FL_ADC_InitTypeDef  *ADC_InitStruct);
void FL_ADC_CommonStructInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
FL_ErrorStatus FL_ADC_CommonInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LR0XX_FL_ADC_H*/


/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
