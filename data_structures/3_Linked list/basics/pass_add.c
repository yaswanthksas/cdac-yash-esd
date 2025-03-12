#include<stdio.h>
struct point{
    int x;
    int y;
};
void print(struct point *p1){
    printf("%d%d",p1->x,p1->y);
}
int main(){
    struct point p1={2,3};
    struct point p2={4,5};
    print(&p1);
    print(&p2);

    return 0;
}