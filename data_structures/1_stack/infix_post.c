#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    case '(':
    case '[':
    case '{':
        return 1;
    }
}
struct stack
{
    int *sta;
    int size;
    int tos;
};
// struct stack s;
struct stack ip;
int full()
{
    if (ip.tos == ip.size - 1)
    {
        return 1;
    }
    return 0;
}
int empty()
{
    if (ip.tos == -1)
    {
        return 1;
    }
    return 0;
}
void push(int num)
{
    if (!full())
    {
        ip.tos++;
        ip.sta[ip.tos] = num;
    }
    else
    {
        printf("Stack is full\n");
    }
}
int pop()
{
    int x = -11;
    if (!empty())
    {
        x = ip.sta[ip.tos];
        ip.tos--;
    }
    else
    {
        printf("Stack is empty\n");
    }
    return x;
}
int peep()
{
    int x = -11;
    if (!empty())
    {
        x = ip.sta[ip.tos];
    }
    else
    {
        printf("Stack is empty\n");
    }
    return x;
}
char ins[] = "{a+b*c/f-[d*e/g]}";
int main()
{
    char *op;
    int j = 0;
    ip.tos=-1;
    int l = strlen(ins);
    printf("%d", l);
    ip.size = l;
    op = (char *)malloc(sizeof(char) * l);
    ip.sta = (int *)malloc(sizeof(int) * l);
    for (int i = 0; ins[i]!='\0'; i++)
    {
        char ch = ins[i];
        switch (ch)
        {
        case '[':
        case '{':
        case '(':
            push(ch);
            break;
        case ']':
        case '}':
        case ')':
            while (!((peep() == '[') || (peep() == '(') || (peep() == '{')))
            {
                op[j] = pop();
                j++;
            }
            int x;
            x = pop();
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (!empty() && prec(ch) <= prec(peep()))
            {
                op[j] = pop();
                j++;
            }
            push(ch);
            break;
        default:
            op[j] = ch;
            j++;
            break;
        }
    }
    op[j] = '\0';
    printf("%s", op);
    return 0;
}