#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*
    to read data from kernel
    stored in op_result
    steps involved:
    open 
    read 
    close
*/
int main(){
    int fd;
    int op_result;

    printf("Welcome to read application\n");

    fd = open("/dev/read_app",O_RDWR,0777);
    // if(fd<0){
    //     printf("Error in opening the file\n");
    //     return -1;
    // }
    // printf("Success in opening the read file\n");
    // ssize_t result;
    // result = read(fd,&op_result,sizeof(op_result));
    read(fd,&op_result,sizeof(op_result));
    // if(result < 0){
    //     printf("Error in reading file from user\n");
    //     return -1;
    // }
    printf("Data read addition is %d\n",op_result);

    close(fd);
    return 0;
}