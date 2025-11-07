#ifndef HASHED_DICTIONARY
#define HASHED_DICTIONARY

#include "DictionaryInterface.h"
#include "HashedEntry.h"

template <class KeyType, class ItemType>
class HashedDictionary : public DictionaryInterface<KeyType, ItemType> {
    private:
        HashedEntry<KeyType, ItemType>** hashTable;
        int itemCount;
        int hashTableSize;
        static const int DEFAULT_SIZE = 101;
    public:
        HashedDictionary();
        bool isEmpty() const;
        int getNumberOfItems() const;
        bool add(const KeyType& searchKey, const ItemType& newItem);
        bool remove(const KeyType& searchKey);
        void clear();
        ItemType getItem(const KeyType& searchKey) const;
        bool contains(const KeyType& searchKey) const;
        int getHashIndex(const KeyType& searchKey) const;
        void display() const;
        class NotFoundException {};
}; // end HashedDictionary

#include "HashedDictionary.cpp"

#endif
