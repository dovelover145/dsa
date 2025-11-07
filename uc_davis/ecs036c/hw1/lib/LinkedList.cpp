#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList() : _size(0), _head(nullptr), _tail(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&other) : _size(other._size),
                                                   _head(other._head),
                                                   _tail(other._tail)
{
    other._size = 0;
    other._head = nullptr;
    other._tail = nullptr;
}

// TODO: Implement all other methods defined in LinkedList.hpp here

/*
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other)
{
    if (other._size == 0)
    { // Case 1: Empty linked list
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    }
    else
    { // Case 2: Non-empty linked list
        LinkedListNode<T> *paramListPtr = other._head;

        _head = new LinkedListNode<T>(paramListPtr->value);
        LinkedListNode<T> *copiedListPtr = _head;

        paramListPtr = paramListPtr->_next;

        while (paramListPtr != nullptr)
        {
            copiedListPtr->_next = new LinkedListNode<T>(paramListPtr->value);
            copiedListPtr = copiedListPtr->_next;
            paramListPtr = paramListPtr->_next;
        }

        _tail = copiedListPtr;
        _size = other._size;
    }
}
*/

template <typename T>
LinkedList<T>::LinkedList(const std::vector<T> &items)
{
    int vectorSize = items.size();
    if (vectorSize == 0)
    {
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    }
    else
    {
        int index = 0;
        _head = new LinkedListNode<T>(items[index]);
        LinkedListNode<T> *listPtr = _head;
        index++;
        while (index < vectorSize)
        {
            listPtr->_next = new LinkedListNode<T>(items[index]);
            listPtr = listPtr->_next;
            index++;
        }
        _tail = listPtr;
        _size = vectorSize;
    }
}

template <typename T>
size_t LinkedList<T>::size() const
{
    return _size;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::head() const
{
    return _head;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::tail() const
{
    return _tail;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::find(T value) const
{
    LinkedListNode<T> *listPtr = _head;
    while (listPtr != nullptr && listPtr->value != value)
    {
        listPtr = listPtr->_next;
    }
    return listPtr;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::prepend(T value)
{
    LinkedListNode<T> *tempPtr = _head;
    _head = new LinkedListNode<T>(value);
    _head->_next = tempPtr;
    if (_size == 0)
    {
        _tail = _head;
    }
    _size++;
    return _head;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::append(T value)
{
    LinkedListNode<T> *tempPtr = _tail;
    _tail = new LinkedListNode<T>(value);
    if (tempPtr != nullptr)
    {
        tempPtr->_next = _tail;
    }
    else
    {
        _head = _tail;
    }
    _size++;
    return _tail;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::insertAfter(LinkedListNode<T> *node, T value)
{
    LinkedListNode<T> *newNodePtr;
    if (node == nullptr)
    {
        newNodePtr = prepend(value);
    }
    else
    {
        newNodePtr = new LinkedListNode(value);
        newNodePtr->_next = node->_next;
        node->_next = newNodePtr;
        if (node == _tail)
        {
            _tail = newNodePtr;
        }
        _size++;
    }
    return newNodePtr;
}

template <typename T>
std::optional<T> LinkedList<T>::removeHead()
{
    if (_size == 0)
    {
        return std::nullopt;
    }
    else
    {
        LinkedListNode<T> *deletePtr = _head;
        T value = deletePtr->value;
        _head = _head->_next;
        delete deletePtr;
        if (_size == 1)
        {
            _head = nullptr;
            _tail = nullptr;
        }
        _size--;
        return value;
    }
}

template <typename T>
bool LinkedList<T>::remove(T value)
{
    if (_head == nullptr)
    { // Case 1: The list is empty
        return false;
    }
    else
    {
        LinkedListNode<T> *listPtr = _head;
        if (listPtr->value == value)
        { // Case 2: The value is located in the first node
            LinkedListNode<T> *nodeToDeletePtr = listPtr;
            _head = _head->_next;
            delete nodeToDeletePtr;
            if (_size == 1)
            { // Subcase 2-1: The size of the list was 1
                _head == nullptr;
                _tail = nullptr;
            }
        }
        else
        { // The value could be somewhere else in the list (not in the first node)
            LinkedListNode<T> *prevPtr = listPtr;
            listPtr = listPtr->_next;
            while (listPtr != nullptr && listPtr->value != value)
            {
                prevPtr = listPtr;
                listPtr = listPtr->_next;
            }
            if (listPtr == nullptr)
            { // Case 3: The value is not in the list
                return false;
            }
            else
            { // Case 4: The value is in the list
                LinkedListNode<T> *nodeToDeletePtr = listPtr;
                prevPtr->_next = listPtr->_next;
                if (listPtr == _tail)
                { // Subcase 4-1: The value is located in the last node
                    _tail = prevPtr;
                }
                delete nodeToDeletePtr;
            }
        }
        _size--;
        return true;
    }
}

template <typename T>
void LinkedList<T>::clear()
{
    LinkedListNode<T> *listPtr = _head;
    LinkedListNode<T> *nodeToDeletePtr;
    while (listPtr != nullptr)
    {
        nodeToDeletePtr = listPtr;
        listPtr = listPtr->_next;
        delete nodeToDeletePtr;
    }
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

#endif
