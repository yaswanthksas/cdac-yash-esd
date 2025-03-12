#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[] = "{a+b-[d*e/g]}";
struct sn
{
    char *instring;
    int l;
    int tos;
};
struct sn s;
// char instring[20] = "{a+b-[d*e/g]}";
int isfull()
{
    if (s.tos == s.l - 1)
    {
        return 1;
    }
    return 0;
}
void push(char ch)
{
    if (!isfull())
    {
        s.tos++;
        s.instring[s.tos] = ch;
    }
    else
    {
        printf("stack is full");
    }
}
int isempty()
{
    if (s.tos == -1)
    {
        printf("Empty");
        return 1;
    }
    return 0;
}
int peep()
{
    char x;
    if (!isempty())
    {

        x = s.instring[s.tos];
    }
    else
    {
        printf("Stack is empty");
    }

    return x;
}
int pop()
{
    int x;
    if (!isempty())
    {
        x = s.instring[s.tos];
        s.tos--;
    }
    else
    {
        printf("Stack is empty");
    }
    return x;
}
void display()
{
    for (int i = 0; i <= s.tos; i++)
    {
        printf("%c", s.instring[i]);
    }
    printf("\n");
}
int main()
{
    int flag = 0;
    int n = strlen(str);
    printf("%d",n);
    s.instring = (char *)malloc(sizeof(char) * n);
    s.l = strlen(str);
    s.tos = -1;
    char ch, a;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];
        switch (ch)
        {
        case '[':
        case '{':
        case '(':
            push(ch);
            //printf("%c", ch);
            display();
            break;
        case ']':
        case '}':
        case ')':
            if (ch == ']' && peep() == '[')
            {
                a = pop();
                display();
                printf("\n");
            }
            else
            {
                flag = 1;
            }
            break;
        default:;
        }
        if (flag == 1)
        {
            break;
        }
    }
    printf("%d",i);
    isempty();
    if (i == n && (isempty()))
    {
        printf("Balanced");
    }
    else
    {
        printf("not balanced");
    }
    return 0;
}