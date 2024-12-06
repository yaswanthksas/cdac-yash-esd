#include<stdio.h>
 #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <sys/ioctl.h>



#define i_s_m _IOR('q',1,char *)    //macro //with respet to kernel
#define i_g_m _IOW('q',2,char *)



int main(){
    int fd;
    char uread[50];
    fd = open("/dev/device_file_1",O_RDWR);
    char buff[]="this is the user space\n";
    int i,j;
    i = ioctl(fd,i_s_m,buff);
    j = ioctl(fd,i_g_m,uread);
    printf("%s",uread);

    close(fd);
}