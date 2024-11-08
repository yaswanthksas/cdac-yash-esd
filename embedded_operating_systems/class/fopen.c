#include<stdio.h>
int main(){
    FILE *fp;
    fp = fopen("myfile.txt","w");
    if(fp == NULL){
        printf("file is empty");
    }
    char ch;
    printf("enter text\n");
    while((ch = getchar()) != EOF){
        fputc(ch,fp);
    }
    fclose(fp);
}