/**
  ****************************************************************************************************
  * @file    fm33lr0xx_fl_gpio.c
  * @author  FMSH Application Team
  * @brief   Src file of GPIO FL Module
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

/* Private macros ------------------------------------------------------------*/
/** @addtogroup GPIO_FL_Private_Macros
  * @{
  */
#define         IS_GPIO_ALL_INSTANCE(INTENCE)              (((INTENCE) == GPIOA)||\
                                                            ((INTENCE) == GPIOB)||\
                                                            ((INTENCE) == GPIOC)||\
                                                            ((INTENCE) == GPIOD)||\
                                                            ((INTENCE) == GPIOE))

#define         IS_FL_GPIO_PIN(__VALUE__)                  ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                            ((__VALUE__) <= (FL_GPIO_PIN_ALL)))

#define         IS_FL_GPIO_MODE(__VALUE__)                  (((__VALUE__) == FL_GPIO_MODE_ANALOG)||\
                                                             ((__VALUE__) == FL_GPIO_MODE_INPUT)||\
                                                             ((__VALUE__) == FL_GPIO_MODE_OUTPUT)||\
                                                             ((__VALUE__) == FL_GPIO_MODE_DIGITAL))

#define         IS_FL_GPIO_OPENDRAIN(__VALUE__)             (((__VALUE__) == FL_GPIO_OUTPUT_OPENDRAIN)||\
                                                             ((__VALUE__) == FL_GPIO_OUTPUT_PUSHPULL))


#define         IS_FL_GPIO_PULL(__VALUE__)                  (((__VALUE__) == FL_GPIO_PULLUP_ENABLE)||\
                                                             ((__VALUE__) == FL_GPIO_PULLDOWN_ENABLE)||\
                                                             ((__VALUE__) == FL_GPIO_BOTH_DISABLE))

#define         IS_FL_GPIO_ANALOG_SWITCH(__VALUE__)         (((__VALUE__) == FL_DISABLE)||\
                                                             ((__VALUE__) == FL_ENABLE))

#define         IS_FL_GPIO_REMAPPIN(__VALUE__)              (((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON1)||\
                                                             ((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON2)||\
                                                             ((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON3)||\
                                                             ((__VALUE__) == FL_GPIO_PINREMAP_FUNCTON4))

#define         IS_FL_GPIO_WKUP_ENTRY(__VALUE__)            (((__VALUE__) == FL_GPIO_WKUP_INT_ENTRY_NMI)||\
                                                             ((__VALUE__) == FL_GPIO_WKUP_INT_ENTRY_NUM_39))

#define         IS_FL_GPIO_WKUP_EDGE(__VALUE__)             (((__VALUE__) == FL_GPIO_WAKEUP_TRIGGER_RISING)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_TRIGGER_FALLING)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_TRIGGER_BOTH))


#define         IS_FL_GPIO_WKUP_NUM(__VALUE__)              (((__VALUE__) == FL_GPIO_WAKEUP_0)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_1)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_2)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_3)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_4)||\
                                                             ((__VALUE__) == FL_GPIO_WAKEUP_5))


#define          IS_FL_GPIO_DRIVESTRENGTH(__VALUE__)         (((__VALUE__) == FL_GPIO_DRIVESTRENGTH_HIGH)||\
                                                             ((__VALUE__) == FL_GPIO_DRIVESTRENGTH_LOW)||\
                                                             ((__VALUE__) == FL_GPIO_DRIVESTRENGTH_CLOSE)||\
                                                             ((__VALUE__) == FL_GPIO_DRIVESTRENGTH_X1)||\
                                                             ((__VALUE__) == FL_GPIO_DRIVESTRENGTH_X3)||\
                                                             ((__VALUE__) == FL_GPIO_DRIVESTRENGTH_X4))


#define          IS_FL_GPIO_SLEWRATE(__VALUE__)              (((__VALUE__) == FL_GPIO_SLEWRATE_HIGH)||\
                                                             ((__VALUE__) == FL_GPIO_SLEWRATE_LOW))  
/**
  * @}
  */

/** @addtogroup GPIO_FL_EF_Init
  * @{
  */

/**
  * @brief  复位对应GPIO控制寄存器.
  * @param  GPIOx GPIO Port
  * @retval ErrorStatus枚举值:
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_GPIO_DeInit(GPIO_Type *GPIOx, uint32_t pin)
{
    uint32_t pinPos     = 0x00000000U;
    uint32_t currentPin = 0x00000000U;
    /* 入口参数检查 */
    assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
    assert_param(IS_FL_GPIO_PIN(pin));
    /* 恢复寄存器值为默认值 */
    while(((pin) >> pinPos) != 0x00000000U)
    {
        /* 获取当前遍历到的Pin脚 */
        currentPin = (pin) & (0x1UL << pinPos);
        if(currentPin != 0X0U)
        {
            FL_GPIO_SetPinMode(GPIOx, currentPin, FL_GPIO_MODE_INPUT);
            FL_GPIO_DisablePinInput(GPIOx, currentPin);
            FL_GPIO_DisablePinOpenDrain(GPIOx, currentPin);
            FL_GPIO_DisablePinPullupOrPulldown(GPIOx, currentPin);
            FL_GPIO_SetPinRemap(GPIOx, currentPin, FL_GPIO_PINREMAP_FUNCTON1);
        }
        pinPos++;
    }
    return FL_PASS;
}

/**
  * @brief  根据 GPIO_InitStruct的配置信息初始化对应外设.
  * @param  GPIOx GPIO Port
  * @param  GPIO_InitStruct 指向一个 @ref FL_GPIO_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_GPIO_Init(GPIO_Type *GPIOx, FL_GPIO_InitTypeDef *initStruct)
{
    uint32_t pinPos     = 0x00000000U;
    uint32_t currentPin = 0x00000000U;
    FL_ErrorStatus status = FL_FAIL;
    if(initStruct != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
        assert_param(IS_FL_GPIO_PIN(initStruct->pin));
        assert_param(IS_FL_GPIO_MODE(initStruct->mode));
        assert_param(IS_FL_GPIO_OPENDRAIN(initStruct->outputType));
        assert_param(IS_FL_GPIO_PULL(initStruct->pull));
        assert_param(IS_FL_GPIO_REMAPPIN(initStruct->remapPin));
        assert_param(IS_FL_GPIO_DRIVESTRENGTH(initStruct->driveStrength));
        assert_param(IS_FL_GPIO_SLEWRATE(initStruct->slewrate));
        /* 使能时钟总线 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_PAD);
        /* 这里考虑到PIN有可能不止一个因此需要遍历 */
        while(((initStruct->pin) >> pinPos) != 0x00000000U)
        {
            /* 获取当前遍历到的Pin脚 */
            currentPin = (initStruct->pin) & (0x1UL << pinPos);
            if(currentPin != 0X0U)
            {
                /* Pin脚模拟模式设置 */
                if(initStruct->mode == FL_GPIO_MODE_ANALOG)
                {
                    FL_GPIO_DisablePinInput(GPIOx, currentPin);
                    FL_GPIO_DisablePinPullupOrPulldown(GPIOx, currentPin);
                    FL_GPIO_DisablePinOpenDrain(GPIOx, currentPin);
                }
                /* Pin脚输入使能控制 */
                if(initStruct->mode == FL_GPIO_MODE_INPUT)
                {
                    FL_GPIO_EnablePinInput(GPIOx, currentPin);
                }
                else
                {
                    FL_GPIO_DisablePinInput(GPIOx, currentPin);
                }
                /* Pin脚输出模式设置 */
                if(initStruct->outputType == FL_GPIO_OUTPUT_PUSHPULL)
                {
                    FL_GPIO_DisablePinOpenDrain(GPIOx, currentPin);
                }
                else
                {
                    FL_GPIO_EnablePinOpenDrain(GPIOx, currentPin);
                }
                /* Pin脚上拉/下拉模式设置 */
                if(initStruct->pull == FL_GPIO_PULLUP_ENABLE)
                {
                    FL_GPIO_EnablePinPullupOrPulldown(GPIOx, currentPin);
                    FL_GPIO_SetPinPullMode(GPIOx, currentPin, FL_GPIO_PULLUP_ENABLE);
                }
                else if(initStruct->pull == FL_GPIO_PULLDOWN_ENABLE)
                {
                    FL_GPIO_EnablePinPullupOrPulldown(GPIOx, currentPin);
                    FL_GPIO_SetPinPullMode(GPIOx, currentPin, FL_GPIO_PULLDOWN_ENABLE);
                }
                else
                {
                    FL_GPIO_DisablePinPullupOrPulldown(GPIOx, currentPin);
                }
                
                /* 数字模式复用功能选择 */
                if(initStruct->mode == FL_GPIO_MODE_DIGITAL)
                {
                    /*重定向*/
                    FL_GPIO_SetPinRemap(GPIOx, currentPin, initStruct->remapPin);
                }
                if(initStruct ->driveStrength ==FL_GPIO_DRIVESTRENGTH_LOW)
                {
                    FL_GPIO_SetDriveStrengthToLow(GPIOx,currentPin);   
                }
                else if(initStruct ->driveStrength ==FL_GPIO_DRIVESTRENGTH_X1)
                {
                    FL_GPIO_SetDriveStrengthToLow(GPIOx,currentPin);
                }
                else if(initStruct ->driveStrength ==FL_GPIO_DRIVESTRENGTH_CLOSE)
                {
                    FL_GPIO_SetDriveStrengthToLow(GPIOx,currentPin);
                }
                else
                {
                    FL_GPIO_SetDriveStrengthToHigh(GPIOx,currentPin);
                }
                  if(initStruct ->slewrate ==FL_GPIO_SLEWRATE_LOW)
                {
                    FL_GPIO_SetSlewRateToLow(GPIOx,currentPin);
                }
                else
                {
                    FL_GPIO_SetSlewRateToHigh(GPIOx,currentPin);
                }
                /* Pin脚工作模式设置 */
                FL_GPIO_SetPinMode(GPIOx, currentPin, initStruct->mode);
            }
            pinPos++;
        }
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  设置 GPIO_InitStruct 为默认配置
  * @param  GPIO_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_GPIO_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_GPIO_StructInit(FL_GPIO_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        /* 复位配置信息 */
        initStruct->pin              = FL_GPIO_PIN_ALL;
        initStruct->mode             = FL_GPIO_MODE_INPUT;
        initStruct->outputType       = FL_GPIO_OUTPUT_OPENDRAIN;
        initStruct->pull             = FL_GPIO_PULLUP_ENABLE;
			  initStruct->driveStrength    = FL_GPIO_DRIVESTRENGTH_HIGH;
			  initStruct->slewrate         = FL_GPIO_SLEWRATE_LOW;
        initStruct->remapPin         = FL_GPIO_PINREMAP_FUNCTON1;
    }
}

/**
  * @brief  根据 WKUP_InitTypeDef的配置信息初始化对应外设.
  * @param  WKUP_InitTypeDef 指向一个 @ref FL_WKUP_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @param  Wkupx 唤醒入口
  *         FL_GPIO_WKUP_0
  *         FL_GPIO_WKUP_1
  *         FL_GPIO_WKUP_2
  *         FL_GPIO_WKUP_3
  *         FL_GPIO_WKUP_4
  *         FL_GPIO_WKUP_5
  *         FL_GPIO_WKUP_6
  *         FL_GPIO_WKUP_7
  *         FL_GPIO_WKUP_8
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_WKUP_Init(FL_WKUP_InitTypeDef *initStruct, uint32_t wakeup)
{
    FL_ErrorStatus status = FL_FAIL;
    if(initStruct != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FL_GPIO_WKUP_NUM(wakeup));
        assert_param(IS_FL_GPIO_WKUP_EDGE(initStruct->polarity));
        FL_GPIO_EnableWakeup(GPIO, wakeup);
        FL_GPIO_SetWakeupEdge(GPIO, wakeup, initStruct->polarity);
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  去初始化Wakeup设置.
  * @param  Wkupx 唤醒入口
  *         FL_GPIO_WKUP_0
  *         FL_GPIO_WKUP_1
  *         FL_GPIO_WKUP_2
  *         FL_GPIO_WKUP_3
  *         FL_GPIO_WKUP_4
  *         FL_GPIO_WKUP_5
  *         FL_GPIO_WKUP_6
  *         FL_GPIO_WKUP_7
  *         FL_GPIO_WKUP_8
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_WKUP_DeInit(uint32_t wakeup)
{
    /* 入口参数检查 */
    assert_param(IS_FL_GPIO_WKUP_NUM(wakeup));
    FL_GPIO_DisableWakeup(GPIO, wakeup);
    return FL_PASS;
}
/**
  * @brief  设置 GPIO_InitStruct 为默认配置
  * @param  GPIO_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_GPIO_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_WKUP_StructInit(FL_WKUP_InitTypeDef *initStruct_Wakeup)
{
    if(initStruct_Wakeup != NULL)
    {
        /* 复位配置信息 */
        initStruct_Wakeup->polarity = FL_GPIO_WAKEUP_TRIGGER_FALLING;
    }
}

/**
  * @brief  配置所有IO口为输入模式、输入使能关闭（高阻态），SWD接口除外。
  * @note   PA3和PA4为调试接口
  *
  * @param  None
  *
  * @retval None
  */
void FL_GPIO_ALLPIN_LPM_MODE(void)
{
    (void)FL_GPIO_DeInit(GPIOA, FL_GPIO_PIN_ALL & (~FL_GPIO_PIN_3) & (~FL_GPIO_PIN_4));
    (void)FL_GPIO_DeInit(GPIOB, FL_GPIO_PIN_ALL);
    (void)FL_GPIO_DeInit(GPIOC, FL_GPIO_PIN_ALL );
    (void)FL_GPIO_DeInit(GPIOD, FL_GPIO_PIN_ALL & (~FL_GPIO_PIN_10));
    (void)FL_GPIO_DeInit(GPIOE, FL_GPIO_PIN_ALL);
}
/**
  * @}
  */

/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/
