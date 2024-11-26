/*
描述
根据主函数以及输入输出要求，定义猫类Cat

int main()
{
    Cat c1("Tom"), c2("Kitty"), c3("Garfield");
    c1.playwith(c2);
    c2.playwith(c1);
    c3.playwith();
    return 0;
}

输入
无

输出
输出的是以下三行文字，最后一行后也有换行。

Tom is playing with Kitty
Kitty is playing with Tom
Garfield is playing alone


样例输入


样例输出
Tom is playing with Kitty
Kitty is playing with Tom
Garfield is playing alone
*/

#include <iostream>
#include <string>
using namespace std;

class Cat
{
private:
    string name;

public:
    Cat(string name_) : name(name_) {}
    void playwith(Cat &c)
    {
        cout << name << " is playing with " << c.name << endl;
    }

    void playwith()
    {
        cout << name << " is playing alone" << endl;
    }
};

int main()
{
    Cat c1("Tom"), c2("Kitty"), c3("Garfield");
    c1.playwith(c2);
    c2.playwith(c1);
    c3.playwith();
    return 0;
}