/*
描述
把代码补充完整

#include<iostream>
#include<string>
using namespace std;
//在这里实现Student类，要求属性全部定义成私有的
//在这里定义display函数，该函数是Student类的友元函数
int main()
{
 Student s1("Minamoto Shizuka", 2, 95), s2("Nobita Nobi", 2, 0), s3("Edogawa Konan", 1, 100);
 display(s1);
 display(s2);
 display(s3);
 return 0;
}


输入
无

输出
My name is Minamoto Shizuka. I'm in grade 2. My score is 95. I passed the exam.
My name is Nobita Nobi. I'm in grade 2. My score is 0. I failed in the exam.
My name is Edogawa Konan. I'm in grade 1. My score is 100. I passed the exam.


样例输入


样例输出
My name is Minamoto Shizuka. I'm in grade 2. My score is 95. I passed the exam.
My name is Nobita Nobi. I'm in grade 2. My score is 0. I failed in the exam.
My name is Edogawa Konan. I'm in grade 1. My score is 100. I passed the exam.
*/

#include <iostream>
#include <string>
using namespace std;
// 在这里实现Student类，要求属性全部定义成私有的
class Student
{
private:
    string name;
    int grade, score;

public:
    Student(string name_, int grade_, int score_) : name(name_), grade(grade_), score(score_) {}
    string getName()
    {
        return name;
    }
    int getGrade()
    {
        return grade;
    }
    int getScore()
    {
        return score;
    }
    friend void display(Student &);
};
// 在这里定义display函数，该函数是Student类的友元函数
void display(Student &s)
{
    cout << "My name is " << s.getName() << ". I'm in grade " << s.getGrade() << ". My score is " << s.getScore() << ".";
    if (s.getScore() == 0)
    {
        cout << " I failed in the exam.";
    }
    else
    {
        cout << " I passed the exam.";
    }
    cout << endl;
}
int main()
{
    Student s1("Minamoto Shizuka", 2, 95), s2("Nobita Nobi", 2, 0), s3("Edogawa Konan", 1, 100);
    display(s1);
    display(s2);
    display(s3);
    return 0;
}