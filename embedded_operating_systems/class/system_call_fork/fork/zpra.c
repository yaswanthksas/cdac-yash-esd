#include<stdio.h>
 #include <sys/types.h>
       #include <unistd.h>
#include<stdlib.h>
int main(){
    pid_t id;
    printf("Before fork");
    printf("pid : %d\n",getpid());
    printf("ppid : %d\n",getppid());
    id = fork();
    if(id == 0){
        printf("child pid: %d ppid: %d",getpid(),getppid());
        exit(0);
    }
    else if(id != 0){
        sleep(10);
        printf("parent pid: %d ppid: %d",getpid(),getppid());
    }

    return 0;
}