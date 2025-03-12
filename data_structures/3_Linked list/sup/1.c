#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;

void append(){
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    printf("Enter node data");
    scanf("%d",&temp->data);
    //temp->next = NULL;
    if(start == NULL){
        start = temp;
    }
    else{
        struct node *p;
        p = start;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}
int length(){
    struct node *temp;
    int count=0;
    temp = start;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}
void insert_begin(int num){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
    if(start == NULL){
        start = temp;
    }
    else{
        temp->next = start;
        start = temp;
    }
}
void insert_end(int num){
    struct node *temp,*curr;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
}
void insert_after(int num,int ele){
    struct node *temp,*curr;
    if(start != NULL){
        curr = start;
        while(curr != NULL && curr->data != ele){
            curr = curr->next;
        }
        if(curr != NULL){
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = ele;
            temp->next = curr->next;
            curr->next = temp;
        }
        else{
            printf("Element not found\n");
        }
    }
    else{
        printf("list is empty\n");
    }
}
void insert_before(int num,int ele){
    struct node *temp,*curr;
    if(start != NULL){
        curr = start;
        if(curr->data == ele){
            temp = (struct node *) malloc(sizeof(struct node));
            temp->data = num;
            temp->next = start;
            start = temp;
        }
        while(curr->next != NULL && curr->next->data != ele){
            curr = curr->next;
        }
        if(curr->next != NULL){
            temp = (struct node *) malloc(sizeof(struct node));
            temp->data = num;
            temp->next = curr->next;
            curr->next = temp;
        }
        else{
            printf("Element not found\n");
        }
    }
    else{
        printf("List is empty\n");
    }
}
int del_first(){
    struct node *temp;
    if(start !=NULL){
        temp = start;
        int x;
        x = temp->data;
        start = start->next;
        free(temp);
    }
    else{
        printf("list is empty");
    }
}
int del_last(){
    struct node *temp,*curr;
    if(start != NULL){
        curr = start;
        int x;
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        x = curr->next->data;
        free(curr->next);
        curr->next = NULL;
    }
    else{
        printf("list is empty");
    }
}
int del_spe(int num){
    struct node *curr,*temp;
    if(start != NULL){
        curr = start;
        while(curr->next != NULL && curr->next->data != num){
            curr = curr->next;
        }
        if(curr->next != NULL){
        //     int x;
        //     x = curr->next->data;
            temp=curr->next;
            curr->next = temp->next;
            free(temp);
        }
    }
    else{
        printf("list is empty");
    }
}
void display(){
    struct node *temp;
    temp = start;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
void backward(struct node *curr){
    if(curr == NULL){
        return;
    }
    backward(curr->next);
    printf("%d",curr->data);
}
void travel_backward(){
    if(start != NULL){
        backward(start);
    }
    else{
        printf("List is empty");
    }
}
void reverse(){
    struct node *rev=NULL,*temp;
    while(start != NULL){

    temp = start;
    start = temp->next;
    temp->next = rev;
    rev = temp;

    }
    start = rev;

}
int main(){
    append();
    append();
    append();
    append();
    travel_backward();
    display();
    reverse();
    display();

    return 0;
}