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
struct node * addp(struct node *p1,struct node *p2){

    struct node *ptr1,*ptr2,*ptr3;
    ptr1 = p1;
    ptr2 = p2;
    ptr3 = NULL;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->power > ptr2->power){
            ptr3 = insert(ptr3,ptr1->coeff,ptr1->power);
            ptr1 = ptr1->next;
        }
        else if(ptr1 -> power < ptr2->power){
            ptr3 = insert(ptr3,ptr2->coeff,ptr2->power);
            ptr2 = ptr2->next;
        }
        else{
            ptr3 = insert(ptr3,(ptr1->coeff + ptr2->coeff),ptr1->power);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    // if(p1 != NULL){
    //     res->next = p1;
    // }
    // if(p2 != NULL){
    //     res->next = p2;
    // }
    if(ptr1 != NULL){
        ptr3 = ptr1;
        //ptr1 = ptr1->next;
    }
    if(ptr2 != NULL){
        ptr3 = ptr2;
        //ptr2 = ptr2->next;
    }
    // while(ptr1 != NULL){
    //     ptr3 = ptr1;
    //     ptr1 = ptr1->next;
    // }
    // while(ptr2 != NULL){
    //     ptr3 = ptr2;
    //     ptr2 = ptr2->next;
    // }
    // return res->next;
    return ptr3;

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