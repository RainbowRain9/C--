/*
描述
补充Person类的定义，需要定义成类模板

#include<iostream>
#include<string>
using namespace std;
class Cat
{
private:
 string name;
public:
 Cat(string name) :name(name) {}
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
 Mouse(string name) :name(name) {}
 string getType()
 {
  return "mouse";
 }
 string getName()
 {
  return name;
 }
};
//Person类模板
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


输入
无

输出
AAA has a pet cat named Tom.
BBB has a pet mouse named Jerry.


样例输入


样例输出
AAA has a pet cat named Tom.
BBB has a pet mouse named Jerry.
*/
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
    string pname;
    T *pet;

public:
    Person(string pname, T *pet) : pname(pname), pet(pet) {}
    void display()
    {
        cout << pname << " has a pet " << pet->getType() << " named " << pet->getName() << "." << endl;
    }
};
{
int main()
    Cat c("Tom");
    Mouse m("Jerry");
    Person<Cat> p1("AAA", &c);
    Person<Mouse> p2("BBB", &m);
    p1.display();
    p2.display();
    return 0;
}