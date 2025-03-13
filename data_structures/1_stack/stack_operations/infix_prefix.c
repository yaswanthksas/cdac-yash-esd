#include<stdio.h>
#include"dec.h"
#include<stdlib.h>
#include<string.h>

extern struct stack s;

int prec(char ch)
{
    switch (ch)
    {
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    case '}':
    case ')':
    case ']':
        return 1;
    }
}
// struct stac
// {
//     char *c;
//     int size;
//     int tos;
// };
// struct stac sl;
char str[] = "{a+b*c/f-[d*e/g]}";
char *op;
int main(){
    int l = strlen(str);
    s.c = (char *) malloc(sizeof(char)*l);
    op = (char *) malloc(sizeof(char)*l);
    s.size = l;
    s.tos = -1;
    int i,j=0;
    char ch,x;
    for(i=l-1;i>=0;i--){
        ch = str[i];
        switch (ch)
        {
        case '}':
        case ']':
        case ')':
            push(ch);
            break;
        case '{':
        case '[':
        case '(':
            while(!(peep()=='}' || peep()==')' || peep()==']')){
                op[j] = pop();
                j++;
            }
            x = pop();
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        while(!isempty() && prec(ch)<prec(peep())){
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
    printf("%s\n",op);
    int z;
    z = strlen(op);
    for(int i=z-1;i>=0;i--){
        printf("%c",op[i]);
    }
    return 0;


}