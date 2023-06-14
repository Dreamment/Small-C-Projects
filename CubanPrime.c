#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int number);
bool isCubanPrime(int number);
void printResult(int number);

int main() {
    char continueOrNot = 'y';
    while (continueOrNot == 'y' || continueOrNot == 'Y') {
        int numberFromUser;
        do {
            printf("Please enter a positive integer to check if it is a Cuban Prime Number (enter -1 to exit): ");
            while (scanf("%d", &numberFromUser) != 1) {
                fflush(stdin);
                printf("\nInvalid input. Please enter a positive integer to check if it is a Cuban Prime Number (enter -1 to exit): ");
            }
            if (numberFromUser == -1) {
                printf("Exiting...\n");
                return 0;
            }
        } while (numberFromUser <= 0);
        printResult(numberFromUser);
        printf("Do you want to try another number? (y/n): ");
        while (scanf(" %c", &continueOrNot) != 1 || (continueOrNot != 'y' && continueOrNot != 'n' && continueOrNot != 'Y' && continueOrNot != 'N')) {
            fflush(stdin);
            printf("\nInvalid input. Do you want to try another number? (y/n): ");
        }

    }
    printf("Exiting...\n");
    return 1;
}

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

bool isCubanPrime(int number) {
    int y = 1;
    int x = y + 1;
    int calculation;
    while (true) {
        calculation = (pow(x, 3) - pow(y, 3)) / (x - y);
        if (calculation == number) {
            return true;
        }
        y++;
        x = y + 1;
        if (calculation > number) {
            break;
        }
    }
    return false;
}

void printResult(int number) {
    if (isPrime(number)) {
        if (isCubanPrime(number)) {
            printf("%d is a Cuban Prime Number\n", number);
        }
        else {
            printf("%d is not a Cuban Prime Number\n", number);
        }
    }
    else {
        printf("%d is not a Cuban Prime Number, not even a Prime Number\n", number);
    }
}