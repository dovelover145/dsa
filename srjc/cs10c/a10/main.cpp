#include <iostream>
#include "ArrayQueue.h"
using namespace std;

int main() {
    ArrayQueue<int> aQ;
    
    // testing enqueue()
    for (int i = 0; i < 20; i++) {
        cout << "Adding " << i << " to the queue. ";
        aQ.enqueue(i);
        aQ.print();
        cout << endl;
        cout << "The capacity is " << aQ.capacity << " and the number of items is " << aQ.numItems << "." << endl << endl;
        
    }
    
    // testing dequeue()
    for (int i = 0; i < 20; i++) {
        cout << "Removing " << aQ.peekFront() << " from the queue. ";
        aQ.dequeue();
        aQ.print();
        cout << endl;
        cout << "The capacity is " << aQ.capacity << " and the number of items is " << aQ.numItems << "." << endl << endl;
    }
    
    for (int i = 0; i < 20; i++) {
        aQ.enqueue(i);
        cout << "Adding " << i << " to the queue. ";
        aQ.print();
        cout << endl;
        if (i % 3) {
            cout << "Removing from the queue. ";
            aQ.dequeue();
            aQ.print();
        }
        cout << endl;
    }
    
    cout << endl;
    cout << "Testing copy constructor. " << endl;
    ArrayQueue<int> aQ2(aQ);
    cout << "Removing first 3 items from new ArrayQueue. ";
    aQ2.dequeue();
    aQ2.dequeue();
    aQ2.dequeue();
    aQ2.print();
    cout << " This is the original ArrayQueue. ";
    aQ.print();
    cout << endl;
    
    cout << "Testing assignment operator. " << endl;
    aQ2 = aQ2;
    aQ2.print();
    
    
    
}

