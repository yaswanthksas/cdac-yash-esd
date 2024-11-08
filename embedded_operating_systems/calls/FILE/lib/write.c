#include<stdio.h>
int main(){
    FILE *fp;
    fp = fopen("a.txt","w");


    char ch;
    while((ch = getchar()) != EOF){
        fputc(ch,fp);
    }


    fclose(fp);

    return 0;
}