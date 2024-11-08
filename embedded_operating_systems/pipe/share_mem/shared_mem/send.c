#include<stdio.h>
  #include <sys/mman.h>
       #include <sys/stat.h>        /* For mode constants */
       #include <fcntl.h>  
int main(){
    int *count;
    int fd;
    fd = shm_open("share",O_RDWR,S_IRWXU);
    
    ftruncate(fd,sizeof(int));

    count = (int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

    *count = 0;
    // write(fd,"apple",6);

    while(1){
      (*count)++;
      printf("Count : %d\n",*count);
      sleep(1);
    }


    return 0;
}