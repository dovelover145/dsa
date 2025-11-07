//  Created by Frank M. Carrano and Tim Henry.
//  Edited by David Harden
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
// #include <string>
// #include <cctype>

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem) {
    // Create entry to add to dictionary
    HashedEntry<KeyType, ItemType>* entryToAddPtr = new HashedEntry<KeyType, ItemType>(newItem, searchKey);
    // Compute the hashed index into the array
    int itemHashIndex = getHashIndex(searchKey);
    // Add the entry to the chain at itemHashIndex
    if (hashTable[itemHashIndex] == nullptr) {
       hashTable[itemHashIndex] = entryToAddPtr;
    } else {
       entryToAddPtr->setNext(hashTable[itemHashIndex]);
       hashTable[itemHashIndex] = entryToAddPtr;
    }
    itemCount++;
    return true;
}





template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType& searchKey) {
    bool itemFound = false;
    // Compute the hashed index into the array
    int itemHashIndex = getHashIndex(searchKey);
    if (hashTable[itemHashIndex] != nullptr) {
        // Special case - first node has target
        if (searchKey == hashTable[itemHashIndex]->getKey()) {
            HashedEntry<KeyType, ItemType>* entryToRemovePtr = hashTable[itemHashIndex];
            hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
            delete entryToRemovePtr;
            entryToRemovePtr = nullptr; // For safety
            itemFound = true;
        } else { // Search the rest of the chain
            HashedEntry<KeyType, ItemType>* prevPtr = hashTable[itemHashIndex];
            HashedEntry<KeyType, ItemType>* curPtr = prevPtr->getNext();
            while ((curPtr != nullptr) && !itemFound) {
                // Found item in chain so remove that node
                if (searchKey == curPtr->getKey()) {
                    prevPtr->setNext(curPtr->getNext());
                    delete curPtr;
                    curPtr = nullptr; // For safety
                    itemFound = true;
                } else { // Look at next entry in chain
                    prevPtr = curPtr;
                    curPtr = curPtr->getNext();
                }
            }
        }
    }
    if (itemFound == true) {
        itemCount--;
    }
    return itemFound;
}





template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary() {
    hashTable = new HashedEntry<KeyType, ItemType>*[DEFAULT_SIZE];
    itemCount = 0;
    hashTableSize = DEFAULT_SIZE;
    for (int i = 0; i < hashTableSize; i++) {
        hashTable[i] = nullptr;
    }
}





template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const {
    return itemCount == 0;
}






template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const {
    return itemCount;
}





template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear() {
    for (int i = 0; i < hashTableSize; i++) {
        if (hashTable[i] != nullptr) {
            HashedEntry<KeyType, ItemType>* traversePtr = hashTable[i];
            HashedEntry<KeyType, ItemType>* nodeToDeletePtr = nullptr;
            while (traversePtr != nullptr) {
                nodeToDeletePtr = traversePtr;
                traversePtr = traversePtr->getNext();
                delete nodeToDeletePtr;
            }
            hashTable[i] = nullptr;
        }
    }
    itemCount = 0;
}





template <class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const {
    if (!contains(searchKey)) {
        throw NotFoundException();
    } else {
        int hashIndex = getHashIndex(searchKey);
        HashedEntry<KeyType, ItemType>* curPtr = hashTable[hashIndex];
        while (curPtr != nullptr) {
            if (curPtr->getKey() == searchKey) {
                return curPtr->getItem();
            }
            curPtr = curPtr->getNext();
        }
        return ItemType(); // to avoid a compiler error
    }
}





template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const {
    int hashIndex = getHashIndex(searchKey);
    if (hashTable[hashIndex] != nullptr) {
        HashedEntry<KeyType, ItemType>* curPtr = hashTable[hashIndex];
        while (curPtr != nullptr) {
            if (curPtr->getKey() == searchKey) {
                return true;
            }
            curPtr = curPtr->getNext();
        }
    }
    return false;
}





template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& searchKey) const {
    // Assuming that the search key is a string
    std::string aString = searchKey;
    int hashIndex = (toupper(aString[0]) - 'A' + 1); 
    for (int i = 1; i < aString.length(); i++) {
        hashIndex = (hashIndex * 32 + (toupper(aString[i]) - 'A' + 1)) % hashTableSize;
    }
    return hashIndex;
}





template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::display() const {
    for (int i = 0; i < hashTableSize; i++) {
        HashedEntry<KeyType, ItemType>* curPtr = hashTable[i];
        while (curPtr != nullptr) {
            std::cout << curPtr->getItem() << std::endl;
            curPtr = curPtr->getNext();
        }
    }
}
