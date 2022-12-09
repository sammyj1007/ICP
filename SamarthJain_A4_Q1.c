#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
};

void displayList(struct node *head)
{
    if(head==NULL)
    {
        printf("The list is empty");
    }
    else if(head->next == head)
    {
        printf("%d", head->data);// Edge case for when there's only one element
    }
    else
    {
        struct node *temp = head;
        while(temp->next!=head)
        {
            printf("%d-->",temp->data);
            temp = temp->next; // Print and move till it reaches the second last node of the list

        }
        printf("%d",temp->data); //Printing the last node in the list
    }
}

void Search(struct node *head, int searchvalue)
{

    if(head==NULL)
    {
        printf("The list is empty, try again later!");
    }
    else
    {
        struct node *temp = head;
        int count = 1; // Not treating as array, first position is 1 not 0
        while(temp->next!=head) // Till we reach last node
        {
            if(temp->data == searchvalue)
            {
                break; // Loop will stop when we reach what we're looking for
            }
            temp = temp->next;
            count++;
        }
        //When temp is the last node OR node's data = the value we're looking for
        if(temp->next==head && temp->data!=searchvalue)
        {
            printf("We have reached the end of the list, and we could not find the value!");
        }
        else// Node's data is value we're looking for
        {
            printf("The value you're looking for is at position %d",count);
        }
        
    }

}

struct node *InsertBeg( struct node *head, int d)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    if(head==NULL)
    {
        newnode->data=d;
        newnode->next=newnode;
        return newnode; // Adding the node
    }
    else
    {
        temp = head;
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        //When temp is one before head or the last node
        newnode->data = d;
        newnode->next=head;
        temp->next = newnode;
        //Adding the new node
        return newnode; // This makes newnode the head

    }

}

struct node *InsertEnd( struct node *head, int d)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    if(head==NULL)
    {
        newnode->data=d;
        newnode->next=newnode;
        return newnode;
    }
    else
    {
        temp = head;
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        //When temp is one before head
        newnode->data = d;
        newnode->next=head;
        temp->next = newnode;
        
        return head; //Same code as beginning, just returning head now

    }

}

struct node *InsertAfter( struct node *head, int after, int d)
{
    if(head == NULL)
    {
        return NULL;
    }

    else if(head->next == head) // If only one element
    {
        head = InsertEnd(head,d);
        return head;
    }
    else
    {
        struct node *temp1 = head, *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        while(temp1->data != after)
        {
            if(temp1->next == head) // break when we reach the end
            {
                break;
            }
            temp1 = temp1->next;
        }
        // When temp1 is last node or temp1's value is = after
        if(temp1->next==head && temp1->data!=after)
        {
            return head; // If I can't find the value in the list, the user gets the same list back to them
        }
        else
        {
            newnode->next = temp1->next;
            newnode->data = d;
            temp1->next = newnode;
            return head;
        }

    }
}

struct node *DeleteBeg(struct node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    else if( head->next==head)
    {
        free(head);
        return NULL; // Only one element will result in its own deletion
    }

    else
    {
        struct node *temp = head, *newnode;
        newnode = head->next;//newnode is the second node in the list
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        //When we reach the last node
        temp->next=newnode; // it connects to the second node
        free(head);
        return newnode;
    }
}

struct node *DeleteEnd(struct node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    else if( head->next==head)
    {
        free(head);
        return NULL;
    }

    else
    {
        struct node *temp = head, *newnode;
        while(temp->next->next!=head)
        {
            temp = temp->next;
        }
        //When we reach the second last node
        newnode = temp->next; // newnode is the last node
        temp->next=head; // Second last node connects to the head
        free(newnode); // Last element is deleted
        return head;
    }
}

struct node *DeleteAfter(struct node *head, int after)
{
    if(head == NULL)
    {
        return NULL;
    }

    else if(head->next == head)
    {
        free(head);
        return NULL;
    }
    else
    {
        struct node *temp1 = head, *newnode, *temp2;
        newnode = (struct node *)malloc(sizeof(struct node));
        while(temp1->data != after)
        {
            if(temp1->next == head)
            {
                break;
            }
            temp1 = temp1->next;
        }
        // When temp1 is last node or temp1's value is = after
        if(temp1->next==head && temp1->data!=after)
        {
            return head; // If value doesn't exist, you get the same list back
        }
        else if(temp1->next==head && temp1->data==after) // Handling the edge case that the value we're looking to delete after is the last one of the list
        {
            head = DeleteBeg(head);
            return head;
        }
        else  
        {
            temp2 = temp1->next->next; // The node after the node we want to delete
            newnode = temp1->next; // newnode = node we wanna delete
            temp1->next=temp2; // Link the neighbi=ouring nodes
            free(newnode); // Delete the node
            return head;
        }

    }
}


int main()
{
    struct node *head;
    //struct node *last = NULL;

    // Allocate memory for nodes in the linked list 
    head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    //last = (struct node *)malloc(sizeof(struct node));

    head = InsertBeg(head,55);
    //displayList(head);
    head = InsertBeg(head,100);
    head = InsertBeg(head,150);
    displayList(head);
    printf("\n");
    head = DeleteBeg(head);
    displayList(head);
    printf("\n");
    head = DeleteAfter(head,100);
    displayList(head);
    printf("\n");
    head = InsertAfter(head,100,32);
    displayList(head);
    printf("\n");
    head = DeleteAfter(head,32);
    displayList(head);
    printf("\n");
    head = InsertEnd(head,100);
    head = InsertEnd(head,150);
    head = InsertEnd(head,200);
    head = InsertEnd(head,250);
    displayList(head);
    printf("\n");
    Search(head,100);
    printf("\n");
    Search(head,150);
    printf("\n");
    Search(head,250);
    printf("\n");
    Search(head,32);
    printf("\n");
    head = InsertAfter(head,250,34);
    displayList(head);
    printf("\n");
    return 0;
}