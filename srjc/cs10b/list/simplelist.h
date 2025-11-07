// Here is the file simplelist.h

#ifndef SIMPLELIST_H
#define SIMPLELIST_H
#include <cstdlib>

namespace harden_list {
    class SimpleList {
        public:
            typedef std::size_t size_type;
            typedef int value_type;
            SimpleList();
            void insert(const value_type& insertMe);
            void print() const;
            size_type size() const;
            value_type find(const value_type& findMe, bool& found) const;
            void del(const value_type& deleteMe, bool& found);
            void clear();
            void clone(const SimpleList& cloneMe);
            SimpleList(const SimpleList& copyMe);
            SimpleList operator=(const SimpleList& right);
            ~SimpleList();
        private:
            struct node {
                value_type data;
                node* next;
            };
            node* list;
    };
}

#endif
