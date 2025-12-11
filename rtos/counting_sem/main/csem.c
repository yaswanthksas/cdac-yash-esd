#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/semphr.h"


#define core 1 

TaskHandle_t thandle1,thandle2,thandle3,thandle4;
SemaphoreHandle_t sem;

void task1(void *data){
    
    xSemaphoreTake(sem,pdMS_TO_TICKS(10000));
    
    printf("Task1\n");
    vTaskDelay(5000/portTICK_PERIOD_MS);
    
    xSemaphoreGive(sem);

    vTaskDelete(NULL);
}

void task2(void *data){
    xSemaphoreTake(sem,pdMS_TO_TICKS(10000));
    
    printf("Task2\n");
    vTaskDelay(5000/portTICK_PERIOD_MS);
    
    xSemaphoreGive(sem);

    vTaskDelete(NULL);
}

void task3(void *data){
    xSemaphoreTake(sem,pdMS_TO_TICKS(10000));
    
    printf("Task3\n");
    vTaskDelay(5000/portTICK_PERIOD_MS);
    
    xSemaphoreGive(sem);

    vTaskDelete(NULL);
}

void task4(void *data){
   xSemaphoreTake(sem,pdMS_TO_TICKS(10000));
    
    printf("Task4\n");
    vTaskDelay(5000/portTICK_PERIOD_MS);
    
    xSemaphoreGive(sem);

    vTaskDelete(NULL);
}

void app_main(){
    printf("Mainfunction\n");
    sem = xSemaphoreCreateCounting(2,2);
    xTaskCreatePinnedToCore(task1,"task1",2048,NULL,6,&thandle1,core);
    xTaskCreatePinnedToCore(task2,"task2",2048,NULL,6,&thandle2,core);
    xTaskCreatePinnedToCore(task3,"task3",2048,NULL,6,&thandle3,core);
    xTaskCreatePinnedToCore(task4,"task4",2048,NULL,6,&thandle4,core);

}