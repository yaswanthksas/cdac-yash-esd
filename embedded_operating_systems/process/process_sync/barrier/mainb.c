#include<stdio.h>
 #include <pthread.h>
#include<unistd.h>

pthread_barrier_t bar;
void *temp(void *d){
    printf("temperature barrier\n");
    // sleep(1);
    // sleep(3);
    pthread_barrier_wait(&bar);
    printf("temperature\n");

}
void *lcd(void *d){
    printf("LCD Barrier\n");
    // sleep(1);
    // sleep(1);
    pthread_barrier_wait(&bar);
    printf("lcd\n");


}
void *wifi(void *d){
    printf("wifi barrier\n");
    // sleep(1);
    // sleep(5);
    pthread_barrier_wait(&bar);
    printf("wifi\n");


}
void *eth(void *d){

    printf("eth barrier\n");
    // sleep(1);
    sleep(7);
    pthread_barrier_wait(&bar);
    printf("eth\n");

}


int main(){
    pthread_t t1,t2,t3,t4;
    pthread_barrier_init(&bar,NULL,4);
    pthread_create(&t1,NULL,temp,NULL);
    pthread_create(&t2,NULL,lcd,NULL);
    pthread_create(&t3,NULL,wifi,NULL);
    pthread_create(&t4,NULL,eth,NULL);
 
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);

    return 0;
}
