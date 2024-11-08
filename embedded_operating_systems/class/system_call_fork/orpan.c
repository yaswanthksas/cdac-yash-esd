#include<stdio.h>
 #include <sys/types.h>
       #include <unistd.h>

#include<stdlib.h>

int main(){
    pid_t id;
    printf("Before fork\n");
    id = fork();
    if(id == 0){
        printf("Child PID : %d PPID: %d\n",getpid(),getppid());
        sleep(10);
        printf("Child PID : %d PPID: %d\n",getpid(),getppid());
    }
    else{
        printf("Parent PID: %d PPID: %d\n",getpid(),getppid());
    }

    return 0;
}