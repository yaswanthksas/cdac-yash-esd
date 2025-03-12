#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node *insert(struct node *root, int data)
{
    struct node *temp;
    if (root == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void traverse(struct node *root)
{
    struct node *temp;
    temp = root;
    if (temp != NULL)
    {
        if (temp == NULL)
        {
            return;
        }
        traverse(temp->left);
        printf("%d ", temp->data);
        traverse(temp->right);
    }
}
int main()
{  
    root = insert(root, 15);
    root = insert(root, 8);
    root = insert(root, 6);
    root = insert(root, 10);
    root = insert(root, 7);
    // root = insert(root, 17);
    traverse(root);

    return 0;
}