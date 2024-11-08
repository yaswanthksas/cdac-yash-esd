#include<stdio.h>
 #include <semaphore.h>
#include<pthread.h>
sem_t s1;
int count = 0;
void *inc(void *a){
    while(1){
        sem_wait(&s1);
        count++;
        printf("inc: %d\n",count);
        sem_post(&s1);
    }
}
void *dec(void *a){
    while(1){
        sem_wait(&s1);
        count--;
        printf("dec: %d\n",count);
        sem_post(&s1);
    }
}
int main(){
    pthread_t t1,t2;
    sem_init(&s1,0,1);
    pthread_create(&t1,NULL,inc,NULL);
    pthread_create(&t2,NULL,dec,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&s1);

    return 0;
}