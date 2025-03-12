#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stac{
    int *c;
    int size;
    int tos;
};
struct stac s;
char str[] = "{a+b-[d*e/g]}";

int isfull(){
    if(s.tos == s.size-1){
        return 1;
    }
    return 0;
}
void push(int ch){
    if(!isfull()){
        s.tos++;
        s.c[s.tos] = ch;
    }
    else{
        printf("Stack is full\n");
    }
}
int isempty(){
    if(s.tos == -1){
        return 1;
    }
    return 0;
}
int pop(){
    int x;
    if(!isempty()){
        x = s.c[s.tos];
        s.tos--;
    }
    else{
        printf("Stack is empty\n");
    }
    return x;
}
int peep(){
    int x;
    if(!isempty()){
        x = s.c[s.tos];
    }
    else{
        printf("Stack is empty\n");
    }
    return x;
}
int main(){
    int l;
    int x;
    l = strlen(str);
   s.size = l;
    s.c =(int *) malloc(sizeof(int)*l);
    s.tos = -1;
    int i,flag = 0;
    char ch;
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
                if((ch == '}' && peep() == '{') || (ch == ']' && peep() == '[') || (ch == ')' && peep() == '(')){
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
    if((i == l) && isempty()){
        printf("Balanced\n");
    } 
    else{
        printf("Not balanced");
    }


    return 0;
}