/*
描述
把代码补充完整（共两处，分别标有//①和//②），以实现如下要求的输出。根据提示写代码，其他地方不得添加代码。

1、把代码补充完整（共两处，分别标有//①和//②），以实现如下要求的输出。根据提示写代码，其他地方不得添加代码。
#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
 string name;
 int score;
 //①这里应当是构造函数
};
//②这里应当是show函数的定义
int main()
{
 Student s[] = { Student("Tom", 80),
  Student("Jerry", 95),
  Student("Garfield", 85)
 };
 show(s[0], s[1]);
 show(s[1], s[2]);
 return 0;
}

输入
无

输出
Tom's score is 80.
Jerry's score is 95.
Garfield's score is 85.
Tom's score is 15 lower than Jerry's.
Jerry's score is 10 higher than Garfield's.


样例输入


样例输出
Tom's score is 80.
Jerry's score is 95.
Garfield's score is 85.
Tom's score is 15 lower than Jerry's.
Jerry's score is 10 higher than Garfield's.
*/

#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    string name;
    int score;
    Student(string n, int s) : name(n), score(s)
    {
        cout << name << "'s score is " << s << "." <<  endl;
    }
};
void show(const Student &s1, const Student &s2)
{
    if (s1.score > s2.score)
    {
        cout << s1.name << "'s score is " << s1.score - s2.score << " higher than " << s2.name << "'s." << endl;
    }
    else
    {
        cout << s1.name << "'s score is " << s2.score - s1.score << " lower than " << s2.name << "'s." << endl;
    }
}

int main()
{
    Student s[] = {Student("Tom", 80),
                   Student("Jerry", 95),
                   Student("Garfield", 85)};
    show(s[0], s[1]);
    show(s[1], s[2]);
    return 0;
}
