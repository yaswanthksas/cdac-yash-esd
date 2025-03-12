#include <stdio.h>
#include<stdlib.h>
struct stac
{
    int *a;
    int n;
    int tos;
};
struct stac s;
int isempty()
{
    if (s.tos == -1)
    {
        return 1;
    }
    return 0;
}
int isfull()
{
    if (s.tos == s.n - 1)
    {
        return 1;
    }
    return 0;
}
void push(int n)
{
    if (!isfull())
    {
        s.tos++;
        s.a[s.tos] = n;
    }
    else
    {
        printf("stack is full\n");
    }
}
int pop()
{
    int x = -999;
    if (!isempty())
    {
        x = s.a[s.tos];
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
        printf("%d", s.a[i]);
    }
}
int main()
{   
    printf("enter the size of arry\n");
    scanf("%d", &s.n);
    s.a = (int *)malloc(sizeof(int) * s.n);
    s.tos = -1;
    int ch;
        printf("enter 1 to push the element \n");
        printf("enter 2 to pop the element \n");
        printf("enter 0 exit \n");
        printf("enter 3 to display the element \n");
        scanf("%d", &ch);
        int num, n;
        switch (ch)
        {
        case 1:

            printf("Enter an element to push");
            scanf(" %d", &num);
            push(num);
            break;
        case 2:
            n = pop();
            if (n >= 0)
            {
                printf("Last Element deleted");
            }
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);
            //break;
           // break;
        default:
            printf("enter other number");
            break;
        }
    

    return 0;
}