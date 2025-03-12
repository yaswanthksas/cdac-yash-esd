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
        case '}':
        case '(':
        case ')':
        case '[':
        case ']':
            return 1;
    }
}
// struct stack{
//     int *a;
//     int size;
//     int tos;
// };
char *op;
// struct stack s;
char a[] = "{a+b*c/f-[d*e/g]}";
int main(){
    int l,i;
    char ch;
    l = strlen(a);
    
    s.c = (char *)malloc(sizeof(char)*l);
    op = (char *)malloc(sizeof(char)*l);
    s.tos = -1;
    s.size = l;
    int j=0;
    char st;
    for(i=0;i<l;i++){
        ch = a[i];
        switch(ch){
            case '{':
            case '[':
            case '(':
                push(ch);
                break;
            case '}':
            case ']':
            case ')':
                while( !(peep()== '{' || peep()== '(' || peep()== '[')){
                    op[j] = pop();
                    j++;
                }
                st = pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while(!isempty() && prec(ch) <= prec(peep())){
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