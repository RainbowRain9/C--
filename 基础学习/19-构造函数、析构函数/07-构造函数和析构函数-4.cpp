/*
描述


把代码补充完整，定义一个Teletubbies类以实现要求的输出。

主函数如下：

int main()
{
 Teletubbies t1("Tinky Winky");
 Teletubbies t2("Dipsy");
 Teletubbies t3("Laa-Laa");
 Teletubbies t4("Po");
 t1.playwith(t4);
 t2.playwith(t3);
 return 0;
}


输入
无

输出
以下文字，最后一行后面也要换行。

Here comes Tinky Winky
Here comes Dipsy
Here comes Laa-Laa
Here comes Po
Tinky Winky is playing with Po
Dipsy is playing with Laa-Laa
Po says good night
Laa-Laa says good night
Dipsy says good night
Tinky Winky says good night


样例输入


样例输出
Here comes Tinky Winky
Here comes Dipsy
Here comes Laa-Laa
Here comes Po
Tinky Winky is playing with Po
Dipsy is playing with Laa-Laa
Po says good night
Laa-Laa says good night
Dipsy says good night
Tinky Winky says good night
*/

#include <iostream>
using namespace std;
class Teletubbies
{
private:
    string name;

public:
    Teletubbies(string n)
    {
        name = n;
        cout << "Here comes " << name << endl;
    }
    void playwith(Teletubbies &other)
    {
        cout << name << " is playing with " << other.name << endl;
    }

    ~Teletubbies()
    {
        cout << name << " says good night" << endl;
    }
};

int main()
{
    Teletubbies t1("Tinky Winky");
    Teletubbies t2("Dipsy");
    Teletubbies t3("Laa-Laa");
    Teletubbies t4("Po");
    t1.playwith(t4);
    t2.playwith(t3);
    return 0;
}