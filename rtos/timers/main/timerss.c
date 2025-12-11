#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/timers.h"

#define CORE 1

TaskHandle_t thandle;
TimerHandle_t s_timer;
void serial(TimerHandle_t s_timer){
    printf("Timer fired\n");

}

void serial_task(void *data){
    printf("serial task started\n");
    s_timer = xTimerCreate("one_timer",pdMS_TO_TICKS(3000),pdFALSE,0,serial);
    xTimerStart(s_timer,0);
    vTaskDelete(thandle);

}

    BaseType_t t1;
void app_main(void){
    t1 = xTaskCreatePinnedToCore(serial_task,"new_task",2048,NULL,6,&thandle,CORE);
}