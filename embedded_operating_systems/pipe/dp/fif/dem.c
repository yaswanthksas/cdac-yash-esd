#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>



int main(){
    pid_t id;
    int fd[2];
    //fd[0] - read 
    //fd[1] - write 
    id = fork();

    if(id == 0){    //child process write 
        // sleep(5);
        close(fd[0]); //close the read end 
        // fd[1] = open("")
        write(fd[1],"hello\n",6);
        close(fd[1]);
        // exit(0);
    }
    else{           //parent process read 
        close(fd[1]);
        char buf[10];
        read(fd[0],buf,10);
        printf("data is %s\n",buf);
        close(fd[0]);
    }
    


    return 0;
}