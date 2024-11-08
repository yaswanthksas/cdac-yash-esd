#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *src,*dst;
    // size_t in,out;
    // char buf[10];
    char ch;
    src = fopen("a.txt","r");
    dst = fopen("d.txt","w");

    while((ch = fgetc(src)) != EOF){
        fputc(ch,dst);
    }
//what is fread 
// what is fwrite
// sir, why you make long process ???
    fclose(src);
    fclose(dst);
    return 0;
}