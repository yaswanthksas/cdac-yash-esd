#include<stdio.h>
#include<fcntl.h>
#include <sys/stat.h>        /* For mode constants */
       #include <mqueue.h>

struct mq_attr at;

int main(){
    mqd_t fd;
    fd = mq_open("/ms",O_CREAT | O_RDWR, S_IRUSR|S_IWUSR,&at);

    printf("%d\n",fd);
    

    return 0;
}