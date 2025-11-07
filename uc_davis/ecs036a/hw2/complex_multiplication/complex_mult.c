#include <stdio.h>

int main() {
    int a1;
    char i;
    char plus;
    int b1;
    int a2;
    int b2;
    int a3; // Holds resulting a
    int b3; // Holds resulting b

    printf("Enter the first complex number in the form ai + b: ");
    scanf(" %d", &a1);
    scanf(" %c", &i);
    scanf(" %c", &plus);
    scanf(" %d", &b1);

    printf("Enter the second complex number in the form ai + b: ");
    scanf(" %d", &a2);
    scanf(" %c", &i);
    scanf(" %c", &plus);
    scanf(" %d", &b2);

    a3 = a1 * b2 + a2 * b1;
    b3 = -1 * a1 * a2 + b1 * b2; 

    printf("(%di + %d) * (%di + %d) = %di + %d\n", a1, b1, a2, b2, a3, b3);
}