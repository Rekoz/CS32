#include <iostream>
#include <string>
using namespace std;

class Character
{
public:
    Character(string name):m_name(name){}
    virtual ~Character(){}
    string name() const { return m_name; }
    virtual void printWeapon() const = 0;
    virtual string attackAction() const { return "rushes toward the enemy"; }
private:
    string m_name;
};

class Dwarf: public Character
{
public:
    Dwarf(string name):Character(name){}
    virtual ~Dwarf() { cout << "Destroying " << name() << " the dwarf" << endl; }
    virtual void printWeapon() const { cout << "an axe"; }
};

class Elf: public Character
{
public:
    Elf(string name, int n):Character(name), arrows(n){}
    virtual ~Elf() { cout << "Destroying " << name() << " the elf" << endl; }
    virtual void printWeapon() const { cout << "a bow and quiver of " << arrows << " arrows"; }
private:
    int arrows;
};

class Boggie: public Character
{
public:
    Boggie(string name):Character(name){}
    ~Boggie() { cout << "Destroying " << name() << " the Boggie" << endl; }
    virtual void printWeapon() const { cout << "a short sword"; }
    virtual string attackAction() const { return "whimpers"; }
};