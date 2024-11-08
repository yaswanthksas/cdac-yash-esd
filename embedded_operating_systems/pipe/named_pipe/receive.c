#include<stdio.h>
#include <unistd.h>
  #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>


int main(){
    int fd;
    fd = open("yash",O_RDWR,S_IRUSR | S_IWUSR | S_IXUSR);
    char buf[10];
    read(fd,buf,sizeof(buf));
    printf("%s",buf);
    close(fd);

    return 0;
}