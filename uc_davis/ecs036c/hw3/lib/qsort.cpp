#ifndef QSORT_CPP
#define QSORT_CPP

#include "qsort.hpp"
#include <iostream>
#include <cstdlib> // for rand

template <typename RandomAccessIter, typename Comparator>
void quick_sort(RandomAccessIter first, RandomAccessIter last, Comparator comparator)
{
    // Implement here
    std::function<RandomAccessIter(RandomAccessIter, RandomAccessIter, Comparator)> partition = [&](RandomAccessIter _first, RandomAccessIter _last, Comparator _comparator)
    {
        std::srand(std::time(0));
        int listLength = _first - _last;
        int randomNumber = std::rand() % listLength;
        RandomAccessIter _pivot = _first + randomNumber;
        std::swap(*_pivot, *(_last - 1));
        _pivot = _last - 1;
        RandomAccessIter swappingPlace = _first - 1;
        for (RandomAccessIter curPlace = _first; curPlace != _last; curPlace++)
        {
            if (_comparator(*curPlace, *_pivot) == true)
            { // *i < *_pivot
                swappingPlace++;
                std::swap(*curPlace, *swappingPlace);
            }
        }
        std::swap(*_pivot, *(swappingPlace + 1));
        return swappingPlace + 1;
    };
    if (first != last && first < last - 1)
    { // first != last, i.e., the list is not 0
        RandomAccessIter pivot = partition(first, last, comparator);
        quick_sort(first, pivot, comparator);
        quick_sort(pivot + 1, last, comparator);
    }
}

#endif
