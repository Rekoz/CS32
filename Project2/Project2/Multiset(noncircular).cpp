//
//  Multiset.cpp
//  Homework1
//
//  Created by Yunong Jiang on 1/16/15.
//  Copyright (c) 2015 Rekoz. All rights reserved.
//

#include "Multiset.h"
#include <iostream>

Multiset::Multiset():n(0), sum(0)
{
    head = tail = nullptr;
}

Multiset::~Multiset()
{
    Node *p = head;
    while (p != nullptr)
    {
        Node *q = p->next;
        delete p;
        p = q;
    }
}

Multiset::Multiset(const Multiset& src)
{
    n = src.n;
    sum = src.sum;
    Node *p = src.head;
    if (src.head == nullptr)
    {
        head = tail = nullptr;
    } // in case src is empty
    Node *q;
    while (p != nullptr)
    {
        Node *r = new Node;
        if (p == src.head)
        {
            q = head = tail = r;
            q->prev = nullptr;
            q->next = nullptr;
        }
        else
        {
            q->next = r;
            r->prev = q;
            r->next = nullptr;
            tail = r;
        }
        r->items.name = p->items.name;
        r->items.count = p->items.count;
        q = r;
        p = p->next;
    }
}

Multiset& Multiset::operator=(const Multiset& src)
{
    if (this == &src) return (*this);
    n = src.n;
    sum = src.sum;
    Node *p = head;
    while (p != nullptr)
    {
        //cerr << p->items.name << endl;
        Node *q = p->next;
        delete p;
        p = q;
    }
    p = src.head;
    if (src.head == nullptr)
    {
        head = tail = nullptr;
    } // in case src is empty
    Node *q;
    while (p != nullptr)
    {
        Node *r = new Node;
        if (p == src.head)
        {
            q = head = tail = r;
            q->prev = nullptr;
            q->next = nullptr;
        }
        else
        {
            q->next = r;
            r->prev = q;
            r->next = nullptr;
            tail = r;
        }
        r->items.name = p->items.name;
        r->items.count = p->items.count;
        q = r;
        p = p->next;
    }
    return (*this);
}

bool Multiset::empty() const
{
    if (n == 0) return true;
    else return false;
}// Return true if the multiset is empty, otherwise false.

int Multiset::size() const
{
    return sum;
}
// Return the number of items in the multiset.  For example, the size
// of a multiset containing 20, 20, 20, 10 is 4.

int Multiset::uniqueSize() const
{
    return n;
}
// Return the number of distinct items in the multiset.  For example,
// the uniqueSize of a multiset containing 20, 20, 20,
// 10 is 2.

bool Multiset::insert(const ItemType& value)
{
    Node *p = head;
    while (p != nullptr)
    {
        if (p->items.name == value)
        {
            p->items.count++;
            sum++;
            return true;
        }
        p = p->next;
    }
    p = new Node;
    if (head == nullptr)
        head = tail = p;
    else
        tail->next = p;
    p->items.name = value;
    p->items.count = 1;
    p->next = nullptr;
    p->prev = tail;
    tail = p;
    n++;sum++;
    return true;
}
// Insert value into the multiset.  Return true if the value was
// actually inserted.  Return false if the value was not inserted
// (perhaps because the multiset has a fixed capacity and is full).

int Multiset::erase(const ItemType& value)
{
    Node *p = head;
    while (p != nullptr)
    {
        if (p->items.name == value)
        {
            p->items.count--;
            sum--;
            if (p->items.count == 0)
            {
                n--;
                if (p == tail && p == head)
                    head = tail = nullptr;
                else
                if (p == tail)
                {
                    p->prev->next = nullptr;
                    tail = p->prev;
                }
                else
                if (p == head)
                {
                    head = p->next;
                    p->next->prev = nullptr;
                }
                else
                {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                }
                delete p;
            }
            return 1;
        }
        p = p->next;
    }
    return 0;
}
// Remove one instance of value from the multiset if present.
// Return the number of instances removed, which will be 1 or 0.

int Multiset::eraseAll(const ItemType& value)
{
    Node *p = head;
    while (p != nullptr)
    {
        if (p->items.name == value)
        {
            int m = p->items.count;
            sum -= m;
            n--;
            if (p == tail && p == head)
                head = tail = nullptr;
            else
            if (p == tail)
                tail = p->prev;
            else
            if (p == head)
                head = p->next;
            else
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            delete p;
            return m;
        }
        p = p->next;
    }
    return 0;
}
// Remove all instances of value from the multiset if present.
// Return the number of instances removed.

bool Multiset::contains(const ItemType& value) const
{
    Node *p = head;
    while (p != nullptr)
    {
        if (p->items.name == value)
            return true;
        p = p->next;
    }
    return false;
}
// Return true if the value is in the multiset, otherwise false.

int Multiset::count(const ItemType& value) const
{
    Node *p = head;
    while (p != nullptr)
    {
        if (p->items.name == value)
            return p->items.count;
        p = p->next;
    }
    return 0;
}
// Return the number of instances of value in the multiset.

int Multiset::get(int i, ItemType& value) const
{
    if (i<0 || i>=uniqueSize())
        return 0;
    Node *p = head;
    int m = 0;
    while (p != nullptr)
    {
        if (m < i)
        {
            m++;
            p = p->next;
        }
        else break;
    }
    value = p->items.name;
    return p->items.count;
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
    temp = sum;
    sum = other.sum;
    other.sum = temp;
    Node *p = head;
    head = other.head;
    other.head = p;
    p = tail;
    tail = other.tail;
    other.tail = p;
}
// Exchange the contents of this multiset with the other one.

void Multiset::dump() const
{
    Node *p = head;
    while (p != nullptr)
    {
        cerr << p->items.name << ' ' << p->items.count << endl;
        p = p->next;
    }
}

void combine(const Multiset& ms1, const Multiset& ms2, Multiset& result)
{
    ItemType x;
    result = ms1;
    for (int i = 0; i < ms2.uniqueSize(); i++)
    {
        int n = ms2.get(i, x);
        for (int j = 0; j < n; j++)
            result.insert(x);
    }
}

void subtract(const Multiset& ms1, const Multiset& ms2, Multiset& result)
{
    ItemType x;
    result = ms1;
    for (int i = 0; i < ms2.uniqueSize(); i++)
    {
        int n = ms2.get(i, x);
        for (int j = 0; j < n; j++)
            result.erase(x);
    }
}