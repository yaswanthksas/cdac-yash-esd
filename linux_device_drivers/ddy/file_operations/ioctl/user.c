#include<stdio.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define wr_value _IOW('a',0,int)
#define rd_value _IOR('a',1,int)
// char str[1024],buf[1024];
int x;
int main(){
    int fd;
    fd = open("/dev/device_y_file",O_RDWR);
    // printf("Enter name\n");
    // scanf("%s",buf);
    ioctl(fd,wr_value,54);
    ioctl(fd,rd_value,fd);
    // printf("%s",str);
    close(fd);
    return 0;
}