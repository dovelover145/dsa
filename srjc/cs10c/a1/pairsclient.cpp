#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "orderedpair.h"
using namespace std;
using namespace cs_pairs;

int main() {
    int num1, num2;
    OrderedPair<int> myList[10];
    
    srand(static_cast<unsigned>(time(0)));
    cout << "default value: ";
    myList[0].print();
    cout << endl;
    
    for (int i = 0; i < 10; i++) {
        myList[i].setFirst(rand() % 50);
        myList[i].setSecond(rand() % 50 + 50);
    }
    
    myList[2] = myList[0] + myList[1];
    
    if (myList[0] < myList[1]) {
        myList[0].print();
        cout << " is less than ";
        myList[1].print();
        cout << endl;
    }
    
    for (int i = 0; i < 10; i++) {
        myList[i].print();
        cout << endl;
    }
    
    cout << "Enter two numbers to use in an OrderedPair. Make sure they are different numbers: ";
    cin >> num1 >> num2;
    OrderedPair<int> x;
    
    /* use this before you've implemented the exception handling in the class:
    
    x.setFirst(num1);
    x.setSecond(num2);

    */
    
    // use this after you've implemented the exception handling in the class:
    
    try {
        x.setFirst(num1);
        x.setSecond(num2);
    } catch (OrderedPair<int>::DuplicateMemberError e) {
        cout << "Error, you attempted to set both members of the OrderedPair to the same number."
             << endl;
        x.setFirst(OrderedPair<int>::DEFAULT_VALUE);
        x.setSecond(OrderedPair<int>::DEFAULT_VALUE);
    }

    cout << "The resulting OrderedPair: ";
    x.print();
    cout << endl;
    cin.ignore();
    
    
    
    
    
    string string1, string2;
    OrderedPair<string> myList2[10];
    
    srand(static_cast<unsigned>(time(0)));
    cout << "default value: ";
    myList2[0].print();
    cout << endl;
    
    for (int i = 0; i < 10; i++) {
        string empty = "";
        myList2[i].setFirst(empty + char('a' + rand() % 26));
        myList2[i].setSecond(empty + char('A' + rand() % 26));
    }
    
    myList2[2] = myList2[0] + myList2[1];
    
    if (myList2[0] < myList2[1]) {
        myList2[0].print();
        cout << " is less than ";
        myList2[1].print();
        cout << endl;
    }
    
    for (int i = 0; i < 10; i++) {
        myList2[i].print();
        cout << endl;
    }
    
    cout << "Enter a string to use in an OrderedPair. Make sure there are different strings: ";
    getline(cin, string1);
    cout << "Enter a string to use in an OrderedPair. Make sure there are different strings: ";
    getline(cin, string2);
    OrderedPair<string> x2;
    
    /* use this before you've implemented the exception handling in the class:
    
    x.setFirst(num1);
    x.setSecond(num2);

    */
    
    // use this after you've implemented the exception handling in the class:
    
    try {
        x2.setFirst(string1);
        x2.setSecond(string2);
    } catch (OrderedPair<string>::DuplicateMemberError e) {
        cout << "Error, you attempted to set both members of the OrderedPair to the same number."
             << endl;
        x2.setFirst(OrderedPair<string>::DEFAULT_VALUE);
        x2.setSecond(OrderedPair<string>::DEFAULT_VALUE);
    }

    cout << "The resulting OrderedPair: ";
    x2.print();
    cout << endl;
}

/*
Output:
default value: (0, 0)
(38, 70)
(5, 68)
(43, 138)
(23, 90)
(20, 93)
(7, 60)
(42, 72)
(47, 82)
(1, 63)
(4, 62)
Enter two numbers to use in an OrderedPair. Make sure they are different numbers: 5 7
The resulting OrderedPair: (5, 7)
default value: (, )
(b, U) is less than (g, Q)
(b, U)
(g, Q)
(bg, UQ)
(v, G)
(p, F)
(c, W)
(x, M)
(b, V)
(i, G)
(l, A)
Enter a string to use in an OrderedPair. Make sure there are different strings: bob

Enter a string to use in an OrderedPair. Make sure there are different strings: bob
Error, you attempted to set both members of the OrderedPair to the same number.
The resulting OrderedPair: (, )
Program ended with exit code: 0
*/