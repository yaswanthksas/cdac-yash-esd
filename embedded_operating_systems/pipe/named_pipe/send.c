#include<stdio.h>
#include <unistd.h>
  #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>


int main(){
    int fd;
    fd = open("yash",O_WRONLY,S_IRUSR | S_IWUSR | S_IXUSR);
    char str[10];
    printf("enter name: \n");
    scanf("%s",str);
    write(fd,str,sizeof(str));
    close(fd);

    return 0;
}