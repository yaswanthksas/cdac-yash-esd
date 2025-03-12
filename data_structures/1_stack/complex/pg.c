#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"dec.h"
int prec(char ch){
    switch(ch){
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        case '{':
        case '[':
            return 1;

    }
}
char str[20];
// struct stak{
//     char *c;
//     int size;
//     int tos;
// };
// struct stak s;
int main(){
    scanf("%s",str);
    char *op;
    int l;
    l = strlen(str);
    s.c = (char *) malloc(sizeof(char)*l);
    op = (char *)malloc(sizeof(char)*l);
    s.tos = -1;
    s.size = l;
    int i,j=0;
    char ch,sta;
    for(i=0;i<l;i++){
        ch = str[i];
        switch(ch){
            case '{':
            case '[':
            case '(':
                push(ch);
                break;
            case '}':
            case ']':
            case ')':
                while( !(peep()== '{' || peep() == '[' || peep() == '(')){
                    op[j] = pop();
                    j++;
                }
                sta = pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while(!isempty() && prec(ch)<= prec(peep())){
                        op[j] = pop();
                        j++;
                }
                push(ch);
                break;
            default:
                op[j] = ch;
                j++;
        }
    }
    op[j] = '\0';
    printf("%s",op);



    return 0;
}