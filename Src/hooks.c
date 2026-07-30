#include "FreeRTOS.h"
#include "task.h"

/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook(void)
{
    taskDISABLE_INTERRUPTS();

    while(1)
    {

    }
}

/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook(TaskHandle_t xTask,
                                   char *pcTaskName)
{
    (void)xTask;
    (void)pcTaskName;

    taskDISABLE_INTERRUPTS();

    while(1)
    {

    }
}
