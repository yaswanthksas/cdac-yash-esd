#include<stdio.h>
 #include <sys/mman.h>
       #include <sys/stat.h>        /* For mode constants */
       #include <fcntl.h>  
 #include <unistd.h>
       #include <sys/types.h>

int main(){

    int fd;
    fd = shm_open("r_share",O_CREAT | O_RDWR, S_IRWXU);
    ftruncate(fd,(10 * sizeof(char)));
    char *count;
    count = (char *)mmap(NULL,10*sizeof(char),PROT_READ | PROT_WRITE, MAP_SHARED, fd,0);

    // sem_open("smem",O_CREAT | O_RDWR, S_IRWXU);

    char cnt[10] = "yashwanth";
    count = cnt;
    write(fd,count,sizeof(count));
    // printf("%s",count);

    return 0;
}