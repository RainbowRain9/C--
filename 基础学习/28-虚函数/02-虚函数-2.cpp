/*
描述
在Animal类中添加一个名字为cry的纯虚函数，并完成Cat类的定义，Cat类是Animal类的派生类。

#include<iostream>
#include<string>
using namespace std;
class Animal
{
protected:
 string name;
 int age;
public:
 Animal(string name,int age):name(name),age(age){}
 virtual void eat()
 {
  cout << name << " is eating." << endl;
 }
 void display()
 {
  cout << name << " " << age << endl;
 }
 //纯虚函数cry
};
//Cat类的定义
int main()
{
 Cat c("Tom", 10, "Black");
 c.eat();
 c.cry();
 c.display();
 cout << "----------" << endl;
 Animal *d = new Cat("Garfield", 20, "Yellow");
 d->eat();
 d->cry();
 d->display();
 return 0;
}


样例输入


样例输出
Tom is eating fish.
Tom: Miaow
Name: Tom, Age: 10, Colour: Black
----------
Garfield is eating fish.
Garfield: Miaow
Garfield 20
*/

#include <iostream>
#include <string>
using namespace std;
class Animal
{
protected:
    string name;
    int age;

public:
    Animal(string name, int age) : name(name), age(age) {}
    virtual void eat()
    {
        cout << name << " is eating." << endl;
    }
    void display()
    {
        cout << name << " " << age << endl;
    }
    // 纯虚函数cry
    virtual void cry()
    {
        cout << name << ": Miaow" << endl;
    }
};
// Cat类的定义
class Cat : public Animal
{
protected:
    string color;

public:
    Cat(string name, int age, string color) : Animal(name, age), color(color) {}
    void eat()override
    {
        cout << name << " is eating fish." << endl;
    }
    void cry()override
    {
        cout << name << ": Miaow" << endl;
    }
    void display()
    {
        cout << "Name: " << name << ", Age: " << age << ", Colour: " << color << endl;
    }
};
int main()
{
    Cat c("Tom", 10, "Black");
    c.eat();
    c.cry();
    c.display();
    cout << "----------" << endl;
    Animal *d = new Cat("Garfield", 20, "Yellow");
    d->eat();
    d->cry();
    d->display();
    return 0;
}
