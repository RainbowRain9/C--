/*问题描述
定义一个长方形类Rectangle，类的成员包括：

1、width：长方形的宽，double类型，私有

2、height：长方形的高，double类型，私有

3、构造函数Rectangle()：什么事都不做

4、构造函数Rectangle(double, double)：设置长方形的宽和高，第一个参数赋给宽，第二个参数赋给高

5、void setWidth(double)函数：设置长方形的宽，公有

6、void setHeight(double)函数：设置长方形的高，公有

7、double getCir()函数：返回长方形的周长，公有

8、double getArea()函数：返回长方形的面积，公有

规定主函数是如下代码（不可以修改），根据输入输出，设计Rectangle类以满足要求。

int main()
{
 double w1, h1, w2, h2;
 cin >> w1 >> h1 >> w2 >> h2;
 Rectangle r1(w1, h1);
 Rectangle r2;
 r2.setWidth(w2);
 r2.setHeight(h2);
 cout << r1.getCir() << endl;
 cout << r1.getArea() << endl;
 cout << r2.getCir() << endl;
 cout << r2.getArea() << endl;
 return 0;
}

输入描述
只有一组案例。四个浮点数w1、h1、w2、h2，分别表示第一个长方形的宽和高、第二个长方形的宽和高。

输出描述
第一个长方形的周长，换行。

第一个长方形的面积，换行。

第二个长方形的周长，换行。

第二个长方形的面积，换行。


样例输入
5 3.5 1 2

样例输出
17

17.5

6

2
*/

#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;
    double height;

public:
    Rectangle() {}
    Rectangle(double w, double h) : width(w), height(h) {}
    void setWidth(double w)
    {
        width = w;
    }
    void setHeight(double h)
    {
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
    double w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    Rectangle r1(w1, h1);
    Rectangle r2;
    r2.setWidth(w2);
    r2.setHeight(h2);
    cout << r1.getCir() << endl;
    cout << r1.getArea() << endl;
    cout << r2.getCir() << endl;
    cout << r2.getArea() << endl;
    return 0;
}