#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 #include <unistd.h>


char buff[1024];

int main(){
    int fd;
    fd = open("/dev/riode",O_RDWR);
    ssize_t y;
    y =read(fd,buff,sizeof(buff));
    printf("Read the string is :\n");
    printf("%s",buff);
    close(fd);


    return 0;
}