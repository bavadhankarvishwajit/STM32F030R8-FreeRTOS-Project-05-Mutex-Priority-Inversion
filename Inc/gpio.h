/******************************************************************************
 * @file    gpio.h
 * @author  Vishwajit
 * @brief   GPIO Driver Header for STM32F030R8
 ******************************************************************************/

#ifndef GPIO_H
#define GPIO_H

/*---------------------------------------------------------------------------
 * Includes
 *---------------------------------------------------------------------------*/
#include <stdint.h>
#include "stm32f030x8.h"

/*---------------------------------------------------------------------------
 * LED Configuration
 *---------------------------------------------------------------------------*/
#define LED_GPIO_PORT      GPIOA
#define LED_GPIO_CLK_EN()  (RCC->AHBENR |= RCC_AHBENR_GPIOAEN)

#define LED_PIN            5U

/*---------------------------------------------------------------------------
 * Function Prototypes
 *---------------------------------------------------------------------------*/

/* Initialize LED GPIO */
void GPIO_Init(void);

/* LED Control Functions */
void LED_ON(void);
void LED_OFF(void);
void LED_TOGGLE(void);

#endif /* GPIO_H */
