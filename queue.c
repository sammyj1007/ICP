#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
};

void displayqueue(struct node *head) 
{
    if(head==NULL)
    {
        printf("This list doesn't exist!"); //Edge Case
    }
    struct node *temp;
    for(temp = head; temp != NULL; temp = temp->next) 
    {
        printf("%d <-- ", temp->data); //Changing direction of arrow from previous codes for better visualisation
    }
    printf("NULL\n");
}
//Queue is FIFO, that means dequeue is a beginning thing and enqueue is an end thing

struct node *dequeue(struct node *head)
{
    if(head==NULL)
    {
        return NULL;
    }

    struct node *temp = head;
    head = head->next; // Chnaged to second place
    free(temp); // Removal of first node
    return head;
} 

struct node *enqueue( struct node *head, int d)
{
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp;

    if (head == NULL)
    {
        newnode->data = d;
        newnode->next = NULL;
        return newnode; // Creating the linked List
    }

    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        // When temp is the last node in the list
        temp->next = newnode; // Insertion at the end
        newnode->data = d;
        newnode->next = NULL;

        return head;
    }
}

int main()
{
    struct node *head;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct node *)malloc(sizeof(struct node));
    head = NULL;

    displayqueue(head);
    head = enqueue(head,67);
    head = enqueue(head,57);
    displayqueue(head);
    head = dequeue(head);
    displayqueue(head);
    head = enqueue(head,77);
    head = enqueue(head,679);
    head = enqueue(head,78);
    displayqueue(head);
    head = dequeue(head);
    displayqueue(head);
    return 0;
}
