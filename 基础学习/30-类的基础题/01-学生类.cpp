/*
问题描述
定义一个学生类Student：

1、具有两个属性

（1）name：姓名，string类，私有

（2）score：3门课的成绩，长度为3的int数组，私有

2、具有四个方法

（1）void setName(string name)：根据参数值设置姓名属性，公有

（2）string getName()：返回姓名，公有

（3）void setScore(int score[ ])：根据参数值（存放3门课成绩的数组）设置成绩属性，公有

（4）int getScore()：返回3门课的总成绩，公有

在主函数中输入学生的姓名（不会有空格）和成绩，调用类的2个set方法进行设置。然后调用类的2个get方法输出学生的姓名和总成绩。

输入描述
一个正整数n，表示n组案例。

每组案例由一个字符串和三个整数组成。

输出描述
针对每组案例，输出学生的姓名和总成绩，中间隔一个空格。

每组案例输出完都要换行。

样例输入
2

Tom 80 80 80

Jerry 100 100 100

样例输出
Tom 240

Jerry 300
*/

#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int score[3];

public:
    void setName(string n)
    {
        name = n;
    }
    void setScore(int s[3])
    {
        for (int i = 0; i < 3; i++)
        {
            score[i] = s[i];
        }
    }
    string getName()
    {
        return name;
    }

    int getScore()
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += score[i];
        }
        return sum;
    }
};

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        Student s;
        string name;
        cin >> name;
        int score[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> score[i];
        }
        s.setName(name);
        s.setScore(score);
        cout << s.getName() << " " << s.getScore() << endl;
    }
    return 0;
}