#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"

#define core 1 

TaskHandle_t thandle1,thandle2;
UBaseType_t p1,p2,pmain;
BaseType_t t1,t2;

void serial_task(void *data){
    while(1){
        printf("Serial task started\n");
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
    p1 = uxTaskPriorityGet(NULL);
    printf("serial priority %d\n",p1);
    vTaskDelete(thandle1);
}

void eth_task(void *data){
    p2 = uxTaskPriorityGet(NULL);
    printf("eth priority %d\n",p2);
    while(1){
        printf("Ethernet task started\n");
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
    vTaskDelete(thandle2);
}


void app_main(void){
    t1 = xTaskCreatePinnedToCore(serial_task,"new_task1",2048,NULL,6,&thandle1,core);
    t2 = xTaskCreatePinnedToCore(eth_task,"new_task2",2048,NULL,9,&thandle2,core);
    pmain = uxTaskPriorityGet(NULL);
    printf("Main thread Priority : %d\n",pmain);


    // if(t1 == pdPASS){
    //     printf("Serial task created successfully\n");
    // }
    // if(t2 == pdPASS){
    //     printf("Ethernet task created successfully\n");
    // }

}


