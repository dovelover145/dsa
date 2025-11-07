#include <iostream>
#include <cassert>
#include <cstdlib> // for the abs function
#include <fstream>
#include "fraction.h"
using namespace std;


/*
Class Invariant: A Fraction object has two data members: one representing the numerator and one representing the denominator. Fraction objects will always be simplified automatically upon initialization.
*/



namespace cs_fraction {
    Fraction::Fraction(int inNumerator, int inDenominator) {
        assert(inDenominator != 0); // checks to see if 0 is in the inDenominator parameter
        numerator = inNumerator;
        denominator = inDenominator;
        simplify();
    }





    ostream& operator<<(ostream &out, const Fraction &fraction) {
        if (fraction.denominator == 1) {
            out << fraction.numerator;
        } else if (abs(fraction.numerator) < fraction.denominator) {
            out << fraction.numerator << "/" << fraction.denominator;
        } else if (abs(fraction.numerator) > fraction.denominator) {
            if (fraction.numerator < 0) {
                out << "-" << abs(fraction.numerator) / fraction.denominator << "+" << abs(fraction.numerator) % fraction.denominator << "/" << fraction.denominator;
            } else if (fraction.numerator > 0) {
                out << fraction.numerator / fraction.denominator << "+" << fraction.numerator % fraction.denominator << "/" << fraction.denominator;
            }
        }
        return out;
    }

    



    istream& operator>>(istream &in, Fraction &fraction) {
        int num;
        in >> num;
        if (in.peek() == '+') {
            int num2;
            int num3;
            in.ignore();
            in >> num2;
            in.ignore();
            in >> num3;
            if (num < 0) {
                fraction.numerator = num * num3 - num2;
                fraction.denominator = num3;
            } else {
                fraction.numerator = num * num3 + num2;
                fraction.denominator = num3;
            }
        } else if (in.peek() == '/') {
            int num2;
            in.ignore();
            in >> num2;
            fraction.numerator = num;
            fraction.denominator = num2;
        } else {
            fraction.numerator = num;
            fraction.denominator = 1;
        }
        fraction.simplify();
        return in;
    }





    bool operator>(const Fraction &left, const Fraction &right) {
        return left.numerator * right.denominator > right.numerator * left.denominator;
    }





    bool operator<(const Fraction &left, const Fraction &right) {
        return left.numerator * right.denominator < right.numerator * left.denominator;
    }





    bool operator==(const Fraction &left, const Fraction &right) {
        return left.numerator * right.denominator == right.numerator * left.denominator;
    }





    bool operator>=(const Fraction &left, const Fraction &right) {
        return left > right || left == right;
    }





    bool operator<=(const Fraction &left, const Fraction &right) {
        return left < right || left == right;
    }





    bool operator!=(const Fraction &left, const Fraction &right) {
        return !(left == right);
    }





    Fraction operator+(const Fraction &left, const Fraction &right) {
        int num = left.numerator * right.denominator + right.numerator * left.denominator;
        int denom = left.denominator * right.denominator;
        Fraction answer(num, denom);
        return answer;
    }





    Fraction operator-(const Fraction &left, const Fraction &right) {
        int num = left.numerator * right.denominator - right.numerator * left.denominator;
        int denom = left.denominator * right.denominator;
        Fraction answer(num, denom);
        return answer;
    }





    Fraction operator*(const Fraction &left, const Fraction &right) {
        int num = left.numerator * right.numerator;
        int denom = left.denominator * right.denominator;
        Fraction answer(num, denom);
        return answer;
    }





    Fraction operator/(const Fraction &left, const Fraction &right) {
        int num = left.numerator * right.denominator;
        int denom = left.denominator * right.numerator;
        Fraction answer(num, denom);
        return answer;
    }





    Fraction Fraction::operator+=(const Fraction &right) {
        *this = *this + right;
        return *this;
    }





    Fraction Fraction::operator-=(const Fraction &right) {
        *this = *this - right;
        return *this;
    }





    Fraction Fraction::operator*=(const Fraction &right) {
        *this = *this * right;
        return *this;
    }




    Fraction Fraction::operator/=(const Fraction &right) {
        *this = *this / right;
        return *this;
    }





    Fraction Fraction::operator++() {
        *this = *this + 1;
        return *this;
    }





    Fraction Fraction::operator++(int) {
        Fraction temp;
        temp = *this;
        *this = *this + 1;
        return temp;
    }

    



    Fraction Fraction::operator--() {
        *this = *this - 1;
        return *this;
    }





    Fraction Fraction::operator--(int) {
        Fraction temp;
        temp = *this;
        *this = *this - 1;
        return temp;
    }





    void Fraction::simplify() {
        if (numerator < 0 && denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        
        if (denominator < 0 && numerator > 0) {
            numerator *= -1;
            denominator *= -1;
        }
        
        if (numerator == 0) {
            denominator = 1;
        }
        
        if (abs(numerator) == abs(denominator)) {
            numerator = numerator / abs(numerator);
            denominator = denominator / abs(denominator);
        } else if (abs(numerator) < denominator) {
            int gcf = 1;
            for (int i = 2; i <= abs(numerator); i++) {
                if (numerator % i == 0 && denominator % i == 0) {
                    gcf = i;
                }
            }
            numerator = numerator / gcf;
            denominator = denominator / gcf;
        } else if (abs(numerator) > denominator) {
            int gcf = 1;
            for (int i = 2; i <= denominator; i++) {
                if (numerator % i == 0 && denominator % i == 0) {
                    gcf = i;
                }
            }
            numerator /= gcf;
            denominator /= gcf;
        }
    }
}