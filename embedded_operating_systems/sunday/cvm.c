#include<stdio.h>
#include<pthread.h> 
#include<unistd.h>

pthread_mutex_t m;
pthread_cond_t con;
int count = 0; 

void *send(void *a){
   
    pthread_mutex_lock(&m);

    while(!count){
        printf("waiting \n");
       pthread_cond_wait(&con,&m);
        printf("Wait end\n");
    }
    printf("send count: %d\n",count);
    pthread_mutex_unlock(&m);
}
void *receive(void *a){
 
    pthread_mutex_lock(&m);
    count = 1;
    printf("rec count: %d\n",count);
    printf("condition worked\n");
    pthread_cond_signal(&con);
    printf("hello\n");

    pthread_mutex_unlock(&m);
   
}

int main(){
    pthread_t t1,t2;

    pthread_mutex_init(&m,NULL);
    pthread_cond_init(&con,NULL);
    pthread_create(&t1,NULL,send,NULL);
    pthread_create(&t2,NULL,receive,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_mutex_destroy(&m);
    pthread_cond_destroy(&con);

    return 0;
}