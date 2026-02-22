/**
  ****************************************************************************************************
  * @file    fm33lr0xx_fl_adc.c
  * @author  FMSH Application Team
  * @brief   Src file of ADC FL Module
  * @version  V1.0.6
  * @date     20. October 2025
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


/* Includes ------------------------------------------------------------------*/
#include "fm33lr0xx_fl.h"

/** @addtogroup FM33LR0xx_FL_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

#ifdef FL_ADC_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup ADC_FL_Private_Macros
  * @{
  */

#define         IS_FL_ADC_INSTANCE(INSTANCE)                ((INSTANCE) == ADC)



#define         IS_FL_ADC_APBCLK_PRESCALER(__VALUE__)       (((__VALUE__) == FL_ADC_APBCLK_PSC_DIV1)||\
                                                            ((__VALUE__) == FL_ADC_APBCLK_PSC_DIV2) ||\
                                                            ((__VALUE__) == FL_ADC_APBCLK_PSC_DIV3) ||\
                                                            ((__VALUE__) == FL_ADC_APBCLK_PSC_DIV4)||\
                                                            ((__VALUE__) == FL_ADC_APBCLK_PSC_DIV5)||\
                                                            ((__VALUE__) == FL_ADC_APBCLK_PSC_DIV6)||\
                                                            ((__VALUE__) == FL_ADC_APBCLK_PSC_DIV8))

#define         IS_FL_ADC_CONTINUOUSCONVMODE(__VALUE__)     (((__VALUE__) == FL_ADC_CONV_MODE_SINGLE)||\
                                                            ((__VALUE__) == FL_ADC_CONV_MODE_CONTINUOUS))

#define         IS_FL_ADC_AUTO_MODE(__VALUE__)              (((__VALUE__) == FL_ADC_SINGLE_CONV_MODE_AUTO)||\
                                                            ((__VALUE__) == FL_ADC_SINGLE_CONV_MODE_SEMIAUTO))


#define         IS_FL_ADC_SCANDIRECTION(__VALUE__)          (((__VALUE__) == FL_ADC_SEQ_SCAN_DIR_FORWARD)||\
                                                            ((__VALUE__) == FL_ADC_SEQ_SCAN_DIR_BACKWARD))


#define         IS_FL_ADC_EXTERNALTRIGCONV(__VALUE__)       (((__VALUE__) == FL_ADC_TRIGGER_EDGE_NONE)||\
                                                            ((__VALUE__) == FL_ADC_TRIGGER_EDGE_RISING)||\
                                                            ((__VALUE__) == FL_ADC_TRIGGER_EDGE_FALLING)||\
                                                            ((__VALUE__) == FL_ADC_TRIGGER_EDGE_BOTH))

#define         IS_FL_ADC_EXTERNALTRIGSOURCE(__VALUE__)     (((__VALUE__) == FL_ADC_TRGI_LUT0_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_LUT1_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_LUT2_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_ATIM_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_TAU01_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_ATIM_TRGO2)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_BSTIM16_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_LPTIM16_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_COMP1_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_LUT3_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_TAU00_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_TRGI_GPTIM_TRGO))

#define         IS_FL_ADC_CHANNEL_TIME(__VALUE__)           (((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_2_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_4_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_8_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_16_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_32_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_64_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_80_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_96_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_128_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_160_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_192_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_256_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_320_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_384_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_CH_SAMPLING_TIME_512_ADCCLK))

#define         IS_FL_ADC_OVERSAMPCOFIG(__VALUE__)          (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_ADC_OVERSAMPINGRATIO(__VALUE__)       (((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_2X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_4X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_8X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_16X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_32X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_64X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_128X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_256X))

#define         IS_FL_ADC_OVERSAMPINGSHIFT(__VALUE__)       (((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_0B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_1B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_2B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_3B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_4B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_5B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_6B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_7B)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_SHIFT_8B))

#define         ADC_CALIBRATIN_TIME_OUT                     (500000)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup ADC_FL_EF_Init
  * @{
  */

/**
  * @brief  ADC外设寄存器值为复位值
  * @param  外设入口地址
  * @retval 返回错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_ADC_CommonDeInit(void)
{
    /* 关闭总线时钟 */
     FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_ADC);      
    return FL_PASS;
}
/**
  * @brief  ADC共用寄存器设置以配置外设工作时钟
  *
  * @note   其中FL_LPTIM_OPERATION_MODE_EXTERNAL_ASYN_PAUSE_CNT 模式需要外部脉冲提供给LPTIM模块作为工作时钟，此时
  *         LPTIM完全工作在异步模式下。
  * @param  LPTIM  外设入口地址
  * @param  LPTIM_InitStruct指向FL_LPTIM_TimeInitTypeDef类的结构体，它包含指定LPTIM外设的配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS ADC配置成功
  */
FL_ErrorStatus FL_ADC_CommonInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    if(ADC_CommonInitStruct != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FL_ADC_APBCLK_PRESCALER(ADC_CommonInitStruct->clockPrescaler));
       
        /* 开启总线时钟 */
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_ADC);
        /* 配置ADC时钟 */
        
        /* 配置APBCLOCK时钟预分频 */
        FL_ADC_SetAPBPrescaler(ADC, ADC_CommonInitStruct->clockPrescaler);
        
        status = FL_PASS;
    }
    return status;
}
/**
  * @brief  设置 ADC_CommonInitStruct 为默认配置
  * @param  ADC_CommonInitStruct 指向需要将值设置为默认配置的结构体 @ref FL_ADC_CommonInitTypeDef 结构体
  *
  * @retval None
  */
void FL_ADC_CommonStructInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct)
{
    if(ADC_CommonInitStruct != NULL)
    {
        ADC_CommonInitStruct->clockPrescaler        = FL_ADC_APBCLK_PSC_DIV1;
    }
}
/**
  * @brief  恢复对应的ADC入口地址寄存器为默认值
  *
  * @param  ADCx  外设入口地址
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS ADC配置成功
  */
FL_ErrorStatus  FL_ADC_DeInit(ADC_Type *ADCx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口合法性检查 */
    assert_param(IS_FL_ADC_INSTANCE(ADCx));
    /* 外设复位使能 */
    FL_RMU_EnablePeripheralReset(RMU);
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_ADC);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_ADC);
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_ADCCR);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_ADCCR);
    FL_RMU_DisablePeripheralReset(RMU);
    return status;
}
/**
  * @brief  初始化ADCx指定的入口地址的外设寄存器
  *
  * @note   用户必须检查此函数的返回值，以确保自校准完成，否则转换结果精度无法保证，除此之外ADC使能过采样实际不会增加ADC的
  *         转换精度只会提高转换结果的稳定性（同时配置移位寄存器的情况下），同时过采样会降低转换速度。
  * @param  ADCx  外设入口地址
  * @param  ADC_InitStruct 指向一 @ref FL_ADC_InitTypeDef 结构体，它包含指定ADC外设的配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS ADC配置成功
  */
FL_ErrorStatus FL_ADC_Init(ADC_Type *ADCx, FL_ADC_InitTypeDef  *ADC_InitStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    uint32_t i = 0, Calibration_Flag;
    if(ADC_InitStruct != NULL)
    {
        /* 入口合法性检查 */
        assert_param(IS_FL_ADC_INSTANCE(ADCx));
        assert_param(IS_FL_ADC_CONTINUOUSCONVMODE(ADC_InitStruct->conversionMode));
        assert_param(IS_FL_ADC_AUTO_MODE(ADC_InitStruct->autoMode));
        assert_param(IS_FL_ADC_SCANDIRECTION(ADC_InitStruct->scanDirection));
        assert_param(IS_FL_ADC_EXTERNALTRIGCONV(ADC_InitStruct->externalTrigConv));
        assert_param(IS_FL_ADC_OVERSAMPCOFIG(ADC_InitStruct->oversamplingMode));
        assert_param(IS_FL_ADC_OVERSAMPINGRATIO(ADC_InitStruct->overSampingMultiplier));
        assert_param(IS_FL_ADC_OVERSAMPINGSHIFT(ADC_InitStruct->oversamplingShift));
        FL_PMU_EnableTemperatureSensor(PMU);//置位PTAT_EN寄存器
        FL_ADC_Disable(ADCx);
        FL_ADC_DisableOverSampling(ADCx);
        FL_ADC_Enable(ADCx);
        FL_ADC_EnableCalibration(ADC);
        i = 0;
        do
        {
            Calibration_Flag = FL_ADC_IsActiveFlag_EndOfCalibration(ADC);
            i++;
        } while((i != 0xFFFFFFFFU) && (Calibration_Flag == 0U));           //等待转换完成
        if(Calibration_Flag == 0x01)
        {
            FL_ADC_ClearFlag_EndOfCalibration(ADC);
            /* 关闭ADC，关闭后ADC自校准值依然保持 */
            FL_ADC_Disable(ADCx);
            if(FL_ADC_IsEnabled(ADCx) == 0U)
            {
                /* 连续转换模式 */
                FL_ADC_SetConversionMode(ADCx, ADC_InitStruct->conversionMode);
                /* 自动转换模式 */
                FL_ADC_SetSingleConversionAutoMode(ADCx, ADC_InitStruct->autoMode);
                /* 通道等待使能 */
                if(ADC_InitStruct->waitMode == FL_ENABLE)
                {
                    FL_ADC_EnableWaitMode(ADCx);
                }
                else
                {
                    FL_ADC_DisableWaitMode(ADCx);
                }
                /*数据冲突模式设置*/
                if(ADC_InitStruct->overrunMode == FL_ENABLE)
                {
                    FL_ADC_EnableOverrunMode(ADCx);
                }
                else
                {
                    FL_ADC_DisableOverrunMode(ADCx);
                }
                /* 多通道扫描方向 */
                FL_ADC_SetSequenceScanDirection(ADCx, ADC_InitStruct->scanDirection);
                /* 触发模式 */
                FL_ADC_SetTriggerEdge(ADCx, ADC_InitStruct->externalTrigConv);
                /* 触发源 */
                FL_ADC_SetTriggerSource(ADCx, ADC_InitStruct->triggerSource);
                /*通道采样时间设置*/
                FL_ADC_SetChannelSamplingTime(ADCx, ADC_InitStruct->ChannelSamplingTime);
                if(ADC_InitStruct->oversamplingMode == FL_ENABLE)
                {
                    /*使能过采样倍数后，需要配置移位寄存器进行移位，这一过程是硬件自动完成的最终最大
                    可输出16位的结果值（即256被采样得到的结果是20bit的，右移4bit结果就是16bit的）*/
                    FL_ADC_SetOverSamplingMultiplier(ADCx, ADC_InitStruct->overSampingMultiplier);
                    FL_ADC_SetOverSamplingShift(ADCx, ADC_InitStruct->oversamplingShift);
                    /* 过采样使能 */
                    FL_ADC_EnableOverSampling(ADCx);
                }
                else
                {
                    /* 关闭过采样 */
                    FL_ADC_DisableOverSampling(ADCx);
                }
                status = FL_PASS;
            }
            else
            {
                status = FL_FAIL;
            }
        }
        else
        {
            status = FL_FAIL;
        }
    }
    return status;
}

/**
  * @brief  设置 ADC_InitStruct 为默认配置
  * @param  ADC_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_ADC_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_ADC_StructInit(FL_ADC_InitTypeDef *ADC_InitStruct)
{
    if(ADC_InitStruct != NULL)
    {
        ADC_InitStruct->conversionMode                  = FL_ADC_CONV_MODE_SINGLE;
        ADC_InitStruct->autoMode                        = FL_ADC_SINGLE_CONV_MODE_AUTO;
        ADC_InitStruct->scanDirection                   = FL_ADC_SEQ_SCAN_DIR_FORWARD;
        ADC_InitStruct->externalTrigConv                = FL_ADC_TRIGGER_EDGE_NONE;
        ADC_InitStruct->triggerSource                   = FL_ADC_TRGI_LUT0;
        ADC_InitStruct->overrunMode                     = FL_ENABLE;
        ADC_InitStruct->waitMode                        = FL_ENABLE;
        ADC_InitStruct->ChannelSamplingTime             = FL_ADC_CH_SAMPLING_TIME_2_ADCCLK;
        ADC_InitStruct->oversamplingMode                = FL_ENABLE;
        ADC_InitStruct->overSampingMultiplier           = FL_ADC_OVERSAMPLING_MUL_16X;
        ADC_InitStruct->oversamplingShift               = FL_ADC_OVERSAMPLING_SHIFT_4B;
    }
}

/**
  * @}
  */

#endif /* FL_ADC_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/


