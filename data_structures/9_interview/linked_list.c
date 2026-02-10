#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next; 
}; 
struct node *start; 

void insert_begin(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp -> data = data; 
    temp -> next = NULL; 
    if(start != NULL)
    {
        temp->next = start; 
        start = temp; 
    }
    if(start == NULL){
        start = temp;
    }
}

void insert_end(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL; 

    struct node *curr = start; 
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp; 
}

void display(){
    struct node *curr = start;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next; 
    }
    printf("\n");
}

void insert_after(int num, int ele)
{
    if(start != NULL){
        struct node *curr = start; 
        while(curr != NULL && curr->data != num){
            curr = curr->next; 
        }
        if(curr != NULL){
            struct node *temp = (struct node *)malloc(sizeof(struct node)); 
            temp->data = ele;
            temp->next = curr->next; 
            curr->next = temp; 
        }
        else{
            printf("Element not found\n");
        }

    }
    else{
        printf("List is empty"); 
    }

}

void insert_before(int num,int ele){
    if(start !=NULL){
        struct node *curr = start; 
        while(curr->next != NULL && curr->next->data != num){
            curr = curr->next; 
        }
        if(curr->next != NULL){
            struct node *temp = (struct node *)malloc(sizeof(struct node)); 
            temp->data = ele;
            temp->next = curr->next;
            curr->next = temp;
        }
        else{
            printf("Element not found \n");  
        }

    }
    else{
        printf("List is empty\n");
    }
}

int del_first()
{
    int x = -999;
    if(start != NULL){
        struct node *temp; 
        temp = start; 
        int x; 
        x = temp->data; 
        start = temp->next; 
        free(temp); 
        return x;
    }
    else{
        printf("List is empty\n"); 
    }
    return x;
}

int del_end(){
    int x = -999;
    if(start != NULL){
        struct node *temp,*curr; 
        curr = start; 
        while(curr->next->next != NULL){
            curr = curr->next; 
        }
        int x; 
        x = curr->next->data;
        free(curr->next);
        curr->next = NULL;
        return x;
    }
    else{
        printf("List is empty\n"); 
    }
    return x;
}

void delete_spec(int data)
{
    if(start != NULL){
        struct node *curr = start; 
        while(curr->next != NULL && curr->next->data != data){
            curr = curr->next; 
        }
        if(curr->next != NULL){
            struct node *temp; 
            temp = curr->next; 
            curr->next = temp->next; 
            free(temp);
        }
        else{
            printf("Element not found\n");
        }


    }
    else{
        printf("List is empty\n");
    }
}

void reverse()
{

    struct node *prev= NULL, *curr=start, *next = NULL; 

    while(curr != NULL){
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next;

    }

    start = prev;

}

struct node* middle_node(struct node *head)
{
    struct node *slow = start; 
    struct node *fast = start; 

    while(fast != NULL && fast->next != NULL){
        slow = slow ->next; 
        fast = fast -> next ->next;  
    }
    return slow;
}

struct node *nthfromend(struct node *start,int n)
{
    struct node *slow = start; 
    struct node *fast = start; 

    for(int i=0; i<n; i++){
        if(fast == NULL){
            return NULL;                 // if nodes < 3 or < n , then return NULL
        }                                 
        fast = fast -> next; 
    }
    while(fast != NULL)
    {
        slow = slow -> next; 
        fast = fast -> next; 
    }
    return slow;
}

int detect_loop(struct node *start)
{
    struct node *slow= start, *fast = start; 

    while(fast !=NULL && fast->next != NULL){
        slow = slow->next; 
        fast = fast->next->next;

        if(fast == slow){
            return 1; 
        }

    }

    return 0;

}

struct node * startofloop(struct node *start)
{
    struct node *slow= start, *fast = start; 

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow ->next;
        fast = fast ->next->next; 

        if(slow == fast)
        {
            break;
        }
    }

    if(fast == NULL || fast->next == NULL){
        return NULL;
    }

    slow = start; 
    if(slow != fast){
        slow = slow->next; 
        fast = fast -> next;
    }

    return slow;

}

void remove_duplicates_unsorted(struct node *start)
{

    struct node *curr = start; 

    while(curr != NULL)
    {
        struct node *runner = curr; 

        while(runner->next != NULL)
        {

            if(runner->next->data == curr->data){
                struct node *temp = runner->next; 
                runner->next = temp->next; 
                free(temp);
            }
            else{
                runner = runner->next; 
            }

        }
        curr = curr->next;
    }
}

// void remove_other_duplicates(struct node *start)
// {
//     struct node *curr = start; 

//     while(curr != NULL){
//         struct node * runner = curr->next; 

//         while(runner != NULL){
//             if(curr->data == runner->data){
//                 struct node *temp = runner->next;
//                 runner->next = temp->next; 
//                 free(temp);
//             }
//             else{
//                 runner= runner->next;
//             }
//         }
//         curr = curr->next;


//     }


// }

int main()
{
    insert_begin(20);
    insert_begin(30);
    insert_begin(40);
    display();
    insert_end(10);
    display(); 
    insert_after(10,5);
    display();
    insert_end(60);
    insert_end(70);
    display();
    insert_before(70, 102);
    display(); 

    printf("removed value at first :%d \n",del_first());
    printf("removed value at last : %d\n", del_end()); 
    display();

    delete_spec(102);

    display();

    reverse();
    display();

    struct node *mid;
    mid = middle_node(start);
    printf("middle node : %d\n", mid->data);


    struct node *n_f_end = nthfromend(start,3);
    printf("last nth from end : %d\n",n_f_end->data);

    if(detect_loop(start))
    {
        printf("Loop detected \n");
    }
    else
    {
        printf("loop not detected \n");
    }

    struct node *loop_start = startofloop(start);
    if(loop_start){
        printf("loop is there %d\n", loop_start->data);
    }
    else{
        printf("loop is not there\n");
    }

    insert_end(42);
    insert_end(43);
    insert_end(43);
    insert_end(42);
    insert_end(44);
    insert_end(60);

    display();
    

    remove_duplicates_unsorted(start);
    // remove_other_duplicates(start);

    display();

    // sort_ll(start);

    return 0; 
}