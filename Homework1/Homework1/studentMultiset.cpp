//
//  studentMultiset.cpp
//  Homework1
//
//  Created by Yunong Jiang on 1/16/15.
//  Copyright (c) 2015 Rekoz. All rights reserved.
//

#include "studentMultiset.h"
#include <iostream>
using namespace std;

StudentMultiset::StudentMultiset(){}       // Create an empty student multiset.

bool StudentMultiset::add(unsigned long id)
{
    return m.insert(id);
}
// Add a student id to the StudentMultiset.  Return true if and only
// if the id was actually added.

int StudentMultiset::size() const
{
    return m.size();
}
// Return the number of items in the StudentMultiset.  If an id was
// added n times, it contributes n to the size.

void StudentMultiset::print() const
{
    ItemType x;
    for (int i = 0; i < m.uniqueSize(); i++)
    {
        int y = m.get(i, x);
        for (int j = 0; j < y; j++)
            cout << x << endl;
    }
}
// Print to cout every student id in the StudentMultiset one per line;
// print as many lines for each id as it occurs in the StudentMultiset.