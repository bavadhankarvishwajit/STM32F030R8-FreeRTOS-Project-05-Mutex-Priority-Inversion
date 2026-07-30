/******************************************************************************
 * @file    uart.c
 * @author  Vishwajit
 * @brief   UART Driver for STM32F030R8
 ******************************************************************************/

#include "uart.h"

/******************************************************************************
 * Function : UART2_Init
 * Purpose  : Initialize USART2 for 115200 Baud
 ******************************************************************************/
void UART2_Init(void)
{
    /*----------------------------------------------------------
     * Step 1 : Enable GPIOA Clock
     *---------------------------------------------------------*/
    UART_GPIO_CLK_EN();

    /*----------------------------------------------------------
     * Step 2 : Enable USART2 Clock
     *---------------------------------------------------------*/
    UART_CLK_EN();

    /*----------------------------------------------------------
     * Step 3 : Configure PA2 and PA3 as Alternate Function
     *---------------------------------------------------------*/

    /* PA2 */
    UART_GPIO_PORT->MODER &= ~(3U << (UART_TX_PIN * 2));
    UART_GPIO_PORT->MODER |=  (2U << (UART_TX_PIN * 2));

    /* PA3 */
    UART_GPIO_PORT->MODER &= ~(3U << (UART_RX_PIN * 2));
    UART_GPIO_PORT->MODER |=  (2U << (UART_RX_PIN * 2));

    /*----------------------------------------------------------
     * Step 4 : Select Alternate Function AF1
     *---------------------------------------------------------*/

    UART_GPIO_PORT->AFR[0] &= ~(0xFU << (UART_TX_PIN * 4));
    UART_GPIO_PORT->AFR[0] |=  (UART_AF << (UART_TX_PIN * 4));

    UART_GPIO_PORT->AFR[0] &= ~(0xFU << (UART_RX_PIN * 4));
    UART_GPIO_PORT->AFR[0] |=  (UART_AF << (UART_RX_PIN * 4));

    /*----------------------------------------------------------
     * Step 5 : Configure Baud Rate
     *
     * System Clock = 8 MHz
     * Baud Rate    = 115200
     *
     * USARTDIV = 8000000 / 115200
     *           ≈ 69.44
     *
     * BRR = 69
     *---------------------------------------------------------*/
    UART_PORT->BRR = 69;

    /*----------------------------------------------------------
     * Step 6 : Enable Transmitter
     *---------------------------------------------------------*/
    UART_PORT->CR1 |= USART_CR1_TE;

    /*----------------------------------------------------------
     * Step 7 : Enable Receiver
     *---------------------------------------------------------*/
    UART_PORT->CR1 |= USART_CR1_RE;

    /*----------------------------------------------------------
     * Step 8 : Enable USART
     *---------------------------------------------------------*/
    UART_PORT->CR1 |= USART_CR1_UE;
}

/******************************************************************************
 * Function : UART_SendChar
 ******************************************************************************/
void UART_SendChar(char ch)
{
    /* Wait until transmit register is empty */
    while(!(UART_PORT->ISR & USART_ISR_TXE))
    {

    }

    /* Send data */
    UART_PORT->TDR = ch;
}

/******************************************************************************
 * Function : UART_SendString
 ******************************************************************************/
void UART_SendString(const char *str)
{
    while(*str != '\0')
    {
        UART_SendChar(*str);
        str++;
    }
}

/******************************************************************************
 * printf() Redirection
 ******************************************************************************/
int _write(int file, char *ptr, int len)
{
    (void)file;

    for(int i = 0; i < len; i++)
    {
        UART_SendChar(ptr[i]);
    }

    return len;
}
