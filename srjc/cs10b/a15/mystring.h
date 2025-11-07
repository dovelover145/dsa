#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

/*

Ibrahim Siddiqui
CS10B
April 14, 2022
Instructor David Harden
Assignment 12.1

The MyString class makes working with strings easier. It is basically identical to the normal string class; that is, you can print MyString objects, concatenate MyString objects with other MyString objects and string literals, etc.

MyString(const char *inString = "");
    Post: Initializes the pointer member variable by making it point to a dynamically allocated array that contains the same c-string that was passed as the argument. If no argument is passed to the constructor, the default argument "" is passed (making it the default constructor as well).

MyString(const MyString &right);
    Post: The copy constructor "copies" the contents of the MyString object passed as the argument into the MyString object.

~MyString();
    Post: Deallocates the c-string that the pointer member variable points to on the heap upon destruction of the object.

MyString operator=(const MyString &right);
    Post: Assigns the same c-string stored in the right operand to the left (the MyString object). It returns the MyString object that experienced the assignment.

int length() const;
    Post: Returns the length of a MyString object.

friend std::ostream& operator<<(std::ostream &out, const MyString &printMe);
    Post: Prints out a MyString object.

friend std::istream& operator>>(std::istream &in, MyString &right);
    Post: Deallocates what was previously pointed to by the MyString object (the right operand) and reads input and stores that input into the MyString object. Input reading terminates when a newline character is reached.

char operator[](int index) const;
    Post: Returns the value stored in the index of the MyString object's c-string.

char& operator[](int index);
    Post: Returns the address of a MyString object's c-string that can be used for re-assignment.

friend bool operator>(const MyString &left, const MyString &right);
    Post: Returns true or false depending on whether the left MyString object > the right MyString object (ASCII values).

friend bool operator<(const MyString &left, const MyString &right);
    Post: Retuns whether left < right.

friend bool operator==(const MyString &left, const MyString &right);
    Post: Returns whether left and right are equal.

friend bool operator>=(const MyString &left, const MyString &right);
    Post: Returns whether left and right are equal or left > right.

friend bool operator<=(const MyString &left, const MyString &right);
    Post: Returns whether left and right or equal or left < right.

friend bool operator!=(const MyString &left, const MyString &right);
    Post: Returns whether the two operands are not equal.

friend MyString operator+(const MyString &left, const MyString &right);
    Post: Concatenates the right operand to the left (for example, "compu" + "ter" = "computer").

MyString operator+=(const MyString &right);
    Post: Concatenates the right operand to the end of the left operand and assigns the concatenated product to the left operand.

void read(std::istream &in, char ch);
    Post: Reads input into the calling object (the MyString object) and ends the reading when the character argument is reached. The function comsumes the character in the input stream as well.

*/


namespace cs_mystring {
    class MyString {
        private:
            char *string;
        public:
            static const int MAX_INPUT_SIZE = 127;
            MyString(const char *inString = "");
            MyString(const MyString &right);
            ~MyString();
            MyString operator=(const MyString &right);
            int length() const;
            friend std::ostream& operator<<(std::ostream &out, const MyString &printMe);
            friend std::istream& operator>>(std::istream &in, MyString &right);
            char operator[](int index) const;
            char& operator[](int index);
            friend bool operator>(const MyString &left, const MyString &right);
            friend bool operator<(const MyString &left, const MyString &right);
            friend bool operator==(const MyString &left, const MyString &right);
            friend bool operator>=(const MyString &left, const MyString &right);
            friend bool operator<=(const MyString &left, const MyString &right);
            friend bool operator!=(const MyString &left, const MyString &right);
            friend MyString operator+(const MyString &left, const MyString &right);
            MyString operator+=(const MyString &right);
            void read(std::istream &in, char ch);
    };
}

#endif
