#include<stdio.h>
  #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main(){
    int fd;
    fd = open("new.txt",O_CREAT | O_RDWR, S_IRWXU | S_IWGRP);



    close(fd);
    return 0;
}