/**
  *******************************************************************************************************
  * @file    fm33lr0xx_fl_rng.c
  * @author  FMSH Application Team
  * @brief   Src file of RNG FL Module
  * @version  V1.0.5
  * @date     29. June 2025
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

/** @addtogroup RNG
  * @{
  */

#ifdef FL_RNG_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup RNG_FL_Private_Macros
  * @{
  */

#define         IS_FL_RNG_INSTANCE(INTANCE)                         ((INTANCE) == RNG)

#define         IS_FL_RNG_CLOCK_PRESCALER(__VALUE__)               (((__VALUE__) == FL_CMU_RNG_PSC_DIV1)||\
                                                                     ((__VALUE__) == FL_CMU_RNG_PSC_DIV2)||\
                                                                     ((__VALUE__) == FL_CMU_RNG_PSC_DIV4)||\
                                                                     ((__VALUE__) == FL_CMU_RNG_PSC_DIV8)||\
                                                                     ((__VALUE__) == FL_CMU_RNG_PSC_DIV16)||\
                                                                     ((__VALUE__) == FL_CMU_RNG_PSC_DIV32))


/**
  * @}
  */

/* Private consts ------------------------------------------------------------*/
/** @addtogroup RNG_FL_Private_Consts
  * @{
  */



/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/



/* Exported functions --------------------------------------------------------*/
/** @addtogroup RNG_FL_EF_Init
  * @{
  */

/**
  * @brief  复位对应RNG寄存器.
  *
  * @param  RNGx 外设入口地址
  *
  * @retval ErrorStatus枚举值
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_RNG_DeInit(RNG_Type *RNGx)
{
    assert_param(IS_FL_RNG_INSTANCE(RNGx));
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);
    /* 复位外设寄存器 */
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_RNG);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_RNG);
    /* 关闭外设总线始时钟和工作时钟 */
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_RNG);
    /* 锁定外设复位 */
    FL_RMU_DisablePeripheralReset(RMU);
    return FL_PASS;
}
/**
  * @brief  根据 InitStruct 的配置信息初始化对应外设入口地址的寄存器值.
  * @param  RNGx 外设入口地址
  *
  * @param  initStruct 指向一个 @ref FL_RNG_InitTypeDef 结构体 其中包含了外设的相关配置信息.
  *
  * @note   RNG使用RCHF默认的8M作为时钟输入，经2分频后4M提供给RNG
  *
  * @retval ErrorStatus枚举值
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_RNG_Init(RNG_Type *RNGx)
{
    assert_param(IS_FL_RNG_INSTANCE(RNGx));
    /* RNG 使用RCHF作为工作时钟因此必须确认RCHF使能*/
    if(FL_CMU_RCHF_IsEnabled() != 0x01)
    {
        FL_CMU_RCHF_Enable();
    }
    /* RNG 总线时钟使能 */
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_RNG);
    /* RNG 工作时钟预分频*/
    switch(FL_CMU_RCHF_GetFrequency())
    {
        case FL_CMU_RCHF_FREQUENCY_8MHZ:
            FL_CMU_SetRNGPrescaler(FL_CMU_RNG_PSC_DIV2);
            break;
        case FL_CMU_RCHF_FREQUENCY_16MHZ:
            FL_CMU_SetRNGPrescaler(FL_CMU_RNG_PSC_DIV4);
            break;
        case FL_CMU_RCHF_FREQUENCY_24MHZ:
            FL_CMU_SetRNGPrescaler(FL_CMU_RNG_PSC_DIV8);
            break;
        case FL_CMU_RCHF_FREQUENCY_32MHZ:
            FL_CMU_SetRNGPrescaler(FL_CMU_RNG_PSC_DIV8);
            break;
        default:
            FL_CMU_SetRNGPrescaler(FL_CMU_RNG_PSC_DIV2);
            break;
    }
    /* RNG 工作时钟使能*/
    FL_CMU_EnableOperationClock(FL_CMU_OPCLK_RNG);
    return FL_PASS;
}

/**
  * @brief  获取一次随机数
  * @param  rng：输出参数，随机数的值
  * @retval FL_ErrorStatus枚举值
  *         -FL_PASS 成功
  *         -FL_FAIL 失败
  */
FL_ErrorStatus GetRandomNumber(uint32_t *rng)
{
    FL_RNG_ClearFlag_RandomFail(RNG);
    FL_RNG_Enable(RNG);
    /* 由于LFSR循环移位周期是32cycle，为保证随机数质量，应用应保证两次读取RNGOUT之间的间隔大于32个TRNG_CLK周期 */
    FL_DelayUs(12);
    FL_RNG_Disable(RNG);
    if(FL_RNG_IsActiveFlag_RandomFail(RNG) == 0x01)
    {
        FL_RNG_ClearFlag_RandomFail(RNG);
        *rng = 0xFFFFFFFFU;
        return FL_FAIL;
    }
    *rng = FL_RNG_ReadData(RNG);
    return FL_PASS;
}
/**
  * @brief  获取CRC32
  * @param  dataIn：输入参数 待计算的数据
  * @param  crcResult：输出参数 crc计算结果
  * @retval FL_ErrorStatus枚举值
  *         -FL_PASS 成功
  *         -FL_FAIL 失败
  *
  */
FL_ErrorStatus GetCrc32(uint32_t dataIn, uint32_t *crcResult)
{
    uint32_t timeout = 0, completeStatus;
    FL_RNG_CRC_WriteData(RNG, dataIn);
    FL_RNG_ClearFlag_CRCComplete(RNG);
    FL_RNG_CRC_Enable(RNG);
    do
    {
        completeStatus = FL_RNG_IsActiveFlag_CRCComplete(RNG);
        timeout++;
    } while((timeout != RNG_TIMEOUT) && (completeStatus != 0x1U));
    if(completeStatus != 0x1U)
    {
        FL_RNG_ClearFlag_CRCComplete(RNG);
        FL_RNG_Disable(RNG);
        *crcResult = 0xFFFFFFFFU;
        return FL_FAIL;
    }
    FL_RNG_ClearFlag_CRCComplete(RNG);
    *crcResult = FL_RNG_ReadData(RNG);
    FL_RNG_Disable(RNG);
    return FL_PASS;
}

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup RNG_FL_Private_Functions RNG Private Functions
  * @{
  */



/**
  * @}
  */

#endif /* FL_RNG_DRIVER_ENABLED */


/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
