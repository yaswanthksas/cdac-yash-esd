#include<stdio.h>
 #include <sys/types.h>
       #include <unistd.h>

     //  pid_t fork(void);
int main(){
    printf("Before fork\n");
    printf("pid : %d\n",getpid());
    printf("ppid : %d\n",getppid());
    printf("\n-------------------------\n");
    fork();
    printf("After fork 1 \n");
    printf("pid : %d\n",getpid());
    printf("ppid : %d\n",getppid());
    printf("\n-------------------------\n");
    fork();
    printf("After fork 2 \n");
    printf("pid : %d\n",getpid());
    printf("ppid : %d\n",getppid());
    printf("\n-------------------------\n");
    // fork();
    // printf("After fork 3 \n");
    // printf("pid : %d\n",getpid());
    // printf("ppid : %d\n",getppid());
    // printf("\n-------------------------\n");
    // fork();
    // printf("After fork 4 \n");
    // printf("pid : %d\n",getpid());
    // printf("ppid : %d\n",getppid());
    // printf("\n-------------------------\n");
    

    return 0;
}