/**
  ****************************************************************************************************
  * @file    fm33lr0xx_fl_cmu.c
  * @author  FMSH Application Team
  * @brief   Src file of CMU FL Module
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

/** @addtogroup CMU_FL_OPEREAT
  * @{
  */

/**
  * @brief  设置系统工作使用时钟。
  * @param  系统工作时钟源及频率。
  * @note   函数中用到了XTHF_VALUE 宏，这个宏应该被定义为外部晶振的输入频率值。
  * @note   其他时钟源可由应用程序实现，如PLL_RCHF_40M, PLL_XTHF_64M
  * @note   PLL倍频频率范围为32M-64M
  * @note   对功耗由要求的应用，注意关闭未使用到的空闲时钟源
  *
  * @retval 系统时钟设置状态。
  *
  */
FL_ErrorStatus FL_CMU_SetSystemClock(FL_SystemClock systemClock)
{
    FL_ErrorStatus errorStatus = FL_PASS;
    /* <= 24M: 0wait; > 24 and <= 48: 1wait; */
    switch(systemClock)
    {
        case FL_SYSTEM_CLOCK_RCHF_8M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_8MHZ);
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_RCHF);
            break;
        case FL_SYSTEM_CLOCK_RCHF_16M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_WriteTrimValue(RCHF16M_TRIM);
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_16MHZ);
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_RCHF);
            break;
        case FL_SYSTEM_CLOCK_RCHF_24M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_WriteTrimValue(RCHF24M_TRIM);
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_24MHZ);
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_RCHF);
            break;
        case FL_SYSTEM_CLOCK_PLL_RCHF_32M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_8MHZ);
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            FL_CMU_PLL_SetClockSource(FL_CMU_PLL_CLK_SOURCE_RCHF);
            FL_CMU_PLL_SetPrescaler(FL_CMU_PLL_PSC_DIV2);
            FL_CMU_PLL_WriteMultiplier(8 - 1);
            FL_CMU_PLL_Enable();
            while(FL_CMU_IsActiveFlag_PLLReady() == 0x0)
            {
            }
            FL_FLASH_SetCodeReadWait(FLASH, FL_FLASH_READ_CODEWAIT_1CYCLE);
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_PLL);
            break;
        case FL_SYSTEM_CLOCK_PLL_RCHF_48M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_8MHZ);
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            FL_CMU_PLL_SetClockSource(FL_CMU_PLL_CLK_SOURCE_RCHF);
            FL_CMU_PLL_SetPrescaler(FL_CMU_PLL_PSC_DIV2);
            FL_CMU_PLL_WriteMultiplier(12 - 1);
            FL_CMU_PLL_Enable();
            while(FL_CMU_IsActiveFlag_PLLReady() == 0x0)
            {
            }
            FL_FLASH_SetCodeReadWait(FLASH, FL_FLASH_READ_CODEWAIT_1CYCLE);
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_PLL);
            break;
        case FL_SYSTEM_CLOCK_XTHF:
            FL_CMU_XTHF_WriteDriverStrength(0x08U);
            FL_CMU_XTHF_SetStartWaitTime(FL_CMU_XTHF_START_WAIT_CYCLE_16384);
            FL_CMU_XTHF_Enable();
            FL_DelayMs(2);
            while(FL_CMU_XTHF_IsReady() == 0x0)
            {
            }
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_XTHF);
            break;
        default:
            // 不应来到此处
            errorStatus = FL_FAIL;
            break;
    }
    return errorStatus;
}

/**
  * @brief  获取系统当前工作时钟SYSCLK。
  * @param  None
  * @note   函数中用到了XTHF_VALUE 宏，这个宏应该被定义为外部晶振的输入频率值。
  *
  * @retval 系统时钟频率 (Hz)。
  *
  */
uint32_t FL_CMU_GetSystemClockFreq(void)
{
    uint32_t frequency = 0;
    /* 获取系统时钟源 */
    switch(FL_CMU_GetSystemClockSource())
    {
        /* 系统时钟源为内部RCHF */
        case FL_CMU_SYSTEM_CLK_SOURCE_RCHF:
            /* 内部RCHF默认为8MHz ,可以配置为16或24M */
            frequency = FL_CMU_GetRCHFClockFreq();
            break;
        /* 系统时钟源为XTHF */
        case FL_CMU_SYSTEM_CLK_SOURCE_XTHF:
            frequency = XTHFClock;
            break;
        /* 系统时钟源为PLL */
        case FL_CMU_SYSTEM_CLK_SOURCE_PLL:
            frequency = FL_CMU_GetPLLClockFreq();
            break;
        default:
            frequency = 8000000;
            break;
    }
    return frequency;
}

/**
  * @brief  获取 AHB 总线时钟频率。
  *
  * @param  SYSCLK_Frequency  系统主时钟频率SYSCLK
  *
  * @retval AHB 总线时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetAHBClockFreq(void)
{
    uint32_t frequency = 0;
    /* 获取AHB分频系数，AHB源自系统主时钟 */
    switch(FL_CMU_GetAHBPrescaler())
    {
        case FL_CMU_AHBCLK_PSC_DIV1:
            frequency = FL_CMU_GetSystemClockFreq();
            break;
        case FL_CMU_AHBCLK_PSC_DIV2:
            frequency = FL_CMU_GetSystemClockFreq() / 2;
            break;
        case FL_CMU_AHBCLK_PSC_DIV4:
            frequency = FL_CMU_GetSystemClockFreq() / 4;
            break;
        case FL_CMU_AHBCLK_PSC_DIV8:
            frequency = FL_CMU_GetSystemClockFreq() / 8;
            break;
        case FL_CMU_AHBCLK_PSC_DIV16:
            frequency = FL_CMU_GetSystemClockFreq() / 16;
            break;
        default:
            frequency = FL_CMU_GetSystemClockFreq();
            break;
    }
    return frequency;
}

/**
  * @brief  获取当前系统的APB总线时钟
  * @param  APB_Frequency APB总线的时钟频率
  *
  * @retval APB clock frequency (in Hz)
  *
  */
uint32_t FL_CMU_GetAPBClockFreq(void)
{
    uint32_t frequency = 0;
    /* 获取APB1分频系数，APB源自AHB */
    switch(FL_CMU_GetAPBPrescaler())
    {
        case FL_CMU_APBCLK_PSC_DIV1:
            frequency = FL_CMU_GetAHBClockFreq();
            break;
        case FL_CMU_APBCLK_PSC_DIV2:
            frequency = FL_CMU_GetAHBClockFreq() / 2;
            break;
        case FL_CMU_APBCLK_PSC_DIV4:
            frequency = FL_CMU_GetAHBClockFreq() / 4;
            break;
        case FL_CMU_APBCLK_PSC_DIV8:
            frequency = FL_CMU_GetAHBClockFreq() / 8;
            break;
        case FL_CMU_APBCLK_PSC_DIV16:
            frequency = FL_CMU_GetAHBClockFreq() / 16;
            break;
        default:
            frequency = FL_CMU_GetAHBClockFreq();
            break;
    }
    return frequency;
}

/**
  * @brief  获取RCHF输出时钟频率
  * @param  None
  *
  * @retval 返回RCHF输出时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetRCHFClockFreq(void)
{
    uint32_t frequency = 0;
    switch(FL_CMU_RCHF_GetFrequency())
    {
        case FL_CMU_RCHF_FREQUENCY_8MHZ:
            frequency = 8000000;
            break;
        case FL_CMU_RCHF_FREQUENCY_16MHZ:
            frequency = 16000000;
            break;
        case FL_CMU_RCHF_FREQUENCY_24MHZ:
            frequency = 24000000;
            break;
        case FL_CMU_RCHF_FREQUENCY_32MHZ:
            frequency = 32000000;
            break;
        default:
            frequency = 8000000;
            break;
    }
    return frequency;
}
/**
  * @brief  获取PLL输出时钟频率
  * @param  None
  *
  * @retval 返回PLL输出时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetPLLClockFreq(void)
{
    uint32_t frequency = 0;
    uint32_t multiplier = 0;
    uint32_t pllPSC = 0;
    
//    /* 获取PLL时钟源 */
//    if(FL_CMU_PLL_GetClockSource() == FL_CMU_PLL_CLK_SOURCE_RCHF)
//    {
//        frequency = FL_CMU_GetRCHFClockFreq();
//    }
//    else
//    {
//        frequency = XTHFClock;
//    }
//    /* 获取PLL时钟分频系数 */
//    switch(FL_CMU_PLL_GetPrescaler())
//    {
//        case FL_CMU_PLL_PSC_DIV1:
//            break;
//        case FL_CMU_PLL_PSC_DIV2:
//            frequency /= 2;
//            break;
//        case FL_CMU_PLL_PSC_DIV3:
//            frequency /= 3;
//            break;
//        case FL_CMU_PLL_PSC_DIV4:
//            frequency /= 4;
//            break;
//        case FL_CMU_PLL_PSC_DIV6:
//            frequency /= 6;
//            break;
//        case FL_CMU_PLL_PSC_DIV8:
//            frequency /= 8;
//            break;
//        case FL_CMU_PLL_PSC_DIV10:
//            frequency /= 10;
//            break;
//        case FL_CMU_PLL_PSC_DIV12:
//            frequency /= 12;
//            break;
//        default:
//            frequency /= 2;
//            break;
//    }
    multiplier = FL_CMU_PLL_ReadMultiplier() + 1;
    pllPSC=FL_CMU_PLL_ReadPLLOutputPSC() + 1;
    frequency = ((4000000*multiplier)/pllPSC);
    return frequency;
}

/**
  * @}
  */
/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/



