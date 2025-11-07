/*

Ibrahim Siddiqui
CS 10C
David Harden
Assignment 3.1 and 3.2
6 September 2022

*/

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing 1-1.
    @file setinterface.h */

#ifndef SETINTERFACE_H
#define SETINTERFACE_H

#include <vector>

namespace cs_set {
    template <class ItemType>
    class SetInterface {
        public:
           /** Gets the current number of entries in this set.
            @return  The integer number of entries currently in the set. */
           virtual int getCurrentSize() const = 0;
       
           /** Sees whether this set is empty.
            @return  True if the set is empty, or false if not. */
           virtual bool isEmpty() const = 0;
       
           /** Adds a new entry to this set (as long as it's not a duplicate).
            @post  If successful, a newEntry is stored in the set and
               the count of items in the set has increased by 1.
            @param newEntry  The object to be added as a new entry. */
           virtual void add(const ItemType& newEntry) = 0;
       
           /** Removes one occurrence of a given entry from this set,
               if possible.
            @post  If successful, anEntry has been removed from the set
               and the count of items in the set has decreased by 1.
            @param anEntry  The entry to be removed. */
           virtual void remove(const ItemType& anEntry) = 0;
       
           /** Removes all entries from this set.
            @post  Set contains no items, and the count of items is 0. */
           virtual void clear() = 0;
       
           /** Tests whether this set contains a given entry.
            @param anEntry  The entry to locate.
            @return  True if set contains anEntry, or false otherwise. */
           virtual bool contains(const ItemType& anEntry) const = 0;
       
           /** Empties and then fills a given vector with all entries that
               are in this set.
            @return  A vector containing all the entries in the set. */
           virtual std::vector<ItemType> toVector() const = 0;
       
           /** Destroys this set and frees its assigned memory. (See C++ Interlude 2.) */
           virtual ~SetInterface() {}
    };
}

#endif
