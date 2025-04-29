
#include <stdio.h>
#include <stdint.h> 


int addition(int a, int b)
{
    printf("Additiond : %d\n",a+b);
    return a + b;
}

int subtraction(int a, int b)
{
    printf("Subtractiond : %d\n",a-b);
    return a - b;
}


typedef struct operations_s 
{
    int (*add)(int,int);
    int (*sub)(int,int);
    int age;

}operations_t;

operations_t oper = {
    .add = addition,
    .sub = subtraction,
    .age = 22
};



#include <stdio.h>

int main()
{
//      operations_t oper; 
//      oper.add = addition;
//      oper.sub = subtraction;

    int a = 7, b = 3;

    printf("Addition: %d\n", oper.add(a, b));
    printf("Subtraction: %d\n", oper.sub(a, b));
    printf("Age : %d\n", oper.age);
    return 0;
}
