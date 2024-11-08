 #include <mqueue.h>
#include <fcntl.h>           /* For O_* constants */
       #include <sys/stat.h>        /* For mode constants */
       #include <mqueue.h>
#include<stdio.h>
int main(){
    struct mq_attr at;
    at.mq_maxmsg = 4;
    at.mq_msgsize = 100;
    at.mq_curmsgs = 0;
    at.mq_flags = 0;
    mqd_t fd;
    fd = mq_open("/msgque", O_CREAT | O_RDWR, S_IRWXU,&at);
    // char s[10] = "hello\n";
    // mq_send(fd,s,100,0);

    int arr[3]={1,2,3};
int *ptr;
ptr = arr;
    mq_send(fd,(char *)arr,sizeof(arr),0);

    mq_close(fd);


    return 0;
}