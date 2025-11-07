#include <iostream>

template <class ItemType>
ArrayQueue<ItemType>::ArrayQueue() {
    capacity = DEFAULT_CAPACITY;
    items = new ItemType[DEFAULT_CAPACITY];
    front = 0;
    back = DEFAULT_CAPACITY - 1;
    numItems = 0;
}





template <class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const {
    return numItems == 0;
}





template <class ItemType>
void ArrayQueue<ItemType>::enqueue(const ItemType& newEntry) {
    if (numItems < capacity) { // there is room for another entry in the array
        back = (back + 1) % capacity;
        items[back] = newEntry;
        numItems++;
    } else { // the array is full, so double its capacity
        ItemType *temp = new ItemType[capacity * 2];
        
        int counter = 0;
        for (int i = front; i != back; i = (i + 1) % capacity) {
            temp[counter] = items[i];
            counter++;
        }
        temp[counter] = items[back];
        
        capacity *= 2;
        delete [] items;
        items = temp;
        items[counter + 1] = newEntry;
        front = 0;
        back = counter + 1;
        numItems++;
    }
}





template <class ItemType>
void ArrayQueue<ItemType>::dequeue() {
    if (isEmpty()) {
        throw PrecondViolatedExcep("dequeue() called with empty queue");
    }
    front = (front + 1) % capacity;
    numItems--;
    if (numItems < capacity / 2) { // make the array smaller
        ItemType *temp = new ItemType[capacity / 2];
        
        int counter = 0;
        for (int i = front; i != back; i = (i + 1) % capacity) {
            temp[counter] = items[i];
            counter++;
        }
        temp[counter] = items[back];
        
        capacity /= 2;
        delete [] items;
        items = temp;
        front = 0;
        back = counter;
    }
}





template <class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const {
    if (isEmpty()) {
        throw PrecondViolatedExcep("peekFront() called with empty queue");
    }
    return items[front];
}





template <class ItemType>
void ArrayQueue<ItemType>::print() const {
    std::cout << "Here is the queue: ";
    if (isEmpty()) {
        std::cout << "empty";
    } else {
        for (int i = front; i != back; i = (i + 1) % capacity) {
            std::cout << items[i] << " ";
        }
        std::cout << items[back];
    }
}





template <class ItemType>
ArrayQueue<ItemType>::ArrayQueue(const ArrayQueue<ItemType>& anAQ) {
    copy(anAQ);
}





template <class ItemType>
ArrayQueue<ItemType> ArrayQueue<ItemType>::operator=(const ArrayQueue<ItemType>& anAQ) {
    if (this != &anAQ) {
        delete [] items;
        copy(anAQ);
    }
    return *this;
}





template <class ItemType>
ArrayQueue<ItemType>::~ArrayQueue() {
    delete [] items;
}





template <class ItemType>
void ArrayQueue<ItemType>::copy(const ArrayQueue<ItemType>& anAQ) {
    capacity = anAQ.capacity;
    items = new ItemType[anAQ.capacity];
    front = anAQ.front;
    back = anAQ.back;
    numItems = anAQ.numItems;
    
    for (int i = anAQ.front; i != anAQ.back; i = (i + 1) % anAQ.capacity) {
        items[i] = anAQ.items[i];
    }
    items[back] = anAQ.items[back];
}
