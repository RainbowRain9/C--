/*
描述
把以下代码的主程序部分的对象数组定义，改造成用对象指针定义。不要修改Student类。

#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
 string name;
 int score;
public:
 Student(string name, int score) :name(name), score(score)
 {}
 void print()
 {
  cout << name << " " << score << endl;
 }
};
int main()
{
 Student p[3] { { "AAA",80 },{ "BBB",90 },{ "CCC",100 } }; //把这句改写成用对象指针new 3个对象
 for (int i = 0; i < 3; i++)
 {
  p[i].print(); //这句也改成用指针访问
 }
 return 0;
}


输入
无

输出
以下文字，最后一行后面也要换行。

AAA 80
BBB 90
CCC 100



样例输入


样例输出
AAA 80
BBB 90
CCC 100
*/

#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string name;
    int score;

public:
    Student(string name, int score) : name(name), score(score)
    {
    }
    void print()
    {
        cout << name << " " << score << endl;
    }
};
int main()
{
    Student *p = new Student[3]{Student("AAA", 80), Student("BBB", 90), Student("CCC", 100)};

    // 用指针访问对象并调用print函数
    for (int i = 0; i < 3; i++)
    {
        p[i].print();
    }

    // 释放动态分配的内存
    delete[] p;
    return 0;
}
