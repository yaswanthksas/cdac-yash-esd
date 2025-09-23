#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* start = NULL;

void insertb(int val){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if(start == NULL){
        start = temp;
    }
    else if(start != NULL){
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
}

void inserte(int val){
    struct node *temp = (struct node*)malloc(sizeof(struct node)); 
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if(start == NULL){
        start = temp;
    }
    else{
        struct node *curr = start;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp; 
        temp->prev = curr;
    }

}

void insert_after(int sele,int val){
    if(start != NULL){
        struct node *curr = start;
        while(curr != NULL && curr->data != sele){
            curr = curr->next; 
        }
        if(curr->data == sele){
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp->data = val;
            temp->next = curr->next;
            temp->prev = curr;
            if(curr->next != NULL){
                curr->next->prev = temp;
            }
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

void insert_before(int sele, int val){
    if(start != NULL){
        struct node *curr = start; 
        while(curr != NULL && curr->data != sele){
            curr = curr->next;
        }
        if(curr->data == sele){
            struct node *temp = (struct node *)malloc(sizeof(struct node ));
            temp->data = val;
            temp->next = curr;
            temp->prev = curr->prev;
            curr->prev->next = temp;
            curr->prev = temp;
        }
        else{
            printf("Element not found\n");
        }

    }
    else{
        printf("List is empty\n");
    }
}

int del_beg(){
    if(start != NULL){
        struct node *temp = start;
        int val = temp->data;    // store data to return
        start = start->next;     // move start to next node
        start->prev = NULL;    // set prev of new start to NULL
        free(temp);              // free memory of old start
        return val;              // return deleted value

    }
    else{
        printf("List is empty\n");
        return -999;
    }
}

int del_end(){
    if(start != NULL){
        struct node *curr = start; 
        while(curr->next != NULL){
            curr = curr->next;
        }
        int x = curr->data; // store data to return
        curr->prev->next = NULL; // set next of previous node to NULL
        free(curr); // free memory of last node
        return x; // return deleted value

    }
    else{
        printf("List is empty\n");
        return -999;
    }
}

void del_specific(int sele){
    if(start != NULL)
    {
        struct node *curr = start; 
        while(curr != NULL && curr->data != sele){
            curr = curr->next;
        }
        if(curr->data == sele){
            curr->prev->next = curr->next;  // set next of previous node to next of current node
            curr->next->prev = curr->prev;  // set prev of next node to prev of current node
            free(curr);
        }
        else{
            printf("Element not found\n");
        }

    }
    else{
        printf("List is empty\n");
        
    }

}


void travel_backward(){
    if(start != NULL){
        struct node *curr = start; 
        while(curr->next != NULL){
            curr = curr->next;
        }
        while(curr != NULL){
            printf("%d ", curr->data);
            curr = curr->prev;
        }
        printf("\n");
    }
    else{
        printf("List is empty\n");
    }



}


void display(){
    struct node *curr = start;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


int main(){
    insertb(20);
    insertb(30);
    display();

    inserte(40);
    inserte(50);
    display();

    insert_after(40,45);
    display();

    insert_before(40,39);
    display();


    int x; 
    x = del_beg();
    printf("Deleted start element is %d\n", x);
    display();

    int y; 
    y = del_end();
    printf("Deleted end element is %d\n", y);
    display();

    del_specific(40);
    display();

    travel_backward();
    display();


    return 0;
}