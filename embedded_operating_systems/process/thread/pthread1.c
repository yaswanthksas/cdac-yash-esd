#include<stdio.h>
#include <pthread.h>
void *hi(){
    int i=0;
    while(i<5){
        printf("inside thread\n");
        i++;
    }
}
int main(){
    pthread_t id;
    pthread_create(&id,NULL,&hi,NULL);
    pthread_join(id,NULL);
    printf("after thread join\n");

    return 0;
}