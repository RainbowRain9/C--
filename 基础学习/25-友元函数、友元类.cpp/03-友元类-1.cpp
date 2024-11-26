/*
描述
把代码补充完整。

#include<iostream>
#include<string>
using namespace std;
class Teacher
{
private:
 string name;
 string subject;
public:
 Teacher(string name, string subject) :name(name),subject(subject){}
 void display()
 {
  //实现display函数
 }
 //定义Student类是Teacher类的友元类
};
class Student
{
private:
 string name;
 int score;
 Teacher *teacher;
public:
 Student(string name, Teacher *teacher, int score) :name(name),teacher(teacher),score(score){}
 void display()
 {
  //实现display函数
 }
};

int main()
{
 Teacher t1("DJ Yang", "CPP"), t2("Simin Zhang", "Java");
 Student s1("Tom", &t1, 80), s2("Jerry", &t2, 90), s3("Garfield", &t2, 100);
 t1.display(); t2.display();
 s1.display(); s2.display(); s3.display();
 return 0;
}


输入
无

输出
Name: DJ Yang Subject: CPP
Name: Simin Zhang Subject: Java
Name: Tom Teacher's name: DJ Yang Teacher's subject: CPP Score: 80
Name: Jerry Teacher's name: Simin Zhang Teacher's subject: Java Score: 90
Name: Garfield Teacher's name: Simin Zhang Teacher's subject: Java Score: 100

样例输入


样例输出
Name: DJ Yang Subject: CPP
Name: Simin Zhang Subject: Java
Name: Tom Teacher's name: DJ Yang Teacher's subject: CPP Score: 80
Name: Jerry Teacher's name: Simin Zhang Teacher's subject: Java Score: 90
Name: Garfield Teacher's name: Simin Zhang Teacher's subject: Java Score: 100
*/

#include <iostream>
#include <string>
using namespace std;
class Teacher
{
private:
    string name;
    string subject;

public:
    Teacher(string name, string subject) : name(name), subject(subject) {}
    void display()
    {
        // 实现display函数
        cout << "Name: " << name << " Subject: " << subject << endl;
    }
    // 定义Student类是Teacher类的友元类
    friend class Student;
};
class Student
{
private:
    string name;
    int score;
    Teacher *teacher;

public:
    Student(string name, Teacher *teacher, int score) : name(name), teacher(teacher), score(score) {}
    void display()
    {
        // 实现display函数
        cout << "Name: " << name << " Teacher's name: " << teacher->name << " Teacher's subject: " << teacher->subject << " Score: " << score << endl;
    }
};

int main()
{
    Teacher t1("DJ Yang", "CPP"), t2("Simin Zhang", "Java");
    Student s1("Tom", &t1, 80), s2("Jerry", &t2, 90), s3("Garfield", &t2, 100);
    t1.display();
    t2.display();
    s1.display();
    s2.display();
    s3.display();
    return 0;
}