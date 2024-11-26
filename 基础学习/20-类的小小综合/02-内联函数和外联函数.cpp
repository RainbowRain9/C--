/*
描述
把以下代码中类的内联成员函数（包括构造和析构函数）改写成外联的写法。（不要改程序的功能）

#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
 string name;
 double score;
public:
 Student(string name, double score) :name(name), score(score)
 {
  cout << name << "'s constructor" << endl;
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
 Student s("Tom", 90);
 s.display();
 return 0;
}

输入
无

输出
Tom's constructor
Tom 90
Tom's destructor

样例输入


样例输出
Tom's constructor
Tom 90
Tom's destructor
*/
     
#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
	string name;
	double score;
public:
	Student(string name, double score);
	~Student();
	void display();
};

Student::Student(string name, double score) :name(name), score(score)
{
	cout << name << "'s constructor" << endl;
}
Student::~Student()
{
	cout << name << "'s destructor" << endl;
}
void Student::display()
{
	cout << name << " " << score << endl;
}

int main()
{
	Student s("Tom", 90);
	s.display();
	return 0;
}
