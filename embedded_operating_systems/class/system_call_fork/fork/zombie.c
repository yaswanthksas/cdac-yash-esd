 #include <sys/types.h>
       #include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
    pid_t id;
    printf("before fork\n");
    id = fork();
    if(id == 0){
        printf("CHILD PID: %d PPID: %d\n",getpid(),getppid());
        exit(0);
    }
    else{
        printf("Parent: PID: %d PPID: %d\n",getpid(),getppid());
        sleep(10);
    }
    return 0; 
}