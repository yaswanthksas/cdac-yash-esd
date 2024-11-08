#include<stdio.h>
  #include <sys/types.h>
  #include <unistd.h>

int main(){
    pid_t id;
    printf("before fork\n");
    id = fork();
    if(id == 0){
        printf("CHILD PID: %d PPID: %d\n",getpid(),getppid());
        exit(0);
    }
    else{
        sleep(10);
        printf("Parent: PID: %d PPID: %d\n",getpid(),getppid());
    }
    return 0;
}