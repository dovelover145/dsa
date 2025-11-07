/* 
Prints the roots of a quadratic equation using the quadratic formula, given the coefficients a, b, and c.
*/

#include <stdio.h>
#include <math.h>

/*
Function outputs the solutions of a quadratic equation, given the coefficients a, b, and c.
double a: coefficient a
double b: coefficient b
double c: coefficient c
return: void
*/
void quadFormula(double a, double b, double c);

int main() {
    double a;
    double b;
    double c;

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    
    printf("Please enter a: ");
    scanf("%lf", &a);
    
    printf("Please enter b: ");
    scanf("%lf", &b);
    
    printf("Please enter c: ");
    scanf("%lf", &c);

    quadFormula(a, b, c);

    return 0;
}

void quadFormula(double a, double b, double c) {
    double insideSqrtTerm = pow(b, 2) - 4 * a * c;
    if (insideSqrtTerm < 0) {
        printf("There are no real solutions\n");
    } else if (insideSqrtTerm == 0) {
        printf("There is one real solution: %.2lf\n", -b / (2 * a));
    } else {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", (-1 * b + sqrt(insideSqrtTerm)) / (2 * a));
        printf("Solution 2: %.2lf\n", (-1 * b - sqrt(insideSqrtTerm)) / (2 * a));
    }
}