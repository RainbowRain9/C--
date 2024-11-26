/*
问题描述
定义一个学生类Student，类的成员包括：

1、name：姓名，string类型，私有

2、alias：别名，string类型，私有

3、构造函数Student(string, string)：初始化姓名和别名，并且输出“[name]'s constructor”，其中[name]要用具体的值

4、析构函数~Student()：输出“[name]'s destructor”，其中[name]要用具体的值

5、void print()函数：输出“[alias] is another name for [name]”，其中[name]和[alias]要用具体的值

规定主函数是如下代码（不可以修改），根据输入输出，设计Student类以满足要求

int main()
{
 string name, alias;
 cin >> name >> alias;
 Student s(name, alias);
 s.print();
 return 0;
}

输入描述
只有一组案例。字符串a、字符串b，分别表示学生的姓名和别名。

输出描述
[学生的姓名]'s constructor

[学生的别名] is another name for [学生的姓名]

[学生的姓名]'s destructor

每行输出结果后面都有换行。

样例输入
Elizabeth Lisa

样例输出
Elizabeth's constructor
Lisa is another name for Elizabeth
Elizabeth's destructor
*/

#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    string alias;

public:
    Student(string n, string a) : name(n), alias(a)
    {
        cout << name << "'s constructor" << endl;
    }
    ~Student()
    {
        cout << name << "'s destructor" << endl;
    }
    void print()
    {
        cout << alias << " is another name for " << name << endl;
    }
};
int main()
{
    string name, alias;
    cin >> name >> alias;
    Student s(name, alias);
    s.print();
    return 0;
}