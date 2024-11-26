/*
描述
利用以下部分代码，要求不修改主函数、Cat类，实现Dog类，必须保证输出结果与样例输出相同。

class Cat

{

private:

    string name;

    int age;

public:

    Cat(string name, int age) :name(name), age(age)

    {

        cout << "Create a cat named " << name << "." << endl;

    }

    ~Cat()

    {

        cout << "Destroy a cat named " << name << "." << endl;

    }

    void setName(string name)

    {

        this->name = name;

    }

    string getName()

    {

        return name;

    }

    void display()

    {

        cout << name << " " << age << endl;

    }

};

int main()

{

    Cat c("Tom", 10);

    Dog d("Pluto");

    d.playwith(c);

    return 0;

}

输入
无

输出
参照【样例输出】，最后一行输出完有换行。

样例输入


样例输出
Create a cat named Tom.

Create a dog named Pluto.

Pluto is playing with Tom.

Destroy a dog named Pluto.

Destroy a cat named Tom.

*/

#include <iostream>
using namespace std;

class Cat
{
private:
    string name;

    int age;

public:
    Cat(string name, int age) : name(name), age(age)
    {
        cout << "Create a cat named " << name << "." << endl;
    }

    ~Cat()
    {
        cout << "Destroy a cat named " << name << "." << endl;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};

class Dog
{
private:
    string name;

public:
    Dog(string name) : name(name)
    {
        cout << "Create a dog named " << name << "." << endl;
    }

    ~Dog()
    {
        cout << "Destroy a dog named " << name << "." << endl;
    }

    void playwith(Cat &c)
    {
        cout << name << " is playing with " << c.getName() << "." << endl;
    }
};

int main()

{

    Cat c("Tom", 10);

    Dog d("Pluto");

    d.playwith(c);

    return 0;
}