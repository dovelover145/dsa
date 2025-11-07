#include <stdio.h>
#include <math.h>

int main() {
    double borrowedMoney;
    double annualInterestRate;
    int numPayments;
    double monthlyInterestRate;
    double monthlyPayments;
    double totalPayment;
    
    printf("Please enter the amount of money you borrowed: $"); 
    scanf(" %lf", &borrowedMoney);

    printf("Please enter the annual interest rate: ");
    scanf("%lf", &annualInterestRate);

    printf("Please enter the number of payments to be made: ");
    scanf("%d", &numPayments);

    // Calculate monthly payments
    monthlyInterestRate = annualInterestRate / 12;
    monthlyPayments = (borrowedMoney * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, numPayments * -1.0));

    printf("A loan of $%.2lf with an annual interest of %.2lf paid off over %d months will have monthly payments of $%.2lf.\n", borrowedMoney, annualInterestRate, numPayments, monthlyPayments);

    totalPayment = monthlyPayments * numPayments;
    printf("In total, you will pay $%.2lf, making the cost of your loan $%.2lf.\n", totalPayment, totalPayment - borrowedMoney);
}