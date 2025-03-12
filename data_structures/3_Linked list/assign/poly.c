#include<stdio.h>
#include<stdlib.h>
struct node {
    int coeff;
    int power;
    struct node *next;
};
struct node* insert(int co,int po,struct node* head){
    struct node *temp, *curr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = co;
    temp->power = po;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    return head;
}
struct node* create(struct node *head){
    int n,i;
    int coeff;
    int power;
    printf("Enter number of terms\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter the coeffient of %d term ",i+1);
        scanf("%d",&coeff);

        printf("Enter the exponent of term %d : ",i+1);
        scanf("%d",&power);

        head = insert(coeff,power,head);
    }
    return head;
}
void print(struct node *head){
    if(head == NULL){
        printf("No polynomial");
    }
    else{
        struct node *temp;
        temp = head;
        while(temp != NULL){
            printf("%d x %d",temp->coeff,temp->power);
            temp = temp->next;
        }
    }
}
int main(){
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("enter first polynomial\n");
    


    return 0;
}