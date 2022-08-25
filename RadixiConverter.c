#include <stdio.h>
#include <math.h>
#include <string.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Hendrik Smuts" //defines constants
#define YEAR "2022"

int decnum,radix;

char* Dec2RadixI(int decValue, int radValue){
    
    char digits[17] = "0123456789ABCDEF",line[100]; //Defines a list with all possible values in conversion and the line that will be returned
    int i=99; //defines the dynamic value used for conversion

    line[99] = '\0';//null terminates the return line

    while(decValue){//Loop that continues until the dynamic variable is equal to 0
        line[--i]=digits[decValue%radValue]; //Sets the next value in the radix value = to the value in digits[] that corresponds to the remainder
        decValue /= radValue;//Sets the new value of currentnum
    }

    return(strdup(line + i));
}

void main(){

    printf("*****************************\n");
    printf("%s\n",TITLE);
    printf("Written by: %s\n",AUTHOR); //Prints the heading
    printf("Date: %s\n",YEAR);
    printf("*****************************\n");

    decnum=1;
    while(decnum >=0){
        printf("Enter a decimal number: ");
        scanf("%d",&decnum); //Reads decimal number
        printf("The number you have entered is %d\n",decnum); //Displays decimal number entered
        printf("Enter a radix for the converter between 2 and 16: "); 
        scanf("%d",&radix); //Reads radix number
        printf("The radix you have entered is %d\n",radix); //Displays radix number

        printf("The log2 of the number is %.2f\n",log2(decnum)); //Displays the log2 of the decimal number entered

        printf("The integer result of the number divided by %d is %d\n",radix,decnum/radix);//Displays the decimal number divided by the radix

        printf("The remainder is %d\n",decnum%radix);//Displays the remainder of the decimal number divided by the radix

        printf("The radix-%d value is %s\n",radix,Dec2RadixI(decnum,radix)); //Displays the converted decimal to radix number

    }

    printf("EXIT");
}