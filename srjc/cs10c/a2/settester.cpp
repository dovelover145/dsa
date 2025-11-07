#include <iostream>
#include <vector>
#include "arrayset.h"
using namespace std;
using namespace cs_set;

int main() {
    ArraySet<string> set1;
    ArraySet<string> set2;
    ArraySet<string> set3;
    
    set1.add("Bob");
    set1.add("Robert");
    set1.add("John");
    set1.add("Bron");
    set1.add("Pop");

    /*

    vector<string> vector1 = set1.toVector();
    for (vector<string>::size_type i = 0; i < vector1.size(); i++) {
        cout << vector1.at(i) << endl;
    }
    cout << endl;
    
    */
    
    vector<string> vector1 = set1.toVector();
    for (vector<string>::const_iterator i = vector1.begin(); i != vector1.end(); i++) {
        cout << *i << endl;
    }
    cout << endl;
    
    set2.add("Bobetta");
    set2.add("Robert");
    set2.add("John");
    set2.add("Carl");
    set2.add("Randle");

    ArraySet<string> set4;
    try {
        set4 = set1.setUnion(set2);
    } catch (ArraySet<string>::CapacityExceededError e) {
        cout << "Error: Capacity exceeded." << endl << endl;
    }
    
    /*

    vector<string> vector2 = set4.toVector();
    for (vector<string>::size_type i = 0; i < vector2.size(); i++) {
        cout << vector2.at(i) << endl;
    }
    
    */
    
    vector<string> vector2 = set4.toVector();
    for (vector<string>::const_iterator i = vector2.begin(); i != vector2.end(); i++) {
        cout << *i << endl;
    }
    cout << endl;
    
    cout << "Yuta gappa." << endl;
}

/*
template <class ItemType>
ArraySet<ItemType> ArraySet<ItemType>::setDifference(const ArraySet& set) const {
    ArraySet set2;
    bool isDifferent = true;
    for (int i = 0; i < itemCount; i++) {
        for (int j = 0; j < set.itemCount; j++) {
            if (items[i] == set.items[j]) {
                isDifferent = false;
            }
        }
        if (isDifferent == true && set2.getIndexOf(items[i]) == -1) {
            if (set2.itemCount >= set2.maxItems) {
                throw CapacityExceededError();
            } else {
                set2.add(items[i]);
            }
        }
        isDifferent = true;
    }
    for (int i = 0; i < set.itemCount; i++) {
        for (int j = 0; j < itemCount; j++) {
            if (set.items[i] == items[j]) {
                isDifferent = false;
            }
        }
        if (isDifferent == true && set2.getIndexOf(set.items[i]) == -1) {
            if (set2.itemCount >= set2.maxItems) {
                throw CapacityExceededError();
            } else {
                set2.add(set.items[i]);
            }
        }
        isDifferent = true;
    }
    return set2;
}
}
*/
