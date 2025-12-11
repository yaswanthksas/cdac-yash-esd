#include "freertos/FreeRTOS.h"
#include <stdio.h>
#include "freertos/task.h"
#include "freertos/timers.h"

#define CORE 1

TaskHandle_t t1,t2,t3;

void task1(void *arg)
{
    int count=0;
    while(1)
    {
        count++;
        if(count > 5)
        {
            count=0;
            vTaskResume(t2);
            vTaskDelay(pdMS_TO_TICKS(3000));
            vTaskResume(t3);
        }
        printf("In TASK1 !!\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}


void task2(void *arg)
{
    vTaskSuspend(NULL);
    int count=0;
    while(1)
    {
        count++;
        if(count > 5)
        {
            count=0;
            vTaskSuspend(t2);
        }
        printf("In TASK2 !!\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}


void task3(void *arg)
{
    vTaskSuspend(NULL);
    int count=0;
    while(1)
    {
        count++;
        if(count > 5)
        {
            count=0;
            vTaskSuspend(t3);
        }
        printf("In TASK3 !!\n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}



void app_main()
{
    xTaskCreatePinnedToCore(task1,"TASK 1",2048,NULL,6,&t1,CORE);
    xTaskCreatePinnedToCore(task2,"TASK 2",2048,NULL,7,&t2,CORE);
    xTaskCreatePinnedToCore(task3,"TASK 3",2048,NULL,8,&t3,CORE);
}