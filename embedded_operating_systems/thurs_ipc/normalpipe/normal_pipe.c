#include <unistd.h>
#include<stdio.h>

int main(){
    int fd[2];
   int x;
   x = pipe(fd);
    //fd[0] = read
    //fd[1] = write 
    int id;
    id = fork();
    if(id == 0){
        //child process - reading
        char buf[5];
        close(fd[1]);
        // open missing 
        read(fd[0],buf,sizeof(buf));
        printf("%s",buf);
        close(fd[0]);
    }
    else{
        //parent process - writing 
        close(fd[0]);
        // open missing
        write(fd[1],"yash",4);
        close(fd[1]);

    }


    return 0;
}