#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
};

void displaystack(struct node *head) 
{
    if(head == NULL)
    {
        printf("This list doesn't exist!\n"); // Edge case
    }

    else
    {
        struct node *temp;
        for(temp = head; temp != NULL; temp = temp->next) 
        {
            printf("%d <-- ", temp->data); //Changing direction of arrow from previous codes for better visualisation
        }
        printf("NULL\n");
    }
}
//Stack is LIFO, that means both pop and push are only concerned with the end

struct node *pop(struct node *head)
{
    if(head == NULL)
    {
        return NULL;// edge case
    }

    else 
    {
        struct node *temp = head;
        temp=(struct node *)malloc(sizeof(struct node));
        head = head->next; // move head to second place
        free(temp); // remove original head
        return head;// return the second node as the first one
    }
} 

struct node *push( struct node *head, int d) // Insert at beginning
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
   
    newnode->data = d;
    newnode->next = head;
    head = newnode; // Changing head's value

    return head;
    //I Could've also done return newnode, but somehow segmentation error and felt good to experiment
}

int main()
{
    struct node *head;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct node *)malloc(sizeof(struct node));

    // Link first and last nodes
    head = NULL;

    displaystack(head);
    head = push(head,77);
    head = push(head,679);
    head = push(head,78);
    head = push(head,77);
    head = push(head,500);
    head = push(head,400);
    head = push(head,432);
    head = push(head,4346);
    head = push(head,839);
    displaystack(head);
    head = pop(head);
    displaystack(head); 
    head = pop(head);
    displaystack(head);
    head = pop(head);
    displaystack(head);
    head = pop(head);
    displaystack(head);
    return 0;
}
