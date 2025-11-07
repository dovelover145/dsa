/*
Calculates the foo recurrence given a non-negative number from the user.
*/

#include <stdio.h>

int foo (int n);
int _foo(int n, int n4, int n3, int n2, int n1);

int main() {
    int n;
    int result;
    
    printf("Enter a value for n: ");
    scanf("%d", &n);

    result = foo(n);

    printf("Foo(%d) = %d\n", n, result);

    return 0;
}

/*
Wrapper for actual _foo function.
@param n: foo number.
@return: int representing the foo calculation.
*/
int foo (int n) {
    return _foo(n, 3, 6, 2, 7);
}

/*
Calculates the result corresponding to the given foo number.
@param n: foo number.
@param n4: the number 4 steps behind.
@param n3: the number 3 steps behind.
@param n2: the number 2 step behind.
@param n1: the number 1 step behind.
@return: int representing the foo calculation.
*/
int _foo(int n, int n4, int n3, int n2, int n1) {
    if (n == 0) {
        return n4;
    } else if (n == 1) {
        return n3;
    } else if (n == 2) {
        return n2;
    } else if (n == 3) {
        return n1;
    } else {
        return _foo(n - 1, n3, n2, n1, n1 + n2 + n3 - n4 + 1);
    }
}