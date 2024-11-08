#include<stdio.h>
 #include <unistd.h>
 #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main(){
    int fd;
    fd = open("sys.txt", O_CREAT | O_RDWR, S_IRWXU | S_IWGRP);
    char buf[]="yaswanth \n ";
    write(fd,buf,sizeof(buf));
    
    close(fd);
    return 0;
}

