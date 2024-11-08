#include<stdio.h>
#include <pthread.h>
pthread_mutex_t x;
int count = 0;
void *inc(void *d){
    while(1){
        pthread_mutex_lock(&x);
        count++;
        printf("inc: %d\n",count);
        pthread_mutex_unlock(&x);
    }
}
void *dec(void *d){
    while(1){
        pthread_mutex_lock(&x);
        count--;
        printf("dec: %d\n",count);
        pthread_mutex_unlock(&x);
    }
}
int main(){
    pthread_t t1,t2;
    pthread_mutex_init(&x,NULL);
    pthread_create(&t1,NULL,inc,NULL);
    pthread_create(&t2,NULL,dec,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_mutex_destroy(&x);
    return 0;

}