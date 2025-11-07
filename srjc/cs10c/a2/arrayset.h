//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Header file for an array-based implementation of the ADT bag. Listing 3-1.
 @file ArrayBag.h */

#ifndef ARRAYSET_H
#define ARRAYSET_H

#include "setinterface.h"

namespace cs_set {
    template <class ItemType>
    class ArraySet : public SetInterface<ItemType> {
        public:
            typedef ItemType value_type;
        
            class CapacityExceededError {};
            class ItemNotFoundError {};
            class DuplicateMemberError {};
        
            ArraySet();
            int getCurrentSize() const;
            bool isEmpty() const;
            void add(const ItemType& newEntry);
            void remove(const ItemType& anEntry);
            void clear();
            bool contains(const ItemType& anEntry) const;
            std::vector<ItemType> toVector() const;
            
            /** Creates a set containing the items in the two sets (the calling object and argument). There are no duplicates.
             @param set The second set to be added to the union.
             @return A union of the two sets. */
            ArraySet setUnion(const ArraySet& set) const;
        
            /** Creates a set containing the similar items between the two sets (the calling object and argument).
             @param set The second set (the first one being the calling object).
             @return A set containing the similar items between the two sets. */
            ArraySet setIntersection(const ArraySet& set) const;
            
            /** Creates a set containing the items that are different in the first set from the second set (the calling object and argument). The resultant set has all the items from the first set that are not a part of the second set.
             @param set The second set (the first one being the calling object).
             @return A set containing the different items in the first set. */
            ArraySet setDifference(const ArraySet& set) const;
        private:
            static const int DEFAULT_CAPACITY = 6;
            ItemType items[DEFAULT_CAPACITY];
            int itemCount;
            int maxItems;
            
            // Returns either the index of the element in the array items that
            // contains the given target or -1, if the array does not contain
            // the target.
            int getIndexOf(const ItemType& target) const;
    };
}

#include "arrayset.cpp"

#endif
