#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

/*
Ibrahim Siddiqui
CS10B
March 22, 2022
Instructor David Harden
Assignment 9.1


The Fraction class can be used to create objects storing a fraction (a numerator and denominator). The following functions are available:

Fraction(int inNumerator = 0, int inDenominator = 1);
    Pre: The number 0 is not entered as the denominator by the user.
    Post: The calling object's numerator is initialized to 0 and its denominator is initialized to 1 (default arguments) if the user does not give the arguments. Otherwise the first argument and second argument are assigned to the numerator and denominator member variables, respectively.

friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
    Post: The Fraction object is printed on the screen. It is printed either as a single number (5), as a fraction (2/3) or as an improper fraction (1+2/3).

friend std::istream& operator>>(std::istream &in, Fraction &fraction);
    Post: The Fraction object accepts a fraction (2, 1/2, 2+1/3).

friend bool operator>(const Fraction &left, const Fraction &right);
friend bool operator<(const Fraction &left, const Fraction &right);
friend bool operator==(const Fraction &left, const Fraction &right);
friend bool operator>=(const Fraction &left, const Fraction &right);
friend bool operator<=(const Fraction &left, const Fraction &right);
friend bool operator!=(const Fraction &left, const Fraction &right);
    Post: Two Fraction objects are compared and a bool (true or false) is returned depending on the relationship.

friend Fraction operator+(const Fraction &left, const Fraction &right);
friend Fraction operator-(const Fraction &left, const Fraction &right);
friend Fraction operator*(const Fraction &left, const Fraction &right);
friend Fraction operator/(const Fraction &left, const Fraction &right);
    Post: Performs operations between two Fraction objects or a Fraction object and an int. The resulting answer is returned as a brand new Fraction object.

Fraction operator+=(const Fraction &right);
Fraction operator-=(const Fraction &right);
Fraction operator*=(const Fraction &right);
Fraction operator/=(const Fraction &right);
    Post: Performs operations between a Fraction object and another Fraction object or an int. The object is returned, with the new value stored in it.

Fraction operator++();
Fraction operator++(int);
Fraction operator--();
Fraction operator--(int);
    Post: Performs pre and post incrementing/decrementing (by 1). Pre incrementing functions increment the object and then return it, while the post incrementing functions create a new object with the same number; that object is returned, and the original object is incremented.

void simplify();
    Post: Simplifies the calling object's fraction.

*/

namespace cs_fraction {
    class Fraction {
        private:
            int numerator;
            int denominator;
            void simplify();
        public:
            Fraction(int inNumerator = 0, int inDenominator = 1);
            friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
            friend std::istream& operator>>(std::istream &in, Fraction &fraction);
            friend bool operator>(const Fraction &left, const Fraction &right);
            friend bool operator<(const Fraction &left, const Fraction &right);
            friend bool operator==(const Fraction &left, const Fraction &right);
            friend bool operator>=(const Fraction &left, const Fraction &right);
            friend bool operator<=(const Fraction &left, const Fraction &right);
            friend bool operator!=(const Fraction &left, const Fraction &right);
            friend Fraction operator+(const Fraction &left, const Fraction &right);
            friend Fraction operator-(const Fraction &left, const Fraction &right);
            friend Fraction operator*(const Fraction &left, const Fraction &right);
            friend Fraction operator/(const Fraction &left, const Fraction &right);
            Fraction operator+=(const Fraction &right);
            Fraction operator-=(const Fraction &right);
            Fraction operator*=(const Fraction &right);
            Fraction operator/=(const Fraction &right);
            Fraction operator++();
            Fraction operator++(int);
            Fraction operator--();
            Fraction operator--(int);
    };
}

#endif

/*
Output:
----- Testing basic Fraction creation & printing
(Fractions should be in reduced form, and as mixed numbers.)
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

----- Now reading Fractions from file
Read Fraction = 1/3
Read Fraction = 1/2
Read Fraction = 3/4
Read Fraction = -4/5
Read Fraction = 6
Read Fraction = 5
Read Fraction = -8
Read Fraction = 1+2/5
Read Fraction = -16+2/3
Read Fraction = 1+1/4
Read Fraction = 2
Read Fraction = -4+1/4
Read Fraction = -10+5/6

----- Testing relational operators between Fractions
Comparing 1/2 to -1/2
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true
Comparing -1/2 to 1/2
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing 1/2 to 1/10
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true
Comparing 1/10 to 0
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true
Comparing 0 to 0
    Is left < right? false
    Is left <= right? true
    Is left > right? false
    Is left >= right? true
    Does left == right? true
    Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -1/2 to 2
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing -3 to 1/4
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true

----- Testing binary arithmetic between Fractions
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between Fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on Fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3
Program ended with exit code: 0
*/