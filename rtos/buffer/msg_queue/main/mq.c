#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"

TaskHandle_t thandle1,thandle2,thandle3;

QueueHandle_t q1;
//write
void fun1(void *data){
    printf("Task1\n");
    
    char s1[] = "yaswanth\n";
    while(1){
        xQueueSend(q1,s1,pdMS_TO_TICKS(10000));
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }



    // vTaskDelete(NULL);
}
//write
void fun2(void *data){
     printf("Task2\n");

      char s1[] = "cumbum town\n";
    while(1){
        xQueueSend(q1,s1,pdMS_TO_TICKS(10000));
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }



    // vTaskDelete(NULL);

}
//read
void fun3(void *data){
     printf("Task3\n");
//     char st1[20],st2[20];
//     xQueueReceive(q1,st1,pdMS_TO_TICKS(10000));
//     printf("%s\n",st1);

//   xQueueReceive(q1,st2,pdMS_TO_TICKS(10000));
//     printf("%s\n",st2);
char buf[30];
    while(1){
        xQueueReceive(q1,buf,pdMS_TO_TICKS(10000));
        vTaskDelay(5000/portTICK_PERIOD_MS);
        printf("%s\n",buf);
    }

    // vTaskDelete(NULL);
}


void app_main(){

    printf("In main function\n");
    q1 = xQueueCreate(4,30);
    xTaskCreatePinnedToCore(fun1,"task1",2048,NULL,7,&thandle1,1);
    xTaskCreatePinnedToCore(fun2,"task2",2048,NULL,6,&thandle2,1);
    xTaskCreatePinnedToCore(fun3,"task3",2048,NULL,5,&thandle3,1);
}