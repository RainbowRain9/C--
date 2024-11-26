/*
描述
把Pet类和ExtinctAnimal类都设计成Animal类的派生类，以实现如下的输出。其他地方不得添加代码。

#include<iostream>
#include<string>
using namespace std;
class Animal
{
private:
 string name;
public:
 Animal(string n)
 {
  name = n;
 }
 ~Animal()
 {
  cout << name << " is destroyed." << endl;
 }
 string getName()
 {
  return name;
 }
};

//①这里应该是Pet类的定义

//②这里应该是ExtinctAnimal类的定义

int main()
{
 Pet p("Jerry", 100);
 ExtinctAnimal a1("dinosaur", -65000000);
 ExtinctAnimal a2("Dodo", 1681);
 p.show();
 a1.show();
 a2.show();
 return 0;
}
样例输入


样例输出
Create a pet named Jerry.
Create an ancient animal named dinosaur.
Create an ancient animal named Dodo.
Jerry's price is 100.
The extinction time of dinosaur is 65000000 B.C.E.
The extinction time of Dodo is 1681 C.E.
Dodo is destroyed.
dinosaur is destroyed.
Jerry is destroyed.
*/

#include <iostream>
#include <string>
using namespace std;
class Animal
{
private:
    string name;

public:
    Animal(string n)
    {
        name = n;
    }
    ~Animal()
    {
        cout << name << " is destroyed." << endl;
    }
    string getName()
    {
        return name;
    }
};

// ①这里应该是Pet类的定义
class Pet : public Animal
{
private:
    int price;

public:
    Pet(string name_,int price_) : price(price_), Animal(name_) 
    {
        cout << "Create a pet named " << getName() << "." << endl;
    }
    void show()
    {
        cout << getName() << "'s price is " << price << "." << endl;
    }
};
// ②这里应该是ExtinctAnimal类的定义
class ExtinctAnimal : public Animal
{
public:
    long age;
    ExtinctAnimal(string name, long age) : Animal(name), age(age)
    {
        cout << "Create an ancient animal named " << getName() << "." << endl;
    }
    void show()
    {
        string m = age > 0 ? " C.E" : " B.C.E";
        cout << "The extinction time of " << getName() << " is " << abs(age) << m << "." << endl;
    }
};

int main()
{
    Pet p("Jerry", 100);
    ExtinctAnimal a1("dinosaur", -65000000);
    ExtinctAnimal a2("Dodo", 1681);
    p.show();
    a1.show();
    a2.show();
    return 0;
}