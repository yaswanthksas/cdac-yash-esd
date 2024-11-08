#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
// #include <bits/pthreadtypes.h>
pthread_rwlock_t l;
int count = 0;
void *read1(void *d){
    while(1){
        // printf("read lock 1:\n");
        pthread_rwlock_rdlock(&l);
        // count++;
        printf("read1: %d\n",count);
        sleep(1);
        pthread_rwlock_unlock(&l);
        // printf("read unlock 1: \n");
        // sleep(1);
    }

}
void *read2(void *d){
     while(1){
        //  printf("read lock 2:\n");
        pthread_rwlock_rdlock(&l);
        // count++;
        printf("read2: %d\n",count);
       
        pthread_rwlock_unlock(&l);
        sleep(1);
        // printf("read unlock 2: \n");
    }

}
void *write1(void *d){
     while(1){
        // printf("write lock 1 \n");
        pthread_rwlock_wrlock(&l);
        count++;
        printf("write 1: %d\n",count);
        sleep(5);
        pthread_rwlock_unlock(&l);
        // printf("write unlock 1\n");
    }

}
void *write2(void *d){
    while(1){
        // printf("write lock 2 \n");
          pthread_rwlock_wrlock(&l);
        count+= 5;
        printf("write 2: %d\n",count);
        sleep(5);
        pthread_rwlock_unlock(&l);
        // printf("write unlock 2\n");
    }
}

int main(){
    pthread_t t1,t2,t3,t4;
    pthread_rwlock_init(&l,NULL);
    pthread_create(&t1,NULL,read1,NULL);
    pthread_create(&t3,NULL,write2,NULL);
    pthread_create(&t2,NULL,read2,NULL);
    pthread_create(&t4,NULL,write1,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);


    return 0;
}