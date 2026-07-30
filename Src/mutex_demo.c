#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "mutex_demo.h"

SemaphoreHandle_t uartMutex;

void HighTask(void *pvParameters)
{
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(500));

        printf("\r\n");
        printf("HIGH : Waiting for mutex\r\n");

        xSemaphoreTake(uartMutex, portMAX_DELAY);

        printf("HIGH : Mutex acquired\r\n");

        xSemaphoreGive(uartMutex);

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void MediumTask(void *pvParameters)
{
    while (1)
    {
        printf("MEDIUM : Running\r\n");

        vTaskDelay(pdMS_TO_TICKS(300));
    }
}

void LowTask(void *pvParameters)
{
    while (1)
    {
        xSemaphoreTake(uartMutex, portMAX_DELAY);

        printf("\r\n");
        printf("LOW : Mutex acquired\r\n");

        vTaskDelay(pdMS_TO_TICKS(3000));

        printf("LOW : Mutex released\r\n");

        xSemaphoreGive(uartMutex);

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
