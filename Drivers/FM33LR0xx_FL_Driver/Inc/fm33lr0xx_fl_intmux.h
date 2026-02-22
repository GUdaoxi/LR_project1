/**
  *******************************************************************************************************
  * @file    fm33lr0xx_fl_intmux.h
  * @author  FMSH Application Team
  * @brief   Head file of CMU FL Module
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


/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33LR0XX_FL_INTMUX_H
#define __FM33LR0XX_FL_INTMUX_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33lr0xx_fl_def.h"
/** @addtogroup FM33LR0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup CMU_FL_ES_INIT INTMUX Exported Init structures
  * @{
  */


/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup INTMUX_FL_Exported_Constants INTMUX Exported Constants
  * @{
  */


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

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup INTMUX_FL_Exported_Functions INTMUX Exported Functions
  * @{
  */


/**
  * @brief    Set MUX13SEL
  * @rmtoll   CR    MUX13SEL    FL_INTMUX_SetMUX13SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX13SEL_TAU00
  *           @arg @ref FL_INTMUX_MUX13SEL_UART1
  *           @arg @ref FL_INTMUX_MUX13SEL_UART2
  *           @arg @ref FL_INTMUX_MUX13SEL_CAN1
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX13SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX13SEL_Msk, intsel);
}

/**
  * @brief    Get MUX13SEL
  * @rmtoll   CR    MUX13SEL    FL_INTMUX_GetMUX13SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX13SEL_TAU00
  *           @arg @ref FL_INTMUX_MUX13SEL_UART1
  *           @arg @ref FL_INTMUX_MUX13SEL_UART2
  *           @arg @ref FL_INTMUX_MUX13SEL_CAN1
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX13SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX13SEL_Msk));
}


/**
  * @brief    Set MUX12SEL
  * @rmtoll   CR    MUX12SEL    FL_INTMUX_SetMUX12SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX12SEL_SPI3
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU05
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU07
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX12SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX12SEL_Msk, intsel);
}

/**
  * @brief    Get MUX12SEL
  * @rmtoll   CR    MUX12SEL    FL_INTMUX_GetMUX12SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX12SEL_SPI3
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU05
  *           @arg @ref FL_INTMUX_MUX12SEL_TAU07
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX12SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX12SEL_Msk));
}


/**
  * @brief    Set MUX11SEL
  * @rmtoll   CR    MUX11SEL    FL_INTMUX_SetMUX11SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX11SEL_SPI2
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU11
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU03
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX11SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX11SEL_Msk, intsel);
}

/**
  * @brief    Get MUX11SEL
  * @rmtoll   CR    MUX11SEL    FL_INTMUX_GetMUX11SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX11SEL_SPI2
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU11
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX11SEL_TAU03
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX11SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX11SEL_Msk));
}


/**
  * @brief    Set MUX10SEL
  * @rmtoll   CR    MUX10SEL    FL_INTMUX_SetMUX10SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX10SEL_LUT
  *           @arg @ref FL_INTMUX_MUX10SEL_TAU03
  *           @arg @ref FL_INTMUX_MUX10SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX10SEL_TAU07
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX10SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX10SEL_Msk, intsel);
}

/**
  * @brief    Get MUX10SEL
  * @rmtoll   CR    MUX10SEL    FL_INTMUX_GetMUX10SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX10SEL_LUT
  *           @arg @ref FL_INTMUX_MUX10SEL_TAU03
  *           @arg @ref FL_INTMUX_MUX10SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX10SEL_TAU07
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX10SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX10SEL_Msk));
}


/**
  * @brief    Set MUX9SEL
  * @rmtoll   CR    MUX9SEL    FL_INTMUX_SetMUX9SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX9SEL_CCL
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU05
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU06
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU03
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX9SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX9SEL_Msk, intsel);
}

/**
  * @brief    Get MUX9SEL
  * @rmtoll   CR    MUX9SEL    FL_INTMUX_GetMUX9SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX9SEL_CCL
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU05
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU06
  *           @arg @ref FL_INTMUX_MUX9SEL_TAU03
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX9SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX9SEL_Msk));
}


/**
  * @brief    Set MUX8SEL
  * @rmtoll   CR    MUX8SEL    FL_INTMUX_SetMUX8SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX8SEL_UART5
  *           @arg @ref FL_INTMUX_MUX8SEL_TAU05
  *           @arg @ref FL_INTMUX_MUX8SEL_TAU06
  *           @arg @ref FL_INTMUX_MUX8SEL_TAU12
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX8SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX8SEL_Msk, intsel);
}

/**
  * @brief    Get MUX8SEL
  * @rmtoll   CR    MUX8SEL    FL_INTMUX_GetMUX8SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX8SEL_UART5
  *           @arg @ref FL_INTMUX_MUX8SEL_TAU05
  *           @arg @ref FL_INTMUX_MUX8SEL_TAU06
  *           @arg @ref FL_INTMUX_MUX8SEL_TAU12
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX8SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX8SEL_Msk));
}


/**
  * @brief    Set MUX7SEL
  * @rmtoll   CR    MUX7SEL    FL_INTMUX_SetMUX7SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX7SEL_UART4
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU04
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX7SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX7SEL_Msk, intsel);
}

/**
  * @brief    Get MUX7SEL
  * @rmtoll   CR    MUX7SEL    FL_INTMUX_GetMUX7SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX7SEL_UART4
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX7SEL_TAU04
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX7SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX7SEL_Msk));
}


/**
  * @brief    Set MUX6SEL
  * @rmtoll   CR    MUX6SEL    FL_INTMUX_SetMUX6SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX6SEL_UART3
  *           @arg @ref FL_INTMUX_MUX6SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX6SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX6SEL_TAU02
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX6SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX6SEL_Msk, intsel);
}

/**
  * @brief    Get MUX6SEL
  * @rmtoll   CR    MUX6SEL    FL_INTMUX_GetMUX6SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX6SEL_UART3
  *           @arg @ref FL_INTMUX_MUX6SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX6SEL_TAU13
  *           @arg @ref FL_INTMUX_MUX6SEL_TAU02
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX6SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX6SEL_Msk));
}


/**
  * @brief    Set MUX5SEL
  * @rmtoll   CR    MUX5SEL    FL_INTMUX_SetMUX5SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX5SEL_UART2
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU03
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU11
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX5SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX5SEL_Msk, intsel);
}

/**
  * @brief    Get MUX5SEL
  * @rmtoll   CR    MUX5SEL    FL_INTMUX_GetMUX5SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX5SEL_UART2
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU03
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU04
  *           @arg @ref FL_INTMUX_MUX5SEL_TAU11
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX5SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX5SEL_Msk));
}


/**
  * @brief    Set MUX4SEL
  * @rmtoll   CR    MUX4SEL    FL_INTMUX_SetMUX4SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX4SEL_UART1
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU00
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU01
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU10
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX4SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX4SEL_Msk, intsel);
}

/**
  * @brief    Get MUX4SEL
  * @rmtoll   CR    MUX4SEL    FL_INTMUX_GetMUX4SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX4SEL_UART1
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU00
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU01
  *           @arg @ref FL_INTMUX_MUX4SEL_TAU10
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX4SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX4SEL_Msk));
}


/**
  * @brief    Set MUX3SEL
  * @rmtoll   CR    MUX3SEL    FL_INTMUX_SetMUX3SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX3SEL_UART0
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU11
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU01
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX3SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX3SEL_Msk, intsel);
}

/**
  * @brief    Get MUX3SEL
  * @rmtoll   CR    MUX3SEL    FL_INTMUX_GetMUX3SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX3SEL_UART0
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU11
  *           @arg @ref FL_INTMUX_MUX3SEL_TAU01
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX3SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX3SEL_Msk));
}


/**
  * @brief    Set MUX2SEL
  * @rmtoll   CR    MUX2SEL    FL_INTMUX_SetMUX2SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX2SEL_SPI1
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU01
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU02
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX2SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX2SEL_Msk, intsel);
}

/**
  * @brief    Get MUX2SEL
  * @rmtoll   CR    MUX2SEL    FL_INTMUX_GetMUX2SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX2SEL_SPI1
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU12
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU01
  *           @arg @ref FL_INTMUX_MUX2SEL_TAU02
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX2SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX2SEL_Msk));
}


/**
  * @brief    Set MUX1SEL
  * @rmtoll   CR    MUX1SEL    FL_INTMUX_SetMUX1SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX1SEL_SPI0
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU11
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU06
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX1SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX1SEL_Msk, intsel);
}

/**
  * @brief    Get MUX1SEL
  * @rmtoll   CR    MUX1SEL    FL_INTMUX_GetMUX1SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX1SEL_SPI0
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU10
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU11
  *           @arg @ref FL_INTMUX_MUX1SEL_TAU06
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX1SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX1SEL_Msk));
}


/**
  * @brief    Set MUX0SEL
  * @rmtoll   CR    MUX0SEL    FL_INTMUX_SetMUX0SEL
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX0SEL_FLASH
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU00
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU01
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU02
  * @retval   None
  */
__STATIC_INLINE void FL_INTMUX_SetMUX0SEL(uint32_t intsel)
{
    MODIFY_REG(INTMUX->CR, INTMUX_CR_MUX0SEL_Msk, intsel);
}

/**
  * @brief    Get MUX0SEL
  * @rmtoll   CR    MUX0SEL    FL_INTMUX_GetMUX0SEL
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_INTMUX_MUX0SEL_FLASH
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU00
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU01
  *           @arg @ref FL_INTMUX_MUX0SEL_TAU02
  */
__STATIC_INLINE uint32_t FL_INTMUX_GetMUX0SEL(void)
{
    return (uint32_t)(READ_BIT(INTMUX->CR, INTMUX_CR_MUX0SEL_Msk));
}
/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LR0XX_FL_INTMUX_H*/


/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
