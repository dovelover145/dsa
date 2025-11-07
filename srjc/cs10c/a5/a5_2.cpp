/*

Ibrahim Siddiqui
CS 10C
David Harden
Assignment 5.2
20 September 2022

This program helps to evaluate an infix expression containing single-digit operands and the +, -, *, and / operators. The function evaluateInfix finds the result of the infix expression (that is contained within a string) and it returns that result as an int. There are multiple helper functions that are used to help acheive the final solution.

*/

#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

int precedence(char ch);
int charToInt(char ch);
string infixToPostfix(const string& infixExp);
int evaluateInfix(const string& infixExp);

int main() {
    string s = "1*5+(7-8/3)+6*(9-1)";
    cout << s << ": ";
    int num = evaluateInfix(s);
    cout << num << endl;
    cout << "True value: 57.3" << endl << endl;
    
    string s2 = "7-9*3+(9*8/(9-1))+7";
    cout << s2 << ": ";
    int num2 = evaluateInfix(s2);
    cout << num2 << endl;
    cout << "True value: -4" << endl << endl;
    
    string s3 = "5*5*5+9-6+(9+6-(8-4)*6)+7";
    cout << s3 << ": ";
    int num3 = evaluateInfix(s3);
    cout << num3 << endl;
    cout << "True value: 126" << endl << endl;
    
    return 0;
}





// Pre: ch is either '+', '-', '*', or '/'.
// Param: The char containing the operator.
// Return: A number of precedence corresponding to the operator.
int precedence(const char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return -1;
}





// Pre: ch contains a single-digit character, like '1', for example.
// Param: The char to be converted into int form.
// Return: The char in int form.
int charToInt(char ch) {
    int num = 0;
    if (ch == '1') {
        num = 1;
    } else if (ch == '2') {
        num = 2;
    } else if (ch == '3') {
        num = 3;
    } else if (ch == '4') {
        num = 4;
    } else if (ch == '5') {
        num = 5;
    } else if (ch == '6') {
        num = 6;
    } else if (ch == '7') {
        num = 7;
    } else if (ch == '8') {
        num = 8;
    } else if (ch == '9') {
        num = 9;
    }
    return num;
}





// Pre: infixExp is a string that contains single-digit operands and the +, -, *, and / operators. Spaces are not included within the string.
// Param: The string contaning the infix expression that needs to be converted into postfix form.
// Return: A new string containing a postfix version of the infix expression passed into the string parameter infixExp.
string infixToPostfix(const string& infixExp) {
    string postfixExp = "";
    stack<char> aStack;
    for (int i = 0; i < infixExp.length(); i++) {
        char ch = infixExp[i];
        if (isdigit(ch)) {
            postfixExp += ch;
        } else if (ch == '(') {
            aStack.push(ch);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!aStack.empty() && aStack.top() != '(' && precedence(ch) <= precedence(aStack.top())) {
                postfixExp += aStack.top();
                aStack.pop();
            }
            aStack.push(ch);
        } else if (ch == ')') {
            while (aStack.top() != '(') {
                postfixExp += aStack.top();
                aStack.pop();
            }
            aStack.pop();
        }
    }
    while (!aStack.empty()) {
        postfixExp += aStack.top();
        aStack.pop();
    }
    return postfixExp;
}





// Pre: infixExp is a string that contains single-digit operands and the +, -, *, and / operators. Spaces are not included within the string.
// Param: The infix expression that needs to be evaluated.
// Return: The result of the infix expression.
int evaluateInfix(const string& infixExp) {
    string postfixExp = infixToPostfix(infixExp);
    stack<int> aStack;
    for (int i = 0; i < postfixExp.length(); i++) {
        char ch = postfixExp[i];
        if (isdigit(ch)) {
            aStack.push(charToInt(ch));
        } else {
            int result;
            int operand2 = aStack.top();
            aStack.pop();
            int operand1 = aStack.top();
            aStack.pop();
            if (ch == '+') {
                result = operand1 + operand2;
            } else if (ch == '-') {
                result = operand1 - operand2;
            } else if (ch == '*') {
                result = operand1 * operand2;
            } else if (ch == '/') {
                result = operand1 / operand2;
            }
            aStack.push(result);
        }
    }
    return aStack.top();
}






/*
Output:
1*5+(7-8/3)+6*(9-1): 58
True value: 57.3

7-9*3+(9*8/(9-1))+7: -4
True value: -4

5*5*5+9-6+(9+6-(8-4)*6)+7: 126
True value: 126
*/
