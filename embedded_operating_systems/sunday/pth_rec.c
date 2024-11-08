#include<stdio.h>
#include<pthread.h>
pthread_mutex_t m;
int count = 0;
void *inc(void *b){
    while(1){
        pthread_mutex_lock(&m);
        pthread_mutex_lock(&m);
        count++;
        printf("inc: %d\n",count);
        pthread_mutex_unlock(&m);
        pthread_mutex_unlock(&m);
    }
}
void *dec(void *b){
    while(1){
        pthread_mutex_lock(&m);
        pthread_mutex_lock(&m);
        count++;
        printf("dec: %d\n",count);
        pthread_mutex_unlock(&m);
        pthread_mutex_unlock(&m);
    }
}
int main(){
    pthread_t t1,t2;
    pthread_mutexattr_t a;
    pthread_mutexattr_init(&a);
    pthread_mutexattr_settype(&a,PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(&m,&a);
    pthread_create(&t1,NULL,inc,NULL);
    pthread_create(&t2,NULL,dec,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_mutexattr_destroy(&a);
    pthread_mutex_destroy(&m);
    return 0;
}