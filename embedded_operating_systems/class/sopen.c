#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
 #include <unistd.h>


int main(){
    int x;
    x = open("hello.txt", O_CREAT,S_IRWXU);



    int y;
    y = close(x);

}