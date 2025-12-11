#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

TaskHandle_t thandle1, thandle2;
SemaphoreHandle_t sema;

void adctask(void *data)
{
    printf("Adc task started\n");
    //vTaskDelay(pdMS_TO_TICKS(5000));
        vTaskDelay(pdMS_TO_TICKS(10000));
    xSemaphoreGive(sema);
    printf("adc task send the signal\n");

    vTaskDelete(NULL);
}
void proctask(void *data)
{

    // while (1)
    // {

    //     printf("processing task started\n");

    //     xSemaphoreTake(sema, portMAX_DELAY);
    //     printf("got the signal\n");

    //     vTaskDelay(pdMS_TO_TICKS(1000));
    // }
    printf("processing task started\n");

    xSemaphoreTake(sema,4000);
    printf("got the signal\n");

    // vTaskDelay(pdMS_To_Ticks(1000));
    vTaskDelete(NULL);
}

void app_main()
{
    printf("Semaphore Question\n");
    sema = xSemaphoreCreateBinary();
    xTaskCreatePinnedToCore(adctask, "task1", 2408, NULL, 6, &thandle1, 1);
    xTaskCreatePinnedToCore(proctask, "task2", 2408, NULL, 9, &thandle2, 1);

}
