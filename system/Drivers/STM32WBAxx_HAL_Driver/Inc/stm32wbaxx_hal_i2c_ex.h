/**
  ******************************************************************************
  * @file    stm32wbaxx_hal_i2c_ex.h
  * @author  MCD Application Team
  * @brief   Header file of I2C HAL Extended module.
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
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32WBAxx_HAL_I2C_EX_H
#define STM32WBAxx_HAL_I2C_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32wbaxx_hal_def.h"

/** @addtogroup STM32WBAxx_HAL_Driver
  * @{
  */

/** @addtogroup I2CEx
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup I2C_Exported_Types I2C Exported Types
  * @{
  */

/** @defgroup I2C_Autonomous_Mode_Configuration_Structure_definition Autonomous Mode Configuration Structure definition
  * @brief  I2C Autonomous Mode Configuration structure definition
  * @{
  */
typedef struct
{
  uint32_t TriggerState;        /*!< Specifies the trigger state. This parameter can be a value
                                     of @ref I2CEx_AutonomousMode_FunctionalState */

  uint32_t TriggerSelection;    /*!< Specifies the autonomous mode trigger signal selection. This parameter
                                     can be a value of @ref I2CEx_AutonomousMode_TriggerSelection */

  uint32_t TriggerPolarity;     /*!< Specifies the autonomous mode trigger signal polarity sensitivity. This parameter
                                     can be a value of @ref I2CEx_AutonomousMode_TriggerPolarity */

} I2C_AutonomousModeConfTypeDef;
/**
  * @}
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup I2CEx_Exported_Constants I2C Extended Exported Constants
  * @{
  */

/** @defgroup I2CEx_Analog_Filter I2C Extended Analog Filter
  * @{
  */
#define I2C_ANALOGFILTER_ENABLE         0x00000000U
#define I2C_ANALOGFILTER_DISABLE        I2C_CR1_ANFOFF
/**
  * @}
  */

/** @defgroup I2CEx_FastModePlus I2C Extended Fast Mode Plus
  * @{
  */
#define I2C_FASTMODEPLUS_ENABLE         0x00000000U           /*!< Enable Fast Mode Plus                        */
#define I2C_FASTMODEPLUS_DISABLE        0x00000001U           /*!< Disable Fast Mode Plus                       */
/**
  * @}
  */

/** @defgroup I2CEx_AutonomousMode_FunctionalState I2C Extended Autonomous Mode State
  * @{
  */
#define I2C_AUTO_MODE_DISABLE           (0x00000000U)                    /*!< Autonomous mode disable  */
#define I2C_AUTO_MODE_ENABLE            I2C_AUTOCR_TRIGEN                /*!< Autonomous mode enable   */
/**
  * @}
  */

/** @defgroup I2CEx_AutonomousMode_TriggerSelection I2C Extended Autonomous Mode Trigger Selection
  * @{
  */
#if (defined(I2C1) || defined(I2C2) || defined(I2C4))
#define I2C_TRIG_GRP1                   (0x10000000U)         /*!< Trigger Group for I2C1, I2C2, I2C4 */
#endif /* I2C1, I2C2, I2C4 */
#define I2C_TRIG_GRP2                   (0x20000000U)         /*!< Trigger Group for I2C3 */

#if defined(I2C_TRIG_GRP1)
#define I2C_GRP1_GPDMA_CH0_TCF_TRG      (uint32_t)(I2C_TRIG_GRP1 | (0x00000000U))
/*!< HW Trigger signal is GPDMA_CH0_TRG     */
#define I2C_GRP1_GPDMA_CH1_TCF_TRG      (uint32_t)(I2C_TRIG_GRP1 | (0x1UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is GPDMA_CH1_TRG     */
#define I2C_GRP1_GPDMA_CH2_TCF_TRG      (uint32_t)(I2C_TRIG_GRP1 | (0x2UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is GPDMA_CH2_TRG     */
#define I2C_GRP1_GPDMA_CH3_TCF_TRG      (uint32_t)(I2C_TRIG_GRP1 | (0x3UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is GPDMA_CH3_TRG     */
#define I2C_GRP1_EXTI5_TRG              (uint32_t)(I2C_TRIG_GRP1 | (0x4UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is EXTI5_TRG         */
#define I2C_GRP1_EXTI9_TRG              (uint32_t)(I2C_TRIG_GRP1 | (0x5UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is EXTI9_TRG         */
#define I2C_GRP1_LPTIM1_CH1_TRG         (uint32_t)(I2C_TRIG_GRP1 | (0x6UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is LPTIM1_CH1_TRG    */
#define I2C_GRP1_LPTIM2_CH1_TRG         (uint32_t)(I2C_TRIG_GRP1 | (0x7UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is LPTIM2_CH1_TRG    */
#if defined(COMP1)
#define I2C_GRP1_COMP1_TRG              (uint32_t)(I2C_TRIG_GRP1 | (0x8UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is COMP1_TRG         */
#endif /* COMP1 */
#if defined(COMP2)
#define I2C_GRP1_COMP2_TRG              (uint32_t)(I2C_TRIG_GRP1 | (0x9UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is COMP2_TRG         */
#endif /* COMP2 */
#define I2C_GRP1_RTC_ALRA_TRG           (uint32_t)(I2C_TRIG_GRP1 | (0xAUL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is RTC_ALRA_TRG      */
#define I2C_GRP1_RTC_WUT_TRG            (uint32_t)(I2C_TRIG_GRP1 | (0xBUL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is RTC_WUT_TRG       */
#endif /* I2C_TRIG_GRP1 */

#define I2C_GRP2_GPDMA_CH0_TCF_TRG      (uint32_t)(I2C_TRIG_GRP2 | (0x00000000U))
/*!< HW Trigger signal is GPDMA_CH0_TRG     */
#define I2C_GRP2_GPDMA_CH1_TCF_TRG      (uint32_t)(I2C_TRIG_GRP2 | (0x1UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is GPDMA_CH1_TRG     */
#define I2C_GRP2_GPDMA_CH2_TCF_TRG      (uint32_t)(I2C_TRIG_GRP2 | (0x2UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is GPDMA_CH2_TRG     */
#define I2C_GRP2_GPDMA_CH3_TCF_TRG      (uint32_t)(I2C_TRIG_GRP2 | (0x3UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is GPDMA_CH3_TRG     */
#define I2C_GRP2_EXTI5_TRG              (uint32_t)(I2C_TRIG_GRP2 | (0x4UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is EXTI5_TRG         */
#define I2C_GRP2_EXTI8_TRG              (uint32_t)(I2C_TRIG_GRP2 | (0x5UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is EXTI8_TRG         */
#define I2C_GRP2_LPTIM1_CH1_TRG         (uint32_t)(I2C_TRIG_GRP2 | (0x6UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is LPTIM1_CH1_TRG    */
#if defined(COMP1)
#define I2C_GRP2_COMP1_TRG              (uint32_t)(I2C_TRIG_GRP2 | (0x8UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is COMP1_TRG         */
#endif /* COMP1 */
#if defined(COMP2)
#define I2C_GRP2_COMP2_TRG              (uint32_t)(I2C_TRIG_GRP2 | (0x9UL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is COMP2_TRG         */
#endif /* COMP2 */
#define I2C_GRP2_RTC_ALRA_TRG           (uint32_t)(I2C_TRIG_GRP2 | (0xAUL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is RTC_ALRA_TRG      */
#define I2C_GRP2_RTC_WUT_TRG            (uint32_t)(I2C_TRIG_GRP2 | (0xBUL << I2C_AUTOCR_TRIGSEL_Pos))
/*!< HW Trigger signal is RTC_WUT_TRG       */
/**
  * @}
  */

/** @defgroup I2CEx_AutonomousMode_TriggerPolarity Extended Autonomous Mode Trigger Polarity
  * @{
  */
#define I2C_TRIG_POLARITY_RISING        (0x00000000U)                    /*!< I2C HW Trigger signal on rising edge  */
#define I2C_TRIG_POLARITY_FALLING       I2C_AUTOCR_TRIGPOL               /*!< I2C HW Trigger signal on falling edge */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup I2CEx_Exported_Macros I2C Extended Exported Macros
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup I2CEx_Exported_Functions I2C Extended Exported Functions
  * @{
  */

/** @addtogroup I2CEx_Exported_Functions_Group1 Filter Mode Functions
  * @{
  */
/* Peripheral Control functions  ************************************************/
HAL_StatusTypeDef HAL_I2CEx_ConfigAnalogFilter(I2C_HandleTypeDef *hi2c, uint32_t AnalogFilter);
HAL_StatusTypeDef HAL_I2CEx_ConfigDigitalFilter(I2C_HandleTypeDef *hi2c, uint32_t DigitalFilter);
/**
  * @}
  */

/** @addtogroup I2CEx_Exported_Functions_Group2 WakeUp Mode Functions
  * @{
  */
HAL_StatusTypeDef HAL_I2CEx_EnableWakeUp(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2CEx_DisableWakeUp(I2C_HandleTypeDef *hi2c);
/**
  * @}
  */

/** @addtogroup I2CEx_Exported_Functions_Group3 Fast Mode Plus Functions
  * @{
  */
HAL_StatusTypeDef HAL_I2CEx_ConfigFastModePlus(I2C_HandleTypeDef *hi2c, uint32_t FastModePlus);
/**
  * @}
  */

/** @addtogroup I2CEx_Exported_Functions_Group4 Autonomous Mode Functions
  * @{
  */
HAL_StatusTypeDef HAL_I2CEx_SetConfigAutonomousMode(I2C_HandleTypeDef *hi2c,
                                                    const I2C_AutonomousModeConfTypeDef *sConfig);
HAL_StatusTypeDef HAL_I2CEx_GetConfigAutonomousMode(const I2C_HandleTypeDef *hi2c,
                                                    I2C_AutonomousModeConfTypeDef *sConfig);
HAL_StatusTypeDef HAL_I2CEx_ClearConfigAutonomousMode(I2C_HandleTypeDef *hi2c);
/**
  * @}
  */

/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/** @defgroup I2CEx_Private_Constants I2C Extended Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup I2CEx_Private_Macro I2C Extended Private Macros
  * @{
  */
#define IS_I2C_ANALOG_FILTER(FILTER)    (((FILTER) == I2C_ANALOGFILTER_ENABLE) || \
                                         ((FILTER) == I2C_ANALOGFILTER_DISABLE))

#define IS_I2C_DIGITAL_FILTER(FILTER)   ((FILTER) <= 0x0000000FU)

#define IS_I2C_FASTMODEPLUS(__CONFIG__) (((__CONFIG__) == (I2C_FASTMODEPLUS_ENABLE))   || \
                                         ((__CONFIG__) == (I2C_FASTMODEPLUS_DISABLE)))

#define IS_I2C_AUTO_MODE(__MODE__)                  (((__MODE__) == I2C_AUTO_MODE_DISABLE) || \
                                                     ((__MODE__) == I2C_AUTO_MODE_ENABLE))

#if defined(I2C_TRIG_GRP1)
#define IS_I2C_TRIG_SOURCE(__INSTANCE__, __SOURCE__)  (((__INSTANCE__) == I2C3) ? \
                                                       IS_I2C_GRP2_TRIG_SOURCE(__SOURCE__) : \
                                                       IS_I2C_GRP1_TRIG_SOURCE(__SOURCE__))
#else
#define IS_I2C_TRIG_SOURCE(__INSTANCE__, __SOURCE__)  (IS_I2C_GRP2_TRIG_SOURCE(__SOURCE__))
#endif /* I2C_TRIG_GRP1 */

#if defined(COMP1) && defined(COMP2)
#if defined(I2C_TRIG_GRP1)
#define IS_I2C_GRP1_TRIG_SOURCE(__SOURCE__)  (((__SOURCE__) == I2C_GRP1_GPDMA_CH0_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP1_GPDMA_CH1_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP1_GPDMA_CH2_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP1_GPDMA_CH3_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP1_EXTI5_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP1_EXTI9_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP1_LPTIM1_CH1_TRG     ) || \
                                              ((__SOURCE__) == I2C_GRP1_LPTIM2_CH1_TRG     ) || \
                                              ((__SOURCE__) == I2C_GRP1_COMP1_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP1_COMP2_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP1_RTC_ALRA_TRG       ) || \
                                              ((__SOURCE__) == I2C_GRP1_RTC_WUT_TRG        ))
#endif /* I2C_TRIG_GRP1 */

#define IS_I2C_GRP2_TRIG_SOURCE(__SOURCE__)  (((__SOURCE__) == I2C_GRP2_GPDMA_CH0_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP2_GPDMA_CH1_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP2_GPDMA_CH2_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP2_GPDMA_CH3_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP2_EXTI5_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP2_EXTI8_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP2_LPTIM1_CH1_TRG     ) || \
                                              ((__SOURCE__) == I2C_GRP2_COMP1_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP2_COMP2_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP2_RTC_ALRA_TRG       ) || \
                                              ((__SOURCE__) == I2C_GRP2_RTC_WUT_TRG        ))

#else

#define IS_I2C_GRP1_TRIG_SOURCE(__SOURCE__)  (((__SOURCE__) == I2C_GRP1_GPDMA_CH0_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP1_GPDMA_CH1_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP1_GPDMA_CH2_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP1_GPDMA_CH3_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP1_EXTI5_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP1_EXTI9_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP1_LPTIM1_CH1_TRG     ) || \
                                              ((__SOURCE__) == I2C_GRP1_LPTIM2_CH1_TRG     ) || \
                                              ((__SOURCE__) == I2C_GRP1_RTC_ALRA_TRG       ) || \
                                              ((__SOURCE__) == I2C_GRP1_RTC_WUT_TRG        ))

#define IS_I2C_GRP2_TRIG_SOURCE(__SOURCE__)  (((__SOURCE__) == I2C_GRP2_GPDMA_CH0_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP2_GPDMA_CH1_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP2_GPDMA_CH2_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP2_GPDMA_CH3_TCF_TRG  ) || \
                                              ((__SOURCE__) == I2C_GRP2_EXTI5_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP2_EXTI8_TRG          ) || \
                                              ((__SOURCE__) == I2C_GRP2_LPTIM1_CH1_TRG     ) || \
                                              ((__SOURCE__) == I2C_GRP2_RTC_ALRA_TRG       ) || \
                                              ((__SOURCE__) == I2C_GRP2_RTC_WUT_TRG        ))
#endif /* COMP1 && COMP2 */

#if defined(I2C_TRIG_GRP1)
#define IS_I2C_TRIG_INPUT_INSTANCE(__INSTANCE__)    (IS_I2C_GRP1_INSTANCE(__INSTANCE__) || \
                                                     IS_I2C_GRP2_INSTANCE(__INSTANCE__))
#else
#define IS_I2C_TRIG_INPUT_INSTANCE(__INSTANCE__)    IS_I2C_GRP1_INSTANCE(__INSTANCE__)
#endif /* I2C_TRIG_GRP1 */

#define IS_I2C_AUTO_MODE_TRG_POL(__POLARITY__)      (((__POLARITY__) == I2C_TRIG_POLARITY_RISING) || \
                                                     ((__POLARITY__) == I2C_TRIG_POLARITY_FALLING))
/**
  * @}
  */

/* Private Functions ---------------------------------------------------------*/
/** @defgroup I2CEx_Private_Functions I2C Extended Private Functions
  * @{
  */
/* Private functions are defined in stm32wbaxx_hal_i2c_ex.c file */
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

#endif /* STM32WBAxx_HAL_I2C_EX_H */
