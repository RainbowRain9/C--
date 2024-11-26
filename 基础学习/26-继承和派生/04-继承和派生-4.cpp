/*
描述
把代码补充完整

#include<iostream>
#include<string>
using namespace std;
class Animal
{
public:
 Animal(string name)
 {
  this->name = name;
 }
 string name;
};
class Pet
{
public:
 Pet(double price)
 {
  this->price = price;
 }
 double price;
};
class Cat : public Animal, public Pet
{
public:
 //Cat类构造函数
 void cry()
 {
  cout << name << ": Miaow";
 }
};
int main()
{
 Cat cat1("Tom",1000);
 cat1.cry();
 return 0;
}


样例输出
Tom: Miaow
*/

#include <iostream>
#include <string>
using namespace std;
class Animal
{
public:
    Animal(string name)
    {
        this->name = name;
    }
    string name;
};
class Pet
{
public:
    Pet(double price)
    {
        this->price = price;
    }
    double price;
};
class Cat : public Animal, public Pet   
{
public:
    // Cat类构造函数
    Cat(string name_, double price_) : Animal(name_), Pet(price_) {}
    void cry()
    {
        cout << name << ": Miaow";
    }
};
int main()  
{
    Cat cat1("Tom", 1000);
    cat1.cry();
    return 0;
}
