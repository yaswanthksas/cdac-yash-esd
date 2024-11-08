#include<stdio.h>
#include<stdlib.h>
  #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main(){
    int fr;
    char buf[20];
    fr = open("desdfifo",O_RDONLY);

    read(fr,buf,20);
    printf("Received: %s\n",buf);
    close(fr);


    return 0;
}