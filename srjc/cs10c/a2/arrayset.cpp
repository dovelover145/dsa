//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

namespace cs_set {
    template <class ItemType>
    void ArraySet<ItemType>::add(const ItemType& newEntry) {
        if (itemCount >= maxItems) {
            throw CapacityExceededError();
        } else {
            if (getIndexOf(newEntry) != -1) {
                throw DuplicateMemberError();
            } else {
                items[itemCount] = newEntry;
                itemCount++;
            }
        }
    }





    template <class ItemType>
    ArraySet<ItemType>::ArraySet() {
        itemCount = 0;
        maxItems = DEFAULT_CAPACITY;
    }





    template <class ItemType>
    int ArraySet<ItemType>::getCurrentSize() const {
        return itemCount;
    }





    template <class ItemType>
    bool ArraySet<ItemType>::isEmpty() const {
        return itemCount == 0;
    }






    template <class ItemType>
    std::vector<ItemType> ArraySet<ItemType>::toVector() const {
        std::vector<ItemType> bagContents;
        for (int i = 0; i < itemCount; i++) {
            bagContents.push_back(items[i]);
        }
        return bagContents;
    }





    template <class ItemType>
    bool ArraySet<ItemType>::contains(const ItemType& anEntry) const {
        for (int i = 0; i < itemCount; i++) {
            if (items[i] == anEntry) {
                return true;
            }
        }
        return false;
    }
    




    template <class ItemType>
    void ArraySet<ItemType>::clear() {
        itemCount = 0;
    }





    template <class ItemType>
    int ArraySet<ItemType>::getIndexOf(const ItemType& target) const {
        for (int i = 0; i < itemCount; i++) {
            if (items[i] == target) {
                return i;
            }
        }
        return -1;
    }





    template <class ItemType>
    void ArraySet<ItemType>::remove(const ItemType& anEntry) {
        int locatedIndex = getIndexOf(anEntry);
        if (locatedIndex > -1) {
            itemCount--;
            items[locatedIndex] = items[itemCount];
        } else {
            throw ItemNotFoundError();
        }
    }
        
        
        
        
    template <class ItemType>
    ArraySet<ItemType> ArraySet<ItemType>::setUnion(const ArraySet& set) const {
        ArraySet set2;
        for (int i = 0; i < itemCount; i++) {
            if (set2.itemCount >= set2.maxItems) {
                throw CapacityExceededError();
            } else {
                if (set2.getIndexOf(items[i]) == -1) {
                    set2.add(items[i]);
                }
            }
        }
        for (int i = 0; i < set.itemCount; i++) {
            if (set2.itemCount >= set2.maxItems) {
                throw CapacityExceededError();
            } else {
                if (set2.getIndexOf(set.items[i]) == -1) {
                    set2.add(set.items[i]);
                }
            }
        }
        return set2;
    }
    
/*

template <class ItemType>
ArraySet<ItemType> ArraySet<ItemType>::setUnion(const ArraySet &set) {
    ArraySet unionSet;
    for (int i = 0; i < itemCount; i++) {
        unionSet.add(items[i]);
    }
    for (int i = 0; i < set.ItemCount; i++) {
        if (unionSet.getIndexOf(set.items[i]) == -1) {
            if (unionSet.itemCount >= unionSet.maxItems) {
                throw CapacityExceededError();
            } else {
                unionSet.add(set.items[i]);
        }
    }
    return unionSet;
}

template <class ItemType>
ArraySet<ItemType> ArraySet<ItemType>::setUnion(const ArraySet &set) {
    ArraySet unionSet;
    for (int i = 0; i < itemCount; i++) {
        unionSet.add(items[i]);
    }
    try {
        for (int i = 0; i < set.ItemCount; i++) {
            if (unionSet.getIndexOf(set.items[i]) == -1) {
                unionSet.add(set.items[i]);
            }
        }
    } catch (CapacityExceededError e) {
        throw CapacityExceededError();
    }
    return unionSet;
}

*/
        
        
        
        
    template <class ItemType>
    ArraySet<ItemType> ArraySet<ItemType>::setIntersection(const ArraySet& set) const {
        ArraySet set2;
        for (int i = 0; i < itemCount; i++) {
            for (int j = 0; j < set.itemCount; j++) {
                if (items[i] == set.items[j] && set2.getIndexOf(items[i]) == -1) {
                    set2.add(items[i]);
                }
            }
        }
        return set2;
    }

/*

template <class ItemType>
ArraySet<ItemType> ArraySet<ItemType>::setIntersection(const ArraySet &set) {
    ArraySet intersectionSet;
    for (int i = 0; i < itemCount; i++) {
        int j = 0;
        bool isFound = false;
        while (j < set.itemCount && !isFound) {
            if (items[i] == set.items[j]) {
                intersectionSet.add(items[j]);
                isFound = true;
            }
            j++;
        }
    }
    return intersectionSet;
}

*/
        
        
        
    template <class ItemType>
    ArraySet<ItemType> ArraySet<ItemType>::setDifference(const ArraySet& set) const {
        ArraySet set2 = *this;
        for (int i = 0; i < set2.itemCount; i++) {
            for (int j = 0; j < set.itemCount; j++) {
                if (set2.items[i] == set.items[j]) {
                    set2.remove(set.items[j]);
                }
            }
        }
        return set2;
    }
}

/*

template <class ItemType>
ArraySet<ItemType> ArraySet<ItemType>::setDifference(const ArraySet &set) const {
    ArraySet differenceSet = *this;
    for (int i = 0; i < differenceSet.itemCount; i++) {
        int j = 0;
        bool foundItem = false;
        while (j < set.itemCount && !foundItem) {
            if (differenceSet[i] = set[j]) {
                differenceSet.remove(set[j]);
                i--; // remove places the last item in the place of the removed item's index, so we need to check the same index again just in case
                foundItem = true;
            }
            j++;
        }
    }
    return differenceSet;
}

*/

