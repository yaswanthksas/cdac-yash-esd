#include<stdio.h>
#include <pthread.h>
int count = 0;
pthread_mutex_t l;

void *inc(void *b){
    while(1){
        pthread_mutex_lock(&l);
        pthread_mutex_lock(&l);
        count++;
        printf("inc: %d\n",count);    
        pthread_mutex_unlock(&l);
        pthread_mutex_unlock(&l);
    }
}

void *dec(void *k){
    while(1){
        pthread_mutex_lock(&l);
        pthread_mutex_lock(&l);
        count--;
        printf("dec: %d\n",count);    
        pthread_mutex_unlock(&l);
        pthread_mutex_unlock(&l);
    }

}
int main(){
    pthread_t a,b;
    pthread_mutexattr_t x;
    pthread_mutexattr_init(&x);
    pthread_mutexattr_settype(&x, PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(&l,&x);
    pthread_create(&a,NULL,inc,NULL);
    pthread_create(&b,NULL,dec,NULL);
    pthread_join(a,NULL);
    pthread_join(b,NULL);
    pthread_mutexattr_destroy(&x);
    pthread_mutex_destroy(&l);
    return 0;
} 