#include <cassert>
#include <iostream>
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;
        void simplify();

    public:
        Fraction();
        Fraction(int num, int denom);
        Fraction addedTo(const Fraction& fraction) const;
        Fraction subtract(const Fraction& fraction) const;
        Fraction multipliedBy(const Fraction& fraction) const;
        Fraction dividedBy(const Fraction& fraction) const;
        bool isEqualTo(const Fraction& fraction) const;
        void print() const;
};

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int num, int denom) {
    assert(denom != 0);
    numerator = num;
    denominator = denom;
}

// adds two fractions together and returns a fraction object representing the
// sum of both of them
Fraction Fraction::addedTo(const Fraction& fraction) const {
    Fraction newFraction(
        numerator * fraction.denominator + fraction.numerator * denominator,
        denominator * fraction.denominator);
    return newFraction;
}

// subtracts two fractions and returns the result in the form of a new Fraction
// object
Fraction Fraction::subtract(const Fraction& fraction) const {
    Fraction newFraction(
        numerator * fraction.denominator - fraction.numerator * denominator,
        denominator * fraction.denominator);
    return newFraction;
}

// multiplies two fractions and returns the product as a Fraction object
Fraction Fraction::multipliedBy(const Fraction& fraction) const {
    Fraction newFraction(numerator * fraction.numerator,
                         denominator * fraction.denominator);
    return newFraction;
}

// divides two fractions and returns the quotient as a Fraction object
Fraction Fraction::dividedBy(const Fraction& fraction) const {
    Fraction newFraction(numerator * fraction.denominator,
                         denominator * fraction.numerator);
    return newFraction;
}

// checks whether two fractions are equal to each other and returns true or
// false
bool Fraction::isEqualTo(const Fraction& fraction) const {
    return numerator * fraction.denominator == denominator * fraction.numerator;
}

// prints the fraction in the form of "n/d"
void Fraction::print() const {
    cout << numerator << "/" << denominator << endl;
}

void Fraction::simplify() {
    if (numerator == denominator) {
        numerator = 1;
        denominator = 1;
    } else if (numerator < denominator) {
        int gcf = 1;
        for (int i = 2; i <= numerator; i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                gcf = i;
            }
        }
        numerator = numerator / gcf;
        denominator = denominator / gcf;
    } else if (numerator > denominator) {
        int gcf = 1;
        for (int i = 2; i <= denominator; i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                gcf = i;
            }
        }
        numerator = numerator / gcf;
        denominator = denominator / gcf;
    }
}

int main() {
    Fraction f1(9, 8);
    Fraction f2(2, 3);
    Fraction result;

    cout << "The result starts off at ";
    result.print();
    cout << endl;

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)) {
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }

    const Fraction f3(12, 8);
    const Fraction f4(202, 303);
    result = f3.multipliedBy(f4);
    cout << "The product of ";
    f3.print();
    cout << " and ";
    f4.print();
    cout << " is ";
    result.print();
    cout << endl;
}