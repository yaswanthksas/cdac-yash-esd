#include<stdio.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
      #include <unistd.h>



int main(){
    int fd;
    fd = open("y_s",O_RDWR , S_IRWXU);
    write(fd,"yash",4);
    close(fd);
    

    return 0;
}