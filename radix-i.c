#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define TITLE "DECIMAL TO RADIX-i converter"
#define NAME "DINO CLARO"
#define YEAR 2022
void Dec2RadixI(int decValue, int radValue);    // Declare function
int main(){

int dec = 1;
int rad;
    printf("****************************\n%s\nWritten by: %s\nDate: %d\n****************************\n", TITLE, NAME, YEAR);
while (dec >= 0)
{
    printf("Enter a decimal number: ");
    scanf("%d", &dec);
    if(dec >= 0){
    printf("The decimal number you have entered is %d\nEnter a radix for the converter between 2 and 16: ", dec);
    scanf("%d", &rad);
    printf("The radix you have entered is %d\n", rad);
    printf("The log2 of the number is %0.2f\n", log2(dec));
    Dec2RadixI(dec, rad); // Calls function
    }
    else printf("EXIT\n"); 
 }
return 0;
}

void Dec2RadixI(int decValue, int radValue)
{
    int sizeCon, res,val,index;
    sizeCon = log(decValue)/log(radValue);  // Finds the size of converted number in the respective radix by using log law: logB(X)=log(X)/log(B)
    printf("The radix-%d value is ",radValue);
    for (int counter = 0; counter <= sizeCon; counter++)
{
    val = pow(radValue,sizeCon-counter);
    res = decValue/val;
    if (res <1){
        printf("%c", res=48); // 48 is the ASCII value for 0.
    }
    if (res <= 9 && res >0){
        decValue = decValue-res*val;
        printf("%c", res+48); // To print char, ASCII digits start at decimal value of 48.
    }  
    else if(res > 9 && res <= 16){
        decValue = decValue-res*val; 
         printf("%c", res+55); // to print char, ASCII capital letters start at decimal value of 64.
    }
}
printf("\n");
}

