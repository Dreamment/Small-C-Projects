#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int numberFromUser;
    int numberForDigit;
    int numberForRemainder;
    int digit;
    int remainder;
    int armstrongNumber;
    char response = 'y';
    while (response == 'y' || response == 'Y')
    {
        digit=0;
        armstrongNumber=0;
        bool control = false;
        do {
            printf ("Enter a number to check if it is a armstrong number or not: ");
            if (scanf ("%d", &numberFromUser)==1)
            {
                fflush(stdin);
                control = true;
            }
            else
            {
                fflush(stdin);
                printf("Invalid input.");
            }
        } while (control == false);

        numberForRemainder = numberFromUser;
        numberForDigit = numberFromUser;


        if (numberFromUser >=0)
        {
            while(numberForDigit >= 1)
            {
                numberForDigit /= 10;
                digit ++;
            }
            int i = digit;
            for(;i>0;i--)
            {
                remainder = numberForRemainder / pow(10, i-1);
                numberForRemainder -= remainder * pow(10, i-1);
                armstrongNumber += pow (remainder, digit);
            }
            if(armstrongNumber == numberFromUser)
            {
                printf("%d is an Armstrong number.\n", numberFromUser);
            }
            else
            {
                printf("%d isn't an Armstrong number.\n", numberFromUser);
            }
        }
        else
        {
            printf("Process denied.");
        }

        printf("Press 'y' to do again:");
        scanf("%c",&response);
        fflush(stdin);
    }
    printf("Existing system...");
}