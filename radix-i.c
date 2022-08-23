#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define TITLE "DECIMAL TO RADIX-i converter"
#define NAME "DINO CLARO"
#define YEAR 2022
void Dec2RadixI(int decValue, int radValue);    // Declare function.
int main(){
int decValue = 1; 
int radValue;
    printf("****************************\n%s\nWritten by: %s\nDate: %d\n****************************\n", TITLE, NAME, YEAR);
while (decValue >= 0)                         //Program is exited when the user inputs a decimal value less than 0.                
{
    printf("Enter a decimal number: ");                 //Prompt for user input
    scanf("%d", &decValue);
    if(decValue >= 0){                        //Continues with program if decimal value is greater than 0.
    printf("The decimal number you have entered is %d\nEnter a radix for the converter between 2 and 16: ", decValue);
    scanf("%d", &radValue);
    printf("The radix you have entered is %d\n", radValue);
    printf("The log2 of the number is %0.2f\n", log2(decValue));
    printf("The remiander is %d\n", decValue%radValue);
    Dec2RadixI(decValue, radValue); // Calls function.
    }
    else printf("EXIT\n");                          //Prints "EXIT" if user input is less than zero.
 }
return 0;
}

void Dec2RadixI(int decValue, int radValue)
{
    int sizeConv, result, base;
    sizeConv = log(decValue)/log(radValue);  // Finds the size of converted number in the respective radix by using log law: logB(X)=log(X)/log(B)
    printf("The radix-%d value is ",radValue);
    for (int counter = 0; counter <= sizeConv; counter++)
{
    base = pow(radValue,sizeConv-counter);
    result = decValue/base;
    if (result < 1){
        printf("%c", result=48); // 48 is the ASCII value for 0.
    }
    if (result <= 9 && result >0){
        decValue = decValue-result*base;
        printf("%c", result+48); // To print char, ASCII digits start at decimal value of 48.
    }  
    else if(result > 9 && result <= 16){
        decValue = decValue-result*base; 
         printf("%c", result+55); // to print char, ASCII capital letters start at decimal value of 64.
    }
}
printf("\n");
}

