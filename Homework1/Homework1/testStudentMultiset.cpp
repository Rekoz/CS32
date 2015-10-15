#include "studentMultiset.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    StudentMultiset a;
    assert(a.size() == 0);
    a.print();
    assert(a.add(1234567890));
    assert(a.add(1234567890));
    assert(a.add(1234));
    assert(a.add(5678));
    assert(a.size() == 4);
    a.print();
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}