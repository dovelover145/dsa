// Here is the file simplelist.cpp

#include <iostream>
#include "simplelist.h"
using namespace std;

namespace harden_list {
    SimpleList::SimpleList() {
        list = nullptr;
    }

    void SimpleList::insert(const value_type& insertMe) {
        node* temp = new node;
        temp -> data = insertMe;
        temp -> next = list;
        list = temp;
    }

    void SimpleList::print() const {
        node* tempPtr = list;
        while (tempPtr != nullptr) {
            cout << tempPtr -> data << " ";
            tempPtr = tempPtr -> next;
        }
    }

    SimpleList::size_type SimpleList::size() const {
        size_type count = 0;
        node* tempPtr = list;
        while (tempPtr != nullptr) {
            count++;
            tempPtr = tempPtr -> next;
        }
        return count;
    }

    SimpleList::value_type SimpleList::find(const value_type& findMe, bool& found) const {
        node* curPtr = list;
        while (curPtr != nullptr && curPtr -> data != findMe) {
            curPtr = curPtr -> next;
        }
        
        // assert: curPtr -> data == findMe || curPtr == nullptr
        
        if (curPtr != nullptr) {
            found = true;
            return curPtr -> data;
        } else {
            found = false;
            return value_type();
        }
    }

    /* ALTERNATE VERSION OF FIND()

    SimpleList::value_type SimpleList::find(const value_type& findMe, bool& found) const {
        node* curPtr = list;
        while (curPtr != nullptr) {
            if (curPtr -> data == findMe) {
                found = true;
                return curPtr -> data;
            }
            curPtr = curPtr -> next;
        }
        found = false;
        return value_type();
    }
    
    */

    void SimpleList::del(const value_type& deleteMe, bool& found) {
        node* prevPtr = list;
        if (list == nullptr) {
            found = false;
        } else if (list -> data == deleteMe) {
            node* tempPtr = list;
            list = list -> next;
            delete tempPtr;
            found = true;
        } else {
            while (prevPtr -> next != nullptr && prevPtr -> next -> data != deleteMe) {
                prevPtr = prevPtr -> next;
            }
            if (prevPtr -> next == nullptr) {
                found = false;
            } else {
                node* tempPtr = prevPtr -> next;
                prevPtr -> next = prevPtr -> next -> next;
                delete tempPtr;
                found = true;
            }
        }
    }

    SimpleList::SimpleList(const SimpleList& copyMe) {
        clone(copyMe);
    }

    SimpleList SimpleList::operator=(const SimpleList& right) {
        if (this != &right) {
            clear();
            clone(right);
        }
        return *this;
    }

    SimpleList::~SimpleList() {
        clear();
    }

    void SimpleList::clear() {
        node* tempPtr = list;
        while (tempPtr != nullptr) {
            list = list -> next;
            delete tempPtr;
            tempPtr = list;
        }
    }

    // Note: This function looks really long, but most of it is the explanations that
    // I have added.  There are 13 lines of actual code.

    void SimpleList::clone(const SimpleList& copyMe) {
        if (copyMe.list == nullptr) {
            list = nullptr;
        } else {
        
            // 1. Copy the first node in the original list
            
            list = new node;
            list -> data = copyMe.list -> data;

            // 2. Get sourcePtr and newListPtr set up to copy the remaining nodes:
            // 2a. newListPtr should always point to the last node we created in the new list
            // 2b. sourcePtr should always point to the next node to be copied in the original list
                        
            node* newListPtr = list;
            node* sourcePtr = copyMe.list -> next;
            
            // 3. Now copy the rest of the list
            
            while (sourcePtr != nullptr) {
            
                // 3a. Add a new node to the end of the new list
                // 3b. Move newListPtr down to the newly added node (to meet rule 2a above)
                // 3c. Populate the newly added node
                // 3d. Advance sourcePtr to the next node to be copied in the original list
                //     (to meet rule 2b above)

                newListPtr -> next = new node;
                newListPtr = newListPtr -> next;
                newListPtr -> data = sourcePtr -> data;
                sourcePtr = sourcePtr -> next;
            }
            
            // 4. Make sure the list ends with a nullptr
            
            newListPtr -> next = nullptr;
        }
    }
}

/*
void SimpleList::clone(const SimpleList &copyMe) {
    if (copyMe.list = nullptr) {
        list = nullptr;
    } else {
        list = new node;
        list->data = copyMe.list->data;

        node *newListPtr = list;
        node *sourcePtr = copyMe.list->next;
        while (sourcePtr != nullptr) {
            newListPtr->next = new node;
            newListPtr = newListPtr->next;
            newListPtr->data = sourcePtr->data;
            sourcePtr = sourcePtr->next;
        }
        newListPtr->next = nullptr;
    }
}
*/