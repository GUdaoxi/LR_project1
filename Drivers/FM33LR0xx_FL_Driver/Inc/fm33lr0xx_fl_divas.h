/**
  *******************************************************************************************************
  * @file    fm33lr0xx_fl_divas.h
  * @author  FMSH Application Team
  * @brief   Head file of DIVAS FL Module
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
#ifndef __FM33LR0XX_FL_DIVAS_H
#define __FM33LR0XX_FL_DIVAS_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33lr0xx_fl_def.h"
/** @addtogroup FM33LR0XX_FL_Driver
  * @{
  */

/** @defgroup DIVAS DIVAS
  * @brief DIVAS FL driver
  * @{
  */

/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup DIVAS_FL_ES_INIT DIVAS Exported Init structures
  * @{
  */

/**
  * @brief FL DIVAS Init Sturcture definition
  */

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup DIVAS_FL_Exported_Constants DIVAS Exported Constants
  * @{
  */

#define    DIVAS_SR_DIVBYZERO_Pos                                 (1U)
#define    DIVAS_SR_DIVBYZERO_Msk                                 (0x1U << DIVAS_SR_DIVBYZERO_Pos)
#define    DIVAS_SR_DIVBYZERO                                     DIVAS_SR_DIVBYZERO_Msk

#define    DIVAS_SR_BUSY_Pos                                      (0U)
#define    DIVAS_SR_BUSY_Msk                                      (0x1U << DIVAS_SR_BUSY_Pos)
#define    DIVAS_SR_BUSY                                          DIVAS_SR_BUSY_Msk



#define    FL_DIVAS_SR_BUSY_TIMEOUT                               0xFFFU



/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup DIVAS_FL_Exported_Functions DIVAS Exported Functions
  * @{
  */

/**
  * @brief    Write Dividend Register
  * @rmtoll   END        FL_DIVAS_WriteOperand
  * @param    DIVASx DIVAS instance
  * @param    number
  * @retval   None
  */
__STATIC_INLINE void FL_DIVAS_WriteOperand(DIVAS_Type *DIVASx, uint32_t number)
{
    WRITE_REG(DIVASx->END, (number << 0U));
}

/**
  * @brief    Read Dividend Register
  * @rmtoll   END        FL_DIVAS_ReadOperand
  * @param    DIVASx DIVAS instance
  * @retval
  */
__STATIC_INLINE int32_t FL_DIVAS_ReadOperand(DIVAS_Type *DIVASx)
{
    return (int32_t)(READ_REG(DIVASx->END));
}

/**
  * @brief    Write 16bit Signed Divisor
  * @rmtoll   SOR        FL_DIVAS_WriteDivisor
  * @param    DIVASx DIVAS instance
  * @param    number
  * @retval   None
  */
__STATIC_INLINE void FL_DIVAS_WriteDivisor(DIVAS_Type *DIVASx, uint32_t number)
{
    MODIFY_REG(DIVASx->SOR, (0xffffU << 0U), (number << 0U));
}

/**
  * @brief    Read 16bit Signed Divisor
  * @rmtoll   SOR        FL_DIVAS_ReadDivisor
  * @param    DIVASx DIVAS instance
  * @retval
  */
__STATIC_INLINE int16_t FL_DIVAS_ReadDivisor(DIVAS_Type *DIVASx)
{
    return (int16_t)(READ_BIT(DIVASx->SOR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Read 32bit Signed QUTO
  * @rmtoll   QUOT        FL_DIVAS_ReadQuotient
  * @param    DIVASx DIVAS instance
  * @retval
  */
__STATIC_INLINE int32_t FL_DIVAS_ReadQuotient(DIVAS_Type *DIVASx)
{
    return (int32_t)(READ_REG(DIVASx->QUOT));
}

/**
  * @brief    Read 16bit Signed Reminder
  * @rmtoll   REMD        FL_DIVAS_ReadResidue
  * @param    DIVASx DIVAS instance
  * @retval
  */
__STATIC_INLINE int16_t FL_DIVAS_ReadResidue(DIVAS_Type *DIVASx)
{
    return (int16_t)(READ_BIT(DIVASx->REMD, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get divided by 0 flag
  * @rmtoll   SR    DIVBYZERO    FL_DIVAS_IsActiveFlag_DividedZero
  * @param    DIVASx DIVAS instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DIVAS_IsActiveFlag_DividedZero(DIVAS_Type *DIVASx)
{
    return (uint32_t)(READ_BIT(DIVASx->SR, DIVAS_SR_DIVBYZERO_Msk) == (DIVAS_SR_DIVBYZERO_Msk));
}

/**
  * @brief    Get Busy flag
  * @rmtoll   SR    BUSY    FL_DIVAS_IsActiveFlag_Busy
  * @param    DIVASx DIVAS instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DIVAS_IsActiveFlag_Busy(DIVAS_Type *DIVASx)
{
    return (uint32_t)(READ_BIT(DIVASx->SR, DIVAS_SR_BUSY_Msk) == (DIVAS_SR_BUSY_Msk));
}

/**
  * @}
  */

/** @defgroup DIVAS_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_DIVAS_DeInit(DIVAS_Type *DIVASx);
FL_ErrorStatus FL_DIVAS_Init(DIVAS_Type *DIVASx);
FL_ErrorStatus FL_DIVAS_Hdiv_Calculation(DIVAS_Type *DIVASx, int32_t DivisorEnd, int16_t Divisor, int32_t *Quotient, int16_t *Residue);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LR0XX_FL_DIVAS_H*/


/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
