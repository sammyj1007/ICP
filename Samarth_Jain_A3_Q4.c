#include<stdio.h>
#include<stdlib.h>

int main()
{
    char* str = malloc(80*sizeof(char)); //80 is the number that was given to us
    char ch;
    printf("Enter a string, then a blank space and then any single character\n");

    scanf("%s\n", str); // Adding this new "\n" allows for scanf to accept eveything till the string
    scanf("%c", &ch);   // and doesn't let the space be counted as the character
    printf("%s\n", str);
    printf("%c", ch);
    
    free(str); // clears the memory for future use

    return 0;
}