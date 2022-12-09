#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main()
{
   int x, digit_no, EXP, y, i, sum;

	printf("Kindly enter an integer: \n");
	scanf("%d", &x); 						// x is the input
	
   if( x==0 )
   {
      printf("The sum of all digits is 0\n");
   }

   else
   {
   	digit_no = 0;
      x = abs(x);                //Taking care of the negative numbers
   	sum = 0;                   // Sum gives us a variable that we will enter into the for loop to use
      digit_no = log10(x)+1;  	// Using a logarithmic operator to establish the number of digits that the input has, helps start the program 
       
       
       for( i = (digit_no - 1); i>=0; --i)
       {	//The units digit is 10^0, thus we need to start with one less than our number of digits
          EXP = pow(10,i);	// Defining EXP helps store the power function as a int value, rather than a double or a float
          y = x/EXP;			// E.G. dividing 56789 by 10000(10^4) gives us 5, which is the first digit
          sum = sum + y;   //This variable will have the sum be updated
          x = x%EXP;       // We change the input to remove the first digit, 56789 % 10000 = 6789
       }
       
      printf("The value of sum of all digits is %d\n", sum);
   }
    
   return 0;
}