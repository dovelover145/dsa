#include <cassert> // For assert

namespace cs_stack {
    template <class ItemType>
    ArrayStack<ItemType>::ArrayStack() {
        items = new ItemType[DEFAULT_CAPACITY];
        capacity = DEFAULT_CAPACITY;
        numItems = 0;
    }





    template <class ItemType>
    bool ArrayStack<ItemType>::isEmpty() const {
        return numItems == 0;
    }





    template <class ItemType>
    void ArrayStack<ItemType>::push(const ItemType& newEntry) {
        if (numItems < capacity) {
            numItems++;
            items[numItems - 1] = newEntry;
        } else {
            capacity *= 2;
            ItemType* temp = new ItemType[capacity];
            for (int i = 0; i < numItems; i++) {
                temp[i] = items[i];
            }
            numItems++;
            temp[numItems - 1] = newEntry;
            delete [] items;
            items = temp;
            temp = nullptr;
        }
    }





    template <class ItemType>
    void ArrayStack<ItemType>::pop() {
        if (!isEmpty()) {
            numItems--;
        } else {
            throw StackEmptyError();
        }
        if (numItems < capacity / 2) {
            capacity /= 2;
            ItemType* temp = new ItemType[capacity];
            for (int i = 0; i < numItems; i++) {
                temp[i] = items[i];
            }
            delete [] items;
            items = temp;
            temp = nullptr;
        }
    }





    template <class ItemType>
    ItemType ArrayStack<ItemType>::top() const {
        if (!isEmpty()) {
            return items[numItems - 1];
        } else {
            throw StackEmptyError();
        }
    }





    template <class ItemType>
    ArrayStack<ItemType> ArrayStack<ItemType>::operator=(const ArrayStack<ItemType>& aStack) {
        if (this != &aStack) {
            delete [] items;
            items = new ItemType[aStack.capacity];
            capacity = aStack.capacity;
            numItems = aStack.numItems;
            for (int i = 0; i < aStack.numItems; i++) {
                items[i] = aStack.items[i];
            }
        }
        return *this;
    }





    template <class ItemType>
    ArrayStack<ItemType>::ArrayStack(const ArrayStack<ItemType>& aStack) {
        items = new ItemType[aStack.capacity];
        capacity = aStack.capacity;
        numItems = aStack.numItems;
        for (int i = 0; i < aStack.numItems; i++) {
            items[i] = aStack.items[i];
        }
    }




    
    template <class ItemType>
    ArrayStack<ItemType>::~ArrayStack() {
        delete [] items;
    }
}
