#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void CheckCircle(struct node *head)
{
    if(head == NULL)
    {
        printf("The list is empty!\n");
    } // Edge Case

    else{

        struct node *temp;
        temp = head;

        while(temp->next != head)
        {

            if(temp->next==NULL)
            {
                break;
            }
            temp = temp->next;
        }
        // The loop will break when we are at a node which points to NULL or a node which points to head
        if(temp->next==NULL)
        {
            printf("The is a normal Linked List!\n");
        }
        else
        {
            printf("This is a circular Linked List!\n");
        }
    }
}

int main()
{
    struct node *head, *second;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));

    
    head->data = 42;
    head->next = second;

    second->data = 36;
    second->next = head; // Circular linked list for now
    
    CheckCircle(head);
    return 0;
}
// This function takes care of linked lists that point back to the head