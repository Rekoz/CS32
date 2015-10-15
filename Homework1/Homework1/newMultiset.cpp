//
//  Multiset.cpp
//  Homework1
//
//  Created by Yunong Jiang on 1/16/15.
//  Copyright (c) 2015 Rekoz. All rights reserved.
//

#include "newMultiset.h"
#include <cstdlib>
#include <iostream>

Multiset::Multiset():n(0), capacity(DEFAULT_MAX_ITEMS)
{
    items = new itemAttribute[capacity];
}

Multiset::Multiset(int maxNum):n(0), capacity(maxNum)
{
    if (maxNum < 0)
    {
        cout << "Array size is negative" << endl;
        exit(1);
    }
    items = new itemAttribute[capacity];
}

Multiset::~Multiset()
{
    delete [] items;
}

Multiset::Multiset(const Multiset& src)
{
    n = src.n;
    capacity = src.capacity;
    items = new itemAttribute[capacity];
    for (int i = 0; i < capacity; i++)
    {
        items[i] = src.items[i];
    }
}

Multiset& Multiset::operator=(const Multiset& src)
{
    if (this == &src) return (*this);
    n = src.n;
    capacity = src.capacity;
    delete []items;
    items = new itemAttribute[capacity];
    for (int i = 0; i < capacity; i++)
    {
        items[i] = src.items[i];
    }
    return (*this);
}

bool Multiset::empty() const
{
    if (n == 0) return true; else return false;
}// Return true if the multiset is empty, otherwise false.

int Multiset::size() const
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += items[i].count;
    return sum;
}
// Return the number of items in the multiset.  For example, the size
// of a multiset containing "cumin", "cumin", "cumin", "turmeric" is 4.

int Multiset::uniqueSize() const
{
    return n;
}
// Return the number of distinct items in the multiset.  For example,
// the uniqueSize of a multiset containing "cumin", "cumin", "cumin",
// "turmeric" is 2.

bool Multiset::insert(const ItemType& value)
{
    for (int i = 0; i < n; i++)
        if (items[i].name == value)
        {
            items[i].count++;
            return true;
        }
    if (n == capacity) return false;
    items[n].name = value;
    items[n].count = 1;
    n++;
    return true;
}
// Insert value into the multiset.  Return true if the value was
// actually inserted.  Return false if the value was not inserted
// (perhaps because the multiset has a fixed capacity and is full).

int Multiset::erase(const ItemType& value)
{
    for (int i = 0; i < n; i++)
        if (items[i].name == value)
        {
            if (items[i].count > 0)
            {
                items[i].count--;
                if (items[i].count == 0)
                {
                    n--;
                    for (int j = i; j < n; j++)
                        items[j] = items[j+1];
                }
                return 1;
            }
            else
                return 0;
        }
    return 0;
}
// Remove one instance of value from the multiset if present.
// Return the number of instances removed, which will be 1 or 0.

int Multiset::eraseAll(const ItemType& value)
{
    for (int i = 0; i < n; i++)
        if (items[i].name == value)
        {
            int m = items[i].count;
            n--;
            for (int j = i; j < n; j++)
            items[j] = items[j+1];
            return m;
        }
    return 0;
}
// Remove all instances of value from the multiset if present.
// Return the number of instances removed.

bool Multiset::contains(const ItemType& value) const
{
    for (int i = 0; i < n; i++)
        if (items[i].name == value)
            return true;
    return false;
}
// Return true if the value is in the multiset, otherwise false.

int Multiset::count(const ItemType& value) const
{
    for (int i = 0; i < n; i++)
        if (items[i].name == value)
            return items[i].count;
    return 0;
}
// Return the number of instances of value in the multiset.

int Multiset::get(int i, ItemType& value) const
{
    if (i >= 0 && i < uniqueSize())
    {
        value = items[i].name;
        return items[i].count;
    }
    else
        return 0;
}
// If 0 <= i < uniqueSize(), copy into value an item in the
// multiset and return the number of instances of that item in
// the multiset.  Otherwise, leave value unchanged and return 0.
// (See below for details about this function.)

void Multiset::swap(Multiset& other)
{
    int temp = n;
    n = other.n;
    other.n = temp;
    temp = capacity;
    capacity = other.capacity;
    other.capacity = temp;
    itemAttribute *p = items;
    items = other.items;
    other.items = p;
}
// Exchange the contents of this multiset with the other one.