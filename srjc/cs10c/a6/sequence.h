#include <iostream>

namespace cs_sequence {
    class Sequence {
        public:
            typedef size_t size_type;
            typedef int value_type;
            
            Sequence();
            // Postcondition: The Sequence has been initialized to an empty Sequence.
            
            void start();
            // Postcondition: The first item in the Sequence becomes the current item (but if the
            // Sequence is empty, then there is no current item).
            
            void advance();
            // Precondition: is_item() returns true
            // Postcondition: If the current item was already the last item in the Sequence, then there
            // is no longer any current item. Otherwise, the new current item is the item immediately after
            // the original current item.
            
            void insert(const value_type& entry);
            // Postcondition: A new copy of entry has been inserted in the Sequence before the
            // current item. If there was no current item, then the new entry has been inserted at the
            // front. In either case, the new item is now the current item of the Sequence.
            
            void attach(const value_type& entry);
            // Postcondition: A new copy of entry has been inserted in the Sequence after the current
            // item. If there was no current item, then the new entry has been attached to the end of
            // the Sequence. In either case, the new item is now the current item of the Sequence.
            
            void remove_current();
            // Precondition: is_item returns true.
            // Postcondition: The current item has been removed from the Sequence. If the item removed
            // was the last item in the Sequence, then there is now no current item. Otherwise, the item
            // that was after the removed item is now the current item.
            
            size_type size() const;
            // Postcondition: Returns the number of items in the Sequence.
            
            bool is_item() const;
            // Postcondition: A true return value indicates that there is a valid "current" item that
            // may be retrieved by the current member function (listed below). A false return value
            // indicates that there is no valid current item.
            
            value_type current() const;
            // Precondition: is_item() returns true
            // Postcondition: The current item in the Sequence is returned.
        
            ~Sequence();
            // Postcondition: The Sequence has been destroyed.
        
            Sequence(const Sequence& aSequence);
            // Postcondition: The Sequence has been initialized with the contents of aSequence.
        
            Sequence operator=(const Sequence& aSequence);
            // Postcondition: The Sequence is now the same as aSequence. The return value is the Sequence
            // that received the assignment.
            
        private:
            struct node {
                value_type data;
                node* next;
            };
            
            size_type numItems;
            node* headPtr;
            node* tailPtr;
            node* cursor;
            node* precursor;
            
            void clear();
            // Postcondition: The Sequence has had all of its content cleared.
        
            void copy(const Sequence& aSequence);
            // Postcondition: The Sequence is now a copy of aSequence.
    };
}
