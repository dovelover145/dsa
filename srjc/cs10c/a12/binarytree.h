// Here is the file binarytree.h

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cstdlib> // for size_t
#include "LL.h"

class binarytree {
    public:
        typedef std::size_t size_type;
        binarytree();
        void insert(int item);
        void print() const;
        size_type size() const;
        int find(int target, bool& found) const;
        void del(int target, bool& found);
        int numPrimes() const;
        LL<int> toLL() const;
        binarytree(const binarytree& binTree);
        ~binarytree();
        binarytree operator=(const binarytree& binTree);
    public:
        struct treenode {
            int data;
            treenode* left;
            treenode* right;
        };

        treenode* root;
        size_type mSize;
        
        static void insert_aux(treenode*& root, int item);
        static void print_aux(const treenode* root);
        static size_type size_aux(const treenode* root);
        static int find_aux(const treenode* root, int target, bool& found);
        static void del_aux(treenode*& root, int target, bool& found);
        static void remove_max(treenode*& root, int& max);
        static int numPrimes_aux(const treenode* root);
        static int primeNumChecker(int num);
        static void toLL_aux(const treenode* root, LL<int>& list);
        static void clear(treenode*& root);
        static void copy(treenode*& copyRoot, const treenode* origRoot);
};

#endif

