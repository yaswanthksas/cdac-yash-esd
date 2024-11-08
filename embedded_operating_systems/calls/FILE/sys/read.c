#include<stdio.h>
 #include <unistd.h>
    #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main(){
    // open("sys.txt",O_RDWR,S_IRUSR|S_IWUSR);
    int fd;
    fd = open("sys.txt", O_RDWR, S_IRWXU | S_IWGRP);
    char gold[15];
    read(fd,gold,sizeof(gold));
    printf("%s",gold);

    close(fd);
    return 0;
}