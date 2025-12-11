#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"

TaskHandle_t thandle;

void task_function(void *data){
    printf("Task executed\n");
    UBaseType_t pr;
    pr = uxTaskPriorityGet(thandle);
    printf("Priority Number: %d\n",pr);

    // vTaskDelete(NULL);   
    vTaskDelete(thandle);   
}



void app_main(void){
    BaseType_t t1;
    // UBaseType_t x;
    // x = uxTaskPriorityGet(NULL);
    // printf("main task handle: %d\n",x);
    t1 = xTaskCreate(task_function,"first_task",2048,NULL,6,&thandle);
    if(t1 == pdPASS){
        printf("Task created successfully\n");
    }


}