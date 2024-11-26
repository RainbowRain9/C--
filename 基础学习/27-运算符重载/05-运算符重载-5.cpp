/*
描述
把代码补充完整

#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
 string name;
 int grade, score;
public:
 //可能需要补充友元声明、运算符重载
};
//可能需要补充运算符重载
int main()
{
 int n;
 cin >> n;
 while (n--)
 {
  Student s;
  cin >> s;
  cout << s << endl;
 }
 return 0;
}


输入
一个正整数n，表示有n个学生。

每个学生的资料包括名字（string）、年级（int）和考试成绩（int）。

输出
针对每个学生，输出学生的介绍（格式见样例）。如果学生的成绩达到60，则为通过考试。未达到60的为失败。

每个学生的资料输出完都要换行。

样例输入
3

Shizuka 2 95

Nobi 2 0

Konan 1 100


样例输出
My name is Shizuka. I'm in grade 2. My score is 95. I passed the exam.
My name is Nobi. I'm in grade 2. My score is 0. I failed in the exam.
My name is Konan. I'm in grade 1. My score is 100. I passed the exam.
*/

#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string name;
    int grade, score;

public:
    // 可能需要补充友元声明、运算符重载
    friend istream &operator>>(istream &, Student &);
    friend ostream &operator<<(ostream &, Student &);
};
// 可能需要补充运算符重载
istream &operator>>(istream &s, Student &t)
{
    s >> t.name >> t.grade >> t.score;
    return s;
}
ostream &operator<<(ostream &s, Student &t)
{
    s << "My name is " << t.name << ". I'm in grade " << t.grade << ". My score is " << t.score << ". I " << (t.score >= 60 ? "passed the exam." : "failed in the exam.");
    return s;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        Student s;
        cin >> s;
        cout << s << endl;
    }
    return 0;
}