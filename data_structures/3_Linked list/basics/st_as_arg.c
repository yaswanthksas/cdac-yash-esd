#include<stdio.h>
struct point{
    int x;
    int y;
};
void display(struct point p){
    printf("%d %d",p.x,p.y);
}
int main(){
    struct point p1 = {2,3};
    struct point p2 = {4,5};         // structure variable as argument;
    display(p1);
    display(p2);

    return 0;
}