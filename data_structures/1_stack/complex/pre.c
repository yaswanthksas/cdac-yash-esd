#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dec.h"
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

    case ')':
    case '}':
    case ']':
        return 1;
    }
}
struct stac
{
    char *c;
    int size;
    int tos;
};
struct stac s;
char str[] = "{a+b*c/f-[d*e/g]}";
char *op;
int main()
{
    int l = strlen(str);
    s.c = (char *)malloc(sizeof(char) * l); // stack
    op = (char *)malloc(sizeof(char) * l);  // output
    s.size = l;
    s.tos = -1;
    char ch, st;
    int i, j = 0;
    for (i = l - 1; i >= 0; i--)
    {
        ch = str[i];
        switch (ch)
        {
        case ')':
        case '}':
        case ']':
            push(ch);
            break;
        case '(':
        case '{':
        case '[':
            while (!(peep() == ')' || peep() == '}' || peep() == ']'))
            {
                op[j] = pop();
                j++;
            }
            st = pop();
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (!isempty() && (prec(ch) < prec(peep())))
            {
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
   // printf("%s", op);
    int z=0;
    int m = strlen(op);
    for(z = m-1;z>=0;z--){
        printf("%c",op[z]);
    }
    return 0;
}