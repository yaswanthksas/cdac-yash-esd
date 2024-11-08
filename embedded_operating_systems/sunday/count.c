#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t s1;
/* doubt regarding flow of counting semaphore why it is fast*/
int count = 0;
void* first(void *a){
    while(1){
        sem_wait(&s1);
        count++;
        printf("inc: %d\n",count);
        sem_post(&s1);
    }
}

void* second(void *a){
    while(1){
        sem_wait(&s1);
        count--;
        printf("dec: %d\n",count);
        sem_post(&s1);
    }
}

void* third(void *a){
    while(1){
        sem_wait(&s1);
        count = count +5;
        printf("plus: %d\n",count);
        sem_post(&s1);
    }
}

int main(){
    pthread_t t1,t2,t3;
    sem_init(&s1,0,3);
    pthread_create(&t1,NULL,first,NULL);
    pthread_create(&t2,NULL,second,NULL);
    pthread_create(&t3,NULL,third,NULL);


    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);


    sem_destroy(&s1);
    return 0;
}