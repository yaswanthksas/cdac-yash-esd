#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/timers.h"

TaskHandle_t thandle;
TimerHandle_t tim;
int count = 0;
void timCallback(TimerHandle_t tim){
    count++;
    printf("Timer callback: %d\n",count);
}

void my_task(void *data){
    //create timer
    //start timer 
    tim = xTimerCreate("yash_timer",pdMS_TO_TICKS(1000),pdTRUE,0,timCallback);
    xTimerStart(tim,0);
    vTaskDelay(pdMS_TO_TICKS(1000));
    printf("HLo\n");
    vTaskDelete(NULL);
}

void app_main(){
    printf("one shot timer\n");
    xTaskCreatePinnedToCore( my_task,"yash_task",2048,NULL,6,&thandle,1);

}