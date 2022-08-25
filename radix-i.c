#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define TITLE "DECIMAL TO RADIX-i converter"
#define NAME "DINO CLARO"
#define YEAR 2022
void Dec2RadixI(int decValue, int radValue);                         // Declare function.
int main(){
int decValue = 1; 
int radValue;
    printf("****************************\n%s\nWritten by: %s\nDate: %d\n****************************\n", TITLE, NAME, YEAR);
while (decValue >= 0)                                                //Program is exited when the user inputs a decimal value less than 0.                
{
    printf("Enter a decimal number: ");                               //Prompt for user input
    scanf("%d", &decValue);
    if(decValue >= 0){                                               //Continues with program if decimal value is greater than 0.
    printf("The decimal number you have entered is %d\nEnter a radix for the converter between 2 and 16: ", decValue);
    scanf("%d", &radValue);
    printf("The radix you have entered is %d\n", radValue);
    printf("The log2 of the number is %0.2f\n", log2(decValue));
    printf("The integer result of the number divided by %d is %d\n", radValue, decValue/radValue);
    printf("The remiander is %d\n", decValue%radValue);               // Displays the remainder of the decimal number dividedbyt the radix
    Dec2RadixI(decValue, radValue);                                   // Calls function.
    }
    else printf("EXIT\n");                                            //Prints "EXIT" if user input is less than zero.
 }
return 0;
}

void Dec2RadixI(int decValue, int radValue)
/* This function makes use of the sum of weights algorthim and prints each digit iteratively */
{
    int sizeConv, result, base;
    printf("The radix-%d value is ",radValue);
    if (decValue == 0){                                              // Deals with the case if the decimal number is = 0
        printf("%c", 48);                                            // 48 is the decimal value ASCII value for 0.
        sizeConv = -1;                                               // sets sizeConv to less than zero so that the for loop does not run 
    }
    else sizeConv = log(decValue)/log(radValue);                     // Finds the size of the converted number in the respective radix by using log law: logB(X)=log(X)/log(B)
    
    for (int counter = 0; counter <= sizeConv; counter++)            // Finds each digit iteratively using the sum of weights algorthim 
{
    base = pow(radValue,sizeConv-counter);                           // Base of the radix coresponding to the digit position.
    result = decValue/base;
    if (result < 1){
        printf("%c", result=48);                                     // 48 is the decimal value ASCII value for 0.
    }
    if (result <= 9 && result >0){
        decValue = decValue-result*base;
        printf("%c", result+48);                                     // To print char, ASCII digits start at decimal value of 48.
    }  
    else if(result > 9 && result <= 16){
        decValue = decValue-result*base; 
         printf("%c", result+55); // to print char, ASCII capital letters start at decimal value of 64.
    }
}
printf("\n");
}


