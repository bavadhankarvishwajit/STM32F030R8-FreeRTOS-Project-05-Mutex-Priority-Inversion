/******************************************************************************
 * @file    uart.h
 * @author  Vishwajit
 * @brief   UART Driver Header for STM32F030R8
 ******************************************************************************/

#ifndef UART_H
#define UART_H

/*---------------------------------------------------------------------------
 * Includes
 *---------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include "stm32f030x8.h"

/*---------------------------------------------------------------------------
 * UART Configuration
 *---------------------------------------------------------------------------*/
#define UART_PORT           USART2

#define UART_GPIO_PORT      GPIOA

#define UART_GPIO_CLK_EN()  (RCC->AHBENR |= RCC_AHBENR_GPIOAEN)

#define UART_CLK_EN()       (RCC->APB1ENR |= RCC_APB1ENR_USART2EN)

/* USART2 TX = PA2 */
#define UART_TX_PIN         2U

/* USART2 RX = PA3 */
#define UART_RX_PIN         3U

/* Alternate Function Number */
#define UART_AF             1U

/* UART Baud Rate */
#define UART_BAUDRATE       115200U

/*---------------------------------------------------------------------------
 * Function Prototypes
 *---------------------------------------------------------------------------*/

/* Initialize UART2 */
void UART2_Init(void);

/* Send One Character */
void UART_SendChar(char ch);

/* Send String */
void UART_SendString(const char *str);

#endif
