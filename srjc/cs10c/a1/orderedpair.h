#ifndef ORDEREDPAIR_H
#define ORDEREDPAIR_H

#include <iostream>

/* precondition for setFirst and setSecond: the argument cannot be such that the values of
first and second will become equal, unless the argument is equal to DEFAULT_VALUE.
*/

namespace cs_pairs {
    template <class T>
    class OrderedPair {
        public:
            class DuplicateMemberError {};
            static const T DEFAULT_VALUE;
            OrderedPair(T newFirst = DEFAULT_VALUE, T newSecond = DEFAULT_VALUE);
            void setFirst(T newFirst);
            void setSecond(T newSecond);
            T getFirst() const;
            T getSecond() const;
            OrderedPair operator+(const OrderedPair &right) const;
            bool operator<(const OrderedPair &right) const;
            void print() const;
        private:
            T first;
            T second;
    };
}

#include "orderedpair.cpp"

#endif
