#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

// pthread_barrier_t b;
void *temp(void *a){


}
void *lcd(void *a){
    
}
void *uart(void *a){

}
void *i2c(void *a){

}
int main(){
    pthread_t t1,t2,t3,t4;
    // pthread_barrier_init(&b,NULL,4);
    pthread_create(&t1,NULL,temp,NULL);
    pthread_create(&t2,NULL,lcd,NULL);
    pthread_create(&t3,NULL,uart,NULL);
    pthread_create(&t4,NULL,i2c,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);

    return 0;
}