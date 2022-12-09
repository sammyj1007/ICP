#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char *firstname;
    char *middlename;
    char *lastname;
    struct node *next;
};

/*I started this program because this is what I thought the assignment should be
This program is really complex, but I tried to make it somehwta more readable by having
nested if-else statements and not keeping everything in while loop conditions
OBJECTIVE: This program sorts through a list of names in the same way a CLASS REGISTER would
for example if we have Ananya Sheila Singhal, Ananya Rathor Pritam, Ananya Gopal Agarwal, Ananya Gopal Gupta

our output would look like Ananya Gopal Agarwal, Ananya Gopal Gupta, Ananya Rathor Pritam, Ananya Sheila Singhal

It firsts sorts the first names, if they are equal then middle names and if they are equal then last names

Hoping to cash out some extra credit for this:)! */

//Comments are limited as the code is similar to Q2 a and b

int alphabetical(char *str1, char *str2)
{
    return strcmp(str1,str2);
}

struct node *InsertBeg(struct node *head, char *NFN, char *NMN, char *NLN)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    if(head==NULL)
    {
        newnode->firstname=NFN;
        newnode->middlename=NMN;
        newnode->lastname=NLN;
        newnode->next=NULL;
        return newnode; // Adding the node
    }

    else
    {
        
        //When temp is one before head or the last node
        newnode->firstname=NFN;
        newnode->middlename=NMN;
        newnode->lastname=NLN;
        newnode->next=head;
        //Adding the new node
        return newnode; // This makes newnode the head

    }

}

void displaylist(struct node *head) 
{
    struct node *temp;
    if(head==NULL)
    {
        printf("The list is empty:(\n");
    }
    else
    {
        temp=head;
        for(temp = head; temp != NULL; temp = temp->next) 
        {
            printf("%s %s %s --> ", temp->firstname,temp->middlename,temp->lastname);
        }
        printf("NULL\n");
    }
}

void SearchName(struct node *head, char *NFN, char *NMN, char *NLN)
{
    struct node *temp;
    int count=0;

    if(head == NULL)
    {
        printf("The list doesn't exist");
    }

    else if(head->next==NULL)
    {
        if(head->firstname==NFN && head->middlename==NMN && head->lastname==NLN)
        {
            printf("The value is posiition 1 in the list.\n");
        }
        else
        {
            printf("Hey, you've reached the end of the list, but your name does not exist here!\n");
        }
    }

    else
    {
        temp = head;
        
        while((alphabetical(temp->firstname,NFN)!=0) && (alphabetical(temp->middlename,NMN)!=0) && (alphabetical(temp->lastname,NLN)!=0))
        {
         temp = temp->next;
         count++;
         if(temp->next==NULL)
         {
            break;
         }
        }
        // when first name, middle name, and last name match OR when it is at the last position
        if((alphabetical(temp->firstname,NFN)==0) && (alphabetical(temp->middlename,NMN)==0) && (alphabetical(temp->lastname,NLN)==0))
        {
            printf("The name is in the list and it's at position no. %d on the list\n", count+1);
        }

        else
        {
            printf("Hey, you've reached the end of the list, but your name does not exist here!\n");
        }
        
    }
}

struct node *Insert(struct node *head, char *NFN, char *NMN, char *NLN)
{
    struct node *newnode, *temp;
    int count =0;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->firstname = NFN;
    newnode->middlename = NMN;
    newnode->lastname = NLN;

    if ( head == NULL)
    {
        newnode->next = NULL;
        return newnode;
    }

    else if(head->next==NULL)
    {
        if(alphabetical(head->firstname,NFN)>0)
        {
            head = InsertBeg(head, NFN, NMN, NLN);
            return head;
        }
        else if(alphabetical(head->firstname,NFN)<0)
        {
            head->next=newnode;
            newnode->next = NULL;
            return head;
        }
        
        else
        {
            if(alphabetical(head->middlename,NMN)>0)
            {
                head = InsertBeg(head, NFN, NMN, NLN);
                return head;
            }

            else if(alphabetical(head->middlename,NMN)<0)
            {
                head->next=newnode;
                newnode->next = NULL;
                return head;
            }

            else
            {
                if(alphabetical(head->lastname,NLN)>0)
                {
                    head = InsertBeg(head, NFN, NMN, NLN);
                    return head;
                }

                else if(alphabetical(head->lastname,NLN)<0)
                {
                    head->next=newnode;
                    newnode->next = NULL;
                    return head;
                }

                else
                {
                    head = InsertBeg(head, NFN, NMN, NLN);
                    return head;
                }
            }
        }
    }

    else if (alphabetical(head->firstname,NFN)>0)
    {
        head = InsertBeg(head, NFN, NMN, NLN);
        return head;
    }

    else if (alphabetical(head->firstname,NFN)==0 && alphabetical(head->middlename,NMN)>0)
    {
        head = InsertBeg(head, NFN, NMN, NLN);
        return head;
    }

    else if(alphabetical(head->firstname,NFN)==0 && alphabetical(head->middlename,NMN)==0 && alphabetical(head->lastname,NLN)>0)
    {
        head = InsertBeg(head, NFN, NMN, NLN);
        return head;
    }

    else
    {
        temp = head;
        while(alphabetical(temp->next->firstname,NFN)<0)
        {
            if(temp->next->next == NULL)
            {
                break;
            }
            temp = temp->next;
            count++;
        }
        //When loop stops, temp is at a node where the NEXT node is just alphabetically after NFN or equal to NFN
        //Or TEMP just is the second last node
        if( alphabetical(temp->next->firstname,NFN)==0)
        {
            while(alphabetical(temp->next->middlename,NMN)<0 && ( alphabetical(temp->next->firstname,NFN)==0)&& temp->next==NULL)
            {
                temp= temp->next;
                count++;
            }
            //When loop stops, temp is at a node where the next node is just alphabetically after NMN or equal to NMN
            if(alphabetical(temp->next->middlename,NMN)==0)
            {
                while(alphabetical(temp->next->lastname,NLN)<0 && ( alphabetical(temp->next->firstname,NFN)==0) && (alphabetical(temp->next->middlename,NMN)==0) && temp->next==NULL)
                {
                temp= temp->next;
                count++;
                }
                // Node after is alphabetically more OR equal OR we are at Second last node
                if(alphabetical(temp->next->lastname,NLN)==0 && alphabetical(temp->next->firstname,NFN)==0 && alphabetical(temp->next->middlename,NMN) == 0)
                {
                    //newnode->next = temp->next->next;
                    //temp->next = newnode;
                    newnode->next = NULL;
                    temp->next->next = newnode;
                    return head;
                }
                // Node after is alphabetically more AND we are at Second last node
                else if(temp->next->next == NULL && alphabetical(temp->next->lastname,NLN)<0)
                {
                    newnode->next = NULL;
                    temp->next->next = newnode;
                    return head;
                }

                else
                {
                    newnode->next = temp->next;
                    temp->next = newnode;
                    return head;
                }
            }
            // Node after is alphabetically more AND we are at second last node
            else if(temp->next->next == NULL && alphabetical(temp->next->middlename,NMN)<0)
            {
                newnode->next = NULL;
                temp->next->next = newnode;
                return head;
            }

            else
            {
                newnode->next = temp->next;
                temp->next = newnode;
                return head;
            }
            
        }
        // Node after is alphabetically more or we are at second last node
        else if(temp->next->next == NULL && alphabetical(temp->next->firstname,NFN)<0)
        {
            newnode->next = NULL;
            temp->next->next = newnode;
            return head;
        }
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
            return head;
        }
    }
}
int main()
{   
    struct node *head;
    //struct node *second;

    // Allocate memory for nodes in the linked list 
    head = (struct node *)malloc(sizeof(struct node));
   //second = (struct node *)malloc(sizeof(struct node));
    head = NULL;

    displaylist(head);
    head = Insert(head, "Broma", "Martil","Yakub");
    displaylist(head);
    SearchName(head,"GGG","JJJ","JKL");
    head = Insert(head,"GGG","JJJ","JKL");
    SearchName(head,"GGG","JJJ","JKL");
    head = Insert(head,"Batman","Dick","Grayson");
    displaylist(head);
    SearchName(head,"GGG","JJJ","JKL");
    head = Insert(head, "Ishpreet", "Samarth", "Aryan");
    head = Insert(head, "XXX","Tezo","Populi");
    displaylist(head);
    head = Insert(head,"Clark","Jordan","Kent");
    head = Insert(head, "Diana", "WWW", "Prince");
    head = Insert(head, "Alexis", "WWW", "Prince");
    head = Insert(head, "Alexis", "WWW", "Roberts");


    displaylist(head);

    return 0;
}