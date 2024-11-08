#include<stdio.h>
#include <pthread.h>
int count = 0;
void *inc(void *a){
    int i=0;
    while(i<25){
         printf("increment: %d\n",count);
         count++;
         i++;
    }
}
void *dec(void *b){
    int i=0;
    while(i<25){
         printf("decrement: %d\n",count);
         count--;
         i++;
    }

}
int main(){
    pthread_t id,id2;
    pthread_create(&id,NULL,inc,NULL);
    pthread_create(&id2,NULL,dec,NULL);
    pthread_join(id,NULL);
    pthread_join(id2,NULL);

    return 0;
}