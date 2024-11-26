/*
问题描述
定义一个学生类Student，类的成员包括：

1、name：姓名，string类型，私有

2、score：成绩，double类型，私有

3、构造函数Student(string, double)：初始化学生的姓名和成绩，并且输出“[name]'s constructor”，其中[name]要用具体的值。

4、析构函数~Student()：输出“[name]'s destructor”，其中[name]要用具体的值。

5、string getName()：返回姓名，公有

6、double getScore()函数：返回成绩，公有

把上一题主函数中的两个学生改成用学生类的数组定义，主函数略作修改

int main()

{
 string n1, n2;
 double a1, a2;
 cin >> n1 >> a1 >> n2 >> a2;
 //这行改为定义一个学生类的数组s，长度为2
 cout << s[0].getName() << " " << s[0].getScore() << endl;
 cout << s[1].getName() << " " << s[1].getScore() << endl;
 return 0;
}

输入描述
只有一组案例。字符串n1、浮点数a1、字符串n2、浮点数a2，分别表示第一个学生姓名和成绩、第二个学生姓名和成绩。

输出描述
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

提示说明
提示：假设...代表对象构造函数的参数列表，那么可以用以下不同的方法建立数组

Student s[2]={{...},{...}};

Student s[2]{{...},{...}};

Student s[2]={Student(...),Student(...)};
*/

#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    double score;

public:
    Student(string n, double s)
    {
        name = n;
        score = s;
        cout << name << "'s constructor" << endl;
    }
    ~Student()
    {
        cout << name << "'s destructor" << endl;
    }
    string getName()
    {
        return name;
    }
    double getScore()
    {
        return score;
    }
};
int main()
{
    string n1, n2;
    double a1, a2;
    cin >> n1 >> a1 >> n2 >> a2;
    // 这行改为定义一个学生类的数组s，长度为2
    Student s[2] = {Student(n1,a1), Student(n2,a2)};
    cout << s[0].getName() << " " << s[0].getScore() << endl;
    cout << s[1].getName() << " " << s[1].getScore() << endl;
    return 0;
}