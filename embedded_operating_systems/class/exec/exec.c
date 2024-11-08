#include <unistd.h>
#include<stdio.h>
int main(){
    printf("Before exec\n");
    execl("/usr/bin/ls","","-al",NULL);
    printf("After exec\n");


    return 0;
}