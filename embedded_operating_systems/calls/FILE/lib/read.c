#include<stdio.h>

int main(){
    FILE *fp;
    fp = fopen("a.txt","r");
    char ch;
    while((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }


    fclose(fp);
    return 0;
}