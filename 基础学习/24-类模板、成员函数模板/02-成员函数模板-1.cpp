/*
描述
把以下代码中Cat类中两个重载的playwith成员函数统一写成一个函数模板，同样地，把Mouse类中两个重载的playwith成员函数统一写成一个函数模板。其余代码不必修改。


输入
无

输出
Tom is playing with Garfield.
Garfield is playing with Jerry.
Jerry is playing with Mickey.
Mickey is playing with Tom.


样例输入


样例输出
Tom is playing with Garfield.
Garfield is playing with Jerry.
Jerry is playing with Mickey.
Mickey is playing with Tom.
*/

#include <iostream>
#include <string>
using namespace std;
class Mouse;
class Cat
{
public:
    string name;
    Cat(string);
    template <typename T>
    void playwith(T &other)
    {
        cout << name << " is playing with " << other.name << "." << endl;
    }
};
class Mouse
{
public:
    string name;
    Mouse(string);
    template <typename T>
    void playwith(T &other)
    {
        cout << name << " is playing with " << other.name << "." << endl;
    }
};
Cat::Cat(string name) : name(name) {}
Mouse::Mouse(string name) : name(name) {}
int main()
{
    Cat c1("Tom"), c2("Garfield");
    Mouse m1("Jerry"), m2("Mickey");
    c1.playwith(c2);
    c2.playwith(m1);
    m1.playwith(m2);
    m2.playwith(c1);
    return 0;
}