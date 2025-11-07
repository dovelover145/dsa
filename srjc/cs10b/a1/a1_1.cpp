/*
Ibrahim Siddiqui
January 24, 2022
Assignment 1.1

This program checks whether the date typed in by the user is a "magic date". A
"magic date" is a date where the month times the day is equal to the year.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    char ch;  // Holds the '/' character that is between the int values
    int month;
    int day;
    int year;

    cout << "Enter a date in the format month/day/2-digit-year: ";

    cin >> month;
    cin >> ch;  // Consume the '/' character
    // cin.ignore();
    cin >> day;
    cin >> ch;  // Consume the '/' character
    cin >> year;

    if (month * day == year) {
        cout << "That is a magic date!" << endl;
    }

    return 0;
}

/*
Output:
Enter a date in the format month/day/2-digit-year: 1/1/1
That is a magic date!
Program ended with exit code: 0
*/