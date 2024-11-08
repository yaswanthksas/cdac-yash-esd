#include<stdio.h>
  #include <sys/mman.h>
       #include <sys/stat.h>        /* For mode constants */
       #include <fcntl.h>  
       #include<stdlib.h>
       #include <unistd.h>

int main(){
    int *count;
    char rec[10];
    int fd;
    fd = shm_open("share",O_CREAT|O_RDWR,S_IRWXU);
    
    ftruncate(fd,sizeof(int));

    count = (int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

    *count = 0;
    // read(fd,rec,10);
    // write(1,rec,6);
    while(1){
    //   (*count)++;
      printf("Count : %d\n",*count);
      sleep(1);
    }


    return 0;
}