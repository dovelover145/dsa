//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Edited by Dave Harden

#include "Node.h"
#include <cstddef>

namespace cs_set {
    template <class ItemType>
    LinkedSet<ItemType>::LinkedSet() {
        headPtr = nullptr;
        itemCount = 0;
    }





    template <class ItemType>
    LinkedSet<ItemType>::LinkedSet(const LinkedSet<ItemType>& aSet) {
        clone(aSet);
    }





    template <class ItemType>
    LinkedSet<ItemType>::~LinkedSet() {
        clear();
    }





    template <class ItemType>
    LinkedSet<ItemType> LinkedSet<ItemType>::operator=(const LinkedSet<ItemType>& right) {
        if (this != &right) {
            clear();
            clone(right);
        }
        return *this;
    }

    
    
    
    
    template <class ItemType>
    bool LinkedSet<ItemType>::isEmpty() const {
        return itemCount == 0;
    }
    
    
    
    

    template <class ItemType>
    int LinkedSet<ItemType>::getCurrentSize() const {
        return itemCount;
    }
    
    
    
    

    template <class ItemType>
    void LinkedSet<ItemType>::add(const ItemType& newEntry) {
        if (contains(newEntry)) {
            throw DuplicateMemberError();
        } else {
            Node<ItemType>* nextNodePtr = new Node<ItemType>();
            nextNodePtr->setItem(newEntry);
            nextNodePtr->setNext(headPtr);
            
            headPtr = nextNodePtr;          // New node is now first node
            itemCount++;
        }
    }
    
    
    
    

    template <class ItemType>
    std::vector<ItemType> LinkedSet<ItemType>::toVector() const {
        std::vector<ItemType> setContents;
        Node<ItemType>* curPtr = headPtr;
        while (curPtr != nullptr) {
            setContents.push_back(curPtr->getItem());
            curPtr = curPtr->getNext();
        }
        return setContents;
    }
    
    
    
    

    template <class ItemType>
    void LinkedSet<ItemType>::remove(const ItemType& anEntry) {
        Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
        if (entryNodePtr == nullptr) {
            throw ItemNotFoundError();
        } else {
            // replace data of node to delete with data from first node
            entryNodePtr->setItem(headPtr->getItem());

            // Delete first node
            Node<ItemType>* nodeToDeletePtr = headPtr;
            headPtr = headPtr->getNext();
            delete nodeToDeletePtr;

            itemCount--;
        }
    }
    
    
    
    

    template <class ItemType>
    void LinkedSet<ItemType>::clear() {
        Node<ItemType>* nodeToDeletePtr = headPtr;
        while (headPtr != nullptr) {
            headPtr = headPtr->getNext();
            delete nodeToDeletePtr;
            nodeToDeletePtr = headPtr;
        }
        headPtr = nullptr;
        itemCount = 0;
    }
    
    
    
    

    template <class ItemType>
    bool LinkedSet<ItemType>::contains(const ItemType& anEntry) const {
        return (getPointerTo(anEntry) != nullptr);
    }

    // private
    // Returns either a pointer to the node containing a given entry
    // or nullptr if the entry is not in the bag.
    
    template <class ItemType>
    Node<ItemType>* LinkedSet<ItemType>::getPointerTo(const ItemType& anEntry) const {
        bool found = false;
        Node<ItemType>* curPtr = headPtr;
        while (!found && (curPtr != nullptr)) {
            if (anEntry == curPtr->getItem()) {
                found = true;
            } else {
                curPtr = curPtr->getNext();
            }
        }
        return curPtr;
    }





    template <class ItemType>
    void LinkedSet<ItemType>::clone(const LinkedSet<ItemType>& aSet) {
        itemCount = aSet.itemCount;
        Node<ItemType>* origChainPtr = aSet.headPtr;
        
        if (origChainPtr == nullptr) {
            headPtr = nullptr;
        } else {
            // Copy first node
            headPtr = new Node<ItemType>();
            headPtr->setItem(origChainPtr->getItem());
            
            // Copy remaining nodes
            Node<ItemType>* newChainPtr = headPtr;
            origChainPtr = origChainPtr->getNext();
            
            while (origChainPtr != nullptr) {
                // Get next item from original chain
                ItemType nextItem = origChainPtr->getItem();

                // Create a new node containing the next item
                Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

                // Link new node to end of new chain
                newChainPtr->setNext(newNodePtr);
                //newChainPtr->setNext(new Node<ItemType>(origChainPtr->getItem()));
                
                // Advance pointer to new last node
                newChainPtr = newChainPtr->getNext();

                // Advance original-chain pointer
                origChainPtr = origChainPtr->getNext();
            }
            newChainPtr->setNext(nullptr);
        }
    }

/*

template <class ItemType>
void LinkedSet<ItemType>::clone(const LinkedSet<ItemType> &aSet) {
    itemCount = aSet.itemCount;
    Node<ItemType> *origChainPtr = aSet.headPtr;
    if (origChainPtr = nullptr) {
        headPtr = nullptr;
    } else {
        headPtr = new Node<ItemType>(origChainPtr->getItem());
        Node<ItemType> *newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();
        while (origChainPtr != nullptr) {
            Node<ItemType> *newNodePtr = new Node<ItemType>(origChainPtr->getItem());
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
    }
}

*/

    
    
    
    
    template <class ItemType>
    LinkedSet<ItemType> LinkedSet<ItemType>::setUnion(const LinkedSet<ItemType>& aSet) const {
        LinkedSet<ItemType> resultantSet;
        Node<ItemType>* callingObjectPtr = headPtr;
        while (callingObjectPtr != nullptr) {
            if (!resultantSet.contains(callingObjectPtr->getItem())) {
                Node<ItemType>* newNodePtr = new Node<ItemType>();
                newNodePtr->setItem(callingObjectPtr->getItem());
                newNodePtr->setNext(resultantSet.headPtr);
                resultantSet.headPtr = newNodePtr;
                resultantSet.itemCount++;
            }
            callingObjectPtr = callingObjectPtr->getNext();
        }
        Node<ItemType>* parameterPtr = aSet.headPtr;
        while (parameterPtr != nullptr) {
            if (!resultantSet.contains(parameterPtr->getItem())) {
                Node<ItemType>* newNodePtr = new Node<ItemType>();
                newNodePtr->setItem(parameterPtr->getItem());
                newNodePtr->setNext(resultantSet.headPtr);
                resultantSet.headPtr = newNodePtr;
                resultantSet.itemCount++;
            }
            parameterPtr = parameterPtr->getNext();
        }
        return resultantSet;
    }
    
    
    
    
    
    template <class ItemType>
    LinkedSet<ItemType> LinkedSet<ItemType>::setIntersection(const LinkedSet<ItemType>& aSet) const {
        LinkedSet<ItemType> resultantSet;
        Node<ItemType>* callingObjectPtr = headPtr;
        while (callingObjectPtr != nullptr) {
            if (aSet.contains(callingObjectPtr->getItem())) {
                Node<ItemType>* newNodePtr = new Node<ItemType>();
                newNodePtr->setItem(callingObjectPtr->getItem());
                newNodePtr->setNext(resultantSet.headPtr);
                resultantSet.headPtr = newNodePtr;
                resultantSet.itemCount++;
            }
            callingObjectPtr = callingObjectPtr->getNext();
        }
        return resultantSet;
    }





    template <class ItemType>
    LinkedSet<ItemType> LinkedSet<ItemType>::setDifference(const LinkedSet<ItemType>& aSet) const {
        LinkedSet<ItemType> resultantSet;
        Node<ItemType>* callingObjectPtr = headPtr;
        while (callingObjectPtr != nullptr) {
            if (!aSet.contains(callingObjectPtr->getItem())) {
                Node<ItemType>* newNodePtr = new Node<ItemType>();
                newNodePtr->setItem(callingObjectPtr->getItem());
                newNodePtr->setNext(resultantSet.headPtr);
                resultantSet.headPtr = newNodePtr;
                resultantSet.itemCount++;
            }
            callingObjectPtr = callingObjectPtr->getNext();
        }
        return resultantSet;
    }
}
