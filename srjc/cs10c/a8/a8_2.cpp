/*

Ibrahim Siddiqui
CS 10C
David Harden
Assignment 8.2

This solution rearranges positive and negative integers in an array such that the negative integers appear before the positive ones. One function is of O(n) and the is of O(n^2).

*/

#include <iostream>
using namespace std;

void rearrangeN(int array[], int numItems);
void rearrangeN2(int array[], int numItems);

int main() {
    int array[] = {1, -5, 6, -9, 7, -10, -7};
    rearrangeN(array, 7);
    for (int i = 0; i < 7; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    int array2[] = {1, -5, 6, -9, 7, -10, -7, 90, 10};
    rearrangeN2(array2, 9);
    for (int i = 0; i < 9; i++) {
        cout << array2[i] << " ";
    }
    cout << endl;
}





void rearrangeN(int array[], int numItems) { // O(n)
    int* newArray = new int[numItems];
    int front = 0;
    int tail = numItems - 1;
    for (int i = 0; i < numItems; i++) {
        if (array[i] < 0) {
            newArray[front] = array[i];
            front++;
        } else if (array[i] > 0) {
            newArray[tail] = array[i];
            tail--;
        }
    }
    for (int i = 0; i < numItems; i++) {
        array[i] = newArray[i];
    }
    delete [] newArray;
}

/*

void rearrangeN(int array[]) {
    int left = 0;
    int right = ARRAY_SIZE - 1;
    while (left < right) {
        while (array[left] < 0 && left < right) {
            left++;
        }
        while (array[right] > 0 && left < right) {
            right--;
        }
        swap(array[left], array[right]);
    }
}

*/



void rearrangeN2(int array[], int numItems) { // O(n^2)
    for (int i = 0; i < numItems; i++) {
        for (int j = i; j < numItems; j++) {
            if (array[j] < 0) {
                swap(array[i], array[j]);
            }
        }
    }
}

/*
Output:
-5 -9 -10 -7 7 6 1
-7 -10 -9 -5 7 6 1 90 10
*/
