/*
描述
定义圆类Circle，有3个版本的构造函数（无参时表示半径为0，有参时参数是半径，还有拷贝构造函数），display成员函数用于输出半径、周长、面积，用空格间隔，要换行。

主函数如下：

int main()
{
 double r;
 cin >> r;
 Circle c1(r), c2(c1), c3;
 c1.display();
 c2.display();
 c3.display();
 return 0;
}

输入
一个浮点数，表示c1对象的半径。

输出
3行，分别是c1、c2、c3三个圆的信息，包括半径、周长、面积，用空格间隔，要换行。

圆周率用3.14计算。

样例输入
1

样例输出
1 6.28 3.14
1 6.28 3.14
0 0 0
*/

#include <iostream>
#include <string>
using namespace std;

class Circle
{
private:
    double radius;

public:
    Circle() { radius = 0; }

    Circle(double r_) : radius(r_) {}

    void display()
    {
        cout << radius << " " << 2 * 3.14 * radius << " " << 3.14 * radius * radius << endl;
    }
};

int main()
{
    double r;
    cin >> r;
    Circle c1(r), c2(c1), c3;
    c1.display();
    c2.display();
    c3.display();
    return 0;
}