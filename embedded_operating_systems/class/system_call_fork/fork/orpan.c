#include<stdio.h>
#include <sys/types.h>
       #include <unistd.h>

int main(){
    pid_t id;
    printf("before fork \n");
    id = fork();
    if(id != 0){
        printf("parent pid : %d\n ppid : %d\n",getpid(),getppid());

    }
    else{
        sleep(10);
        printf("child pid: %d\n ppid: %d\n",getpid(),getppid());
    }



    return 0;
}