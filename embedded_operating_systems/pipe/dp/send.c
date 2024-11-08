#include<stdio.h>
#include<stdlib.h>
  #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

 #include <unistd.h>


int main(){
    int fd;
    // char bf[20];
    fd = open("desdfifo",O_WRONLY);

    write(fd,"hello\n",6);
    close(fd);



    return 0;
}