#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"

template <typename T>
Stack<T>::Stack() {}

// TODO: Implement all other methods defined in Stack.hpp here

template <typename T>
Stack<T>::Stack(const std::vector<T> &items) {
    for (int i = 0; i < items.size(); i++) {
        _llist.prepend(items[i]);
    }
}

template <typename T>
size_t Stack<T>::size() const {
    return _llist.size();
}

template <typename T>
std::optional<T> Stack<T>::top() const {
    LinkedListNode<T> *stackTop = _llist.head();
    if (stackTop == nullptr) {
        return std::nullopt;
    } else {
        return stackTop->value;
    }
}

template <typename T>
void Stack<T>::push(T value) {
    _llist.prepend(value);
}

template <typename T>
std::optional<T> Stack<T>::pop() {
    std::optional<T> value = _llist.removeHead();
    return value;
}

#endif
