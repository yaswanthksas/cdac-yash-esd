#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
int main(){
    printf("Before fork\n");
    printf("pid : %d\n",getpid());
    printf("ppid : %d\n",getppid());
    printf("\n ----------------------------------- \n");
    fork();
    printf("after fork\n");
    printf("pid : %d\n",getpid());
    printf("ppid : %d\n",getppid());
    printf("\n ----------------------------------- \n");
    return 0;
}