/*
描述
定义Shape类的派生类Rectangle类

#include<iostream>
using namespace std;
class Shape
{
public:
 virtual double getArea()
 {
  return 0;
 }
};
//Rectangle类
int main()
{
 Shape s1;
 cout << s1.getArea() << endl;//0
 Shape s2 = Rectangle(4, 5);//注意这么写语法没错
 cout << s2.getArea() << endl;//0
 cout << "----------" << endl;
 Rectangle r1(4, 5);
 cout << r1.getArea() << endl;//20
 cout << "----------" << endl;
 Shape *ps1 = new Shape();
 cout << ps1->getArea() << endl;//0
 Shape *ps2 = new Rectangle(4, 5);//注意这句触发虚函数的机制
 cout << ps2->getArea() << endl;//20
 Rectangle *pr = new Rectangle(4, 5);
 cout << pr->getArea() << endl;//20
 //Rectangle *pr2 = new Shape();注意这么写语法报错
 return 0;
}

输入
无

输出
0
0
----------
20
----------
0
20
20


样例输入


样例输出
0
0
----------
20
----------
0
20
20
*/


#include <iostream>
using namespace std;
class Shape
{
public:
    virtual double getArea()
    {
        return 0;
    }
};
// Rectangle类
class Rectangle : public Shape
{
private:
    int a;
    int b;

public:
    Rectangle(int a, int b) : a(a), b(b) {}
    double getArea() override
    {
        return a * b;
    }
};
int main()
{
    Shape s1;
    cout << s1.getArea() << endl; // 0
    Shape s2 = Rectangle(4, 5);   // 注意这么写语法没错
    cout << s2.getArea() << endl; // 0
    cout << "----------" << endl;
    Rectangle r1(4, 5);
    cout << r1.getArea() << endl; // 20
    cout << "----------" << endl;
    Shape *ps1 = new Shape();
    cout << ps1->getArea() << endl;   // 0
    Shape *ps2 = new Rectangle(4, 5); // 注意这句触发虚函数的机制
    cout << ps2->getArea() << endl;   // 20
    Rectangle *pr = new Rectangle(4, 5);
    cout << pr->getArea() << endl; // 20
    // Rectangle *pr2 = new Shape();注意这么写语法报错
    return 0;
}
