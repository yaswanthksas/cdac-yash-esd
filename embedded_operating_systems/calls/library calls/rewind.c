#include<stdio.h>
int main(){
    FILE *fp;
    fp = fopen("sample.txt","r");
    if(fp == NULL){
        printf("file not open\n");
    }
    char ch;
    while((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }
    rewind(fp);
    while((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }
    fclose(fp);
    return 0;
}