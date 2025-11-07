#include <iostream>
#include <cstring>
#include <cassert>
#include "mystring.h"
using namespace std;

/*
Class Invariant: The MyString class has one private member variable: a char pointer to a c-string. 
*/

namespace cs_mystring {
    MyString::MyString(const char *inString) {
        string = new char[strlen(inString) + 1];
        strcpy(string, inString);
    }





    MyString::MyString(const MyString &right) {
        string = new char[strlen(right.string) + 1];
        strcpy(string, right.string);
    }





    MyString::~MyString() {
        delete [] string;
    }





    MyString MyString::operator=(const MyString &right) {
        if (this != &right) {
            delete [] string;
            string = new char[strlen(right.string) + 1];
            strcpy(string, right.string);
        }
        return *this;
    }





    int MyString::length() const {
        return (int) strlen(string);
    }





    ostream& operator<<(ostream &out, const MyString &printMe) {
        int count = 0;
        while (printMe.string[count] != '\0') {
            out << printMe.string[count];
            count++;
        }
        return out;
    }





    char MyString::operator[](int index) const {
        assert(index >= 0 && index <= strlen(string));  // index <= (strlen(string) - 1) or index < strlen(string)
        return string[index];
    }





    char& MyString::operator[](int index) {
        assert(index >= 0 && index <= strlen(string)); // same
        return string[index];
    }





    bool operator>(const MyString &left, const MyString &right) {
        return strcmp(left.string, right.string) > 0;
    }





    bool operator<(const MyString &left, const MyString &right) {
        return strcmp(left.string, right.string) < 0;
    }





    bool operator==(const MyString &left, const MyString &right) {
        return strcmp(left.string, right.string) == 0;
    }





    bool operator>=(const MyString &left, const MyString &right) {
        return left > right || left == right;
    }





    bool operator<=(const MyString &left, const MyString &right) {
        return left < right || left == right;
    }





    bool operator!=(const MyString &left, const MyString &right) {
        return !(left == right);
    }





    istream& operator>>(istream &in, MyString &right) {
        while (isspace(in.peek())) {
            in.ignore();
        }
        char temp[MyString::MAX_INPUT_SIZE + 1]; // char *temp = new char[MyString::MAX_INPUT_SIZE + 1];
        in.getline(temp, MyString::MAX_INPUT_SIZE);
        delete [] right.string;
        right.string = new char[strlen(temp) + 1];
        strcpy(right.string, temp);
        // delete [] temp;
        return in;
    }





    MyString operator+(const MyString &left, const MyString &right) {
        MyString result;
        delete [] result.string;
        result.string = new char[strlen(left.string) + strlen(right.string) + 1];
        strcpy(result.string, left.string);
        strcat(result.string, right.string);
        return result;
    }





    MyString MyString::operator+=(const MyString &right) {
        *this = *this + right;
        return *this;
    }





    void MyString::read(istream &in, char ch) {
        char temp[MyString::MAX_INPUT_SIZE + 1];
        in.getline(temp, MyString::MAX_INPUT_SIZE, ch);
        in.ignore(); 
        delete [] string;
        string = new char[strlen(temp) + 1];
        strcpy(string, temp);
    }
}