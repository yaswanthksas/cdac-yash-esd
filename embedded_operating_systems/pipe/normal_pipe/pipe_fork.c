#include<stdio.h>
 #include <unistd.h>

 int main(){
    int fd[2];
    int pip;
    pip = pipe(fd);
    char str[10];
    int id;
    id = fork();
    if (id == 0){
        //child process 
        //read 
        char buf[10];
        close(fd[1]);
    // while(read(fd[0],buf,1) > 0){
        //     printf("%c",buf);
        // }    
        read(fd[0],buf,sizeof(buf));
        printf("%s",buf);
        write(STDERR_FILENO,"\n",1);
        close(fd[0]);
    }
    else if(id>0){
        // parent process - write 
        // sleep(5);
        close(fd[0]); //read end close 
        printf("Enter name: \n");
        scanf("%s",str);
        write(fd[1],str,sizeof(str));
        close(fd[1]);
        // sleep(5);
    }


 }