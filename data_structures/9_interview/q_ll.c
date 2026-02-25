#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}; 

struct node *front = NULL;
struct node *rear = NULL; 

void enqueue(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp->data = data;
    temp->next = NULL; 

    if(rear==NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp; 
        rear = temp;
    }
}

void dequeue(){
    if(front == NULL){
        printf("queue underflow\n"); 
    }

    struct node *temp = front; 
    printf("deleted : %d\n", temp->data); 

    front = front->next; 

    if(front == NULL){
        rear = NULL;
    }
    free(temp); 
}

void display(){
    struct node *temp = front; 

    printf("Queue elements : \n"); 
    while(temp != NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){

    enqueue(10);
    enqueue(20); 
    display(); 
    dequeue();
    display();


    

    return 0; 
}