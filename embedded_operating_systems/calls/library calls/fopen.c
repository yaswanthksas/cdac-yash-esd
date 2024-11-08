#include<stdio.h>  // file operations are there in stdio.h file

int main(){
    FILE *fp;
    fp = fopen("sample.txt","w+");
    printf("enter text:\n");
    char ch;
    while((ch = getchar()) != EOF){
        fputc(ch,fp);   //ctrl +shift + d = save 
    }
    //for reading the file 
    while((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }

    fclose(fp);
    return 0;
}