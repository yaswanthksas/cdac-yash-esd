#include <unistd.h>
  #include <sys/types.h>
#include <stdio.h>
int main(){
    pid_t ven;
    printf("hello world\n");
    ven = fork();
    if(ven == 0){
        execl("/home/l1-pc22/Desktop/eos/class/exec/ya","",NULL);
    }
    else{
        printf("every thing is good\n");
    }
    return 0;
}
