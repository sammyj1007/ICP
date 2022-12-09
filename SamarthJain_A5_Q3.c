#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
};

int Search(struct node *head, int d)
{

    if(head==NULL)
    {
        return 0;
    }

    else if(head->next == NULL)
    {
        if(head->data == d)
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }
    else
    {
        struct node *temp = head;
        while(temp->next!= NULL) // Till we reach last node
        {
            if(temp->data == d)
            {
                break; // Loop will stop when we reach what we're looking for
            }
            temp = temp->next;
        }
        //When temp is the last node OR node's data = the value we're looking for
        if(temp->next==NULL && temp->data!=d)
        {
            return 0;
        }

        else if(temp->next==NULL && temp->data==d)
        {
            return 1;
        }
        else// Node's data is value we're looking for
        {
            return 1;
        }
        
    }

}

void SearchBoth(struct node *head1, struct node *head2, int d)
{
    if((Search(head1,d)) && (Search(head2,d))) // Only if both are true
    {
        printf("%d EXISTS IN BOTH LISTS! \n", d);
    }
    else
    {
        printf("%d doesn't exist in both lists\n", d);
    }
}

int main()
{
    struct node *head1, *head2;
    //struct node *second1, *second2;
    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    //second1 = (struct node *)malloc(sizeof(struct node));
    //second2 = (struct node *)malloc(sizeof(struct node));

    head1->data = 43;
    head1->next = NULL;

    head2->data = 43;
    head2->next = NULL;
    
    SearchBoth(head1,head2,43);
    
    return 0;

}