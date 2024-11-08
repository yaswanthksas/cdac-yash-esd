#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int count = 0;
sem_t s1,s2;
void *inc(void *a){

    while(1){
        sem_wait(&s1);  // 1 to 0 
        count++;
        printf("inc: %d\n",count);
        sem_post(&s2);  // 0 to 1 
    }
}
void *dec(void *a){
    while(1){
        sem_wait(&s2); //1 to 0 
        count--;
        printf("dec: %d\n",count);
         sem_post(&s1); //  0 to 1 
    }
}
int main(){
    pthread_t t1,t2;
    sem_init(&s1,0,1);
    sem_init(&s2,0,0);
    pthread_create(&t1,NULL,inc,NULL);
    pthread_create(&t2,NULL,dec,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    sem_destroy(&s1);
    sem_destroy(&s2);

    return 0;
}