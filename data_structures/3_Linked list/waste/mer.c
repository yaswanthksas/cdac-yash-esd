// doubt doubt doubt

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data; // doubt;;;
    struct node *next;
};
struct node *p1, *p2;
struct node *p3;
struct node *insert(struct node *p1, int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
    if (p1 == NULL)
    {
        p1 = temp;
    }
    else
    {
        struct node *curr;
        curr = p1;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = NULL;
    }
    return p1;
}
void display(struct node *p1)
{
    struct node *curr;
    curr = p1;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
struct node *merge(struct node *p1, struct node *p2)
{
    struct node *h3;
    h3 = NULL;
    if (p1 == NULL)
    {
        return p2;
    }
    if (p2 == NULL)
    {
        return p1;
    }
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            h3 = insert(h3, p1->data);
           // display(h3);
            //printf("\n");
            p1 = p1->next;
            // printf("%d\n",h3->data);
        }
        else
        {
            h3 = insert(h3, p2->data);
            //display(h3);
            //printf("\n");
            p2 = p2->next;
        }
        // h3 = h3->next;
    }
    //if (p2 == NULL)
    //{
        while (p1 != NULL)
        {
            h3 = insert(h3, p1->data);
           // h3->next = p1;
            p1 = p1->next;
        }
   // }
    //else if (p1 == NULL)
    //{
        while (p2 != NULL)
        {
            h3 = insert(h3, p2->data);
            p2 = p2->next;
        }
  //  }
//  if(p1 != NULL){
//         h3->next = p1;
//     }


//     if(p2 != NULL){
//         h3->next = p2;
//     }

    return h3;
    //return h3;
}

int main()
{
    p1 = insert(p1, 20);
    p1 = insert(p1, 40);
    p1 = insert(p1, 60);
    display(p1);

    p2 = insert(p2, 10);
    p2 = insert(p2, 30);
    p2 = insert(p2, 50);
    display(p2);

    p3 = merge(p1, p2);
    display(p3);

    return 0;
}