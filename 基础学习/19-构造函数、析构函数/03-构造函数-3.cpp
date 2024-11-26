/*
描述
定义一个学生类Student，类的成员包括：

1、name：姓名，string类型，私有

2、score：成绩，double类型，私有

3、构造函数Student()：什么都不做

4、构造函数Student(string, double)：初始化学生的姓名和成绩

5、string getName()：返回姓名，公有

6、double getScore()函数：返回成绩，公有

规定主函数是如下代码（不可以修改），根据输入输出，设计Student类以满足要求。

int main()
{
 string n;
 double a;
 cin >> n >> a;
 Student s(n, a);
 cout << s.getName() << endl;
 cout << s.getScore() << endl;
 return 0;
}

输入
只有一组案例。字符串n和浮点数a，分别表示姓名和成绩。

输出
姓名，换行。

成绩，换行。

样例输入
Tom 80

样例输出
Tom

80
*/

#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string name;
    double score;

public:
    Student() {}
    Student(string n, double s) : name(n), score(s) {}
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
    string n;
    double a;
    cin >> n >> a;
    Student s(n, a);
    cout << s.getName() << endl;
    cout << s.getScore() << endl;
    return 0;
}