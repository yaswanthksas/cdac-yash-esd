#include<stdio.h>
int main(){
    FILE *fp;
    fp = fopen("sample.txt","r");
    char ch;
    printf("file contents are\n");
    while((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }

    fclose(fp);
    return 0;
}
