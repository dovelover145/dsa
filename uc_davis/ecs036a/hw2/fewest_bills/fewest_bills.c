#include <stdio.h>

int main() {
    int moneyToWithdraw; // Holds the user-specified amount of money to withdraw
    
    // Prompt user for amount of money to withdraw
    printf("Please enter the amount of money you wish to withdraw: ");
    scanf("%d", &moneyToWithdraw);

    // Produce user-specified amount using fewest possible bills
    printf("You received %d hundred(s)\n", moneyToWithdraw / 100); // Extract and print number of 100s
    printf("You received %d fifty(s)\n", moneyToWithdraw % 100 / 50); // Extract and print number of 50s
    printf("You received %d twenty(s)\n", moneyToWithdraw % 100 % 50 / 20); // Extract and print number of 20s
    printf("You received %d ten(s)\n", moneyToWithdraw % 100 % 50 % 20 / 10); // Extract and print number of 10s
    printf("You received %d five(s)\n", moneyToWithdraw % 100 % 50 % 20 % 10 / 5); // Extract and print number of 5s
    printf("You received %d one(s)\n", moneyToWithdraw % 100 % 50 % 20 % 10 % 5); // Extract and print number of 1s
}