 #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
 #include <unistd.h>

int main(){
int fd;
fd = open("/home/l1-pc22/Desktop/new.txt",O_CREAT|O_RDWR,S_IRWXU | S_IWGRP);
ssize_t y;
char buf[] = "he5151llo";
y = write(fd,buf,sizeof(buf));
int x;
x = close(fd);
return 0;
}
