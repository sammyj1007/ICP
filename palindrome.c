#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int i = 0;

int checkpalindrome(char *s)
{
    static int i,c=0;
    int n=strlen(s);
    
    if(i<n/2)
    {
         if(s[i]==s[n-i-1])
    	c++;
    	i++;
    	checkpalindrome(s+i);
	}

	else
	{
		if(c==i)
        return 1;
        else
        return 0;
	}
 	 
 	
}

int main()
{
    char s[1000];  
   
    printf("Enter  the string: ");
    gets(s);
    
 
    if(checkpalindrome(s))
 	    printf("string is palindrome");
    else
        printf("string is not palindrome");

 }
 /* 1010

 in unsigned will be 8+2 = 10

 in signed will be 

 -x = xbar + 1

 -x -1 = xbar

 0101
 1111
 -------
0100
 */