#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void displaylist(struct node *head) 
{
    struct node *temp;
    for(temp = head; temp != NULL; temp = temp->next) 
    {
        printf("%d --> ", temp->data);
    }
    printf("NULL\n");
}

struct node *reverse(struct node *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    
    else if(head->next==NULL)
    {
        return head;
    } // bring back the same head

    else
    {
        struct node *temp;

        temp = reverse(head->next); // travels to the end of list and reverses from that point
        head->next->next = head; // till we reach the end 
        head->next = NULL;       // then the head is pointed towards the head

        return temp; // We return the head back, which would be the same as head
    }
}

int main()
{
    struct node *head, *second, *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    
    head->data = 42;
    head->next = second;

    second->data = 36;
    second->next = third;

    third->data = 628;
    third->next = NULL; //hard coding the linked list so that you can see its effects
    
    displaylist(head);
    head = reverse(head); // updating the head value
    displaylist(head);
    return 0;
}