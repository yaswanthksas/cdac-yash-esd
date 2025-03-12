#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

struct node * insert(struct node *root,int num){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->right = NULL;
    temp->left = NULL;
    if(root == NULL){
        root = temp;
    }
    else if(num <= root->data){
        root->left = insert(root->left,num);
        // return root;
    }
    else if(num > root->data){
        root->right = insert(root->right,num);
    }
    return root;
}





struct node * delete(struct node *root,int num){
    if(num < root->data){
        root->left = delete(root->left,num);
        return root->left;
    }
    else if(num > root->data){
        root->right = delete(root->right,num);
        return root->right;
    }
    else if(num == root->data){
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
            return root;
        }
        else if(root->left != NULL && root->right == NULL){
            struct node *temp;
            temp = root->left;
            free(root);
            root = NULL;
            return temp;
        }

    }
    else if(root == NULL){
        return NULL;
    }

}






void traverse(struct node *root){
    struct node *curr;
    curr = root;
    if(root == NULL)
    {
        return;
    }
    traverse(curr->left);
    printf("%d ",root->data);
    traverse(curr->right);
}













int find_min(struct node *root){
    int i;
    if(root->left != NULL){
        i = find_min(root->left);
    }
    else{
        return root->data;
    }
}

int find_max(struct node *root){
    int i;
    if(root->right != NULL){
        i = find_max(root->right);
    }
    else{
        return root->data;
    }
}
int minimum(struct node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}






int main(){
    root = insert(root,20);
    root = insert(root,10);
    root = insert(root,5);
    traverse(root);
    int x;
    x = find_min(root);
    printf("\n%d",x);

    int max;
    max = find_max(root);
    printf("\n%d",max);

    int y;
    y = minimum(root);
    printf("\n%d",y);

    return 0;
}