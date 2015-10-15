#include "Multiset.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Multiset ulms;
    assert(ulms.insert(20));
    assert(ulms.insert(10));
    assert(ulms.insert(20));
    assert(ulms.insert(30));
    assert(ulms.insert(20));
    assert(ulms.insert(10));
    assert(ulms.size() == 6  &&  ulms.uniqueSize() == 3);
    assert(ulms.count(10) == 2);
    assert(ulms.count(20) == 3);
    assert(ulms.count(30) == 1);
    assert(ulms.count(40) == 0);
    
    ItemType x;
    assert(ulms.get(0, x) == 3 && x == 20);
    assert(ulms.get(0, x) == 3 && x == 20); // test get
    
    Multiset b = ulms;
    assert(b.insert(20));
    b.swap(ulms);
    assert(ulms.count(20) == 4 && ulms.size()== 7); // test swap
    
    assert(b.eraseAll(20) == 3);
    assert(b.erase(20) == 0);
    assert(b.erase(10) == 1);
    assert(b.erase(30) == 1);
    assert(b.uniqueSize() == 1);
    assert(b.size() == 1);
    assert(b.contains(10)); // test erase
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}