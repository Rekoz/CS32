#include "Multiset.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Multiset t1;
    
    
    
    //Empty Function works
    
    assert(t1.empty());
    
    assert(t1.size() == 0);
    
    assert(t1.uniqueSize() == 0);
    
    assert(t1.erase(123) == 0);
    
    assert(t1.eraseAll(123) == 0);
    
    
    
    //Insert Function works
    
    assert(t1.insert(1));
    
    assert(t1.insert(2));
    
    assert(t1.insert(1));
    
    
    
    //check size & uniqueSize & count functions
    
    assert(!t1.empty());
    
    assert(t1.size() == 3);
    
    assert(t1.uniqueSize() == 2);
    
    assert(t1.count(1)==2 && t1.count(2) == 1);
    
    
    
    //check erase Function
    
    assert(t1.erase(1) == 1);
    
    assert(t1.size() == 2);
    
    assert(t1.uniqueSize() == 2);
    
    assert(t1.erase(1) == 1);
    
    assert(t1.size() == 1);
    
    assert(t1.uniqueSize() ==1);
    
    assert(t1.eraseAll(2) == 1);
    
    
    
    //check eraseAll function
    
    assert(t1.insert(1));
    
    assert(t1.insert(2));
    
    assert(t1.insert(1));
    
    assert(t1.eraseAll(1) == 2);
    
    assert(t1.size() == 1);
    
    assert(t1.uniqueSize() ==1);
    
    t1.eraseAll(2);
    
    
    
    t1.insert(1);
    
    t1.insert(5);
    
    t1.insert(6);
    
    t1.insert(5);
    
    t1.insert(3);
    
    t1.insert(3);
    
    t1.insert(5);
    
    t1.insert(1);
    
    assert(t1.uniqueSize() == 4 && t1.size() == 8);
    
    
    
    
    
    ItemType value1, value2;
    
    
    
    
    
    
    
    
    
    //Check Get Function & Copy Constructor & Count Function
    
    Multiset temp1(t1);
    
    for(int i = 0; i < t1.uniqueSize();i++){
        
        assert((t1.get(i, value1) == t1.count(value1)) ==  (temp1.get(i, value2) == temp1.count(value2)));
        
        value1 = value2;
        
    }
    
    assert(t1.size()==temp1.size() && t1.uniqueSize()==temp1.uniqueSize());
    
    
    
    
    
    
    
    
    
    //Check Copy Assingment Operator
    
    Multiset t2;
    
    t2.insert(23);
    
    t2.insert(33);
    
    t2.insert(88);
    
    t2.insert(99);
    
    t2.insert(24);
    
    t2.insert(2993);
    
    t2.insert(99);
    
    t2.insert(99);
    
    t2.insert(23);
    
    t2.insert(27);
    
    t2.insert(21);
    
    t2.insert(11);
    
    t2 = t1;
    
    for(int i = 0; i < t1.uniqueSize();i++){
        
        assert((t1.get(i, value1) == t1.count(value1)) == (temp1.get(i, value2) == temp1.count(value2)));
        
        value1 = value2;
        
    }
    
    assert(t1.size()==temp1.size() && t1.uniqueSize()==temp1.uniqueSize());
    
    
    
    
    
    
    
    
    
    //Check for aliasing on copy constructor
    
    t1 = t1;
    
    for(int i = 0; i < t1.uniqueSize();i++){
        
        assert((t1.get(i, value1) == t1.count(value1)) == (t1.get(i, value2) == t1.count(value2)));
        
        value1 = value2;
        
    }
    
    Multiset t3;
    
    t3.insert(23);
    
    t3.insert(33);
    
    t3.insert(88);
    
    t3.insert(99);
    
    t3.insert(24);
    
    t3.insert(2993);
    
    t3.insert(99);
    
    t3.insert(99);
    
    t3.insert(23);
    
    t3.insert(27);
    
    t3.insert(21);
    
    t3.insert(11);
    
    Multiset temp3(t3);
    
    
    
    
    
    //Check swap function (t1 = temp1; t3 = temp3)
    
    t1.swap(t3); //so t1 should = temp3. t3 should = temp1
    
    
    
    for(int i = 0; i < temp3.uniqueSize();i++){
        
        assert((t1.get(i, value1) == t1.count(value1)) == (temp3.get(i, value2) == temp3.count(value2)));
        
        value1 = value2;
        
    }
    
    assert(t1.size()==temp3.size() && t1.uniqueSize()==temp3.uniqueSize());
    
    
    
    for(int i = 0; i < temp1.uniqueSize();i++){
        
        assert((t3.get(i, value1) == t3.count(value1)) == (temp1.get(i, value2) == temp1.count(value2)));
        
        value1 = value2;
        
    }
    
    assert(t3.size()==temp1.size() && t3.uniqueSize()==temp1.uniqueSize());
    
    
    
    
    
    
    
    
    
    
    
    //Check Combine Function
    
    Multiset t4, t5, t6, temp6;
    
    temp6.insert(11);
    
    temp6.insert(22);
    
    temp6.insert(33);
    
    temp6.insert(44);
    
    temp6.insert(55);
    
    temp6.insert(66);
    
    temp6.insert(77);
    
    
    
    t4.insert(11);
    
    t4.insert(22);
    
    t4.insert(33);
    
    t4.insert(44);
    
    
    
    t5.insert(55);
    
    t5.insert(66);
    
    t5.insert(77);
    
    
    
    
    
    combine(t4, t5, t6);
    
    
    
    for(int i = 0; i < temp6.uniqueSize();i++){
        
        assert(t6.get(i, value1) == t6.count(value1) == temp6.get(i, value2) == temp6.count(value2));
        
        value1 = value2;
        
    }
    
    
    
    //Check Subtract Function
    
    Multiset t7, t8, t9, temp9;
    
    temp9.insert(22);
    
    temp9.insert(33);
    
    
    
    t7.insert(11);
    
    t7.insert(22);
    
    t7.insert(22);
    
    t7.insert(33);
    
    
    
    t8.insert(11);
    
    t8.insert(22);
    
    t8.insert(47);
    
    t8.insert(11);
    
    t8.insert(11);
    
    
    
    subtract(t7, t8, t9);
    
    
    
    for(int i = 0; i < temp9.uniqueSize();i++){
        
        assert(t9.get(i, value1) == t9.count(value1) == temp9.get(i, value2) == temp9.count(value2));
        
        value1 = value2;
        
    }
    
    
    
    //Check for Aliasing in both subtract & combine
    
    Multiset temp10, temp11;
    
    //temp 10: combination of 2 temp9’s
    
    temp10.insert(22);
    
    temp10.insert(22);
    
    temp10.insert(33);
    
    temp10.insert(33);
    
    
    
    combine(temp9, temp9, temp9);
    
    for(int i = 0; i < temp9.uniqueSize();i++){
        
        assert((temp9.get(i, value1) == temp9.count(value1)) == (temp10.get(i, value2) == temp10.count(value2)));
        
        value1 = value2;
    }
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}