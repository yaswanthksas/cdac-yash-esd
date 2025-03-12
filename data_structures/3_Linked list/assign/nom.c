#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int power;
    struct node *next;
};
struct node *p1,*p2;

struct node * insert(struct node *p1,int co,int po){
    
    struct node *temp,*curr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = co;
    temp->power = po;
    temp->next = NULL;
    if(p1 == NULL){
        p1 = temp;
    }
    else{
        curr = p1;
        while(curr->next != NULL){
            curr= curr->next;
        }
        curr->next = temp;
    }
    return p1;
}
struct node * adding(struct node *p1,struct node *p2){
    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->coeff = p1->coeff + p2->coeff;
    temp->power = p1->power;
    //temp->next = NULL;
    
    return temp;
    
}
struct node * addp(struct node *p1,struct node *p2){

    struct node *res;
    res = (struct node *)malloc(sizeof(struct node));

    while(p1!= NULL && p2 != NULL){
        if(p1->power > p2->power){
            res->next = p1;
            p1 = p1->next;
        }
        else if(p1->power < p2->power){
            res->next = p2;
            p2 = p2->next;
        }
        else{
            // res->next = p1->coeff + p2->coeff;
            struct node *temp;
            temp = adding(p1,p2);
            res->next = temp;
            p1 = p1->next;
            p2 = p2->next;
        }
        res = res->next;
    }
    // if(p1 != NULL){
    //     res->next = p1;
    // }
    // if(p2 != NULL){
    //     res->next = p2;
    // }
    while(p1 != NULL){
        res->next = p1;
        p1 = p1->next;
    }
    while(p2 != NULL){
        res->next = p2;
        p2 = p2->next;
    }
    return res->next;

}
void display(struct node *p1){
    struct node *curr;
    curr = p1;
    while(curr != NULL){
        printf("%dx%d  ",curr->coeff,curr->power);
        curr = curr->next;
    }
    printf("\n");
}
int main(){
    p1 = insert(p1,5,2);
    // display(p1);

    p1 = insert(p1,4,1);

    p1 = insert(p1,2,0);
    display(p1);
    printf("\n\n");

    
    p2 = insert(p2,6,2);
    // display(p1);

    p2 = insert(p2,5,1);

    p2 = insert(p2,5,0);
    display(p2);
    printf("\n\n");


    struct node *sum;
    sum = addp(p1,p2);
    display(sum);

    return 0;
}