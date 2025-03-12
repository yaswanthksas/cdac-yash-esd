#include<stdio.h>
#include<stdlib.h>
struct stck{
    int size;   // its size
    int *a;      // an array
    int tos;     // top of stack 
};
struct stck s;

void push(int ele);
int pop();
void display();
int isempty();
int isfull();

int main()
{
    
    printf("Enter size \n");
    scanf("%d",&s.size);
    s.a = (int *)malloc(sizeof(int)*s.size);
    s.tos = -1;
    // for(int i=0;i<s.size;i++){
    //     scanf("%d",&s.a[i]);
    // }
   //display();
push(26);
push(35);
push(46);
push(89);
display();
// display();
printf("\n");
pop();
pop();
display();
free(s.a);
    return 0;
}

void push(int ele){
    //full ga lekunte push cheyali 
    if(!(isfull())){
        s.tos++;
        s.a[s.tos] = ele;

    }
    else{
        printf("Stack is full");
    }
}

int pop(){
    int x;
    if(!isempty()){
        x = s.a[s.tos];
        s.tos--;
    }
    else{
        printf("stack is empty");
    }
    return x;
}
void display(){
 for(int i=0;i<=s.tos;i++){
        printf("%d",s.a[i]);
        printf("\n");   
    }

}
int isempty(){
    if(s.tos == -1){
        return 1;
    }
    return 0;
}
int isfull(){
    if(s.tos == s.size-1){
        return 1;
    }
    return 0;
}