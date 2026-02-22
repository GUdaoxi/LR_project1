/**
  *******************************************************************************************************
  * @file    fm33lr0xx_fl_flash.h
  * @author  FMSH Application Team
  * @brief   Head file of FLASH FL Module
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


/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33LR0XX_FL_FLASH_H
#define __FM33LR0XX_FL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33lr0xx_fl_def.h"
/** @addtogroup FM33LR0XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup FLASH_FL_ES_INIT FLASH Exported Init structures
  * @{
  */

/**
  * @brief FL FLASH Init Sturcture definition
  */

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup FLASH_FL_Exported_Constants FLASH Exported Constants
  * @{
  */
#define    FLASH_RDCR_CODE_WAIT_Pos                               (0U)
#define    FLASH_RDCR_CODE_WAIT_Msk                               (0x3U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FLASH_RDCR_CODE_WAIT                                   FLASH_RDCR_CODE_WAIT_Msk

#define    FLASH_PFTCON_EN_Pos                                    (0U)
#define    FLASH_PFTCON_EN_Msk                                    (0x1U << FLASH_PFTCON_EN_Pos)
#define    FLASH_PFTCON_EN                                        FLASH_PFTCON_EN_Msk

#define    FLASH_OPTBR_IWDTSLP_Pos                                (31U)
#define    FLASH_OPTBR_IWDTSLP_Msk                                (0x1U << FLASH_OPTBR_IWDTSLP_Pos)
#define    FLASH_OPTBR_IWDTSLP                                    FLASH_OPTBR_IWDTSLP_Msk

#define    FLASH_OPTBR_IWDTEN_Pos                                 (30U)
#define    FLASH_OPTBR_IWDTEN_Msk                                 (0x1U << FLASH_OPTBR_IWDTEN_Pos)
#define    FLASH_OPTBR_IWDTEN                                     FLASH_OPTBR_IWDTEN_Msk

#define    FLASH_OPTBR_ACLOCKEN_Pos                               (2U)
#define    FLASH_OPTBR_ACLOCKEN_Msk                               (0x3U << FLASH_OPTBR_ACLOCKEN_Pos)
#define    FLASH_OPTBR_ACLOCKEN                                   FLASH_OPTBR_ACLOCKEN_Msk

#define    FLASH_OPTBR_DBRDPEN_Pos                                (0U)
#define    FLASH_OPTBR_DBRDPEN_Msk                                (0x3U << FLASH_OPTBR_DBRDPEN_Pos)
#define    FLASH_OPTBR_DBRDPEN                                    FLASH_OPTBR_DBRDPEN_Msk

#define    FLASH_EPCR_ERTYPE_Pos                                  (8U)
#define    FLASH_EPCR_ERTYPE_Msk                                  (0x3U << FLASH_EPCR_ERTYPE_Pos)
#define    FLASH_EPCR_ERTYPE                                      FLASH_EPCR_ERTYPE_Msk

#define    FLASH_EPCR_PREQ_Pos                                    (1U)
#define    FLASH_EPCR_PREQ_Msk                                    (0x1U << FLASH_EPCR_PREQ_Pos)
#define    FLASH_EPCR_PREQ                                        FLASH_EPCR_PREQ_Msk

#define    FLASH_EPCR_EREQ_Pos                                    (0U)
#define    FLASH_EPCR_EREQ_Msk                                    (0x1U << FLASH_EPCR_EREQ_Pos)
#define    FLASH_EPCR_EREQ                                        FLASH_EPCR_EREQ_Msk

#define    FLASH_IER_AUTHIE_Pos                                   (10U)
#define    FLASH_IER_AUTHIE_Msk                                   (0x1U << FLASH_IER_AUTHIE_Pos)
#define    FLASH_IER_AUTHIE                                       FLASH_IER_AUTHIE_Msk

#define    FLASH_IER_KEYIE_Pos                                    (9U)
#define    FLASH_IER_KEYIE_Msk                                    (0x1U << FLASH_IER_KEYIE_Pos)
#define    FLASH_IER_KEYIE                                        FLASH_IER_KEYIE_Msk

#define    FLASH_IER_CKIE_Pos                                     (8U)
#define    FLASH_IER_CKIE_Msk                                     (0x1U << FLASH_IER_CKIE_Pos)
#define    FLASH_IER_CKIE                                         FLASH_IER_CKIE_Msk

#define    FLASH_IER_PRDIE_Pos                                    (1U)
#define    FLASH_IER_PRDIE_Msk                                    (0x1U << FLASH_IER_PRDIE_Pos)
#define    FLASH_IER_PRDIE                                        FLASH_IER_PRDIE_Msk

#define    FLASH_IER_ERDIE_Pos                                    (0U)
#define    FLASH_IER_ERDIE_Msk                                    (0x1U << FLASH_IER_ERDIE_Pos)
#define    FLASH_IER_ERDIE                                        FLASH_IER_ERDIE_Msk

#define    FLASH_ISR_KEYSTA_Pos                                   (17U)
#define    FLASH_ISR_KEYSTA_Msk                                   (0x7U << FLASH_ISR_KEYSTA_Pos)
#define    FLASH_ISR_KEYSTA                                       FLASH_ISR_KEYSTA_Msk

#define    FLASH_ISR_AUTHERR_Pos                                  (10U)
#define    FLASH_ISR_AUTHERR_Msk                                  (0x1U << FLASH_ISR_AUTHERR_Pos)
#define    FLASH_ISR_AUTHERR                                      FLASH_ISR_AUTHERR_Msk

#define    FLASH_ISR_KEYERR_Pos                                   (9U)
#define    FLASH_ISR_KEYERR_Msk                                   (0x1U << FLASH_ISR_KEYERR_Pos)
#define    FLASH_ISR_KEYERR                                       FLASH_ISR_KEYERR_Msk

#define    FLASH_ISR_CKERR_Pos                                    (8U)
#define    FLASH_ISR_CKERR_Msk                                    (0x1U << FLASH_ISR_CKERR_Pos)
#define    FLASH_ISR_CKERR                                        FLASH_ISR_CKERR_Msk

#define    FLASH_ISR_PRD_Pos                                      (1U)
#define    FLASH_ISR_PRD_Msk                                      (0x1U << FLASH_ISR_PRD_Pos)
#define    FLASH_ISR_PRD                                          FLASH_ISR_PRD_Msk

#define    FLASH_ISR_ERD_Pos                                      (0U)
#define    FLASH_ISR_ERD_Msk                                      (0x1U << FLASH_ISR_ERD_Pos)
#define    FLASH_ISR_ERD                                          FLASH_ISR_ERD_Msk

#define    FLASH_ERRIER_IE_Pos                                    (2U)
#define    FLASH_ERRIER_IE_Msk                                    (0x1U << FLASH_ERRIER_IE_Pos)
#define    FLASH_ERRIER_IE                                        FLASH_ERRIER_IE_Msk


#define    FLASH_ECCSR_PERDD_Pos                                  (31U)
#define    FLASH_ECCSR_PERDD_Msk                                  (0x1U << FLASH_ECCSR_PERDD_Pos)
#define    FLASH_ECCSR_PERDD                                      FLASH_ECCSR_PERDD_Msk

#define    FLASH_ECCSR_DC_Pos                                     (29U)
#define    FLASH_ECCSR_DC_Msk                                     (0x1U << FLASH_ECCSR_DC_Pos)
#define    FLASH_ECCSR_DC                                         FLASH_ECCSR_DC_Msk

#define    FLASH_ECCSR_CC_Pos                                     (28U)
#define    FLASH_ECCSR_CC_Msk                                     (0x1U << FLASH_ECCSR_CC_Pos)
#define    FLASH_ECCSR_CC                                         FLASH_ECCSR_CC_Msk

#define    FLASH_ECCSR_BE_Pos                                     (27U)
#define    FLASH_ECCSR_BE_Msk                                     (0x1U << FLASH_ECCSR_BE_Pos)
#define    FLASH_ECCSR_BE                                         FLASH_ECCSR_BE_Msk

#define    FLASH_ECCSR_CIE_Pos                                    (24U)
#define    FLASH_ECCSR_CIE_Msk                                    (0x1U << FLASH_ECCSR_CIE_Pos)
#define    FLASH_ECCSR_CIE                                        FLASH_ECCSR_CIE_Msk

#define    FLASH_ECCSR_FLS_SEL_Pos                                (15U)
#define    FLASH_ECCSR_FLS_SEL_Msk                                (0x1U << FLASH_ECCSR_FLS_SEL_Pos)
#define    FLASH_ECCSR_FLS_SEL                                     FLASH_ECCSR_FLS_SEL_Msk

#define    FLASH_ECCSR_ADDR_Pos                                   (0U)
#define    FLASH_ECCSR_ADDR_Msk                                   (0x7fffU << FLASH_ECCSR_ADDR_Pos)
#define    FLASH_ECCSR_ADDR                                       FLASH_ECCSR_ADDR_Msk

#define    FL_FLASH_ERASE_KEY                                    (0x96969696U)
#define    FL_FLASH_CHIP_ERASE_KEY                               (0x7D7D7D7DU)
#define    FL_FLASH_PAGE_ERASE_KEY                               (0xEAEAEAEAU)
#define    FL_FLASH_SECTOR_ERASE_KEY                             (0x3C3C3C3CU)
#define    FL_FLASH_ERASE_REQUEST                                (0x1234ABCDU)
#define    FL_FLASH_PROGRAM_KEY1                                 (0xA5A5A5A5U)
#define    FL_FLASH_PROGRAM_KEY2                                 (0xF1F1F1F1U)
/*8M*/
#define    FL_FLASH_ERASE_TIMEOUT                                (0x0000FFFFU)
#define    FL_FLASH_ADDRS_ALIGN                                  (0x00000004U)

#define    FL_FLASH_MAX_PAGE_NUM                                 (0x00000100U)
#define    FL_FLASH_MAX_SECTOR_NUM                               (0x00000040U)
#define    FL_FLASH_SECTOR_SIZE_BYTE                             (0x00000800U)
#define    FL_FLASH_PAGE_SIZE_BYTE                               (0x00000200U)
#define    FL_FLASH_ADDR_MAXPROGRAM                              (0x0005FFFFU)

#define    FL_CODE_FLASH_MAX_PAGE_NUM                            (0x00000300U)
#define    FL_CODE_FLASH_MAX_SECTOR_NUM                          (0x000000C0U)
#define    FL_CODE_FLASH_SECTOR_SIZE_BYTE                        (0x00000800U)
#define    FL_CODE_FLASH_PAGE_SIZE_BYTE                          (0x00000200U)
#define    FL_CODE_FLASH_ADDR_MAXPROGRAM                         (0x0001FFFFU)

#define    FL_DATA_FLASH_MAX_PAGE_NUM                            (0x0050001DU)
#define    FL_DATA_FLASH_MIN_PAGE_NUM                            (0x00500000U)
#define    FL_DATA_FLASH_MAX_SECTOR_NUM                          (0x00140008U)
#define    FL_DATA_FLASH_MIN_SECTOR_NUM                          (0x00140000U)
#define    FL_DATA_FLASH_SECTOR_SIZE_BYTE                        (0x00000800U)
#define    FL_DATA_FLASH_PAGE_SIZE_BYTE                          (0x00000200U)
#define    FL_DATA_FLASH_ADDR_MAXPROGRAM                         (0xA0003A00U)
#define    FL_DATA_FLASH_ADDR_MINPROGRAM                         (0xA0000000U)

#define    FL_FLASH_INFORMATION1_REGIN                            (0x1U << 17U)
#define    FL_FLASH_INFORMATION2_REGIN                            (0x1U << 18U)
#define    FL_FLASH_BLOCK_0                                       (0x1U << 0U)
#define    FL_FLASH_BLOCK_1                                       (0x1U << 1U)
#define    FL_FLASH_BLOCK_2                                       (0x1U << 2U)
#define    FL_FLASH_BLOCK_3                                       (0x1U << 3U)
#define    FL_FLASH_BLOCK_4                                       (0x1U << 4U)
#define    FL_FLASH_BLOCK_5                                       (0x1U << 5U)
#define    FL_FLASH_BLOCK_6                                       (0x1U << 6U)
#define    FL_FLASH_BLOCK_7                                       (0x1U << 7U)
#define    FL_FLASH_BLOCK_8                                       (0x1U << 8U)
#define    FL_FLASH_BLOCK_9                                       (0x1U << 9U)
#define    FL_FLASH_BLOCK_10                                      (0x1U << 10U)
#define    FL_FLASH_BLOCK_11                                      (0x1U << 11U)
#define    FL_FLASH_BLOCK_12                                      (0x1U << 12U)
#define    FL_FLASH_BLOCK_13                                      (0x1U << 13U)
#define    FL_FLASH_BLOCK_14                                      (0x1U << 14U)
#define    FL_FLASH_BLOCK_15                                      (0x1U << 15U)
#define    FL_FLASH_LOCK_ALL                                      (0x0U << 0U)
#define    FL_FLASH_LOCK_SOFTWARE                                 (0x2U << 0U)
#define    FL_FLASH_LOCK_NONE                                     (0x3U << 0U)
#define    FL_FLASH_APPCODE_LOCK_ENABLE                           (0x2U << 2U)
#define    FL_FLASH_APPCODE_LOCK_DISABLE                          (0x0U << 2U)
#define    FL_FLASH_DEBUG_READ_ENABLE                             (0x2U << 0U)
#define    FL_FLASH_DEBUG_READ_DISABLE                            (0x0U << 0U)


#define    FL_FLASH_READ_CODEWAIT_0CYCLE                          (0x0U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_1CYCLE                          (0x1U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_2CYCLE                          (0x2U << FLASH_RDCR_CODE_WAIT_Pos)
#define    FL_FLASH_READ_CODEWAIT_3CYCLE                          (0x3U << FLASH_RDCR_CODE_WAIT_Pos)

#define    FL_FLASH_IWDT_STOP_UNDER_SLEEP                         (0x0U << FLASH_OPTBR_IWDTSLP_Pos)
#define    FL_FLASH_IWDT_WORK_UNDER_SLEEP                         (0x1U << FLASH_OPTBR_IWDTSLP_Pos)

#define    FL_FLASH_IWDT_STOP_AFTERPOWERON                        (0x0U << FLASH_OPTBR_IWDTEN_Pos)
#define    FL_FLASH_IWDT_WORK_AFTERPOWERON                        (0x1U << FLASH_OPTBR_IWDTEN_Pos)

#define    FL_FLASH_FLASH_LOCK_DISABLE                            (0x0U << FLASH_OPTBR_ACLOCKEN_Pos)
#define    FL_FLASH_FLASH_LOCK_ENABLE                             (0x2U << FLASH_OPTBR_ACLOCKEN_Pos)

#define    FL_FLASH_SWD_READ_PEOTECTION_DISABLE                   (0x0U << FLASH_OPTBR_DBRDPEN_Pos)
#define    FL_FLASH_SWD_READ_PEOTECTION_ENABLE                    (0x2U << FLASH_OPTBR_DBRDPEN_Pos)

#define    FL_FLASH_ERASE_TYPE_PAGE                               (0x0U << FLASH_EPCR_ERTYPE_Pos)
#define    FL_FLASH_ERASE_TYPE_SECTOR                             (0x1U << FLASH_EPCR_ERTYPE_Pos)


#define    FL_FLASH_KEY_STATUS_LOCK                               (0x0U << FLASH_ISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_ALL_ERASE                          (0x1U << FLASH_ISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_PAGE_ERASE                         (0x2U << FLASH_ISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_PROGRAM                            (0x3U << FLASH_ISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_ERROR                              (0x4U << FLASH_ISR_KEYSTA_Pos)
#define    FL_FLASH_KEY_STATUS_SECTOR_ERASE                       (0x5U << FLASH_ISR_KEYSTA_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup FLASH_FL_Exported_Functions FLASH Exported Functions
  * @{
  */
/**
  * @brief    Data Flash wait cycles config
  * @rmtoll   RDCR    DATA_WAIT    FL_FLASH_SetDataReadWait
  * @param    FLASHx FLASH instance
  * @param    wait This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetDataReadWait(FLASH_Type *FLASHx, uint32_t wait)
{
   // MODIFY_REG(FLASHx->RDCR, FLASH_RDCR_CODE_WAIT_Msk, wait);
}

/**
  * @brief    Get Data flash wait cycles config status
  * @rmtoll   RDCR    DATA_WAIT    FL_FLASH_GetDataReadWait
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_FLASH_GetDataReadWait(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->RDCR, FLASH_RDCR_CODE_WAIT_Msk));
}

/**
  * @brief    Flash Code wait cycles config
  * @rmtoll   RDCR    CODE_WAIT    FL_FLASH_SetCodeReadWait
  * @param    FLASHx FLASH instance
  * @param    wait This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_READ_CODEWAIT_0CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_1CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_2CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_3CYCLE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetCodeReadWait(FLASH_Type *FLASHx, uint32_t wait)
{
    MODIFY_REG(FLASHx->RDCR, FLASH_RDCR_CODE_WAIT_Msk, wait);
}

/**
  * @brief    Get Code flash wait cycles config status
  * @rmtoll   RDCR    CODE_WAIT    FL_FLASH_GetCodeReadWait
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_READ_CODEWAIT_0CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_1CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_2CYCLE
  *           @arg @ref FL_FLASH_READ_CODEWAIT_3CYCLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetCodeReadWait(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->RDCR, FLASH_RDCR_CODE_WAIT_Msk));
}

/**
  * @brief    Prefetch enable
  * @rmtoll   PFTCON    PFTPHASEEN    FL_FLASH_Enable_Prefetch
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_Enable_Prefetch(FLASH_Type *FLASHx)
{
    SET_BIT(FLASHx->PFTCON, FLASH_PFTCON_EN_Msk);
}

/**
  * @brief    Get Prefetch enable status
  * @rmtoll   CR1    CEN    FL_FLASH_IsEnabled_Prefetch
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabled_Prefetch(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->PFTCON, FLASH_PFTCON_EN_Msk) == FLASH_PFTCON_EN_Msk);
}


/**
  * @brief    Prefetch disable
  * @rmtoll   CR1    CEN    FL_FLASH_Disable_Prefetch
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_Disable_Prefetch(FLASH_Type *FLASHx)
{
    CLEAR_BIT(FLASHx->PFTCON, FLASH_PFTCON_EN_Msk);
}

/**
  * @brief    Get IWDT sleep enable status
  * @rmtoll   OPTBR    IWDTSLP    FL_FLASH_GetIWDTStateUnderSleep
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_IWDT_STOP_UNDER_SLEEP
  *           @arg @ref FL_FLASH_IWDT_WORK_UNDER_SLEEP
  */
__STATIC_INLINE uint32_t FL_FLASH_GetIWDTStateUnderSleep(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_IWDTSLP_Msk));
}

/**
  * @brief    Get IWDT status after poweron
  * @rmtoll   OPTBR    IWDTEN    FL_FLASH_GetIWDTStateAfterPowerOn
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_IWDT_STOP_AFTERPOWERON
  *           @arg @ref FL_FLASH_IWDT_WORK_AFTERPOWERON
  */
__STATIC_INLINE uint32_t FL_FLASH_GetIWDTStateAfterPowerOn(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_IWDTEN_Msk));
}

/**
  * @brief    Get AppCode lock enable
  * @rmtoll   OPTBR    ACLOCKEN    FL_FLASH_GetFlashLockState
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_FLASH_LOCK_DISABLE
  *           @arg @ref FL_FLASH_FLASH_LOCK_ENABLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetFlashLockState(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_ACLOCKEN_Msk));
}

/**
  * @brief    Get debug read protection enable status
  * @rmtoll   OPTBR    DBRDPEN    FL_FLASH_GetSWDReadProtectionState
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_SWD_READ_PEOTECTION_DISABLE
  *           @arg @ref FL_FLASH_SWD_READ_PEOTECTION_ENABLE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetSWDReadProtectionState(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->OPTBR, FLASH_OPTBR_DBRDPEN_Msk));
}

/**
  * @brief    Set ACLOCK1 register
  * @rmtoll   ACLOCK1        FL_FLASH_SetFlashLock1
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_BLOCK_0
  *           @arg @ref FL_FLASH_BLOCK_1
  *           @arg @ref FL_FLASH_BLOCK_2
  *           @arg @ref FL_FLASH_BLOCK_3
  *           @arg @ref FL_FLASH_BLOCK_4
  *           @arg @ref FL_FLASH_BLOCK_5
  *           @arg @ref FL_FLASH_BLOCK_6
  *           @arg @ref FL_FLASH_BLOCK_7
  *           @arg @ref FL_FLASH_BLOCK_8
  *           @arg @ref FL_FLASH_BLOCK_9
  *           @arg @ref FL_FLASH_BLOCK_10
  *           @arg @ref FL_FLASH_BLOCK_11
  *           @arg @ref FL_FLASH_BLOCK_12
  *           @arg @ref FL_FLASH_BLOCK_13
  *           @arg @ref FL_FLASH_BLOCK_14
  *           @arg @ref FL_FLASH_BLOCK_15
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_LOCK_ALL
  *           @arg @ref FL_FLASH_LOCK_SOFTWARE
  *           @arg @ref FL_FLASH_LOCK_NONE
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetFlashRegion1Lock(FLASH_Type *FLASHx, uint32_t region, uint32_t mode)
{
    CLEAR_BIT(FLASHx->ACLOCK1, ((region * region) * (((mode == 3) ? 0 : (~mode)) & 0x03)));
}

/**
  * @brief    Get ACLOCK1 register
  * @rmtoll   ACLOCK1        FL_FLASH_GetFlashLock1
  * @param    FLASHx FLASH instance
  * @param    region This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_BLOCK_0
  *           @arg @ref FL_FLASH_BLOCK_1
  *           @arg @ref FL_FLASH_BLOCK_2
  *           @arg @ref FL_FLASH_BLOCK_3
  *           @arg @ref FL_FLASH_BLOCK_4
  *           @arg @ref FL_FLASH_BLOCK_5
  *           @arg @ref FL_FLASH_BLOCK_6
  *           @arg @ref FL_FLASH_BLOCK_7
  *           @arg @ref FL_FLASH_BLOCK_8
  *           @arg @ref FL_FLASH_BLOCK_9
  *           @arg @ref FL_FLASH_BLOCK_10
  *           @arg @ref FL_FLASH_BLOCK_11
  *           @arg @ref FL_FLASH_BLOCK_12
  *           @arg @ref FL_FLASH_BLOCK_13
  *           @arg @ref FL_FLASH_BLOCK_14
  *           @arg @ref FL_FLASH_BLOCK_15
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_FLASH_GetFlashRegion1Lock(FLASH_Type *FLASHx, uint32_t region)
{
    return (uint32_t)(READ_BIT(FLASHx->ACLOCK1, ((region * region) * 0x03)) / (region * region));
}


/**
  * @brief    Set flash erase type
  * @rmtoll   EPCR    ERTYPE    FL_FLASH_SetFlashEraseType
  * @param    FLASHx FLASH instance
  * @param    type This parameter can be one of the following values:
  *           @arg @ref FL_FLASH_ERASE_TYPE_PAGE
  *           @arg @ref FL_FLASH_ERASE_TYPE_SECTOR
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_SetFlashEraseType(FLASH_Type *FLASHx, uint32_t type)
{
    MODIFY_REG(FLASHx->EPCR, FLASH_EPCR_ERTYPE_Msk, type);
}

/**
  * @brief    Get flash erase type
  * @rmtoll   EPCR    ERTYPE    FL_FLASH_GetFlashEraseType
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_ERASE_TYPE_PAGE
  *           @arg @ref FL_FLASH_ERASE_TYPE_SECTOR
  */
__STATIC_INLINE uint32_t FL_FLASH_GetFlashEraseType(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->EPCR, FLASH_EPCR_ERTYPE_Msk));
}

/**
  * @brief    Program request enable
  * @rmtoll   EPCR    PREQ    FL_FLASH_EnableProgram
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableProgram(FLASH_Type *FLASHx)
{
    CLEAR_BIT(FLASHx->EPCR, FLASH_EPCR_EREQ_Msk);
    SET_BIT(FLASHx->EPCR, FLASH_EPCR_PREQ_Msk);
}

/**
  * @brief    Erase request enable
  * @rmtoll   EPCR    EREQ    FL_FLASH_EnableErase
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableErase(FLASH_Type *FLASHx)
{
    CLEAR_BIT(FLASHx->EPCR, FLASH_EPCR_PREQ_Msk);
    SET_BIT(FLASHx->EPCR, FLASH_EPCR_EREQ_Msk);
}

/**
  * @brief    Set flash key
  * @rmtoll   KEY        FL_FLASH_UnlockFlash
  * @param    FLASHx FLASH instance
  * @param    key
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_UnlockFlash(FLASH_Type *FLASHx, uint32_t key)
{
    WRITE_REG(FLASHx->KEY, key);
}

/**
  * @brief    Reset flash key
  * @rmtoll   KEY        FL_FLASH_LockFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_LockFlash(FLASH_Type *FLASHx)
{
    WRITE_REG(FLASHx->KEY, 0xFFFFFFFF);
}

/**
  * @brief    Flash authentication error interrupt enable
  * @rmtoll   IER    AUTHIE    FL_FLASH_EnableIT_AuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_AuthenticationError(FLASH_Type *FLASHx)
{
    SET_BIT(FLASHx->IER, FLASH_IER_AUTHIE_Msk);
}

/**
  * @brief    Flash authentication error interrupt disable
  * @rmtoll   IER    AUTHIE    FL_FLASH_DisableIT_AuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_AuthenticationError(FLASH_Type *FLASHx)
{
    CLEAR_BIT(FLASHx->IER, FLASH_IER_AUTHIE_Msk);
}

/**
  * @brief    Get flash authentication error interrupt enable status
  * @rmtoll   IER    AUTHIE    FL_FLASH_IsEnabledIT_AuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_AuthenticationError(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->IER, FLASH_IER_AUTHIE_Msk) == FLASH_IER_AUTHIE_Msk);
}

/**
  * @brief    Flash key error interrupt enable
  * @rmtoll   IER    KEYIE    FL_FLASH_EnableIT_KeyError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_KeyError(FLASH_Type *FLASHx)
{
    SET_BIT(FLASHx->IER, FLASH_IER_KEYIE_Msk);
}

/**
  * @brief    Flash key error interrupt disable
  * @rmtoll   IER    KEYIE    FL_FLASH_DisableIT_KeyError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_KeyError(FLASH_Type *FLASHx)
{
    CLEAR_BIT(FLASHx->IER, FLASH_IER_KEYIE_Msk);
}

/**
  * @brief    Get Flash key error interrupt enable status
  * @rmtoll   IER    KEYIE    FL_FLASH_IsEnabledIT_KeyError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_KeyError(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->IER, FLASH_IER_KEYIE_Msk) == FLASH_IER_KEYIE_Msk);
}

/**
  * @brief    Erase/Program clock error interrupt enable
  * @rmtoll   IER    CKIE    FL_FLASH_EnableIT_ClockError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ClockError(FLASH_Type *FLASHx)
{
    SET_BIT(FLASHx->IER, FLASH_IER_CKIE_Msk);
}

/**
  * @brief    Erase/Program clock error interrupt disable
  * @rmtoll   IER    CKIE    FL_FLASH_DisableIT_ClockError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ClockError(FLASH_Type *FLASHx)
{
    CLEAR_BIT(FLASHx->IER, FLASH_IER_CKIE_Msk);
}

/**
  * @brief    Get Erase/Program clock error interrupt enable status
  * @rmtoll   IER    CKIE    FL_FLASH_IsEnabledIT_ClockError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ClockError(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->IER, FLASH_IER_CKIE_Msk) == FLASH_IER_CKIE_Msk);
}

/**
  * @brief    Program done interrupt enable
  * @rmtoll   IER    PRDIE    FL_FLASH_EnableIT_ProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ProgramComplete(FLASH_Type *FLASHx)
{
    SET_BIT(FLASHx->IER, FLASH_IER_PRDIE_Msk);
}

/**
  * @brief    Program done interrupt disable
  * @rmtoll   IER    PRDIE    FL_FLASH_DisableIT_ProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ProgramComplete(FLASH_Type *FLASHx)
{
    CLEAR_BIT(FLASHx->IER, FLASH_IER_PRDIE_Msk);
}

/**
  * @brief    Get program done interrupt enable status
  * @rmtoll   IER    PRDIE    FL_FLASH_IsEnabledIT_ProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ProgramComplete(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->IER, FLASH_IER_PRDIE_Msk) == FLASH_IER_PRDIE_Msk);
}

/**
  * @brief    Erase done interrupt enable
  * @rmtoll   IER    ERDIE    FL_FLASH_EnableIT_EraseComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_EraseComplete(FLASH_Type *FLASHx)
{
    SET_BIT(FLASHx->IER, FLASH_IER_ERDIE_Msk);
}

/**
  * @brief    Erase done interrupt disable
  * @rmtoll   IER    ERDIE    FL_FLASH_DisableIT_EraseComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_EraseComplete(FLASH_Type *FLASHx)
{
    CLEAR_BIT(FLASHx->IER, FLASH_IER_ERDIE_Msk);
}

/**
  * @brief    Get erase done interrupt enable status
  * @rmtoll   IER    ERDIE    FL_FLASH_IsEnabledIT_EraseComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_EraseComplete(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->IER, FLASH_IER_ERDIE_Msk) == FLASH_IER_ERDIE_Msk);
}

/**
  * @brief    Get flash key status
  * @rmtoll   ISR    KEYSTA    FL_FLASH_GetFlashLockStatus
  * @param    FLASHx FLASH instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_FLASH_KEY_STATUS_LOCK
  *           @arg @ref FL_FLASH_KEY_STATUS_ALL_ERASE
  *           @arg @ref FL_FLASH_KEY_STATUS_PAGE_ERASE
  *           @arg @ref FL_FLASH_KEY_STATUS_PROGRAM
  *           @arg @ref FL_FLASH_KEY_STATUS_ERROR
  *           @arg @ref FL_FLASH_KEY_STATUS_SECTOR_ERASE
  */
__STATIC_INLINE uint32_t FL_FLASH_GetFlashLockStatus(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ISR, FLASH_ISR_KEYSTA_Msk));
}

/**
  * @brief    Get Flash Authentication Error Flag
  * @rmtoll   ISR    AUTHERR    FL_FLASH_IsActiveFlag_AuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_AuthenticationError(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ISR, FLASH_ISR_AUTHERR_Msk) == (FLASH_ISR_AUTHERR_Msk));
}

/**
  * @brief    ClearFlash Authentication Error Flag
  * @rmtoll   ISR    AUTHERR    FL_FLASH_ClearFlag_AuthenticationError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_AuthenticationError(FLASH_Type *FLASHx)
{
    WRITE_REG(FLASHx->ISR, FLASH_ISR_AUTHERR_Msk);
}

/**
  * @brief    Get Flash Key Error Flag
  * @rmtoll   ISR    KEYERR    FL_FLASH_IsActiveFlag_KeyError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_KeyError(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ISR, FLASH_ISR_KEYERR_Msk) == (FLASH_ISR_KEYERR_Msk));
}

/**
  * @brief    Clear Flash Key Error Flag
  * @rmtoll   ISR    KEYERR    FL_FLASH_ClearFlag_KeyError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_KeyError(FLASH_Type *FLASHx)
{
    WRITE_REG(FLASHx->ISR, FLASH_ISR_KEYERR_Msk);
}

/**
  * @brief    Get Erase/Program Clock Error Flag
  * @rmtoll   ISR    CKERR    FL_FLASH_IsActiveFlag_ClockError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ClockError(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ISR, FLASH_ISR_CKERR_Msk) == (FLASH_ISR_CKERR_Msk));
}

/**
  * @brief    Clear Erase/Program Clock Error Flag
  * @rmtoll   ISR    CKERR    FL_FLASH_ClearFlag_ClockError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ClockError(FLASH_Type *FLASHx)
{
    WRITE_REG(FLASHx->ISR, FLASH_ISR_CKERR_Msk);
}

/**
  * @brief    Get Program Done Flag
  * @rmtoll   ISR    PRD    FL_FLASH_IsActiveFlag_ProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ProgramComplete(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ISR, FLASH_ISR_PRD_Msk) == (FLASH_ISR_PRD_Msk));
}

/**
  * @brief    Clear Program Done Flag
  * @rmtoll   ISR    PRD    FL_FLASH_ClearFlag_ProgramComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ProgramComplete(FLASH_Type *FLASHx)
{
    WRITE_REG(FLASHx->ISR, FLASH_ISR_PRD_Msk);
}

/**
  * @brief    Get Erase Done Flag
  * @rmtoll   ISR    ERD    FL_FLASH_IsActiveFlag_EraseComplete
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_EraseComplete(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ISR, FLASH_ISR_ERD_Msk) == (FLASH_ISR_ERD_Msk));
}

/**
  * @brief    Clear Erase Done Flag
  * @rmtoll   ISR    ERD    FL_FLASH_ClearFlag_EraseComplete
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_EraseComplete(FLASH_Type *FLASHx)
{
    WRITE_REG(FLASHx->ISR, FLASH_ISR_ERD_Msk);
}

/**
  * @brief    Flash ECC Detect Error interrupt enable
  * @rmtoll   ERRIER   IE   FL_FLASH_EnableIT_DetectError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_DetectError(FLASH_Type *FLASHx)
{
    SET_BIT(FLASHx->ERRIER, FLASH_ERRIER_IE_Msk);
}
/**
  * @brief    Flash ECC Detect Error interrupt disable
  * @rmtoll   ERRIER   IE   FL_FLASH_DisableIT_DetectError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_DetectError(FLASH_Type *FLASHx)
{
    CLEAR_BIT(FLASHx->ERRIER, FLASH_ERRIER_IE_Msk);
}
/**
  * @brief    Get Flash ECC Detect Error interrupt enable status
  * @rmtoll   ERRIER   IE   FL_FLASH_IsEnabledIT_DetectError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_DetectError(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ERRIER, FLASH_ERRIER_IE_Msk) == FLASH_ERRIER_IE_Msk);
}


/**
  * @brief    Parity Detection in Data Flash
  * @rmtoll   ECCSR    DD    FL_FLASH_IsActiveFlag_ParityDetectionInDataFlash
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ParityDetectionInDataFlash(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, FLASH_ECCSR_PERDD_Msk) == (FLASH_ECCSR_PERDD_Msk));
}

/**
  * @brief    Clear Parity Detection in Data Flash Flag
  * @rmtoll   ECCSR    DD    FL_FLASH_ClearFlag_ParityDetectionInDataFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ParityDetectionInDataFlash(FLASH_Type *FLASHx)
{
    SET_BIT(FLASHx->ECCSR, FLASH_ECCSR_PERDD_Msk);
    CLEAR_BIT(FLASHx->ERRIER, FLASH_ERRIER_IE_Msk);
}

/**
  * @brief    ECC Detection in Code Flash
  * @rmtoll   ECCSR    DC    FL_FLASH_IsActiveFlag_ECCDetectionInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCDetectionInCodeFlash(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, FLASH_ECCSR_DC_Msk) == (FLASH_ECCSR_DC_Msk));
}

/**
  * @brief    Clear ECC Detection in Code Flash Flag
  * @rmtoll   ECCSR    DC    FL_FLASH_ClearFlag_ECCDetectionInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCDetectionInCodeFlash(FLASH_Type *FLASHx)
{
    SET_BIT(FLASHx->ECCSR, FLASH_ECCSR_DC_Msk);
    CLEAR_BIT(FLASHx->ERRIER, FLASH_ERRIER_IE_Msk);
}

/**
  * @brief    ECC Correction in Code Flash
  * @rmtoll   ECCSR    CC    FL_FLASH_IsActiveFlag_ECCCorrectionInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCCorrectionInCodeFlash(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, FLASH_ECCSR_CC_Msk) == (FLASH_ECCSR_CC_Msk));
}

/**
  * @brief    Clear  Correction in Code Flash Flag
  * @rmtoll   ECCSR    CC    FL_FLASH_ClearFlag_ECCCorrectionInCodeFlash
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCCorrectionInCodeFlash(FLASH_Type *FLASHx)
{
    WRITE_REG(FLASHx->ECCSR, (FLASH_ECCSR_CC_Msk | (FLASHx->ECCSR & FLASH_ECCSR_CIE_Msk)));
}

/**
  * @brief    Get ECC Bit Error Flag
  * @rmtoll   ECCSR    BE    FL_FLASH_IsActiveFlag_ECCBitError
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_ECCBitError(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, FLASH_ECCSR_BE_Msk) == (FLASH_ECCSR_BE_Msk));
}

/**
  * @brief    Clear ECC Bit Error Flag
  * @rmtoll   ECCSR    BE    FL_FLASH_ClearFlag_ECCBitError
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_ClearFlag_ECCBitError(FLASH_Type *FLASHx)
{
    WRITE_REG(FLASHx->ECCSR, (FLASH_ECCSR_BE_Msk | (FLASHx->ECCSR & FLASH_ECCSR_CIE_Msk)));
}

/**
  * @brief    ECC Correction interrupt enable
  * @rmtoll   ECCSR    CIE    FL_FLASH_EnableIT_ECCCorrection
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_EnableIT_ECCCorrection(FLASH_Type *FLASHx)
{
    SET_BIT(FLASHx->ECCSR, FLASH_ECCSR_CIE_Msk);
}

/**
  * @brief    ECC Correctioninterrupt disable
  * @rmtoll   ECCSR    CIE    FL_FLASH_DisableIT_ECCCorrection
  * @param    FLASHx FLASH instance
  * @retval   None
  */
__STATIC_INLINE void FL_FLASH_DisableIT_ECCCorrection(FLASH_Type *FLASHx)
{
    CLEAR_BIT(FLASHx->ECCSR, FLASH_ECCSR_CIE_Msk);
}

/**
  * @brief    Get ECC Correctioninter interrupt enable status
  * @rmtoll   ECCSR    CIE    FL_FLASH_IsEnabledIT_ECCCorrection
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsEnabledIT_ECCCorrection(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, FLASH_ECCSR_CIE_Msk) == FLASH_ECCSR_CIE_Msk);
}

/**
  * @brief    Get Flash ECC ERROR status
  * @rmtoll   ECCSR    FLS_SEL    FL_FLASH_IsActiveFlag_FlashSEL
  * @param    FLASHx FLASH instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_FLASH_IsActiveFlag_FlashSEL(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, FLASH_ECCSR_FLS_SEL_Msk) == (FLASH_ECCSR_FLS_SEL_Msk));
}

/**
  * @brief    Read ECC Error Address
  * @rmtoll   ECCSR    ADDR    FL_FLASH_ReadECCErrorAddress
  * @param    FLASHx FLASH instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_FLASH_ReadECCErrorAddress(FLASH_Type *FLASHx)
{
    return (uint32_t)(READ_BIT(FLASHx->ECCSR, (0x1ffffU << 0U)) >> 0U);
}

 
/**
  * @}
  */

/** @defgroup FLASH_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_FLASH_PageErase(FLASH_Type *FLASHx, uint32_t address);
FL_ErrorStatus FL_FLASH_SectorErase(FLASH_Type *FLASHx, uint32_t address);

FL_ErrorStatus FL_FLASH_Program_Word(FLASH_Type *FLASHx, uint32_t address, uint32_t data);
FL_ErrorStatus FL_FLASH_Program_Page(FLASH_Type *FLASHx, uint32_t pageNum, uint32_t *data);
FL_ErrorStatus FL_FLASH_Program_Sector(FLASH_Type *FLASHx, uint32_t sectorNum, uint32_t *data);

FL_ErrorStatus FL_FLASH_Write_Dma(FLASH_Type *FLASHx, uint32_t address, uint32_t *data);
FL_ErrorStatus FL_FLASH_Read_Dma(FLASH_Type *FLASHx, uint32_t address, uint32_t *data, uint32_t length);

/**
  * @}
  */


/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33LR0XX_FL_FLASH_H*/


/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
