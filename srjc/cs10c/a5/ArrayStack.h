#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "StackInterface.h"

namespace cs_stack {
    template <class ItemType>
    class ArrayStack : public StackInterface<ItemType> {
        private:
            static const int DEFAULT_CAPACITY = 1;
            ItemType* items;
            int capacity;
            int numItems;
        public:
            class CapacityExceededError {};
            class StackEmptyError {};
            ArrayStack();
            bool isEmpty() const;
            void push(const ItemType& newEntry);
            void pop();
            ItemType top() const;
            ArrayStack<ItemType> operator=(const ArrayStack<ItemType>& aStack);
            ArrayStack(const ArrayStack<ItemType>& aStack);
            ~ArrayStack();
    };
}

#include "ArrayStack.cpp"

#endif
