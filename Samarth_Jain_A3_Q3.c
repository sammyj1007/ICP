#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int checkPre(char* str1, char* str2)
{
	int x = strlen(str1), y = strlen(str2), min_len, i;
	//The initial variables that I will be using in the program

	(x >= y) ? (min_len = y) : (min_len = x); //A ternary operator to determine to what length the for loop will have to run for

	for( i = 0; i <= min_len-1; i++)
	{
		if(str1[i]!=str2[i]) //Because each position has to be the exact same
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	char str1[50], str2[50];//initialisation values
    
    printf("Enter two strings, press Enter between the two strings: \n");
    gets(str1); // Press Enter after the first string, which will allow you to compare sentences. BE CAREFUL FOR SPACES
	gets(str2); //Taking these two in gets helps each string have spaces in them, 
   
    if(checkPre(str1,str2) == 1)

    {
        printf("The string is a prefix! :)\n");
    }

    else 
	
    {
    	printf("The string is not a prefix! :(\n");
    }

    
    return 0;
}