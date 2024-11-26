/*
描述
按照要求把代码补充完整（共两处，分别标有//①和//②），定义Shape抽象类和calcArea函数，以实现如下的输出。其中Shape抽象类中仅具有getArea纯虚函数；不得重载calcArea函数。

#include <iostream>
using namespace std;
//①这里应该是Shape抽象类的定义
class Rectangle : public Shape
{
 double width, height;
public:
 Rectangle(double w, double h) : width(w), height(h) { }
 double getArea() { return width*height; }
};
class Circle : public Shape
{
 double radius;
public:
 Circle(double r) : radius(r) { }
 double getArea() { return 3.14*radius*radius; }
};
//② 补充calcArea函数的定义
int main()
{
 Rectangle rect(3, 4);
 Circle cir(1);
 cout << calcArea(&rect) << endl << calcArea(&cir) << endl;
 return 0;
}

样例输出
12

3.14
*/

#include <iostream>
using namespace std;
// ①这里应该是Shape抽象类的定义
class Shape
{
public:
    virtual double getArea() { return 0; }
};
class Rectangle : public Shape
{
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() { return width * height; }
};
class Circle : public Shape
{
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea() { return 3.14 * radius * radius; }
};
// ② 补充calcArea函数的定义
double calcArea(Shape *shape) { return shape->getArea(); }
int main()
{
    Rectangle rect(3, 4);
    Circle cir(1);
    cout << calcArea(&rect) << endl
         << calcArea(&cir) << endl;
    return 0;
}