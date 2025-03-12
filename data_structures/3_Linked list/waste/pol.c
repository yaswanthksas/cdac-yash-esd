#include<stdio.h>
#include<stdlib.h>
struct node {
    int coeff;
    int power;
    struct node *next;
};
struct node *p1,*p2;
struct node * insert(struct node *p1,int co,int po){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = co;
    temp->power = po;
    temp->next = NULL;
    if(p1 == NULL){
        p1 = temp;
    }
    else{
        struct node *curr;
        curr = p1;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = NULL;
    }
    return p1;
}
void display(struct node *p1){
    struct node *curr;
    curr = p1;
    while(curr != NULL){
        printf("%dx%d  ",curr->coeff,curr->power);
        curr=curr->next;
    }
    printf("\n\n");
}
struct node* addpoly(struct node *p1,struct node *p2){

    struct node *h1;
    struct node *h2;
    struct node *h3;
    h1 = p1;
    h2 = p2;
    h3 = NULL;
    while(h1 != NULL && h2 != NULL){
        if(h1->power > h1->power){
            h3 = insert(h3,h1->coeff,h1->power);
            h1 = h1->next;
        }
        else if(h1->power < h2->power){
            h3 = insert(h3,h2->coeff,h2->power);
            h2 = h2->next;
        }
        else{
            h3 = insert(h3,(h1->coeff+h2->coeff),h1->power);
            h1 = h1->next;
            h2 = h2->next;
        }
    }

    if(h1 != NULL){
        h3->next = h1;
    }


    if(h2 != NULL){
        h3->next = h2;
    }

    return h3;



}
int main(){
    // insert(p1,5,2);
    // display(p1);
    // insert(p1,6,1);
    // display(p1);
    // insert(p1,5,0);
    // display(p1);
    p1 = insert(p1,5,2);
    p1 = insert(p1,6,1);
    p1 = insert(p1,5,0);
    display(p1);

    p2 = insert(p2,2,2);
    p2 = insert(p2,8,1);
    p2 = insert(p2,9,0);
    display(p2);

    struct node *sum;
    sum = addpoly(p1,p2);
    // printf("%d",sum);

display(sum);
    return 0;
}