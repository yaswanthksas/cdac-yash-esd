#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include<unistd.h>
#include<sys/types.h>
  #include <sys/mman.h>
#include<stdio.h>
int main(){
    int fd;
    fd = shm_open("yas", O_RDWR, S_IRWXU);

    ftruncate(fd,sizeof(int));

    int *count;
    count = (int *)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE, MAP_SHARED,fd,0);
    // *count = 0;

    while(1){
        // (*count)++;
        printf("count : %d\n",(*count));

        sleep(1);
    }


    return 0;
}