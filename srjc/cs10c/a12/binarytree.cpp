// Here is the file binarytree.cpp

#include <iostream>
#include "binarytree.h"
#include "LL.h"
using namespace std;





binarytree::binarytree() {
    root = nullptr;
    mSize = 0;
}





void binarytree::print() const {
    print_aux(root);
}





void binarytree::insert(int item) {
    insert_aux(root, item);
    mSize++;
}





binarytree::size_type binarytree::size() const {
    return mSize;
    // return size_aux(root);
}





int binarytree::find(int target, bool& found) const {
    return find_aux(root, target, found);
}





void binarytree::del(int target, bool& found) {
    del_aux(root, target, found);
    mSize--;
}





void binarytree::del_aux(treenode*& root, int target, bool& found) {
    if (root == nullptr) {
        found = false;
    } else if (target < root -> data) {
        del_aux(root -> left, target, found);
    } else if (target > root -> data) {
        del_aux(root -> right, target, found);
    } else if (root -> left == nullptr) {
        treenode* tempptr = root;
        root = root -> right;
        delete tempptr;
        found = true;
    } else {
        int max;
        remove_max(root -> left, max);
        root -> data = max;
        found = true;
    }
}





// pre: root != nullptr
void binarytree::remove_max(treenode*& root, int& max) {
    if (root -> right == nullptr) {
        max = root -> data;
        treenode* tempptr = root;
        root = root -> left;
        delete tempptr;
    } else {
        remove_max(root -> right, max);
    }
}





int binarytree::find_aux(const treenode* root, int target, bool& found) {
    if (root == nullptr) {
        found = false;
        return 0;
    } else if (target == root -> data) {
        found = true;
        return root -> data;
    } else if (target < root -> data) {
        return find_aux(root -> left, target, found);
    } else {
        return find_aux(root -> right, target, found);
    }
}





binarytree::size_type binarytree::size_aux(const treenode* root){
    if (root == nullptr) {
        return 0;
    } else {
        return size_aux(root -> left) + size_aux(root -> right) + 1;
    }
}





void binarytree::insert_aux(treenode*& root, int item) {
    if (root == nullptr) {
        root = new treenode;
        root -> data = item;
        root -> left = nullptr;
        root -> right = nullptr;
    } else if (item <= root -> data) {
        insert_aux(root -> left, item);
    } else {
        insert_aux(root -> right, item);
    }
}





void binarytree::print_aux(const treenode* root) {
    if (root != nullptr) {
        print_aux(root -> left);
        cout << root -> data << " ";
        print_aux(root -> right);
    }
}





int binarytree::numPrimes() const {
    return numPrimes_aux(root);
}





int binarytree::numPrimes_aux(const treenode* root) {
    if (root != nullptr) {
        int primeNumCount = primeNumChecker(root->data);
        primeNumCount += numPrimes_aux(root->left);
        primeNumCount += numPrimes_aux(root->right);
        return primeNumCount;
    }
    return 0;
}





int binarytree::primeNumChecker(int num) {
    int count = 0;
    num = abs(num);
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    if (count == 0 && (num != 0 && num != 1)) {
        return 1; // the number is a prime number
    } else {
        return 0; // the number is not a prime number
    }
}





LL<int> binarytree::toLL() const {
    LL<int> list;
    toLL_aux(root, list);
    return list;
}





void binarytree::toLL_aux(const treenode* root, LL<int>& list) {
    if (root != nullptr) {
        toLL_aux(root->right, list);
        list.push_front(root->data);
        toLL_aux(root->left, list);
    }
}





void binarytree::clear(treenode*& root) {
    if (root != nullptr) {
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}





void binarytree::copy(treenode*& copyRoot, const treenode* origRoot) {
    if (origRoot == nullptr) {
        copyRoot = nullptr;
    } else {
        copyRoot = new treenode;
        copyRoot->data = origRoot->data;
        copy(copyRoot->left, origRoot->left);
        copy(copyRoot->right, origRoot->right);
    }
}





binarytree::binarytree(const binarytree& binTree) {
    copy(root, binTree.root);
}





binarytree::~binarytree() {
    clear(root);
}





binarytree binarytree::operator=(const binarytree& binTree) {
    if (this != &binTree) {
        clear(root);
        copy(root, binTree.root);
    }
    return *this;
}
