#include<stdio.h>
int* returnPointer(int a[]){
    a = a+2;
    return a;
}
int main(){
    int *p;
    int a[] = {1,2,3,4,5};
    p = returnPointer(a);
    printf("%d",*p);
    return 0;
}