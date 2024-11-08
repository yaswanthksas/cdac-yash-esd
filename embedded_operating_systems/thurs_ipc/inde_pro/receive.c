#include<stdio.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
      #include <unistd.h>



int main(){
    int fd;
    char buf[10];
    fd = open("y_s",O_RDWR, S_IRWXU);
    read(fd,buf,10);
    printf("%s",buf);
    close(fd);

    return 0;
}