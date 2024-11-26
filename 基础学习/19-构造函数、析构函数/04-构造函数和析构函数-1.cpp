/*
描述
定义一个学生类Student，类的成员包括：

1、name：姓名，string类型，私有

2、score：成绩，double类型，私有

3、构造函数Student(string, double)：初始化学生的姓名和成绩，并且输出“[name]'s constructor”，其中[name]要用具体的值。

4、析构函数~Student()：输出“[name]'s destructor”，其中[name]要用具体的值。

5、string getName()：返回姓名，公有

6、double getScore()函数：返回成绩，公有

规定主函数是如下代码（不可以修改），根据输入输出，设计Student类以满足要求。

int main()
{
 string n1, n2;
 double a1, a2;
 cin >> n1 >> a1 >> n2 >> a2;
 Student s1(n1, a1), s2(n2, a2);
 cout << s1.getName() << " " << s1.getScore() << endl;
 cout << s2.getName() << " " << s2.getScore() << endl;
 return 0;
}

输入
只有一组案例。字符串n1、浮点数a1、字符串n2、浮点数a2，分别表示第一个学生姓名和成绩、第二个学生姓名和成绩。

输出
[第一个学生的姓名]'s constructor

[第二个学生的姓名]'s constructor

[第一个学生的姓名][空格][第一个学生的成绩]

[第二个学生的姓名][空格][第二个学生的成绩]

[第二个学生的姓名]'s destructor

[第一个学生的姓名]'s destructor

每行输出结果后面都有换行。


样例输入
Tom 80 Jerry 85

样例输出
Tom's constructor
Jerry's constructor
Tom 80
Jerry 85
Jerry's destructor
Tom's destructor
*/

#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    double score;

public:
    Student(string name_, double score_) : name(name_), score(score_)
    {
        cout << name << "'s constructor" << endl;
    }

    ~Student()
    {
        cout << name << "'s destructor" << endl;
    }
    string getName() { return name; }

    double getScore() { return score; }
};

int main()
{
    string n1, n2;
    double a1, a2;
    cin >> n1 >> a1 >> n2 >> a2;
    Student s1(n1, a1), s2(n2, a2);
    cout << s1.getName() << " " << s1.getScore() << endl;
    cout << s2.getName() << " " << s2.getScore() << endl;
    return 0;
}