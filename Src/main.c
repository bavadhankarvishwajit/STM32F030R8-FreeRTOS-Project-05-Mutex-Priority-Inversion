#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "gpio.h"
#include "uart.h"
#include "mutex_demo.h"

int main(void)
{
    GPIO_Init();
    UART2_Init();

    printf("\r\n");
    printf("STM32F030R8 Mutex Demo\r\n");

    uartMutex = xSemaphoreCreateMutex();

    if (uartMutex == NULL)
    {
        while (1)
        {

        }
    }

    xTaskCreate(
            HighTask,
            "HIGH",
            128,
            NULL,
            3,
            NULL);

    xTaskCreate(
            MediumTask,
            "MEDIUM",
            128,
            NULL,
            2,
            NULL);

    xTaskCreate(
            LowTask,
            "LOW",
            128,
            NULL,
            1,
            NULL);

    vTaskStartScheduler();

    while (1)
    {

    }
}
