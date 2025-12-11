#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"

TaskHandle_t thandle1,thandle2,thandle3;

void ser_task(void *data){
    printf("Task1\n");
    vTaskResume(thandle2);
    vTaskResume(thandle3);
    vTaskDelete(NULL);
}
void eth_task1(void *data){
    vTaskSuspend(NULL);
    printf("Task2 is resumed\n");
    printf("Task 2\n");
    vTaskDelete(NULL);
}

void eth_task2(void *data){
    vTaskSuspend(NULL);
    printf("Task3 is resumed\n");
    printf("Task 3\n");
    vTaskDelete(NULL);
}

void app_main(void){
    printf("in main function\n");
    xTaskCreatePinnedToCore(ser_task,"task1",2048,NULL,6,&thandle1,1);
    xTaskCreatePinnedToCore(eth_task1,"task2",2048,NULL,7,&thandle2,1);
    xTaskCreatePinnedToCore(eth_task2,"task3",2048,NULL,8,&thandle3,1);

}