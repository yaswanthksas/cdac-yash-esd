#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"

TaskHandle_t thandle1,thandle2;
// BaseType_t t1,t2;

void serial_fun(void *data){
    int count = 0;

    while(1){
        count++;
        if(count > 5){
            vTaskResume(thandle2);
            vTaskSuspend(thandle1);
            count=0;
        }
        printf("serial task\n");
        // vTaskSuspend(thandle1);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    //vTaskDelete(NULL);
}

void eth_fun(void *data){
    vTaskSuspend(thandle2);
    int count = 0;

    while(1){
        
        count++;
        if(count > 5){
            vTaskResume(thandle1);
            vTaskSuspend(thandle2);
            count=0;
        }
        printf("eth task\n");
    
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

   // vTaskDelete(NULL);

}
void app_main(void){

    printf("In main function\n");
    xTaskCreatePinnedToCore(serial_fun,"serial_function",2408,NULL,6,&thandle1,1);
    xTaskCreatePinnedToCore(eth_fun,"eth_function",2408,NULL,9,&thandle2,1);

}