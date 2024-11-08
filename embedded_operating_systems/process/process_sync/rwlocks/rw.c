#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
// int count = 0;
pthread_rwlock_t l;
void *read1(void *d){
    while(1){
        printf("read1 lock\n");
        pthread_rwlock_rdlock(&l);
        printf("REading 1 file\n");
        pthread_rwlock_unlock(&l);
        printf("Read1 unlocked\n\n");
        sleep(10);
    }
}
void *read2(void *d){
    while(1){
        printf("read2 lock\n");
        pthread_rwlock_rdlock(&l);
        printf("Reading 2 file\n");
        pthread_rwlock_unlock(&l);
        printf("Read2 unlocked\n\n");
        sleep(1);
    }
}
void *write1(void *d){
    while(1){
        printf("Write 1 lock\n");
        pthread_rwlock_wrlock(&l);
        printf("writing 1 file\n");
        pthread_rwlock_unlock(&l);
        printf("write 1 unlock\n\n");
        sleep(5);
    }
}
void *write2(void *d){
    while(1){

    printf("write2 lock\n");
    pthread_rwlock_wrlock(&l);
    printf("writing 2 file\n");
    pthread_rwlock_unlock(&l);
    printf("write2 unlock\n\n");
    sleep(5);
    }

}
int main(){
    pthread_t i1,i2,i3,i4;
    pthread_rwlock_init(&l,NULL);
    pthread_create(&i1,NULL,read1,NULL);
    pthread_create(&i3,NULL,write1,NULL);
    pthread_create(&i2,NULL,read2,NULL);
    pthread_create(&i4,NULL,write2,NULL);

    pthread_join(i1,NULL);
    pthread_join(i2,NULL);
    pthread_join(i3,NULL);
    pthread_join(i4,NULL);
    pthread_rwlock_destroy(&l);
    return 0;
}