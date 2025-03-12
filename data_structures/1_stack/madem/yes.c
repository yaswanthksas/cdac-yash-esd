#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"yah.h"
struct stack{
    char *c;
    int size;
    int tos;
};
struct stack s;

int main(){
    char str[] = "{a+b-[d*e/g]}";
    int l = strlen(str);
    s.c = (char *) malloc(sizeof(int) * l);
    s.size = l;
    s.tos = -1;
    char ch;
    char x;
    int flag =0,i;
    for(i =0;i<l;i++){
        switch(ch){
        case '{':
        case '[':
        case '(':
            push(ch);
            break;
        case '}':
        case ']':
        case ')':
            if((ch == '}' && peep() == '{') && (ch == ')' && peep() == '(') ){
                x = pop();
            }
            else{
                flag = 1;
                break;
            }
        default:
            ;
     }
     if(flag == 1){
        break;
     }
    }
    if(i == l && isempty()){
        printf("Balanced");
    }
    else{
        printf("not balanced");
    }
    


    return 0;
}