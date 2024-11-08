#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
  #include <unistd.h>
#include<stdio.h>

int main(){
    int fd;
    fd = open("yash.txt",O_CREAT | O_RDWR, 00700 | 00020);
    printf("fd: %d\n",fd);
    char buf[] = "rio de jenero";
    ssize_t z;
    z = write(fd,buf,sizeof(buf));
    printf("z: %ld\n",z);
    int y;
    y = close(fd);
    printf("y: %d\n",y);
    return 0;
}