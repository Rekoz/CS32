//
//  Multiset.h
//  Homework1
//
//  Created by Yunong Jiang on 1/16/15.
//  Copyright (c) 2015 Rekoz. All rights reserved.
//

#ifndef __Homework1__Multiset__
#define __Homework1__Multiset__

#include <string>
using namespace std;

const int DEFAULT_MAX_ITEMS = 200;

typedef unsigned long ItemType;  // define Number as a synonym for int

class Multiset
{
public:
    Multiset();    // Create an empty multiset.
    ~Multiset();
    Multiset(const Multiset& src);
    Multiset &operator=(const Multiset& src);
    
    bool empty() const;// Return true if the multiset is empty, otherwise false.
    int size() const;
    int uniqueSize() const;
    bool insert(const ItemType& value);
    // Insert value into the multiset.  Return true if the value was
    // actually inserted.  Return false if the value was not inserted
    // (perhaps because the multiset has a fixed capacity and is full).
    
    int erase(const ItemType& value);
    // Remove one instance of value from the multiset if present.
    // Return the number of instances removed, which will be 1 or 0.
    
    int eraseAll(const ItemType& value);
    // Remove all instances of value from the multiset if present.
    // Return the number of instances removed.
    
    bool contains(const ItemType& value) const;
    // Return true if the value is in the multiset, otherwise false.
    
    int count(const ItemType& value) const;
    // Return the number of instances of value in the multiset.
    
    int get(int i, ItemType& value) const;
    // If 0 <= i < uniqueSize(), copy into value an item in the
    // multiset and return the number of instances of that item in
    // the multiset.  Otherwise, leave value unchanged and return 0.
    // (See below for details about this function.)
    
    void swap(Multiset& other);
    // Exchange the contents of this multiset with the other one.
    
    void dump() const;

    
private:
    struct itemAttribute
    {
        ItemType name;
        int count;
    };
    struct Node
    {
        itemAttribute items;
        Node *next, *prev;
    };
    int n, sum;
    Node *head;
};

void combine(const Multiset& ms1, const Multiset& ms2, Multiset& result);

void subtract(const Multiset& ms1, const Multiset& ms2, Multiset& result);

#endif /* defined(__Homework1__Multiset__) */
