#include<stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t id;   //declare
int count=0;
void *inc(void *a){
    while(1){
        sem_wait(&id);
        count++;
        printf("INC: %d\n",count);
        sem_post(&id);
    }
}
void *dec(void *a){
    while(1){
        sem_wait(&id);
        count--;
        printf("DEC: %d\n",count);
        sem_post(&id);
    }
}
int main(){
    sem_init(&id,0,1); //initialization
    pthread_t x,y;
    pthread_create(&x,NULL,inc,NULL);
    pthread_create(&y,NULL,dec,NULL);
    pthread_join(x,NULL);
    pthread_join(y,NULL);

    return 0;
}