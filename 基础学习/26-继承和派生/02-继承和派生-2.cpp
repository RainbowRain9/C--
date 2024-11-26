/*
描述
把Student类和Teacher类都设计成Person类的派生类，以实现如下的输出。其他地方不得添加代码。

#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
 string name;
public:
 Person(string n)
 {
  name = n;
  cout << name << " goes to school." << endl;
 }
 string getName()
 {
  return name;
 }
};

//①这里应该是Student类的定义

//②这里应该是Teacher类的定义

int main()
{
 Student s1("Twilight Sparkle"), s2("Pinkie Pie");
 Teacher t("Princess Celestia");
 cout << "----------" << endl;
 t.teach(s1);
 t.teach(s2);
 cout << "----------" << endl;
 return 0;
}

样例输入


样例输出
Twilight Sparkle goes to school.
Twilight Sparkle is a student.
Pinkie Pie goes to school.
Pinkie Pie is a student.
Princess Celestia goes to school.
Princess Celestia is a teacher.
----------
Princess Celestia is teaching Twilight Sparkle.
Princess Celestia is teaching Pinkie Pie.
----------
Princess Celestia goes to the office.
Pinkie Pie goes home.
Twilight Sparkle goes home.
*/

#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string name;

public:
    Person(string n)
    {
        name = n;
        cout << name << " goes to school." << endl;
    }
    string getName()
    {
        return name;
    }
};

// ①这里应该是Student类的定义
class Student : public Person
{
public:
    Student(string name_) : Person(name_)
    {
        cout << getName() << " is a student." << endl;
    }
    ~Student()
    {
        cout << getName() << " goes home." << endl;
    }
};
// ②这里应该是Teacher类的定义
class Teacher : public Person
{
public:
    Teacher(string name_) : Person(name_)
    {
        cout << getName() << " is a teacher." << endl;
    }
    void teach(Student &stu)
    {
        cout << getName() << " is teaching " << stu.getName() << "." << endl;
    }
    ~Teacher()
    {
        cout << getName() << " goes to the office." << endl;
    }
};  
int main()
{
    Student s1("Twilight Sparkle"), s2("Pinkie Pie");
    Teacher t("Princess Celestia");
    cout << "----------" << endl;
    t.teach(s1);
    t.teach(s2);
    cout << "----------" << endl;
    return 0;
}