#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

int main(){
    pid_t id;
    printf("Before fork \n");
    printf("PID: %d\n",getpid());
    printf("PPID: %d\n",getppid());
    printf("\n---------------------------------\n\n");
    id = fork();
    if(id == 0){
        printf("CHILD PID: %d PPID: %d\n",getpid(),getppid());

    }
    else{
        printf("Parent PID: %d PPID: %d\n",getpid(),getppid());
    }


    return 0;
}
