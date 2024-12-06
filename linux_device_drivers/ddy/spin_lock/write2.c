#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
    /*
    read two number pass to an array 
    open device file
    write data to device file 
    close device file
    */

int main(){
    int fd;
    int n1,n2;
    printf("Welcome to write app 2\n");
    printf("Enter two numbers\n");
    scanf("%d%d",&n1,&n2);

    int number[2] = {n1,n2};

    fd = open("/dev/write_app2s",O_RDWR, S_IRWXU);

    // if(fd < 0){
    //     printf("Error opening the file\n");
    //     return -1;
    // }
    // printf("Success in opening file\n");
    int result;
    result = write(fd,(char *)number,sizeof(number));

    // if(result < 0){
    //     printf("Error in writing data from user file\n");
    //     return -1;
    // }
    // printf("Success in writing file\n");

    close(fd);
    return 0;
}