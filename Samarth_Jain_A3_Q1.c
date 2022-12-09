#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int isPalindrome(char* str) //pointer in variable so that it can call by reference 
{
    int i;
    int length = strlen(str); //string.h function to get the length of a string
    for( i = 0 ; i < length/2 ; i++ ) //more effecient than checking the entire string as palindromes are symmetric
    {
        if(str[i] != str[length-i-1])
        {
            return 0;
        } //There is no need for an else condition otherwise, with an if else return in the for loop, we would have multiple returns
    }
    return 1;
}

int main()
{
    char str[50];// initialisation value
    printf("Enter a string: \n");
    gets(str);

    if(isPalindrome(str) == 1) //based on the return value of the above function

    {
        printf("The string is a palindrome! :)\n");
    }
    else 

    {
        printf("The string is not a palindrome! :(\n");
    }

    
    return 0;
}
