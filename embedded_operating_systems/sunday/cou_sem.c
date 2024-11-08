#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
/* 

/* wrong 
greatest mistake of os 

with out knowing the critical region 
or shared resource how can you lock or unlock 
sema phore 

*/
sem_t s1;
int count = 0;
void* first(void *a){
    while(1){
        sem_wait(&s1);
        printf("First\n");
        sem_post(&s1);
    }
}

void* second(void *a){
    while(1){
        sem_wait(&s1);
        printf("second\n");
        sem_post(&s1);
    }
}

void* third(void *a){
    while(1){
        sem_wait(&s1);
        printf("third\n");
        sem_post(&s1);
    }
}

void* fourth(void *a){
    while(1){
        sem_wait(&s1);
        printf("fourth\n");
        sem_post(&s1);
    }
}
int main(){
    pthread_t t1,t2,t3,t4;
    sem_init(&s1,0,3);
    pthread_create(&t1,NULL,first,NULL);
    pthread_create(&t2,NULL,second,NULL);
    pthread_create(&t3,NULL,third,NULL);
    pthread_create(&t4,NULL,fourth,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);

    sem_destroy(&s1);
    return 0;
}