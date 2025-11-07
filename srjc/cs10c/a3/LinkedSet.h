//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#ifndef LINKED_SET
#define LINKED_SET

#include "SetInterface.h"
#include "Node.h"

namespace cs_set {
    template <class ItemType>
    class LinkedSet : public SetInterface<ItemType> {
        private:
            Node<ItemType>* headPtr;
            int itemCount;
            
            // Returns either a pointer to the node containing a given entry
            // or nullptr if the entry is not in the bag.
            Node<ItemType>* getPointerTo(const ItemType& target) const;
            
            void clone(const LinkedSet<ItemType>& aSet);
        public:
            class ItemNotFoundError {};
            class DuplicateMemberError {};
            LinkedSet();
            LinkedSet(const LinkedSet<ItemType>& aSet);
            virtual ~LinkedSet();
            LinkedSet<ItemType> operator=(const LinkedSet<ItemType>& right);
            int getCurrentSize() const;
            bool isEmpty() const;
            
            // Adds a new item to the set, provided that it is not already in it (no duplicates).
            // param is the new item that is to be added to the set
            void add(const ItemType& newEntry);
            
            void remove(const ItemType& anEntry);
            void clear();
            bool contains(const ItemType& anEntry) const;
            std::vector<ItemType> toVector() const;
            
            // Creates a new set containing all the items (only once, and without duplicates) in both sets.
            // param is one of the two sets to be "unified"
            // returns the union set
            LinkedSet<ItemType> setUnion(const LinkedSet<ItemType>& aSet) const;
            
            // Creates a new set and makes it contain all the items that are in both sets.
            // param is one of the two sets to be used to get the "intersected" set
            // returns the "intersected" set
            LinkedSet<ItemType> setIntersection(const LinkedSet<ItemType>& aSet) const;
            
            // Creates a new set and makes it contain all the items in the calling object set that aren't in the parameter set (i.e. calling object set - parameter set).
            // param is the set that needs to be subtracted from the first set (the calling object set)
            // returns the resultant set which is equal to the calling object set minus the parameter set
            LinkedSet<ItemType> setDifference(const LinkedSet<ItemType>& aSet) const;
    };
}

#include "LinkedSet.cpp"

#endif
