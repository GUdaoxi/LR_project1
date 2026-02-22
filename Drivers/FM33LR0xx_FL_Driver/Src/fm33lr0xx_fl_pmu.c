/**
  ****************************************************************************************************
  * @file    fm33lr0xx_fl_pmu.c
  * @author  FMSH Application Team
  * @brief   Src file of PMU FL Module
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

/** @addtogroup fm33lr0XX_FL_Driver_PMU
  * @{
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup PMU_FL_Private_Macros
  * @{
  */



#define         IS_FL_PMU_INSTANCE(INSTANCE)                (((INSTANCE) == PMU))

#define         IS_FL_PMU_MODE(__VALUE__)                   (((__VALUE__) == FL_PMU_POWER_MODE_ACTIVE)||\
                                                             ((__VALUE__) == FL_PMU_POWER_MODE_LPRUN_ONLY)||\
                                                             ((__VALUE__) == FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP))



#define         IS_FL_PMU_DEEPSLEEP(__VALUE__)              (((__VALUE__) == FL_PMU_SLEEP_MODE_DEEP)||\
                                                             ((__VALUE__) == FL_PMU_SLEEP_MODE_NORMAL))

#define         IS_FL_PMU_WAKEUPFREQUENCY(__VALUE__)        (((__VALUE__) == FL_PMU_RCHF_WAKEUP_FREQ_8MHZ)||\
                                                             ((__VALUE__) == FL_PMU_RCHF_WAKEUP_FREQ_16MHZ)||\
                                                             ((__VALUE__) == FL_PMU_RCHF_WAKEUP_FREQ_24MHZ))
                                                             

#define         IS_FL_PMU_WAKEUPDELAYT1A(__VALUE__)          (((__VALUE__) == FL_PMU_WAKEUP_DELAYT1A_10US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAYT1A_12US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAYT1A_16US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAYT1A_20US))
                                                             
#define         IS_FL_PMU_WAKEUPDELAYT2A(__VALUE__)            (((__VALUE__) == FL_PMU_WAKEUP_DELAYT2A_20US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAYT2A_30US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAYT2A_40US)||\
                                                             ((__VALUE__) == FL_PMU_WAKEUP_DELAYT2A_50US))
/**
  *@}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup PMU_FL_EF_Init
  * @{
  */

/**
  * @brief  复位pmu外设
  *
  * @param  外设入口地址
  *
  * @retval 返回错误状态，可能值:
  *         -FL_PASS 外设寄存器值回复复位值
  *         -FL_FAIL 位成功执行
  */
FL_ErrorStatus FL_PMU_Sleep_DeInit(PMU_Type *PMUx)
{
    FL_ErrorStatus status = FL_FAIL;
    /* 参数合法性检测 */
    assert_param(IS_FL_PMU_INSTANCE(PMU));
    PMUx->CR   = 0x11000000U;
    PMUx->WKTR = 0x00000041U;
    PMUx->IER  = 0x00000000U;
    status = FL_PASS;
    return status;
}


/**
  * @brief  根据lpm_initstruct结构体包含的配置信息配置pmu寄存器
  *
  * @note   为更好的睡眠功耗用户可能需要根据实际应用，调用 @ref fm33lr0xx_fl_pmu.h中的其他接口
  *          来完成睡眠前的模式配置，包括睡眠行为和唤醒后的行为(注：此函数会关闭BOR)
  * @param  PMUx  外设入口地址
  * @param  LPM_InitStruct 指向一个 @ref FL_PMU_SleepInitTypeDef 类型的结构体，它包含指定PMU外设的配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS PMU配置成功
  */
FL_ErrorStatus FL_PMU_Sleep_Init(PMU_Type *PMUx, FL_PMU_SleepInitTypeDef *LPM_InitStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    if(LPM_InitStruct != NULL)
    {
        /* 参数合法性检查 */
        assert_param(IS_FL_PMU_INSTANCE(PMUx));
        assert_param(IS_FL_PMU_DEEPSLEEP(LPM_InitStruct->deepSleep));
        assert_param(IS_FL_PMU_WAKEUPFREQUENCY(LPM_InitStruct->wakeupFrequency));
        assert_param(IS_FL_PMU_WAKEUPDELAYT1A(LPM_InitStruct->wakeupDelayT1A));
        assert_param(IS_FL_PMU_WAKEUPDELAYT2A(LPM_InitStruct->wakeupDelayT2A));
        
         /* 唤醒时间 */
        FL_PMU_SetWakeupDelayT1A(PMUx, LPM_InitStruct->wakeupDelayT1A);      
        /* 唤醒时间 T2A */
        FL_PMU_SetWakeupDelayT2A(PMUx, LPM_InitStruct->wakeupDelayT2A);
        /* 唤醒后RCHF的频率 */
        FL_PMU_SetRCHFWakeupFrequency(PMUx, LPM_InitStruct->wakeupFrequency);
        /* M0系统控制器，一般配置为0即可*/
        SCB->SCR = 0;
        /* 睡眠模式 */
        FL_PMU_SetSleepMode(PMUx, LPM_InitStruct->deepSleep);
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  LPM_InitStruct 为默认配置
  * @param  LPM_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_PMU_SleepInitTypeDef structure
  *         结构体
  * @retval None
  */
void FL_PMU_StructInit(FL_PMU_SleepInitTypeDef *LPM_InitStruct)
{
    if(LPM_InitStruct != NULL)
    {
        LPM_InitStruct->deepSleep           = FL_PMU_SLEEP_MODE_NORMAL;
        LPM_InitStruct->wakeupFrequency     = FL_PMU_RCHF_WAKEUP_FREQ_8MHZ;
        LPM_InitStruct->wakeupDelayT1A      = FL_PMU_WAKEUP_DELAYT1A_10US;
        LPM_InitStruct->wakeupDelayT2A      = FL_PMU_WAKEUP_DELAYT2A_20US;       
    }
}

/**
  * @}
  */


/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/

