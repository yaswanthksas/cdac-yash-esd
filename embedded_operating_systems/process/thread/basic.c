#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* pf(){
    pthread_t id;
    id = pthread_self();
    printf("thread id: %ld\n",id);
    printf("Thread is executing\n");
    return NULL;
}
void* p(){
    pthread_t id;
    id = pthread_self();
    printf("thread id: %ld\n",id);
    printf("Thread is second\n");
    return NULL;
}
int main(){
    pthread_t id,id1;
    printf("Before pthread\n");
    pthread_create(&id,NULL,pf,NULL);
    pthread_create(&id1,NULL,p,NULL);
    pthread_join(id1,NULL);   //why output not came
    pthread_join(id,NULL);   //why output not came
    printf("After thread\n");
    return 0;
}