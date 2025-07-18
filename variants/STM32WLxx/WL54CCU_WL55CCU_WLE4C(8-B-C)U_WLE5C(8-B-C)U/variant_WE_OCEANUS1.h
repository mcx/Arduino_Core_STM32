/*
 *******************************************************************************
 * Copyright (c) 2020, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#pragma once

/*----------------------------------------------------------------------------
 *        STM32 pins number
 *----------------------------------------------------------------------------*/
#define PA0                     0
#define PA1                     1
#define PA2                     2
#define PA3                     3
#define PA4                     4
#define PA5                     5
#define PA6                     6
#define PA7                     7
#define PA8                     8
#define PA9                     9
#define PA10                    PIN_A3
#define PA11                    PIN_A7
#define PA12                    PIN_A8
#define PA13                    PIN_A5
#define PA14                    PIN_A6
#define PA15                    PIN_A4
#define PB2                     PIN_A2
#define PB3                     PIN_A0
#define PB4                     PIN_A1
#define PB5                     19
#define PB6                     20
#define PB7                     21
#define PB8                     22
#define PB12                    23
#define PC13                    24
#define PH3                     25

// Not available
// PB0
// PC14
// PC15

// Alternate pins number
#define PA1_ALT1                (PA1 | ALT1)
#define PA2_ALT1                (PA2 | ALT1)
#define PA3_ALT1                (PA3 | ALT1)
#define PA4_ALT1                (PA4 | ALT1)
#define PA5_ALT1                (PA5 | ALT1)
#define PA6_ALT1                (PA6 | ALT1)
#define PA7_ALT1                (PA7 | ALT1)
#define PB8_ALT1                (PB8 | ALT1)

#define NUM_DIGITAL_PINS        26
#define NUM_ANALOG_INPUTS       9

// SPI definitions
#ifndef PIN_SPI_SS
  #define PIN_SPI_SS            PA15
#endif
#ifndef PIN_SPI_SS1
  #define PIN_SPI_SS1           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS2
  #define PIN_SPI_SS2           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS3
  #define PIN_SPI_SS3           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_MOSI
  #define PIN_SPI_MOSI          PB5
#endif
#ifndef PIN_SPI_MISO
  #define PIN_SPI_MISO          PB4
#endif
#ifndef PIN_SPI_SCK
  #define PIN_SPI_SCK           PB3
#endif

// I2C definitions
#ifndef PIN_WIRE_SDA
  #define PIN_WIRE_SDA          PB7
#endif
#ifndef PIN_WIRE_SCL
  #define PIN_WIRE_SCL          PB8
#endif

// Timer Definitions
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
#ifndef TIMER_TONE
  #define TIMER_TONE            TIM16
#endif
#ifndef TIMER_SERVO
  #define TIMER_SERVO           TIM17
#endif

// UART Definitions
#ifndef SERIAL_UART_INSTANCE
  #define SERIAL_UART_INSTANCE  101
#endif

// Default pin used for generic 'Serial' instance
// Mandatory for Firmata
#ifndef PIN_SERIAL_RX
  #define PIN_SERIAL_RX         PA3
#endif
#ifndef PIN_SERIAL_TX
  #define PIN_SERIAL_TX         PA2
#endif

// Alias
#ifndef DEBUG_SUBGHZSPI_MOSI
  #define DEBUG_SUBGHZSPI_MOSI  PA7_ALT1
#endif
#ifndef DEBUG_SUBGHZSPI_MISO
  #define DEBUG_SUBGHZSPI_MISO  PA6_ALT1
#endif
#ifndef DEBUG_SUBGHZSPI_SCLK
  #define DEBUG_SUBGHZSPI_SCLK  PA5_ALT1
#endif
#ifndef DEBUG_SUBGHZSPI_SS
  #define DEBUG_SUBGHZSPI_SS    PA4_ALT1
#endif

// Extra HAL modules
#if !defined(HAL_DAC_MODULE_DISABLED)
  #define HAL_DAC_MODULE_ENABLED
#endif

// LoRaWAN definitions

#define LORAWAN_BOARD_HAS_TCXO          1U
#define LORAWAN_BOARD_HAS_DCDC          1U
#define LORAWAN_TX_CONFIG               RBI_CONF_RFO_LP

#define LORAWAN_RFSWITCH_PINS           PB12, PC13
#define LORAWAN_RFSWITCH_PIN_COUNT      2
#define LORAWAN_RFSWITCH_OFF_VALUES     LOW, LOW
#define LORAWAN_RFSWITCH_RX_VALUES      HIGH, LOW
#define LORAWAN_RFSWITCH_RFO_LP_VALUES  HIGH, HIGH
#define LORAWAN_RFSWITCH_RFO_HP_VALUES  HIGH, HIGH

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #ifndef SERIAL_PORT_MONITOR
    #define SERIAL_PORT_MONITOR   Serial
  #endif
  #ifndef SERIAL_PORT_HARDWARE
    #define SERIAL_PORT_HARDWARE  Serial
  #endif
#endif
