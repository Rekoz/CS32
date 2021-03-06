#include "newMultiset.h"
#include <cassert>
#include <iostream>

int main()
{
    Multiset a(1000);   // a can hold at most 1000 distinct items
    Multiset b(5);      // b can hold at most 5 distinct items
    Multiset c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
    ItemType v[6] = { 10, 20, 30, 40, 50, 60 };
    // No failures inserting 5 distinct items twice each into b
    for (int k = 0; k < 5; k++)
    {
        assert(b.insert(v[k]));
        assert(b.insert(v[k]));
    }
    assert(b.size() == 10  &&  b.uniqueSize() == 5  &&  b.count(v[0]) == 2);
    // Failure if we try to insert a sixth distinct item into b
    assert(!b.insert(v[5]));
    
    // When two Multisets' contents are swapped, their capacities are swapped
    // as well:
    a.swap(b);
    assert(!a.insert(v[5])  &&  b.insert(v[5]));
    
    Multiset d = a;
    assert(d.count(v[0]) == 2 && d.size() == 10 && d.uniqueSize() == 5);
    
    c = a;
    assert(c.count(v[0]) == 2 && c.size() == 10 && c.uniqueSize() == 5);
    
    cout << "Passed all tests" << endl;
}