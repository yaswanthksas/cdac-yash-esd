#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"

#define core 1 
TaskHandle_t thandle1,thandle2;
StreamBufferHandle_t strm;
// uint8_t arr[4]={1,2,3,4};
// uint8_t arr1[4]={5,6,7,8};
char s[12]="hello\n";
void fun1(void *data){
    printf("In send\n");
    
    // xStreamBufferSend( strm, arr, 4, pdMS_TO_TICKS(4000) );
    // xStreamBufferSend( strm, arr1, 4, pdMS_TO_TICKS(4000) );
    xStreamBufferSend( strm, s, sizeof(s), pdMS_TO_TICKS(4000) );
    
    vTaskDelete(NULL);
}
void fun2(void *data){
    printf("In receive\n");
    // uint8_t ar1[8];
    char n[12];
    // xStreamBufferReceive( strm, ar1, sizeof(ar1), pdMS_TO_TICKS(4000));
    xStreamBufferReceive( strm, n, sizeof(n), pdMS_TO_TICKS(4000));

    // for(int i=0;i<8;i++){
    //     printf("Number: %d\n",ar1[i]);
    // }
    printf("%s\n",n);
    vTaskDelete(NULL);
}
void app_main(){
    
    printf("In main function\n");
    strm = xStreamBufferCreate(200,0);
    xTaskCreatePinnedToCore(fun1,"task1",2408,NULL,6,&thandle1,core);
    xTaskCreatePinnedToCore(fun2,"task2",2408,NULL,5,&thandle2,core);


}