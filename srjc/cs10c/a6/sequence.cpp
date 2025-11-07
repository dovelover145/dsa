#include <iostream>
#include <cassert>
#include "sequence.h"
using namespace std;

namespace cs_sequence {
    Sequence::Sequence() {
        numItems = 0;
        headPtr = nullptr;
        tailPtr = nullptr;
        cursor = nullptr;
        precursor = nullptr;
    }





    void Sequence::start() {
        if (headPtr != nullptr) {
            cursor = headPtr;
            precursor = nullptr;
        }
    }





    void Sequence::advance() {
        assert(is_item());
        if (cursor == tailPtr) {
            cursor = nullptr;
            precursor = nullptr;
        } else {
            precursor = cursor;
            cursor = cursor->next;
        }
    }





    void Sequence::insert(const value_type& entry) {
        node* newNodePtr = new node;
        newNodePtr->data = entry;
        newNodePtr->next = nullptr;
        numItems++;
        if (cursor == headPtr || !is_item()) {
            newNodePtr->next = headPtr;
            headPtr = newNodePtr;
            if (numItems == 1) {
                tailPtr = newNodePtr;
            }
        } else {
            newNodePtr->next = cursor;
            precursor->next = newNodePtr;
        }
        cursor = newNodePtr;
    }





    void Sequence::attach(const value_type& entry) {
        node* newNodePtr = new node;
        newNodePtr->data = entry;
        newNodePtr->next = nullptr;
        numItems++;
        if (headPtr == nullptr && tailPtr == nullptr) { // the list is empty
            headPtr = newNodePtr;
            tailPtr = newNodePtr;
        } else if (!is_item()) { // there is no current item; insert at the end of the list
            tailPtr->next = newNodePtr;
            precursor = tailPtr;
            tailPtr = newNodePtr;
        } else if ((cursor == headPtr && cursor == tailPtr) || cursor == tailPtr) { // the current item is the first and only item of the list or it is the very last item of the list
            cursor->next = newNodePtr;
            tailPtr = newNodePtr;
            precursor = cursor;
        } else { // the current item is in the middle of the list
            newNodePtr->next = cursor->next;
            cursor->next = newNodePtr;
            precursor = cursor;
        }
        cursor = newNodePtr;
    }





    void Sequence::remove_current() {
        assert(is_item());
        numItems--;
        if (cursor == tailPtr) { // the current item is the last item in the list
            cursor = nullptr;
            delete tailPtr;
            tailPtr = precursor;
            precursor = nullptr;
            if (numItems > 0) { // the current item wasn't the only item in the list
                tailPtr->next = nullptr;
            } else { // the current item was the last and only item in the list
                headPtr = nullptr;
            }
        } else if (cursor == headPtr) { // the current item is the first item in the list
            node* delPtr = cursor;
            cursor = cursor->next;
            headPtr = cursor;
            delete delPtr;
        } else { // the current item is in the middle of the list
            node* delPtr = cursor;
            cursor = cursor->next;
            precursor->next = cursor;
            delete delPtr;
        }
    }

 



    Sequence::size_type Sequence::size() const {
        return numItems;
    }





    bool Sequence::is_item() const {
        return cursor != nullptr;
    }





    Sequence::value_type Sequence::current() const {
        assert(is_item());
        return cursor->data;
    }





    Sequence::~Sequence() {
        clear();
    }





    Sequence::Sequence(const Sequence& aSequence) {
        copy(aSequence);
    }





    Sequence Sequence::operator=(const Sequence& aSequence) {
        if (this != &aSequence) {
            clear();
            copy(aSequence);
        }
        return *this;
    }





    void Sequence::clear() {
        node* curPtr = headPtr;
        while (curPtr != nullptr) {
            node* delPtr = curPtr;
            curPtr = curPtr->next;
            delete delPtr;
        }
        headPtr = nullptr;
        tailPtr = nullptr;
        cursor = nullptr;
        precursor = nullptr;
        numItems = 0;
    }





    void Sequence::copy(const Sequence& aSequence) {
        numItems = aSequence.numItems;
        node* origChainPtr = aSequence.headPtr;
        if (origChainPtr == nullptr) {
            headPtr = nullptr;
            tailPtr = nullptr;
            cursor = nullptr;
            precursor = nullptr;
        } else {
            cursor = nullptr;
            precursor = nullptr;
            headPtr = new node;
            headPtr->data = origChainPtr->data;
            node* newChainPtr = headPtr;
            if (origChainPtr == aSequence.cursor) {
                cursor = headPtr;
                precursor = nullptr;
            }
            origChainPtr = origChainPtr->next;
            while (origChainPtr != nullptr) {
                node* newNodePtr = new node;
                newNodePtr->data = origChainPtr->data;
                newChainPtr->next = newNodePtr;
                newChainPtr = newChainPtr->next;
                if (origChainPtr == aSequence.cursor) {
                    cursor = newChainPtr;
                } else if (origChainPtr == aSequence.precursor) {
                    precursor = newChainPtr;
                }
                origChainPtr = origChainPtr->next;
            }
            newChainPtr->next = nullptr;
            tailPtr = newChainPtr;
        }
    }
}
