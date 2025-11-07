#ifndef TREE_SET_CPP
#define TREE_SET_CPP

#include "TreeSet.hpp"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
TreeSet<T>::TreeSet() : _root(nullptr), _size(0)
{
    _comparator = [](T left, T right)
    {
        if (left < right)
        {
            return -1;
        }
        else if (left > right)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };
}

// TODO: Implement all methods defined in TreeSet.hpp here

template <typename T>
TreeSet<T>::TreeSet(const std::vector<T> &items)
{
    _comparator = [](T left, T right)
    {
        if (left < right)
        {
            return -1;
        }
        else if (left > right)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };
    _root = nullptr;
    _size = 0;
    for (int i = 0; i < items.size(); i++)
    {
        add(items[i]);
    }
}

template <typename T>
TreeSet<T>::TreeSet(std::function<int(T, T)> comparator) : _root(nullptr), _size(0)
{
    _comparator = comparator;
}

template <typename T>
TreeSet<T>::TreeSet(const std::vector<T> &items, std::function<int(T, T)> comparator)
{
    _comparator = comparator;
    _root = nullptr;
    _size = 0;
    for (int i = 0; i < items.size(); i++)
    {
        add(items[i]);
    }
}

template <typename T>
size_t TreeSet<T>::size() const
{
    return _size;
}

template <typename T>
void TreeSet<T>::add(T value)
{
    bool duplicateItem = false;
    if (_root == nullptr)
    {
        _root = new BinaryTreeNode<T>(value, Red);
        fix_violation(_root);
    }
    else
    {
        BinaryTreeNode<T> *tempPtr = _root;
        BinaryTreeNode<T> *prevPtr;
        while (tempPtr != nullptr && !duplicateItem)
        {
            prevPtr = tempPtr;
            if (_comparator(tempPtr->value, value) == 1) // tempPtr->value > value
            {
                tempPtr = tempPtr->_left;
            }
            else if (_comparator(tempPtr->value, value) == -1) // tempPtr->value < value
            {
                tempPtr = tempPtr->_right;
            }
            else
            {
                tempPtr->value = value;
                duplicateItem = true;
            }
        }
        if (_comparator(prevPtr->value, value) == 1) // prevPtr->value > value
        {
            prevPtr->_left = new BinaryTreeNode<T>(value, Red);
            prevPtr->_left->_parent = prevPtr;
            fix_violation(prevPtr->_left);
        }
        else if (_comparator(prevPtr->value, value) == -1) // prevPtr->value < value
        {
            prevPtr->_right = new BinaryTreeNode<T>(value, Red);
            prevPtr->_right->_parent = prevPtr;
            fix_violation(prevPtr->_right);
        }
    }
    if (!duplicateItem)
    {
        _size++;
    }
}

template <typename T>
bool TreeSet<T>::contains(T value) const
{
    BinaryTreeNode<T> *containingTreeNode = _root;
    bool found = false;
    while (containingTreeNode != nullptr && !found)
    {
        if (_comparator(containingTreeNode->value, value) == 1) // containingTreeNode->value > value
        {
            containingTreeNode = containingTreeNode->_left;
        }
        else if (_comparator(containingTreeNode->value, value) == -1) // containingTreeNode->value < value
        {
            containingTreeNode = containingTreeNode->_right;
        }
        else
        {
            found = true;
        }
    }
    return found;
}

template <typename T>
bool TreeSet<T>::is_empty() const
{
    return _size == 0;
}

template <typename T>
std::optional<T> TreeSet<T>::min() const
{
    if (_root != nullptr)
    {
        BinaryTreeNode<T> *minTreeNode = _root;
        while (minTreeNode->_left != nullptr)
        {
            minTreeNode = minTreeNode->_left;
        }
        return minTreeNode->value;
    }
    else
    {
        return std::nullopt;
    }
}

template <typename T>
std::optional<T> TreeSet<T>::max() const
{
    if (_root != nullptr)
    {
        BinaryTreeNode<T> *maxTreeNode = _root;
        while (maxTreeNode->_right != nullptr)
        {
            maxTreeNode = maxTreeNode->_right;
        }
        return maxTreeNode->value;
    }
    else
    {
        return std::nullopt;
    }
}

template <typename T>
std::vector<T> TreeSet<T>::to_vector() const
{
    std::vector<T> resultantVector;
    std::function<void(BinaryTreeNode<T> *)> vectorize_aux = [&](BinaryTreeNode<T> *treeNode)
    {
        if (treeNode != nullptr)
        {
            vectorize_aux(treeNode->_left);
            resultantVector.push_back(treeNode->value);
            vectorize_aux(treeNode->_right);
        }
    };
    vectorize_aux(_root);
    return resultantVector;
}

template <typename T>
std::optional<T> TreeSet<T>::get(T value) const
{
    bool found = contains(value);
    if (found)
    {
        return value;
    }
    else
    {
        return std::nullopt;
    }
}

template <typename T>
TreeSet<T> TreeSet<T>::operator+(const TreeSet<T> &other)
{
    TreeSet<T> unionSet;
    std::vector<T> set1 = this->to_vector();
    std::vector<T> set2 = other.to_vector();
    for (int i = 0; i < set1.size(); i++)
    {
        unionSet.add(set1[i]);
    }
    for (int i = 0; i < set2.size(); i++)
    {
        unionSet.add(set2[i]);
    }
    return unionSet;
}

template <typename T>
TreeSet<T> &TreeSet<T>::operator+=(const TreeSet<T> &other)
{
    std::vector<T> set2 = other.to_vector();
    for (int i = 0; i < set2.size(); i++)
    {
        this->add(set2[i]);
    }
    return *this;
}

template <typename T>
TreeSet<T> TreeSet<T>::operator&(const TreeSet<T> &other)
{
    TreeSet<T> intersectionSet;
    std::vector<T> set2 = other.to_vector();
    for (int i = 0; i < set2.size(); i++)
    {
        if (contains(set2[i]))
        {
            intersectionSet.add(set2[i]);
        }
    }
    return intersectionSet;
}

template <typename T>
bool TreeSet<T>::operator==(const TreeSet<T> &other) const
{
    int counter = 0;
    std::vector<T> set2 = other.to_vector();
    for (int i = 0; i < set2.size(); i++)
    {
        if (contains(set2[i]))
        {
            counter++;
        }
    }
    return _size == set2.size() && counter == set2.size();
}

template <typename T>
bool TreeSet<T>::operator!=(const TreeSet<T> &other) const
{
    return !(*this == other);
}

template <typename T>
void TreeSet<T>::clear()
{
    std::function<void(BinaryTreeNode<T> *&)> clear_aux = [&](BinaryTreeNode<T> *&treeNode)
    {
        if (treeNode != nullptr)
        {
            clear_aux(treeNode->_left);
            clear_aux(treeNode->_right);
            delete treeNode;
            treeNode = nullptr;
        }
    };
    clear_aux(_root);
    _size = 0;
}

template <typename T>
TreeSet<T>::~TreeSet()
{
    clear();
}

template <typename T>
void TreeSet<T>::fix_violation(BinaryTreeNode<T> *z)
{
    while (z->_parent != nullptr && z->_parent->_color == Red)// z's parent is not black, but red
    {
        if ((z->_parent->_parent != nullptr && z->_parent->_parent->_left != nullptr) && z->_parent == z->_parent->_parent->_left)
        {
            BinaryTreeNode<T> *y = z->_parent->_parent->_right;
            if (y != nullptr && y->_color == Red)
            {
                z->_parent->_color = Black;
                y->_color = Black;
                z->_parent->_parent->_color = Red;
                z = z->_parent->_parent;
            }
            else
            {
                if (z == z->_parent->_right)
                {
                    z = z->_parent;
                    rotate_left(z);
                }
                z->_parent->_color = Black;
                z->_parent->_parent->_color = Red;
                rotate_right(z->_parent->_parent);
            }
        }
        else if ((z->_parent->_parent != nullptr && z->_parent->_parent->_right != nullptr) && z->_parent == z->_parent->_parent->_right)
        {
            BinaryTreeNode<T> *y = z->_parent->_parent->_left;
            if (y != nullptr && y->_color == Red)
            {
                z->_parent->_color = Black;
                y->_color = Black;
                z->_parent->_parent->_color = Red;
                z = z->_parent->_parent;
            }
            else
            {
                if (z == z->_parent->_left)
                {
                    z = z->_parent;
                    rotate_right(z);
                }
                z->_parent->_color = Black;
                z->_parent->_parent->_color = Red;
                rotate_left(z->_parent->_parent);
            }
        }
    }
    _root->_color = Black;
}

template <typename T>
void TreeSet<T>::rotate_left(BinaryTreeNode<T> *x)
{
    BinaryTreeNode<T> *y = x->_right;
    x->_right = y->_left;
    if (y->_left != nullptr)
    {
        y->_left->_parent = x;
    }
    y->_parent = x->_parent;
    if (x->_parent == nullptr)
    {
        _root = y;
    }
    else if (x == x->_parent->_left)
    {
        x->_parent->_left = y;
    }
    else
    {
        x->_parent->_right = y;
    }
    y->_left = x;
    x->_parent = y;
}

template <typename T>
void TreeSet<T>::rotate_right(BinaryTreeNode<T> *y)
{
    BinaryTreeNode<T> *x = y->_left;
    y->_left = x->_right;
    if (x->_right != nullptr)
    {
        x->_right->_parent = y;
    }
    x->_parent = y->_parent;
    if (y->_parent == nullptr)
    {
        _root = x;
    }
    else if (y == y->_parent->_right)
    {
        y->_parent->_right = x;
    }
    else
    {
        y->_parent->_left = x;
    }
    x->_right = y;
    y->_parent = x;
}

#endif
