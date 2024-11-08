#include<stdio.h>
int sum(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int main(){
    int a=5,b=6;
    printf("sum: %d\n",sum(a,b));
    printf("sub: %d\n",sub(a,b));
    return 0;
}