/*
描述
定义一个长方形类Rectangle，类的成员包括：

1、width：长方形的宽，double类型，私有

2、height：长方形的高，double类型，私有

3、构造函数Rectangle(double, double)：设置长方形的宽和高，第一个参数赋给宽，第二个参数赋给高

4、double getCir()函数：返回长方形的周长，公有

5、double getArea()函数：返回长方形的面积，公有

规定主函数是如下代码（不可以修改），根据输入输出，设计Rectangle类以满足要求。

int main()
{
 double w, h;
 cin >> w >> h;
 Rectangle r(w, h);
 cout << r.getCir() << endl;
 cout << r.getArea() << endl;
 return 0;
}

输入
只有一组案例。两个浮点数w和h，分别表示长方形的宽和高。

输出
长方形的周长，换行。

长方形的面积，换行。



样例输入
5 3.5

样例输出
17

17.5
*/

#include <iostream>
using namespace std;
class Rectangle
{
private:
    double width;
    double height;

public:
    Rectangle (double w, double h)
    {
        width = w;
        height = h;
    }
    double getCir()
    {
        return (width + height) * 2;
    }
    double getArea()
    {
        return width * height;
    }
};

int main()
{
    double w, h;
    cin >> w >> h;
    Rectangle r(w, h);
    cout << r.getCir() << endl;
    cout << r.getArea() << endl;
    return 0;
}