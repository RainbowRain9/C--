/*
描述
定义一个学生类Student，类的成员包括：

1、name：姓名，string类型，私有

2、score：成绩，double类型，私有

3、构造函数Student(string, double)：初始化学生的姓名和成绩，并且输出“[name]'s constructor”，其中[name]要用具体的值。

4、拷贝构造函数Student(Student &)：根据参数学生的姓名和成绩，初始化学生的姓名和成绩，其中名字前面多个C，成绩相同。例如参数的姓名叫Tom，成绩是90，则初始化的姓名是CTom，成绩也是90。还要输出“[name]'s copy constructor”，其中[name]要用加C后的具体值。

5、析构函数~Student()：输出“[name]'s destructor”，其中[name]要用具体的值。

6、void display()函数：输出学生的姓名和成绩，中间有一个空格，最后要换行。

规定主函数是如下代码（不可以修改），根据输入输出，设计Student类以满足要求。

int main()
{
 string n1, n2;
 double a1, a2;
 cin >> n1 >> a1 >> n2 >> a2;
 Student s[2] = { {n1,a1},{n2,a2} };
 Student t = s[0];
 s[0].display();
 s[1].display();
 t.display();
 return 0;
}

输入
只有一组案例。字符串n1、浮点数a1、字符串n2、浮点数a2，分别表示第一个学生姓名和成绩、第二个学生姓名和成绩。

输出
[第一个学生的姓名]'s constructor

[第二个学生的姓名]'s constructor

[第一个学生的拷贝的姓名]'s copy constructor

[第一个学生的姓名][空格][第一个学生的成绩]

[第二个学生的姓名][空格][第二个学生的成绩]

[第一个学生的拷贝的姓名][空格][第一个学生的拷贝的成绩]

[第一个学生的拷贝的姓名]'s destructor

[第二个学生的姓名]'s destructor

[第一个学生的姓名]'s destructor

每行输出结果后面都有换行。

样例输入
AAA 10

BBB 20

样例输出
AAA's constructor
BBB's constructor
CAAA's copy constructor
AAA 10
BBB 20
CAAA 10
CAAA's destructor
BBB's destructor
AAA's destructor

提示说明
用Student类型的B对象拷贝构造A对象时，以下两种写法都是一样触发拷贝构造

Student A=B;

Student A(B);

但如果定义和构造分开写，只能是

Student A;

A=B;
*/

#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    double score;

public:
    Student(string n, double s) : name(n), score(s)
    {
        cout << name << "'s constructor" << endl;
    }
    Student(Student &other)
    {
        name = 'C' + other.name;
        score = other.score;
        cout << name << "'s copy constructor" << endl;
    }
    ~Student()
    {
        cout << name << "'s destructor" << endl;
    }
    void display()
    {
        cout << name << " " << score << endl;
    }
};

int main()
{
    string n1, n2;
    double a1, a2;
    cin >> n1 >> a1 >> n2 >> a2;
    Student s[2] = {{n1, a1}, {n2, a2}};
    Student t = s[0];
    s[0].display();
    s[1].display();
    t.display();
    return 0;
}