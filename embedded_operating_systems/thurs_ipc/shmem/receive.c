#include<stdio.h>
  #include <sys/mman.h>
       #include <sys/stat.h>        /* For mode constants */
       #include <fcntl.h>  
       #include<stdlib.h>
       #include <unistd.h>        /* For O_* constants */

int main(){
    int fd;
    fd = shm_open("/yas",O_CREAT | O_RDWR, S_IRWXU);
    
    ftruncate(fd,sizeof(int));
    int *count;
    count = (int *)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);

    // *count = 56;
    printf("%d",*count);


    return 0;
}