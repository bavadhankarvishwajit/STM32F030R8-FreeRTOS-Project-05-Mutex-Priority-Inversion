#ifndef MUTEX_DEMO_H
#define MUTEX_DEMO_H

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

extern SemaphoreHandle_t uartMutex;

void HighTask(void *pvParameters);
void MediumTask(void *pvParameters);
void LowTask(void *pvParameters);

#endif
