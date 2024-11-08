#include<stdio.h>
 #include <pthread.h>
int count = 0;
void *inc(void *a){
    while(1){
        count++;
        printf("Increment: %d\n",count);
    }
}
void *dec(void *b){
    while(1){
        count--;
        printf("Decrement: %d\n",count);
    }
}

int main(){
    pthread_t id1,id2;
    pthread_create(&id1,NULL,inc,NULL);
    pthread_create(&id2,NULL,dec,NULL);

    pthread_join(id1,NULL);
    pthread_join(id2,NULL);

    return 0;
}
