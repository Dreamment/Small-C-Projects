#include <stdio.h>
#include <math.h>

int digitOfNumber(int number);
int sumOfNumber(int number, int digit);
int productOfNumber(int number, int digit);
void isSpyNumber(int number, int sum, int product);

int main (){
    int number = 0;
    int digit= 0;

    printf("Enter a number to check if it is a spy number: ");
    while (scanf("%d", &number) != 1){
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Enter a number to check if it is a spy number: ");
    }
    digit = digitOfNumber(number);
    int sum = sumOfNumber(number, digit);
    int product = productOfNumber(number, digit);

    isSpyNumber(number, sum, product);

    return 0;
}

int digitOfNumber(int number){
    int digit = 0;
    while (number > 0){
        number /= 10;
        digit++;
    }
    return digit;
}

int sumOfNumber(int number, int digit){
    int sum = 0;
    while (number > 0){
        int divisor = (int)pow(10, digit-1);
        sum += number / divisor;
        number %= divisor;
        digit--;
    }
    return sum;
}

int productOfNumber(int number, int digit){
    int product = 1;
    while (number > 0){
        int divisor = (int)pow(10, digit-1);
        product *= number / divisor;
        number %= divisor;
        digit--;
    }
    return product;
}

void isSpyNumber(int number, int sum, int product){
    if (sum == product){
        printf("%d is a spy number", number);
    }
    else {
        printf("%d is not a spy number", number);
    }
}