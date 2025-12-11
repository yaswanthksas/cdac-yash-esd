#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/message_buffer.h"

#define core 1 

TaskHandle_t thandle1,thandle2;
MessageBufferHandle_t msg;

int a1[] = {1,2,3,4};
int aa1[] = {1,2,9,87};

void fun1(void *data){
    printf("In send\n");
    xMessageBufferSend(msg,a1,sizeof(a1),pdMS_TO_TICKS(5000));
    xMessageBufferSend(msg,aa1,sizeof(aa1),pdMS_TO_TICKS(5000));

    vTaskDelete(NULL);

}
void fun2(void *data){
    printf("In receive\n");
    int a2[4],aa2[4];
    xMessageBufferReceive(msg,a2,sizeof(a2),pdMS_TO_TICKS(5000));
    xMessageBufferReceive(msg,aa2,sizeof(aa2),pdMS_TO_TICKS(5000));

    for(int i=0;i<4;i++){
        printf("NUmber: %d\n",a2[i]);
    }
    for(int i=0;i<4;i++){
        printf("NUmber: %d\n",aa2[i]);
    }
    vTaskDelete(NULL);
}

void app_main(){
    printf("In main function\n");
    msg = xMessageBufferCreate(200);
    xTaskCreatePinnedToCore(fun1,"task1",2408,NULL,7,&thandle1,core);
    xTaskCreatePinnedToCore(fun2,"task2",2408,NULL,6,&thandle2,core);


}