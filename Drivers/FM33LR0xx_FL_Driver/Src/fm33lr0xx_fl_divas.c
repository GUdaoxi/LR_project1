/**
  *******************************************************************************************************
  * @file    fm33lr0xx_fl_divas.c
  * @author  FMSH Application Team
  * @brief   Src file of DIVAS FL Module
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

/** @addtogroup DIVAS
  * @{
  */

#ifdef FL_DIVAS_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup DIVAS_FL_Private_Macros
  * @{
  */

#define         IS_DIVAS_ALL_INSTANCE(INTENCE)              ((INTENCE) == DIVAS)

#define         IS_FL_DIVAS_DIVISOR(__VALUE__)              (((__VALUE__) != 0))

/**
  * @}
  */

/* Private consts ------------------------------------------------------------*/
/** @addtogroup DIVAS_FL_Private_Consts
  * @{
  */



/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/



/* Exported functions --------------------------------------------------------*/
/** @addtogroup DIVAS_FL_EF_Init
  * @{
  */
/**
  * @brief  复位对应HDIV控制寄存器.
  *
  * @param  DIVASx 外设入口地址
  *
  * @retval ErrorStatus枚举值
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_DIVAS_DeInit(DIVAS_Type *DIVASx)
{
    /* 入口参数检查 */
    assert_param(IS_DIVAS_ALL_INSTANCE(DIVASx));
    /* 外设复位使能 */
    FL_RMU_EnablePeripheralReset(RMU);
    /* 恢复寄存器值为默认值 */
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_DIVAS);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_DIVAS);
    /* 关闭总线时钟 */
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_DIVAS);
    /* 锁定外设复位功能 */
    FL_RMU_DisablePeripheralReset(RMU);
    return FL_PASS;
}

/**
  * @brief  根据 初始化对应外设DIVAS.
  *
  * @param  DIVASx 外设入口地址
  *
  * @retval ErrorStatus枚举值
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_DIVAS_Init(DIVAS_Type *DIVASx)
{
    /* 入口参数检查 */
    assert_param(IS_DIVAS_ALL_INSTANCE(DIVASx));
    /* 使能时钟总线 */
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_DIVAS);
    return FL_PASS;
}
/**
  * @brief 硬件除法器计算函数
  *
  * @param  DIVASx 外设入口地址
  * @param  DivisorEnd 32位有符号被除数
  * @param  Divisor 16位有符号除数，注意不能为0
  * @param  Quotient 指向 @ref int32_t 指针 保存商的地址
  * @param  Residue 指向 @ref int16_t 指针 保存余数的地址
  *
  * @retval 计算正确性与否
  *         -0 计算结果正确
  *         -非0 计算过程发生错误
  */
FL_ErrorStatus FL_DIVAS_Hdiv_Calculation(DIVAS_Type *DIVASx, int32_t DivisorEnd, int16_t Divisor, int32_t *Quotient, int16_t *Residue)
{
    uint32_t  TimeOut ;
    FL_ErrorStatus status = FL_FAIL;
    if((Quotient != NULL) && (Residue != NULL))
    {
        FL_DIVAS_WriteOperand(DIVASx, (uint32_t)DivisorEnd);
        FL_DIVAS_WriteDivisor(DIVASx, (uint32_t)Divisor);
        if(FL_DIVAS_IsActiveFlag_DividedZero(DIVASx) == 0X1)
        {
            /*除数为0 */
            *Quotient = 0;
            *Residue  = 0;
            return FL_FAIL;
        }
        TimeOut = FL_DIVAS_SR_BUSY_TIMEOUT;
        while(FL_DIVAS_IsActiveFlag_Busy(DIVASx) == 0X1)
        {
            TimeOut--;
            if(TimeOut == 0)
            {
                /* 计算超时*/
                *Quotient = 0;
                *Residue  = 0;
                return FL_FAIL;
            }
        }
        *Quotient = FL_DIVAS_ReadQuotient(DIVASx);
        *Residue  = FL_DIVAS_ReadResidue(DIVASx);
        status = FL_PASS;
    }
    return status;
}



/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup DIVAS_FL_Private_Functions DIVAS Private Functions
  * @{
  */



/**
  * @}
  */

#endif /* FL_DIVAS_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
