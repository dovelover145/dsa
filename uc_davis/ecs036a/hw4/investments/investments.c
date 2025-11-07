/* 
Tells the user which strategy of paying off loans completely first or investing alongside paying the minimum loan
payment is more optimal.
*/

#include <stdio.h>

double minLoanStrategy(double loanAmt, double monthlyLoanInterest, double loanMinPayment, double loanRetirementMoney, int curAge, int retirementAge, double monthlyROR);
double maxLoanStrategy(double loanAmt, double monthlyLoanInterest, double loanRetirementMoney, int curAge, int retirementAge, double monthlyROR);
void printOptimal(double minStrategyAmt, double maxStrategyAmt, double loanRetirementMoney);

int main() {
    double loanAmt;
    double yearlyLoanInterest;
    double monthlyLoanInterest;
    double loanMinPayment;
    double loanRetirementMoney;
    int curAge;
    int retirementAge;
    double annualROR;
    double monthlyROR;

    do {
        printf("Enter how much you owe in loans: ");
        scanf("%lf", &loanAmt);
    } while (!(loanAmt >= 0.0)); 

    do {
        printf("Enter the annual interest rate of the loans: ");
        scanf("%lf", &yearlyLoanInterest);
    } while (!(yearlyLoanInterest >= 0.0));

    monthlyLoanInterest = yearlyLoanInterest / 12.0;

    do {
        printf("Enter your minimum monthly loan payment: ");
        scanf("%lf", &loanMinPayment);
    } while (!(loanMinPayment >= 0.0));

    do {
        printf("Enter how much money you will be putting towards loans/retirement each month: ");
        scanf("%lf", &loanRetirementMoney);
    } while (!(loanRetirementMoney >= loanMinPayment));

    do {
        printf("Enter your current age: ");
        scanf("%d", &curAge);
    } while (!(curAge >= 0));

    do {
        printf("Enter the age you plan to retire at: ");
        scanf("%d", &retirementAge);
    } while (!(retirementAge >= curAge));

    do {
        printf("Enter your predicted annual rate of return: ");
        scanf("%lf", &annualROR);
    } while (!(annualROR >= 0.0));

    monthlyROR = annualROR / 12.0;

    double minStrategyAmt = minLoanStrategy(loanAmt, monthlyLoanInterest, loanMinPayment, loanRetirementMoney, curAge, retirementAge, monthlyROR);
    double maxStrategyAmt = maxLoanStrategy(loanAmt, monthlyLoanInterest, loanRetirementMoney, curAge, retirementAge, monthlyROR);

    printOptimal(minStrategyAmt, maxStrategyAmt, loanRetirementMoney);
    return 0;
}

/*
Calculates the minimum loan strategy of paying the base loan payment while investing.
param loanAmt is initial loan amount, monthlyLoanInterest is interest rate on loan amount, loanMinPayment
is minimum loan payment to make per month, loanRetirementMoney is money that can be used for paying off loans
and investing, curAge is starting age for work, retirementAge is age of retiring, monthlyROR is interest rate on
investment savings
returns the amount of money in investment savings given the above information
*/
double minLoanStrategy(double loanAmt, double monthlyLoanInterest, double loanMinPayment, double loanRetirementMoney, int curAge, int retirementAge, double monthlyROR) {
    int months = (retirementAge - curAge) * 12;
    double investmentAmt = 0.0;

    for (int i = 0; i < months; i++) {
        investmentAmt += investmentAmt * monthlyROR;
        loanAmt += loanAmt * monthlyLoanInterest;
        if (loanAmt > loanMinPayment) {
            loanAmt -= loanMinPayment;
            investmentAmt += (loanRetirementMoney - loanMinPayment);
        } else {
            investmentAmt += (loanRetirementMoney - loanAmt);
            loanAmt = 0.0;
        }
    }

    investmentAmt -= loanAmt;

    return investmentAmt;
}

/*
Calculates the maximum loan strategy of paying the loan payment completely before investing.
param loanAmt is initial loan amount, monthlyLoanInterest is interest rate on loan amount, loanRetirementMoney is money that can be used for paying off loans
and investing, curAge is starting age for work, retirementAge is age of retiring, monthlyROR is interest rate on
investment savings
returns the amount of money in investment savings given the above information
*/
double maxLoanStrategy(double loanAmt, double monthlyLoanInterest, double loanRetirementMoney, int curAge, int retirementAge, double monthlyROR) {
    int months = (retirementAge - curAge) * 12;
    double investmentAmt = 0.0;

    for (int i = 0; i < months; i++) {
        investmentAmt += investmentAmt * monthlyROR;
        loanAmt += loanAmt * monthlyLoanInterest;
        if (loanAmt > loanRetirementMoney) {
            loanAmt -= loanRetirementMoney;
        } else {
            investmentAmt += (loanRetirementMoney - loanAmt);
            loanAmt = 0.0;
        }
    }

    investmentAmt -= loanAmt;
    
    return investmentAmt;
}

/*
prints the optimal investing strategy
param minStrategyAmt is amount of money with minimum loan payments, maxStrategyAmt is amount of money with max loan 
payments before investing, loanRetirementMoney is amount of money for paying loans and investing every month
returns nothing
*/
void printOptimal(double minStrategyAmt, double maxStrategyAmt, double loanRetirementMoney) {
    if (minStrategyAmt > maxStrategyAmt) {
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you paid off your loan before investing.\n", minStrategyAmt, maxStrategyAmt);
    } else if (minStrategyAmt < maxStrategyAmt) {
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", loanRetirementMoney);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.\n", maxStrategyAmt, minStrategyAmt);
    } else if (minStrategyAmt - maxStrategyAmt < 0.0001) {
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you paid off your loan before investing.\n", minStrategyAmt, maxStrategyAmt);
    }
}