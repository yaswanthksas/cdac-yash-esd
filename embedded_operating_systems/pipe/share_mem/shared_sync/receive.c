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

  //  *count = "yashwanth";
    // write(fd,count,sizeof(count));
    read(fd,count,sizeof(count));
    printf("%s",count);
    printf("is good\n");


    return 0;
}