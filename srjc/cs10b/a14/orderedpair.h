#ifndef ORDEREDPAIR_H
#define ORDEREDPAIR_H

#include <iostream>

/*

precondition for setFirst and setSecond: the argument cannot be such that the values of
first and second will become equal, unless the argument is equal to DEFAULT_VALUE.

*/


namespace cs_pairs {
    template <class T>
    class OrderedPair {
        public:
            // Use the first of the following two lines to make the non-templated version work.
            // Switch to the second one when you begin converting to a templated version.
            
            // static const int DEFAULT_VALUE = int();
            static const T DEFAULT_VALUE;
        
            class DuplicateMemberError {};

            OrderedPair(T newFirst = DEFAULT_VALUE, T newSecond = DEFAULT_VALUE);
            void setFirst(T newFirst);
            void setSecond(T newSecond);
            T getFirst() const;
            T getSecond() const;
            OrderedPair operator+(const OrderedPair& right) const;
            bool operator<(const OrderedPair& right) const;
            void print() const;
        private:
            T first;
            T second;
    };


    // Leave the following const declaration commented out when you are testing the non-templated
    // version. Uncomment it when you begin converting to a templated version.
    // The templated version will require a template prefix as well as some minor edits to the code.
    
    template <class T>
    const T OrderedPair<T>::DEFAULT_VALUE = T();
}

#include "orderedpair.cpp"

#endif