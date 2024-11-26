
#include <iostream>
#include <string>
using namespace std;
class Cat
{
private:
    string name;

public:
    Cat(string name) : name(name) {}
    string getType()
    {
        return "cat";
    }
    string getName()
    {
        return name;
    }
};
class Mouse
{
private:
    string name;

public:
    Mouse(string name) : name(name) {}
    string getType()
    {
        return "mouse";
    }
    string getName()
    {
        return name;
    }
};
// Person类模板
template <typename T>
class Person
{
private:
    string name;
    T pet;

public:
    Person(string n, T *p) : name(n), pet(*p) {}
    void display()
    {
        cout << name << " has a pet " << pet.getType() << " named " << pet.getName() << "." << endl;
    }
};
int main()
{
    Cat c("Tom");
    Mouse m("Jerry");
    Person<Cat> p1("AAA", &c);
    Person<Mouse> p2("BBB", &m);
    p1.display();
    p2.display();
    return 0;
}