  #include <sys/types.h>
       #include <unistd.h>
#include<stdio.h>
int main(){
    pid_t id;
    printf("Before fork\n");
    printf("pid: %d ppid: %d\n",getpid(),getppid());
    printf("\n--------------\n");
    id = fork();
    if(id == 0){
        sleep(10);
        printf("child pid: %d ppid: %d",getpid(),getppid());
    }
    else if(id != 0){
        printf("parent pid: %d ppid: %d",getpid(),getppid());

    }



    return 0;
}