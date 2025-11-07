#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include "QueueInterface.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
class ArrayQueue : public QueueInterface<ItemType> {
    public:
        ArrayQueue();
        bool isEmpty() const;
        void enqueue(const ItemType& newEntry);
        void dequeue();
        ItemType peekFront() const;
        void print() const;
        ArrayQueue(const ArrayQueue<ItemType>& anAQ);
        ArrayQueue<ItemType> operator=(const ArrayQueue<ItemType>& anAQ);
        ~ArrayQueue();
    public:
        static const int DEFAULT_CAPACITY = 1;
        int capacity;
        ItemType* items;
        int front;
        int back;
        int numItems;
        void copy(const ArrayQueue<ItemType>& anAQ);
};

#include "ArrayQueue.cpp"

#endif
