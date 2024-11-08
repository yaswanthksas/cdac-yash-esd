#include<stdio.h>
 #include <unistd.h>
    #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main(){
    int fd,n;
    fd = open("sys.txt", O_RDWR, S_IRWXU | S_IWGRP);
    char bu[10];
    read(fd,bu,sizeof(bu));

    n = open("dest.txt",O_CREAT | O_RDWR,S_IRWXU | S_IWGRP); 
    write(n,bu,sizeof(bu));

    close(fd);
    close(n);
    return 0;
}