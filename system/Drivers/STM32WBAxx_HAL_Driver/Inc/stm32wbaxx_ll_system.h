/**
  ******************************************************************************
  * @file    stm32wbaxx_ll_system.h
  * @author  MCD Application Team
  * @brief   Header file of SYSTEM LL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The LL SYSTEM driver contains a set of generic APIs that can be
    used by user:
      (+) Some of the FLASH features need to be handled in the SYSTEM file.
      (+) Access to DBGCMU registers
      (+) Access to SYSCFG registers
      (+) Access to VREFBUF registers (not available on all devices)
  @endverbatim
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32WBAxx_LL_SYSTEM_H
#define STM32WBAxx_LL_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32wbaxx.h"

/** @addtogroup STM32WBAxx_LL_Driver
  * @{
  */

#if defined (FLASH) || defined (SYSCFG) || defined (DBGMCU) || defined (VREFBUF)

/** @defgroup SYSTEM_LL SYSTEM
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Private_Constants SYSTEM LL Private Constants
  * @{
  */

/**
  * @brief Power-down in Run mode Flash key
  */
#if defined(FLASH_DBANK_SUPPORT)
#define FLASH_PDKEY1_1                 0x04152637U /*!< Flash bank 1 power down key1 */
#define FLASH_PDKEY1_2                 0xFAFBFCFDU /*!< Flash bank 1 power down key2: used with FLASH_PDKEY1R
                                                       to unlock the PDREQ1 bit in FLASH_ACR */
#define FLASH_PDKEY2_1                 0x40516273U /*!< Flash bank 2 power down key1 */
#define FLASH_PDKEY2_2                 0xAFBFCFDFU /*!< Flash bank 2 power down key2: used with FLASH_PDKEY2R
                                                       to unlock the PDREQ2 bit in FLASH_ACR */
#else
#define FLASH_PDKEY1_1                 0x04152637U /*!< Flash power down key1 */
#define FLASH_PDKEY1_2                 0xFAFBFCFDU /*!< Flash power down key2: used with FLASH_PDKEYR
                                                       to unlock the PDREQ bit in FLASH_ACR */
#endif /* FLASH_DBANK_SUPPORT */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Exported_Constants SYSTEM Exported Constants
  * @{
  */

/** @defgroup SYSTEM_LL_EC_CS1 SYSCFG SYSCFG Vdd compensation cell Code selection
  * @{
  */
#define LL_SYSCFG_VDD_CELL_CODE                  0U               /*VDD I/Os code from the cell (available in the SYSCFG_CCVR)*/
#define LL_SYSCFG_VDD_REGISTER_CODE              SYSCFG_CCCSR_CS1 /*VDD I/Os code from the SYSCFG compensation cell code register (SYSCFG_CCCR)*/
/**
  * @}
  */

#ifdef SYSCFG_CCCSR_EN2
/** @defgroup SYSTEM_LL_EC_CS2 SYSCFG SYSCFG VddIO2 compensation cell Code selection
  * @{
  */
#define LL_SYSCFG_VDDIO2_CELL_CODE               0U               /*VDDIO2 I/Os code from the cell (available in the SYSCFG_CCVR)*/
#define LL_SYSCFG_VDDIO2_REGISTER_CODE           SYSCFG_CCCSR_CS2 /*VDDIO2 I/Os code from the SYSCFG compensation cell code register (SYSCFG_CCCR)*/
/**
  * @}
  */
#endif /* SYSCFG_CCCSR_EN2 */

/** @defgroup SYSTEM_LL_EC_ERASE_MEMORIES_STATUS SYSCFG MEMORIES ERASE
  * @{
  */
#define LL_SYSCFG_MEMORIES_ERASE_ON_GOING         0U               /*Memory erase on going*/
#define LL_SYSCFG_MEMORIES_ERASE_ENDED            SYSCFG_MESR_MCLR /*Memory erase done */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_I2C_FASTMODEPLUS SYSCFG I2C FASTMODEPLUS
  * @{
  */
#define LL_SYSCFG_I2C_FASTMODEPLUS_PA6     SYSCFG_CFGR1_PA6_FMP   /*!< Enable Fast Mode Plus on PA6  */
#define LL_SYSCFG_I2C_FASTMODEPLUS_PA7     SYSCFG_CFGR1_PA7_FMP   /*!< Enable Fast Mode Plus on PA7  */
#define LL_SYSCFG_I2C_FASTMODEPLUS_PA15    SYSCFG_CFGR1_PA15_FMP  /*!< Enable Fast Mode Plus on PA15 */
#define LL_SYSCFG_I2C_FASTMODEPLUS_PB3     SYSCFG_CFGR1_PB3_FMP   /*!< Enable Fast Mode Plus on PB3  */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_TIMBREAK SYSCFG TIMER BREAK
  * @{
  */
#define LL_SYSCFG_TIMBREAK_ECC             SYSCFG_CFGR2_ECCL  /*!< Enables and locks the ECC error signal
                                                                   with Break Input of TIM1/16/17                       */
#define LL_SYSCFG_TIMBREAK_PVD             SYSCFG_CFGR2_PVDL  /*!< Enables and locks the PVD connection
                                                                   with TIM1/16/17 Break Input and also
                                                                   the PVDE and PLS bits of the Power Control Interface */
#define LL_SYSCFG_TIMBREAK_SRAM_ECC_LOCK   SYSCFG_CFGR2_SPL   /*!< Enables and locks the SRAM ECC double error signal
                                                                   with Break Input of TIM1/16/17                       */
#define LL_SYSCFG_TIMBREAK_LOCKUP          SYSCFG_CFGR2_CLL   /*!< Enables and locks the LOCKUP output of CortexM33
                                                                   with Break Input of TIM1/16/17                       */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_SECURE_ATTRIBUTES Secure attributes
  * @note Only available when system implements security (TZEN=1)
  * @{
  */
#define LL_SYSCFG_CLOCK_SEC                SYSCFG_SECCFGR_SYSCFGSEC  /*!< SYSCFG clock configuration secure-only access */
#define LL_SYSCFG_CLOCK_NSEC               0U                        /*!< SYSCFG clock configuration secure/non-secure access */
#define LL_SYSCFG_CLASSB_SEC               SYSCFG_SECCFGR_CLASSBSEC  /*!< Class B configuration secure-only access */
#define LL_SYSCFG_CLASSB_NSEC              0U                        /*!< Class B configuration secure/non-secure access */
#define LL_SYSCFG_FPU_SEC                  SYSCFG_SECCFGR_FPUSEC     /*!< FPU configuration secure-only access */
#define LL_SYSCFG_FPU_NSEC                 0U                        /*!< FPU configuration secure/non-secure access */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_APB1_GRP1_STOP_IP DBGMCU APB1 GRP1 STOP IP
  * @{
  */
#define LL_DBGMCU_APB1_GRP1_TIM2_STOP      DBGMCU_APB1LFZR_DBG_TIM2_STOP   /*!< The counter clock of TIM2 is stopped when the core is halted*/
#define LL_DBGMCU_APB1_GRP1_TIM3_STOP      DBGMCU_APB1LFZR_DBG_TIM3_STOP   /*!< The counter clock of TIM3 is stopped when the core is halted*/
#if defined(TIM4)
#define LL_DBGMCU_APB1_GRP1_TIM4_STOP      DBGMCU_APB1LFZR_DBG_TIM4_STOP   /*!< The counter clock of TIM4 is stopped when the core is halted*/
#endif /* TIM4 */
#define LL_DBGMCU_APB1_GRP1_WWDG_STOP      DBGMCU_APB1LFZR_DBG_WWDG_STOP   /*!< The window watchdog counter clock is stopped when the core is halted*/
#define LL_DBGMCU_APB1_GRP1_IWDG_STOP      DBGMCU_APB1LFZR_DBG_IWDG_STOP   /*!< The independent watchdog counter clock is stopped when the core is halted*/
#if defined(I2C1)
#define LL_DBGMCU_APB1_GRP1_I2C1_STOP      DBGMCU_APB1LFZR_DBG_I2C1_STOP   /*!< The I2C1 SMBus timeout is frozen*/
#endif /* I2C1 */
#if defined(I2C2)
#define LL_DBGMCU_APB1_GRP1_I2C2_STOP      DBGMCU_APB1LFZR_DBG_I2C2_STOP   /*!< The I2C2 SMBus timeout is frozen*/
#endif /* I2C2 */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_APB1_GRP2_STOP_IP DBGMCU APB1 GRP2 STOP IP
  * @{
  */
#if defined(I2C4)
#define LL_DBGMCU_APB1_GRP2_I2C4_STOP      DBGMCU_APB1HFZR_DBG_I2C4_STOP   /*!< The I2C4 SMBus timeout is frozen*/
#endif /* I2C4 */
#if defined(LPTIM2)
#define LL_DBGMCU_APB1_GRP2_LPTIM2_STOP    DBGMCU_APB1HFZR_DBG_LPTIM2_STOP /*!< The counter clock of LPTIM2 is stopped when the core is halted*/
#endif /* LPTIM2 */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_APB2_GRP1_STOP_IP DBGMCU APB2 GRP1 STOP IP
  * @{
  */
#define LL_DBGMCU_APB2_GRP1_TIM1_STOP      DBGMCU_APB2FZR_DBG_TIM1_STOP    /*!< The counter clock of TIM1 is stopped when the core is halted*/
#define LL_DBGMCU_APB2_GRP1_TIM16_STOP     DBGMCU_APB2FZR_DBG_TIM16_STOP   /*!< The counter clock of TIM16 is stopped when the core is halted*/
#define LL_DBGMCU_APB2_GRP1_TIM17_STOP     DBGMCU_APB2FZR_DBG_TIM17_STOP   /*!< The counter clock of TIM17 is stopped when the core is halted*/
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_APB7_GRP1_STOP_IP DBGMCU APB7 GRP1 STOP IP
  * @{
  */
#define LL_DBGMCU_APB7_GRP1_I2C3_STOP      DBGMCU_APB7FZR_DBG_I2C3_STOP    /*!< The counter clock of I2C3 is stopped when the core is halted*/
#define LL_DBGMCU_APB7_GRP1_LPTIM1_STOP    DBGMCU_APB7FZR_DBG_LPTIM1_STOP  /*!< The counter clock of LPTIM1 is stopped when the core is halted*/
#define LL_DBGMCU_APB7_GRP1_RTC_STOP       DBGMCU_APB7FZR_DBG_RTC_STOP     /*!< The counter clock of RTC is stopped when the core is halted*/
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_LATENCY FLASH LATENCY
  * @{
  */
#define LL_FLASH_LATENCY_0    0                                                                 /*!< FLASH Zero wait state      */
#define LL_FLASH_LATENCY_1    FLASH_ACR_LATENCY_0                                               /*!< FLASH One wait state       */
#define LL_FLASH_LATENCY_2    FLASH_ACR_LATENCY_1                                               /*!< FLASH Two wait states      */
#define LL_FLASH_LATENCY_3    (FLASH_ACR_LATENCY_1 | FLASH_ACR_LATENCY_0)                       /*!< FLASH Three wait states    */
#define LL_FLASH_LATENCY_4    FLASH_ACR_LATENCY_2                                               /*!< FLASH Four wait states     */
#define LL_FLASH_LATENCY_5    (FLASH_ACR_LATENCY_2 | FLASH_ACR_LATENCY_0)                       /*!< FLASH Five wait state      */
#define LL_FLASH_LATENCY_6    (FLASH_ACR_LATENCY_2 | FLASH_ACR_LATENCY_1)                       /*!< FLASH Six wait state       */
#define LL_FLASH_LATENCY_7    (FLASH_ACR_LATENCY_2 | FLASH_ACR_LATENCY_1 | FLASH_ACR_LATENCY_0) /*!< FLASH Seven wait states    */
#define LL_FLASH_LATENCY_8    FLASH_ACR_LATENCY_3                                               /*!< FLASH Eight wait states    */
#define LL_FLASH_LATENCY_9    (FLASH_ACR_LATENCY_3 | FLASH_ACR_LATENCY_0)                       /*!< FLASH Nine wait states     */
#define LL_FLASH_LATENCY_10   (FLASH_ACR_LATENCY_3 | FLASH_ACR_LATENCY_1)                       /*!< FLASH Ten wait state       */
#define LL_FLASH_LATENCY_11   (FLASH_ACR_LATENCY_3 | FLASH_ACR_LATENCY_1 | FLASH_ACR_LATENCY_0) /*!< FLASH Eleven wait state    */
#define LL_FLASH_LATENCY_12   (FLASH_ACR_LATENCY_3 | FLASH_ACR_LATENCY_2)                       /*!< FLASH Twelve wait states   */
#define LL_FLASH_LATENCY_13   (FLASH_ACR_LATENCY_3 | FLASH_ACR_LATENCY_2 | FLASH_ACR_LATENCY_0) /*!< FLASH Thirteen wait states */
#define LL_FLASH_LATENCY_14   (FLASH_ACR_LATENCY_3 | FLASH_ACR_LATENCY_2 | FLASH_ACR_LATENCY_1) /*!< FLASH Fourteen wait states */
#define LL_FLASH_LATENCY_15   FLASH_ACR_LATENCY                                                 /*!< FLASH Fifteen wait states  */
/**
  * @}
  */

#if defined(VREFBUF)
/** @defgroup SYSTEM_LL_EC_VOLTAGE VREFBUF VOLTAGE
  * @{
  */
#define LL_VREFBUF_VOLTAGE_SCALE0          VREFBUF_CSR_VRS_OUT1   /*!< Voltage reference scale 0 (VREF_OUT1) */
#define LL_VREFBUF_VOLTAGE_SCALE1          VREFBUF_CSR_VRS_OUT2   /*!< Voltage reference scale 1 (VREF_OUT2) */
#define LL_VREFBUF_VOLTAGE_SCALE2          VREFBUF_CSR_VRS_OUT3   /*!< Voltage reference scale 2 (VREF_OUT3) */
#define LL_VREFBUF_VOLTAGE_SCALE3          VREFBUF_CSR_VRS_OUT4   /*!< Voltage reference scale 3 (VREF_OUT4) */
/**
  * @}
  */
#endif /* VREFBUF */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Exported_Functions SYSTEM Exported Functions
  * @{
  */

/** @defgroup SYSTEM_LL_EF_SYSCFG SYSCFG
  * @{
  */

/**
  * @brief  Enable I/O analog switch voltage booster.
  * @note   When voltage booster is enabled, I/O analog switches are supplied
  *         by a dedicated voltage booster, from VDD power domain. This is
  *         the recommended configuration with low VDDA voltage operation.
  * @note   The I/O analog switch voltage booster is relevant for peripherals
  *         using I/O in analog input: ADC, COMP, OPAMP.
  *         However, COMP and OPAMP inputs have a high impedance and
  *         voltage booster do not impact performance significantly.
  *         Therefore, the voltage booster is mainly intended for
  *         usage with ADC.
  * @rmtoll SYSCFG_CFGR1 BOOSTEN       LL_SYSCFG_EnableAnalogBooster
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableAnalogBooster(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_BOOSTEN);
}

/**
  * @brief  Disable I/O analog switch voltage booster.
  * @note   When voltage booster is enabled, I/O analog switches are supplied
  *         by a dedicated voltage booster, from VDD power domain. This is
  *         the recommended configuration with low VDDA voltage operation.
  * @note   The I/O analog switch voltage booster is relevant for peripherals
  *         using I/O in analog input: ADC, COMP, OPAMP.
  *         However, COMP and OPAMP inputs have a high impedance and
  *         voltage booster do not impact performance significantly.
  *         Therefore, the voltage booster is mainly intended for
  *         usage with ADC.
  * @rmtoll SYSCFG_CFGR1 BOOSTEN       LL_SYSCFG_DisableAnalogBooster
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableAnalogBooster(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_BOOSTEN);
}

/**
  * @brief  Enable the I2C fast mode plus driving capability.
  * @rmtoll SYSCFG_CFGR1 I2C_PABx_FMP   LL_SYSCFG_EnableFastModePlus\n
  *         SYSCFG_CFGR1 I2Cx_FMP      LL_SYSCFG_EnableFastModePlus
  * @param  ConfigFastModePlus This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_PA6
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_PA7
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_PA15
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_PB3
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableFastModePlus(uint32_t ConfigFastModePlus)
{
  SET_BIT(SYSCFG->CFGR1, ConfigFastModePlus);
}

/**
  * @brief  Disable the I2C fast mode plus driving capability.
  * @rmtoll SYSCFG_CFGR1 I2C_PBx_FMP   LL_SYSCFG_DisableFastModePlus\n
  *         SYSCFG_CFGR1 I2Cx_FMP      LL_SYSCFG_DisableFastModePlus
  * @param  ConfigFastModePlus This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_PA6
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_PA7
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_PA15
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_PB3
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableFastModePlus(uint32_t ConfigFastModePlus)
{
  CLEAR_BIT(SYSCFG->CFGR1, ConfigFastModePlus);
}

/**
  * @brief  Enable Floating Point Unit Invalid operation Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_0      LL_SYSCFG_EnableIT_FPU_IOC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_IOC(void)
{
  SET_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_0);
}

/**
  * @brief  Enable Floating Point Unit Divide-by-zero Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_1      LL_SYSCFG_EnableIT_FPU_DZC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_DZC(void)
{
  SET_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_1);
}

/**
  * @brief  Enable Floating Point Unit Underflow Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_2      LL_SYSCFG_EnableIT_FPU_UFC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_UFC(void)
{
  SET_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_2);
}

/**
  * @brief  Enable Floating Point Unit Overflow Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_3      LL_SYSCFG_EnableIT_FPU_OFC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_OFC(void)
{
  SET_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_3);
}

/**
  * @brief  Enable Floating Point Unit Input denormal Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_4      LL_SYSCFG_EnableIT_FPU_IDC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_IDC(void)
{
  SET_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_4);
}

/**
  * @brief  Enable Floating Point Unit Inexact Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_5      LL_SYSCFG_EnableIT_FPU_IXC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_IXC(void)
{
  SET_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_5);
}

/**
  * @brief  Disable Floating Point Unit Invalid operation Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_0      LL_SYSCFG_DisableIT_FPU_IOC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_IOC(void)
{
  CLEAR_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_0);
}

/**
  * @brief  Disable Floating Point Unit Divide-by-zero Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_1      LL_SYSCFG_DisableIT_FPU_DZC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_DZC(void)
{
  CLEAR_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_1);
}

/**
  * @brief  Disable Floating Point Unit Underflow Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_2      LL_SYSCFG_DisableIT_FPU_UFC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_UFC(void)
{
  CLEAR_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_2);
}

/**
  * @brief  Disable Floating Point Unit Overflow Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_3      LL_SYSCFG_DisableIT_FPU_OFC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_OFC(void)
{
  CLEAR_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_3);
}

/**
  * @brief  Disable Floating Point Unit Input denormal Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_4      LL_SYSCFG_DisableIT_FPU_IDC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_IDC(void)
{
  CLEAR_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_4);
}

/**
  * @brief  Disable Floating Point Unit Inexact Interrupt
  * @rmtoll SYSCFG_FPUIMR FPU_IE_5      LL_SYSCFG_DisableIT_FPU_IXC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_IXC(void)
{
  CLEAR_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_5);
}

/**
  * @brief  Check if Floating Point Unit Invalid operation Interrupt source is enabled or disabled.
  * @rmtoll SYSCFG_FPUIMR FPU_IE_0      LL_SYSCFG_IsEnabledIT_FPU_IOC
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_IOC(void)
{
  return ((READ_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_0) == SYSCFG_FPUIMR_FPU_IE_0) ? 1UL : 0UL);
}

/**
  * @brief  Check if Floating Point Unit Divide-by-zero Interrupt source is enabled or disabled.
  * @rmtoll SYSCFG_FPUIMR FPU_IE_1      LL_SYSCFG_IsEnabledIT_FPU_DZC
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_DZC(void)
{
  return ((READ_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_1) == SYSCFG_FPUIMR_FPU_IE_1) ? 1UL : 0UL);
}

/**
  * @brief  Check if Floating Point Unit Underflow Interrupt source is enabled or disabled.
  * @rmtoll SYSCFG_FPUIMR FPU_IE_2      LL_SYSCFG_IsEnabledIT_FPU_UFC
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_UFC(void)
{
  return ((READ_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_2) == SYSCFG_FPUIMR_FPU_IE_2) ? 1UL : 0UL);
}

/**
  * @brief  Check if Floating Point Unit Overflow Interrupt source is enabled or disabled.
  * @rmtoll SYSCFG_FPUIMR FPU_IE_3      LL_SYSCFG_IsEnabledIT_FPU_OFC
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_OFC(void)
{
  return ((READ_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_3) == SYSCFG_FPUIMR_FPU_IE_3) ? 1UL : 0UL);
}

/**
  * @brief  Check if Floating Point Unit Input denormal Interrupt source is enabled or disabled.
  * @rmtoll SYSCFG_FPUIMR FPU_IE_4      LL_SYSCFG_IsEnabledIT_FPU_IDC
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_IDC(void)
{
  return ((READ_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_4) == SYSCFG_FPUIMR_FPU_IE_4) ? 1UL : 0UL);
}

/**
  * @brief  Check if Floating Point Unit Inexact Interrupt source is enabled or disabled.
  * @rmtoll SYSCFG_FPUIMR FPU_IE_5      LL_SYSCFG_IsEnabledIT_FPU_IXC
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_IXC(void)
{
  return ((READ_BIT(SYSCFG->FPUIMR, SYSCFG_FPUIMR_FPU_IE_5) == SYSCFG_FPUIMR_FPU_IE_5) ? 1UL : 0UL);
}

/**
  * @brief  Set connections to TIM1/8/15/16/17 Break inputs
  * @rmtoll SYSCFG_CFGR2 CLL          LL_SYSCFG_SetTIMBreakInputs\n
  *         SYSCFG_CFGR2 SPL          LL_SYSCFG_SetTIMBreakInputs\n
  *         SYSCFG_CFGR2 PVDL         LL_SYSCFG_SetTIMBreakInputs\n
  *         SYSCFG_CFGR2 ECCL         LL_SYSCFG_SetTIMBreakInputs
  * @param  Break This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_TIMBREAK_ECC
  *         @arg @ref LL_SYSCFG_TIMBREAK_PVD
  *         @arg @ref LL_SYSCFG_TIMBREAK_SRAM_ECC_LOCK
  *         @arg @ref LL_SYSCFG_TIMBREAK_LOCKUP
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetTIMBreakInputs(uint32_t Break)
{
  MODIFY_REG(SYSCFG->CFGR2, SYSCFG_CFGR2_CLL | SYSCFG_CFGR2_SPL | SYSCFG_CFGR2_PVDL | SYSCFG_CFGR2_ECCL, Break);
}

/**
  * @brief  Get connections to TIM1/8/15/16/17 Break inputs
  * @rmtoll SYSCFG_CFGR2 CLL           LL_SYSCFG_GetTIMBreakInputs\n
  *         SYSCFG_CFGR2 SPL           LL_SYSCFG_GetTIMBreakInputs\n
  *         SYSCFG_CFGR2 PVDL          LL_SYSCFG_GetTIMBreakInputs\n
  *         SYSCFG_CFGR2 ECCL          LL_SYSCFG_GetTIMBreakInputs
  * @retval Returned value can be can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_TIMBREAK_ECC
  *         @arg @ref LL_SYSCFG_TIMBREAK_PVD
  *         @arg @ref LL_SYSCFG_TIMBREAK_SRAM_ECC_LOCK
  *         @arg @ref LL_SYSCFG_TIMBREAK_LOCKUP
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetTIMBreakInputs(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_CLL | SYSCFG_CFGR2_SPL | SYSCFG_CFGR2_PVDL | SYSCFG_CFGR2_ECCL));
}

/**
  * @}
  */

/** @defgroup SYSTEM_LL_EF_SYSCFG_Secure_Management Secure Management
  * @{
  */

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)

/**
  * @brief  Configure Secure mode
  * @note Only available from secure state when system implements security (TZEN=1)
  * @rmtoll SECCFGR     SYSCFGSEC     LL_SYSCFG_ConfigSecure\n
  *         SECCFGR     CLASSBSEC     LL_SYSCFG_ConfigSecure\n
  *         SECCFGR     FPUSEC        LL_SYSCFG_ConfigSecure
  * @param  Configuration This parameter shall be the full combination
  *         of the following values:
  *         @arg @ref LL_SYSCFG_CLOCK_SEC or LL_SYSCFG_CLOCK_NSEC
  *         @arg @ref LL_SYSCFG_CLASSB_SEC or LL_SYSCFG_CLASSB_NSEC
  *         @arg @ref LL_SYSCFG_FPU_SEC or LL_SYSCFG_FPU_NSEC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_ConfigSecure(uint32_t Configuration)
{
  WRITE_REG(SYSCFG->SECCFGR, Configuration);
}

#endif /* __ARM_FEATURE_CMSE && (__ARM_FEATURE_CMSE == 3U) */

/**
  * @brief  Get Secure mode configuration
  * @note Only available when system implements security (TZEN=1)
  * @rmtoll SECCFGR     SYSCFGSEC     LL_SYSCFG_ConfigSecure\n
  *         SECCFGR     CLASSBSEC     LL_SYSCFG_ConfigSecure\n
  *         SECCFGR     FPUSEC        LL_SYSCFG_ConfigSecure
  * @retval Returned value is the combination of the following values:
  *         @arg @ref LL_SYSCFG_CLOCK_SEC or LL_SYSCFG_CLOCK_NSEC
  *         @arg @ref LL_SYSCFG_CLASSB_SEC or LL_SYSCFG_CLASSB_NSEC
  *         @arg @ref LL_SYSCFG_FPU_SEC or LL_SYSCFG_FPU_NSEC
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetConfigSecure(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->SECCFGR, 0xBU));
}

/**
  * @}
  */

/** @defgroup SYSTEM_LL_EF_SYSCFG_ERASE_MEMORIE_STATUS SYSCFG ERASE MEMORIE STATUS
  * @{
  */

/**
  * @brief  Clear Status of End of Erase for ICACHE and PKA RAMs
  * @rmtoll MESR   IPMEE    LL_SYSCFG_ClearEraseEndStatus
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_ClearEraseEndStatus(void)
{
  SET_BIT(SYSCFG->MESR, SYSCFG_MESR_IPMEE);
}

/**
  * @brief  Get Status of End of Erase for ICACHE and PKA RAMs
  * @rmtoll MESR   IPMEE    LL_SYSCFG_GetEraseEndStatus
  * @retval Returned value can be one of the following values:
  *   @arg LL_SYSCFG_MEMORIES_ERASE_ON_GOING : Erase of memories not yet done
  *   @arg LL_SYSCFG_MEMORIES_ERASE_ENDED: Erase of memories ended
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetEraseEndStatus(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->MESR, SYSCFG_MESR_IPMEE));
}


/**
  * @brief  Clear Status of End of Erase after reset  for SRAM2, BKPRAM, ICACHE, DCACHE,PKA rams
  * @rmtoll MESR   MCLR    LL_SYSCFG_ClearEraseAfterResetStatus
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_ClearEraseAfterResetStatus(void)
{
  SET_BIT(SYSCFG->MESR, SYSCFG_MESR_MCLR);
}

/**
  * @brief  Get Status of End of Erase after reset  for SRAM2, BKPRAM, ICACHE, DCACHE,PKA rams
  * @rmtoll MESR   MCLR    LL_SYSCFG_GetEraseAfterResetStatus
  * @retval Returned value can be one of the following values:
  *   @arg LL_SYSCFG_MEMORIES_ERASE_ON_GOING : Erase of memories not yet done
  *   @arg LL_SYSCFG_MEMORIES_ERASE_ENDED: Erase of memories ended
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetEraseAfterResetStatus(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->MESR, SYSCFG_MESR_MCLR));
}
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EF_SYSCFG_COMPENSATION SYSCFG COMPENSATION
  * @{
  */

/**
  * @brief  Get the compensation cell value of the GPIO PMOS transistor supplied by VDD
  * @rmtoll CCVR    PCV1   LL_SYSCFG_GetPMOSVddCompensationValue
  * @retval Returned value is the PMOS compensation cell
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetPMOSVddCompensationValue(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CCVR, SYSCFG_CCVR_PCV1));
}

/**
  * @brief  Get the compensation cell value of the GPIO NMOS transistor supplied by VDD
  * @rmtoll CCVR    NCV1   LL_SYSCFG_GetNMOSVddCompensationValue
  * @retval Returned value is the NMOS compensation cell
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetNMOSVddCompensationValue(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CCVR, SYSCFG_CCVR_NCV1));
}


/**
  * @brief  Set the compensation cell code of the GPIO PMOS transistor supplied by VDD
  * @rmtoll CCCR    PCC1  LL_SYSCFG_SetPMOSVddCompensationCode
  * @param  PMOSCode PMOS compensation code
  *         This code is applied to the PMOS compensation cell when the CS1 bit of the
  *         SYSCFG_CCCSR is set
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetPMOSVddCompensationCode(uint32_t PMOSCode)
{
  MODIFY_REG(SYSCFG->CCCR, SYSCFG_CCCR_PCC1, PMOSCode << SYSCFG_CCCR_PCC1_Pos);
}

/**
  * @brief  Get the compensation cell code of the GPIO PMOS transistor supplied by VDD
  * @rmtoll CCCR    PCC1   LL_SYSCFG_GetPMOSVddCompensationCode
  * @retval Returned value is the PMOS compensation cell
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetPMOSVddCompensationCode(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CCCR, SYSCFG_CCCR_PCC1));
}

/**
  * @brief  Set the compensation cell code of the GPIO NMOS transistor supplied by VDD
  * @rmtoll CCCR    NCC1  LL_SYSCFG_SetNMOSVddCompensationCode
  * @param  NMOSCode NMOS compensation code
  *         This code is applied to the NMOS compensation cell when the CS1 bit of the
  *         SYSCFG_CCCSR is set
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetNMOSVddCompensationCode(uint32_t NMOSCode)
{
  MODIFY_REG(SYSCFG->CCCR, SYSCFG_CCCR_NCC1, NMOSCode << SYSCFG_CCCR_NCC1_Pos);
}

/**
  * @brief  Get the compensation cell code of the GPIO NMOS transistor supplied by VDD
  * @rmtoll CCCR    NCC1   LL_SYSCFG_GetNMOSVddCompensationCode
  * @retval Returned value is the Vdd compensation cell code for NMOS transistors
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetNMOSVddCompensationCode(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CCCR, SYSCFG_CCCR_NCC1));
}

/**
  * @brief  Enable the Compensation Cell of GPIO supplied by VDD
  * @rmtoll CCCSR   EN1    LL_SYSCFG_EnableVddCompensationCell
  * @note   The vdd compensation cell can be used only when the device supply
  *         voltage ranges from 1.71 to 3.6 V
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableVddCompensationCell(void)
{
  SET_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN1);
}

/**
  * @brief  Disable the Compensation Cell of GPIO supplied by VDD
  * @rmtoll CCCSR   EN1    LL_SYSCFG_EnableVddCompensationCell
  * @note   The Vdd compensation cell can be used only when the device supply
  *         voltage ranges from 1.71 to 3.6 V
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableVddCompensationCell(void)
{
  CLEAR_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN1);
}

/**
  * @brief  Check if the Compensation Cell of GPIO supplied by VDD is enable
  * @rmtoll CCCSR   EN1    LL_SYSCFG_IsEnabled_VddCompensationCell
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabled_VddCompensationCell(void)
{
  return ((READ_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN1) == SYSCFG_CCCSR_EN1) ? 1UL : 0UL);
}

/**
  * @brief  Get Compensation Cell ready Flag of GPIO supplied by VDD
  * @rmtoll CCCSR   RDY1   LL_SYSCFG_IsActiveFlag_VddCMPCR
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsActiveFlag_VddCMPCR(void)
{
  return ((READ_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_RDY1) == (SYSCFG_CCCSR_RDY1)) ? 1UL : 0UL);
}

/**
  * @brief  Set the compensation cell code selection of GPIO supplied by VDD
  * @rmtoll CCCSR   CS1    LL_SYSCFG_SetVddCellCompensationCode
  * @param  CompCode: Selects the code to be applied for the Vdd compensation cell
  *   This parameter can be one of the following values:
  *   @arg LL_SYSCFG_VDD_CELL_CODE : Select Code from the cell (available in the SYSCFG_CCVR)
  *   @arg LL_SYSCFG_VDD_REGISTER_CODE: Select Code from the SYSCFG compensation cell code register (SYSCFG_CCCR)
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetVddCellCompensationCode(uint32_t CompCode)
{
  MODIFY_REG(SYSCFG->CCCSR, SYSCFG_CCCSR_CS1, CompCode);
}

/**
  * @brief  Get the compensation cell code selection of GPIO supplied by VDD
  * @rmtoll CCCSR   CS1    LL_SYSCFG_GetVddCellCompensationCode
  * @retval Returned value can be one of the following values:
  *   @arg LL_SYSCFG_VDD_CELL_CODE : Selected Code is from the cell (available in the SYSCFG_CCVR)
  *   @arg LL_SYSCFG_VDD_REGISTER_CODE: Selected Code is from the SYSCFG compensation cell code register (SYSCFG_CCCR)
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetVddCellCompensationCode(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_CS1));
}

#ifdef SYSCFG_CCCSR_EN2
/**
  * @brief  Get the compensation cell value of the GPIO PMOS transistor supplied by VDDIO2
  * @rmtoll CCVR    PCV2   LL_SYSCFG_GetPMOSVddIO2CompensationValue
  * @retval Returned value is the PMOS compensation cell
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetPMOSVddIO2CompensationValue(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CCVR, SYSCFG_CCVR_PCV2));
}

/**
  * @brief  Get the compensation cell value of the GPIO NMOS transistor supplied by VDDIO2
  * @rmtoll CCVR    NCV2   LL_SYSCFG_GetNMOSVddIO2CompensationValue
  * @retval Returned value is the NMOS compensation cell
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetNMOSVddIO2CompensationValue(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CCVR, SYSCFG_CCVR_NCV2));
}


/**
  * @brief  Set the compensation cell code of the GPIO PMOS transistor supplied by VDDIO2
  * @rmtoll CCCR    PCC2  LL_SYSCFG_SetPMOSVddIO2CompensationCode
  * @param  PMOSCode PMOS compensation code
  *         This code is applied to the PMOS compensation cell when the CS2 bit of the
  *         SYSCFG_CCCSR is set
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetPMOSVddIO2CompensationCode(uint32_t PMOSCode)
{
  MODIFY_REG(SYSCFG->CCCR, SYSCFG_CCCR_PCC2, PMOSCode << SYSCFG_CCCR_PCC2_Pos);
}

/**
  * @brief  Get the compensation cell code of the GPIO PMOS transistor supplied by VDDIO2
  * @rmtoll CCCR    PCC2   LL_SYSCFG_GetPMOSVddIO2CompensationCode
  * @retval Returned value is the PMOS compensation cell
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetPMOSVddIO2CompensationCode(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CCCR, SYSCFG_CCCR_PCC2));
}

/**
  * @brief  Set the compensation cell code of the GPIO NMOS transistor supplied by VDDIO2
  * @rmtoll CCCR    NCC2  LL_SYSCFG_SetNMOSVddIO2CompensationCode
  * @param  NMOSCode NMOS compensation code
  *         This code is applied to the NMOS compensation cell when the CS2 bit of the
  *         SYSCFG_CCCSR is set
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetNMOSVddIO2CompensationCode(uint32_t NMOSCode)
{
  MODIFY_REG(SYSCFG->CCCR, SYSCFG_CCCR_NCC2, NMOSCode << SYSCFG_CCCR_NCC2_Pos);
}

/**
  * @brief  Get the compensation cell code of the GPIO NMOS transistor supplied by VDDIO2
  * @rmtoll CCCR    NCC2   LL_SYSCFG_GetNMOSVddIO2CompensationCode
  * @retval Returned value is the VddIO2 compensation cell code for NMOS transistors
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetNMOSVddIO2CompensationCode(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CCCR, SYSCFG_CCCR_NCC2));
}

/**
  * @brief  Enable the Compensation Cell of GPIO supplied by VDDIO2
  * @rmtoll CCCSR   EN2    LL_SYSCFG_EnableVddIO2CompensationCell
  * @note   The VddIO2 compensation cell can be used only when the device supply
  *         voltage ranges from 1.71 to 3.6 V
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableVddIO2CompensationCell(void)
{
  SET_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN2);
}

/**
  * @brief  Disable the Compensation Cell of GPIO supplied by VDDIO2
  * @rmtoll CCCSR   EN2    LL_SYSCFG_EnableVddIO2CompensationCell
  * @note   The VddIO2 compensation cell can be used only when the device supply
  *         voltage ranges from 1.71 to 3.6 V
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableVddIO2CompensationCell(void)
{
  CLEAR_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN2);
}

/**
  * @brief  Check if the Compensation Cell of GPIO supplied by VDDIO2 is enable
  * @rmtoll CCCSR   EN2    LL_SYSCFG_IsEnabled_VddIO2CompensationCell
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabled_VddIO2CompensationCell(void)
{
  return ((READ_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_EN2) == SYSCFG_CCCSR_EN2) ? 1UL : 0UL);
}

/**
  * @brief  Get Compensation Cell ready Flag of GPIO supplied by VDDIO2
  * @rmtoll CCCSR   RDY2   LL_SYSCFG_IsActiveFlag_VddIO2CMPCR
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsActiveFlag_VddIO2CMPCR(void)
{
  return ((READ_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_RDY2) == (SYSCFG_CCCSR_RDY2)) ? 1UL : 0UL);
}

/**
  * @brief  Set the compensation cell code selection of GPIO supplied by VDDIO2
  * @rmtoll CCCSR   CS2    LL_SYSCFG_SetVddIO2CellCompensationCode
  * @param  CompCode: Selects the code to be applied for the VddIO2 compensation cell
  *   This parameter can be one of the following values:
  *   @arg LL_SYSCFG_VDDIO2_CELL_CODE : Select Code from the cell (available in the SYSCFG_CCVR)
  *   @arg LL_SYSCFG_VDDIO2_REGISTER_CODE: Select Code from the SYSCFG compensation cell code register (SYSCFG_CCCR)
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetVddIO2CellCompensationCode(uint32_t CompCode)
{
  MODIFY_REG(SYSCFG->CCCSR, SYSCFG_CCCSR_CS2, CompCode);
}

/**
  * @brief  Get the compensation cell code selection of GPIO supplied by VDDIO2
  * @rmtoll CCCSR   CS2    LL_SYSCFG_GetVddIO2CellCompensationCode
  * @retval Returned value can be one of the following values:
  *   @arg LL_SYSCFG_VDDIO2_CELL_CODE : Selected Code is from the cell (available in the SYSCFG_CCVR)
  *   @arg LL_SYSCFG_VDDIO2_REGISTER_CODE: Selected Code is from the SYSCFG compensation cell code register (SYSCFG_CCCR)
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetVddIO2CellCompensationCode(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CCCSR, SYSCFG_CCCSR_CS2));
}
#endif /* SYSCFG_CCCSR_EN2 */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup SYSTEM_LL_EF_DBGMCU DBGMCU
  * @{
  */

/**
  * @brief  Return the device identifier
  * @rmtoll DBGMCU_IDCODE DEV_ID        LL_DBGMCU_GetDeviceID
  * @retval Values between Min_Data=0x00 and Max_Data=0xFFFF (ex: device ID is 0x6415)
  */
__STATIC_INLINE uint32_t LL_DBGMCU_GetDeviceID(void)
{
  return (uint32_t)(READ_BIT(DBGMCU->IDCODE, DBGMCU_IDCODE_DEV_ID));
}

/**
  * @brief  Return the device revision identifier
  * @note This field indicates the revision of the device.
  * @rmtoll DBGMCU_IDCODE REV_ID        LL_DBGMCU_GetRevisionID
  * @retval Values between Min_Data=0x00 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t LL_DBGMCU_GetRevisionID(void)
{
  return (uint32_t)(READ_BIT(DBGMCU->IDCODE, DBGMCU_IDCODE_REV_ID) >> DBGMCU_IDCODE_REV_ID_Pos);
}

/**
  * @brief  Enable the Debug Module during STOP mode
  * @rmtoll DBGMCU_SCR    DBG_STOP      LL_DBGMCU_EnableDBGStopMode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_EnableDBGStopMode(void)
{
  SET_BIT(DBGMCU->SCR, DBGMCU_SCR_DBG_STOP);
}

/**
  * @brief  Disable the Debug Module during STOP mode
  * @rmtoll DBGMCU_SCR    DBG_STOP      LL_DBGMCU_DisableDBGStopMode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_DisableDBGStopMode(void)
{
  CLEAR_BIT(DBGMCU->SCR, DBGMCU_SCR_DBG_STOP);
}

/**
  * @brief  Enable the Debug Module during STANDBY mode
  * @rmtoll DBGMCU_SCR    DBG_STANDBY   LL_DBGMCU_EnableDBGStandbyMode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_EnableDBGStandbyMode(void)
{
  SET_BIT(DBGMCU->SCR, DBGMCU_SCR_DBG_STANDBY);
}

/**
  * @brief  Disable the Debug Module during STANDBY mode
  * @rmtoll DBGMCU_SCR    DBG_STANDBY   LL_DBGMCU_DisableDBGStandbyMode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_DisableDBGStandbyMode(void)
{
  CLEAR_BIT(DBGMCU->SCR, DBGMCU_SCR_DBG_STANDBY);
}

/**
  * @brief  Freeze APB1 peripherals (group1 peripherals)
  * @rmtoll DBGMCU_APB1LFZR DBG_xxxx_STOP  LL_DBGMCU_APB1_GRP1_FreezePeriph
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM2_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM3_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM4_STOP (*)
  *         @arg @ref LL_DBGMCU_APB1_GRP1_WWDG_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_IWDG_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_I2C1_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_I2C2_STOP (*)
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB1_GRP1_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->APB1LFZR, Periphs);
}

/**
  * @brief  Freeze APB1 peripherals (group2 peripherals)
  * @rmtoll DBGMCU_APB1HFZR DBG_xxxx_STOP  LL_DBGMCU_APB1_GRP2_FreezePeriph
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB1_GRP2_I2C4_STOP (*)
  *         @arg @ref LL_DBGMCU_APB1_GRP2_LPTIM2_STOP
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB1_GRP2_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->APB1HFZR, Periphs);
}

/**
  * @brief  Unfreeze APB1 peripherals (group1 peripherals)
  * @rmtoll DBGMCU_APB1LFZR DBG_xxxx_STOP  LL_DBGMCU_APB1_GRP1_UnFreezePeriph
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM2_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM3_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_TIM4_STOP (*)
  *         @arg @ref LL_DBGMCU_APB1_GRP1_WWDG_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_IWDG_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_I2C1_STOP
  *         @arg @ref LL_DBGMCU_APB1_GRP1_I2C2_STOP (*)
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB1_GRP1_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->APB1LFZR, Periphs);
}

/**
  * @brief  Unfreeze APB1 peripherals (group2 peripherals)
  * @rmtoll DBGMCU_APB1HFZR DBG_xxxx_STOP  LL_DBGMCU_APB1_GRP2_UnFreezePeriph
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB1_GRP2_I2C4_STOP (*)
  *         @arg @ref LL_DBGMCU_APB1_GRP2_LPTIM2_STOP
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB1_GRP2_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->APB1HFZR, Periphs);
}

/**
  * @brief  Freeze APB2 peripherals
  * @rmtoll DBGMCU_APB2FZ DBG_TIMx_STOP  LL_DBGMCU_APB2_GRP1_FreezePeriph
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB2_GRP1_TIM1_STOP
  *         @arg @ref LL_DBGMCU_APB2_GRP1_TIM16_STOP
  *         @arg @ref LL_DBGMCU_APB2_GRP1_TIM17_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB2_GRP1_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->APB2FZR, Periphs);
}

/**
  * @brief  Unfreeze APB2 peripherals
  * @rmtoll DBGMCU_APB2FZR DBG_TIMx_STOP  LL_DBGMCU_APB2_GRP1_UnFreezePeriph
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB2_GRP1_TIM1_STOP
  *         @arg @ref LL_DBGMCU_APB2_GRP1_TIM16_STOP
  *         @arg @ref LL_DBGMCU_APB2_GRP1_TIM17_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB2_GRP1_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->APB2FZR, Periphs);
}

/**
  * @brief  Freeze APB7 peripherals
  * @rmtoll DBGMCU_APB7FZ DBG_TIMx_STOP  LL_DBGMCU_APB7_GRP1_FreezePeriph
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB7_GRP1_I2C3_STOP
  *         @arg @ref LL_DBGMCU_APB7_GRP1_LPTIM1_STOP
  *         @arg @ref LL_DBGMCU_APB7_GRP1_RTC_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB7_GRP1_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->APB7FZR, Periphs);
}

/**
  * @brief  Unfreeze APB7 peripherals
  * @rmtoll DBGMCU_APB7FZR DBG_TIMx_STOP  LL_DBGMCU_APB7_GRP1_UnFreezePeriph
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_APB7_GRP1_I2C3_STOP
  *         @arg @ref LL_DBGMCU_APB7_GRP1_LPTIM1_STOP
  *         @arg @ref LL_DBGMCU_APB7_GRP1_RTC_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB7_GRP1_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->APB7FZR, Periphs);
}

/**
  * @}
  */



/** @defgroup SYSTEM_LL_EF_FLASH FLASH
  * @{
  */
/**
  * @brief  Set FLASH Latency
  * @rmtoll FLASH_ACR    LATENCY       LL_FLASH_SetLatency
  * @param  Latency This parameter can be one of the following values:
  *         @arg @ref LL_FLASH_LATENCY_0
  *         @arg @ref LL_FLASH_LATENCY_1
  *         @arg @ref LL_FLASH_LATENCY_2
  *         @arg @ref LL_FLASH_LATENCY_3
  *         @arg @ref LL_FLASH_LATENCY_4
  *         @arg @ref LL_FLASH_LATENCY_5
  *         @arg @ref LL_FLASH_LATENCY_6
  *         @arg @ref LL_FLASH_LATENCY_7
  *         @arg @ref LL_FLASH_LATENCY_8
  *         @arg @ref LL_FLASH_LATENCY_9
  *         @arg @ref LL_FLASH_LATENCY_10
  *         @arg @ref LL_FLASH_LATENCY_11
  *         @arg @ref LL_FLASH_LATENCY_12
  *         @arg @ref LL_FLASH_LATENCY_13
  *         @arg @ref LL_FLASH_LATENCY_14
  *         @arg @ref LL_FLASH_LATENCY_15
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetLatency(uint32_t Latency)
{
  MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, Latency);
}

/**
  * @brief  Get FLASH Latency
  * @rmtoll FLASH_ACR    LATENCY       LL_FLASH_GetLatency
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_LATENCY_0
  *         @arg @ref LL_FLASH_LATENCY_1
  *         @arg @ref LL_FLASH_LATENCY_2
  *         @arg @ref LL_FLASH_LATENCY_3
  *         @arg @ref LL_FLASH_LATENCY_4
  *         @arg @ref LL_FLASH_LATENCY_5
  *         @arg @ref LL_FLASH_LATENCY_6
  *         @arg @ref LL_FLASH_LATENCY_7
  *         @arg @ref LL_FLASH_LATENCY_8
  *         @arg @ref LL_FLASH_LATENCY_9
  *         @arg @ref LL_FLASH_LATENCY_10
  *         @arg @ref LL_FLASH_LATENCY_11
  *         @arg @ref LL_FLASH_LATENCY_12
  *         @arg @ref LL_FLASH_LATENCY_13
  *         @arg @ref LL_FLASH_LATENCY_14
  *         @arg @ref LL_FLASH_LATENCY_15
  */
__STATIC_INLINE uint32_t LL_FLASH_GetLatency(void)
{
  return (uint32_t)(READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY));
}

/**
  * @brief  Enable Flash Power-down mode during run mode or Low-power run mode
  * @note Flash memory can be put in power-down mode only when the code is executed
  *       from RAM
  * @note Flash must not be accessed when power down is enabled
  * @note Flash must not be put in power-down while a program or an erase operation
  *       is on-going
  * @rmtoll FLASH_ACR    PDREQ         LL_FLASH_EnableRunPowerDown\n
  *         FLASH_PDKEYR PDKEY1_1      LL_FLASH_EnableRunPowerDown\n
  *         FLASH_PDKEYR PDKEY1_2      LL_FLASH_EnableRunPowerDown
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableRunPowerDown(void)
{
#if defined(FLASH_DBANK_SUPPORT)
  /* Following values must be written consecutively to unlock the PDREQ1 bit in
  FLASH_ACR for Bank 1 */
  WRITE_REG(FLASH->PDKEY1R, FLASH_PDKEY1_1);
  WRITE_REG(FLASH->PDKEY1R, FLASH_PDKEY1_2);

  /* Following values must be written consecutively to unlock the PDREQ2 bit in
  FLASH_ACR for Bank 2 */
  WRITE_REG(FLASH->PDKEY2R, FLASH_PDKEY2_1);
  WRITE_REG(FLASH->PDKEY2R, FLASH_PDKEY2_2);

  /*Request to enter flash in power mode */
  SET_BIT(FLASH->ACR, (FLASH_ACR_PDREQ1 | FLASH_ACR_PDREQ2));
#else
  /* Following values must be written consecutively to unlock the PDREQ bit in
  FLASH_ACR */
  WRITE_REG(FLASH->PDKEYR, FLASH_PDKEY1_1);
  WRITE_REG(FLASH->PDKEYR, FLASH_PDKEY1_2);

  /*Request to enter flash in power mode */
  SET_BIT(FLASH->ACR, FLASH_ACR_PDREQ);
#endif /* FLASH_DBANK_SUPPORT */
}

/**
  * @brief  Enable Flash Power-down mode during Sleep or Low-power sleep mode
  * @note Flash must not be put in power-down while a program or an erase operation
  *       is on-going
  * @rmtoll FLASH_ACR    SLEEP_PD      LL_FLASH_EnableSleepPowerDown
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_EnableSleepPowerDown(void)
{
  SET_BIT(FLASH->ACR, FLASH_ACR_SLEEP_PD);
}

/**
  * @brief  Disable Flash Power-down mode during Sleep or Low-power sleep mode
  * @rmtoll FLASH_ACR    SLEEP_PD      LL_FLASH_DisableSleepPowerDown
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_DisableSleepPowerDown(void)
{
  CLEAR_BIT(FLASH->ACR, FLASH_ACR_SLEEP_PD);
}

/**
  * @brief  Return the Unique Device Number
  * @retval Values between Min_Data=0x00000000 and Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_FLASH_GetUDN(void)
{
  return (READ_REG(*((uint32_t *)UID64_BASE)));
}

/**
  * @brief  Return the Device ID
  *         For STM32WBA52xx devices, the device ID is 0x2A
  * @retval Values between Min_Data=0x00 and Max_Data=0xFF (ex: Device ID is 0x2A)
  */
__STATIC_INLINE uint32_t LL_FLASH_GetDeviceID(void)
{
  return ((READ_REG(*((uint32_t *)UID64_BASE + 1U))) & 0x000000FFU);
}

/**
  * @brief  Return the ST Company ID
  * @note   For STM32WBAxxxx devices, the ST Company ID is 0x0080E1
  * @retval Values between Min_Data=0x00 and Max_Data=0xFFFFFF (ex: ST Company ID is 0x0080E1)
  */
__STATIC_INLINE uint32_t LL_FLASH_GetSTCompanyID(void)
{
  return (((READ_REG(*((uint32_t *)UID64_BASE + 1U))) >> 8U) & 0x00FFFFFFU);
}
/**
  * @}
  */


#if defined(VREFBUF)
/** @defgroup SYSTEM_LL_EF_VREFBUF VREFBUF
  * @{
  */

/**
  * @brief  Enable Internal voltage reference
  * @rmtoll VREFBUF_CSR  ENVR          LL_VREFBUF_Enable
  * @retval None
  */
__STATIC_INLINE void LL_VREFBUF_Enable(void)
{
  SET_BIT(VREFBUF->CSR, VREFBUF_CSR_ENVR);
}

/**
  * @brief  Disable Internal voltage reference
  * @rmtoll VREFBUF_CSR  ENVR          LL_VREFBUF_Disable
  * @retval None
  */
__STATIC_INLINE void LL_VREFBUF_Disable(void)
{
  CLEAR_BIT(VREFBUF->CSR, VREFBUF_CSR_ENVR);
}

/**
  * @brief  Enable high impedance (VREF+pin is high impedance)
  * @rmtoll VREFBUF_CSR  HIZ           LL_VREFBUF_EnableHIZ
  * @retval None
  */
__STATIC_INLINE void LL_VREFBUF_EnableHIZ(void)
{
  SET_BIT(VREFBUF->CSR, VREFBUF_CSR_HIZ);
}

/**
  * @brief  Disable high impedance (VREF+pin is internally connected to the voltage reference buffer output)
  * @rmtoll VREFBUF_CSR  HIZ           LL_VREFBUF_DisableHIZ
  * @retval None
  */
__STATIC_INLINE void LL_VREFBUF_DisableHIZ(void)
{
  CLEAR_BIT(VREFBUF->CSR, VREFBUF_CSR_HIZ);
}

/**
  * @brief  Set the Voltage reference scale
  * @rmtoll VREFBUF_CSR  VRS           LL_VREFBUF_SetVoltageScaling
  * @param  Scale This parameter can be one of the following values:
  *         @arg @ref LL_VREFBUF_VOLTAGE_SCALE0
  *         @arg @ref LL_VREFBUF_VOLTAGE_SCALE1
  *         @arg @ref LL_VREFBUF_VOLTAGE_SCALE2
  *         @arg @ref LL_VREFBUF_VOLTAGE_SCALE3
  * @retval None
  */
__STATIC_INLINE void LL_VREFBUF_SetVoltageScaling(uint32_t Scale)
{
  MODIFY_REG(VREFBUF->CSR, VREFBUF_CSR_VRS, Scale);
}

/**
  * @brief  Get the Voltage reference scale
  * @rmtoll VREFBUF_CSR  VRS           LL_VREFBUF_GetVoltageScaling
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_VREFBUF_VOLTAGE_SCALE0
  *         @arg @ref LL_VREFBUF_VOLTAGE_SCALE1
  *         @arg @ref LL_VREFBUF_VOLTAGE_SCALE2
  *         @arg @ref LL_VREFBUF_VOLTAGE_SCALE3
  */
__STATIC_INLINE uint32_t LL_VREFBUF_GetVoltageScaling(void)
{
  return (uint32_t)(READ_BIT(VREFBUF->CSR, VREFBUF_CSR_VRS));
}

/**
  * @brief  Check if Voltage reference buffer is ready
  * @rmtoll VREFBUF_CSR  VRR           LL_VREFBUF_IsVREFReady
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_VREFBUF_IsVREFReady(void)
{
  return ((READ_BIT(VREFBUF->CSR, VREFBUF_CSR_VRR) == VREFBUF_CSR_VRR) ? 1UL : 0UL);
}

/**
  * @brief  Get the trimming code for VREFBUF calibration
  * @rmtoll VREFBUF_CCR  TRIM          LL_VREFBUF_GetTrimming
  * @retval Between 0 and 0x3F
  */
__STATIC_INLINE uint32_t LL_VREFBUF_GetTrimming(void)
{
  return (uint32_t)(READ_BIT(VREFBUF->CCR, VREFBUF_CCR_TRIM));
}

/**
  * @brief  Set the trimming code for VREFBUF calibration (Tune the internal reference buffer voltage)
  * @rmtoll VREFBUF_CCR  TRIM          LL_VREFBUF_SetTrimming
  * @param  Value Between 0 and 0x3F
  * @retval None
  */
__STATIC_INLINE void LL_VREFBUF_SetTrimming(uint32_t Value)
{
  WRITE_REG(VREFBUF->CCR, Value);
}

/**
  * @}
  */
#endif /* VREFBUF */

/**
  * @}
  */

#endif /* defined (FLASH) || defined (SYSCFG) || defined (DBGMCU) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32WBAxx_LL_SYSTEM_H */
