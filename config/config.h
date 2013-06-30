/**
 *    ||          ____  _ __                           
 * +------+      / __ )(_) /_______________ _____  ___ 
 * | 0xBC |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * +------+    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *  ||  ||    /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2011-2012 Bitcraze AB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, in version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * config.h - Main configuration file
 *
 * This file define the default configuration of the copter
 * It contains two types of parameters:
 * - The global parameters are globally defined and independent of any
 *   compilation profile. An example of such define could be some pinout.
 * - The profiled defines, they are parameter that can be specific to each
 *   dev build. The vanilla build is intended to be a "customer" build without
 *   fancy spinning debugging stuff. The developers build are anything the
 *   developer could need to debug and run his code/crazy stuff.
 *
 * The golden rule for the profile is NEVER BREAK ANOTHER PROFILE. When adding a
 * new parameter, one shall take care to modified everything necessary to
 * preserve the behavior of the other profiles.
 *
 * For the flag. T_ means task. H_ means HAL module. U_ would means utils.
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#include "nrf24l01.h"

#define CONFIG_BLOCK_ADDRESS 0x1FC00

#define P_NAME "Crazyflie Rev.F"

#define H_INIT_EXTI
#define T_LAUNCH_ADC
#define T_LAUNCH_RADIO
#define T_LAUNCH_POWERMANAGMENT

#define T_LAUNCH_CONTROL
#define T_LAUNCH_MULTILOG_1
#define T_LAUNCH_MULTICONTROL

//Task priorities. Lower number higher priority
#define SYSTEM_TASK_PRI         2
#define ADC_TASK_PRI            3
#define PM_TASK_PRI             3
#define CRTP_TX_TASK_PRI        2
#define CRTP_RX_TASK_PRI        2
#define LOG_TASK_PRI            1
#define PARAM_TASK_PRI          1
#define STABILIZER_TASK_PRI     2
#define RADIOLINK_TASK_PRI      1
#define ESKYLINK_TASK_PRI       1
#define UART_TASK_PRI           2
//Task names
#define SYSTEM_TASK_NAME        "SYSTEM"
#define ADC_TASK_NAME           "ADC"
#define PM_TASK_NAME            "PWRMGNT"
#define CRTP_TX_TASK_NAME       "CRTP-TX"
#define CRTP_RX_TASK_NAME       "CRTP-RX"
#define LOG_TASK_NAME           "LOG"
#define PARAM_TASK_NAME         "PARAM"
#define STABILIZER_TASK_NAME    "STABILIZER"
#define RADIOLINK_TASK_NAME     "RADIOLINK"
#define ESKYLINK_TASK_NAME      "ESKYLINK"
#define UART_TASK_NAME          "UART-RX"
//Task stack sizes
#define SYSTEM_TASK_STACKSIZE         (2* configMINIMAL_STACK_SIZE)
#define ADC_TASK_STACKSIZE            configMINIMAL_STACK_SIZE
#define PM_TASK_STACKSIZE             configMINIMAL_STACK_SIZE
#define CRTP_TX_TASK_STACKSIZE        configMINIMAL_STACK_SIZE
#define CRTP_RX_TASK_STACKSIZE        configMINIMAL_STACK_SIZE
#define LOG_TASK_STACKSIZE            configMINIMAL_STACK_SIZE
#define PARAM_TASK_STACKSIZE          configMINIMAL_STACK_SIZE
#define STABILIZER_TASK_STACKSIZE     (2 * configMINIMAL_STACK_SIZE)
#define RADIOLINK_TASK_STACKSIZE      configMINIMAL_STACK_SIZE
#define ESKYLINK_TASK_STACKSIZE       configMINIMAL_STACK_SIZE
#define UART_TASK_STACKSIZE           configMINIMAL_STACK_SIZE

//The radio channel. From 0 to 125
#define RADIO_CHANEL 10
#define RADIO_DATARATE RADIO_RATE_250K

//Define to activate automatic shutdown
#define ACTIVATE_AUTO_SHUTDOWN
// Shutdown timeout in minutes
#define SYSTEM_SHUTDOWN_TIMEOUT  5


//Debug defines
//#define BRUSHLESS_MOTORCONTROLLER
//#define ADC_OUTPUT_RAW_DATA
//#define UART_OUTPUT_TRACE_DATA
//#define UART_OUTPUT_RAW_DATA_ONLY
//#define IMU_OUTPUT_RAW_DATA_ON_UART
//#define T_LAUCH_MOTORS
//#define T_LAUCH_MOTOR_TEST
//#define MOTOR_RAMPUP_TEST
/**
 * \def ADC_OUTPUT_RAW_DATA
 * When defined the gyro data will be written to the UART channel.
 * The UART must be configured to run really fast, e.g. in 2Mb/s.
 */
//#define ADC_OUTPUT_RAW_DATA

#if defined(UART_OUTPUT_TRACE_DATA) && defined(ADC_OUTPUT_RAW_DATA)
#  error "Can't define UART_OUTPUT_TRACE_DATA and ADC_OUTPUT_RAW_DATA at the same time"
#endif

#if defined(UART_OUTPUT_TRACE_DATA) || defined(ADC_OUTPUT_RAW_DATA) || defined(IMU_OUTPUT_RAW_DATA_ON_UART)
#define UART_OUTPUT_RAW_DATA_ONLY
#endif

#if defined(UART_OUTPUT_TRACE_DATA) && defined(T_LAUNCH_ACC)
#  error "UART_OUTPUT_TRACE_DATA and T_LAUNCH_ACC doesn't work at the same time yet due to dma sharing..."
#endif

#endif /* CONFIG_H_ */
