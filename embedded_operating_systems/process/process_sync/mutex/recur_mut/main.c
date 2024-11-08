#include<stdio.h>
#include<pthread.h>
int count=0;
pthread_mutex_t l;
void *incre(void *data){
    pthread_mutex_lock(&l);
    pthread_mutex_lock(&l);
    pthread_mutex_lock(&l);
    int i=0;
    while(i<1000){
        count++;
        printf("increment: %d\n",count);
        i++;
    }
    pthread_mutex_unlock(&l);
    pthread_mutex_unlock(&l);
    pthread_mutex_unlock(&l);
}
void *decre(){
    pthread_mutex_lock(&l);
    pthread_mutex_lock(&l);
    pthread_mutex_lock(&l);
    int i=0;
    while(i<1000){
        count--;
        printf("Decrement: %d\n",count);
        i++;
    }
    pthread_mutex_unlock(&l);
    pthread_mutex_unlock(&l);
    pthread_mutex_unlock(&l);
}
int main(){
    pthread_t a,b;
    pthread_mutexattr_t t;
    pthread_mutexattr_init(&t);
    pthread_mutexattr_settype(&t,PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(&l,&t);
    pthread_create(&a,NULL,incre,NULL);
    pthread_create(&b,NULL,decre,NULL);
    

    pthread_join(a,NULL);
    pthread_join(b,NULL);
    pthread_mutexattr_destroy(&t);
    pthread_mutex_destroy(&l);
}