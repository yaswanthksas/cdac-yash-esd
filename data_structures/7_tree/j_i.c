#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node * insert(struct node *root,int num){
    if(root == NULL){
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = num;
        temp->right = NULL;
        temp->left = NULL;
        root = temp;
    }
    else if(num <= root->data){
        root->left = insert(root->left,num);
    }
    else if(num > root->data){
        root->right = insert(root->right,num);
    }
    return root;
}
void traverse(struct node *root){
    struct node *curr;
    curr = root;
    if(root == NULL){
        return;
    }
        traverse(curr->left);
        printf("%d ",curr->data);
        traverse(curr->right);
    
}

int main(){
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    traverse(root);



    return 0;
}