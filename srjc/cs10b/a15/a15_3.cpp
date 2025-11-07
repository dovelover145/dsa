/*
Ibrahim Siddiqui
CS10B
Assignment 15.3
Instructor David Harden

This program has a recursive function sort that sorts an array of integers into ascending order.
*/

#include <iostream>
using namespace std;

void sort(int array[], int size);
int indexOfSmallest(int array[], int size);

int main() {
    int array[] = {2000, 19, 75, 86, -50, 800, 57, 902, 10222, 93, 93};
    for (int i = 0; i < 11; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    sort(array, 11);
    for (int i = 0; i < 11; i++) {
        cout << array[i] << " ";
    }
}





// sorts array into ascending order
void sort(int array[], int size) {
    if (size == 1)
    {
        ;
    } else {
        int smallestIndex = indexOfSmallest(array, size);
        swap(array[0], array[smallestIndex]);
        sort(array + 1, size - 1);
    }
}




// finds smallest number in array and returns its index
int indexOfSmallest(int array[], int size) {
    int smallestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < array[smallestIndex]) {
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

/*
Output:
2000 19 75 86 -50 800
-50 19 75 86 800 2000 Program ended with exit code: 0
*/