/*
描述
定义一个长方形类Rectangle：

1、具有两个属性

（1）w：宽，int类，公有

（2）h：高，int类，公有

2、具有两个方法

（1）int getCir()：返回长方形的周长，公有

（2）int getArea()：返回长方形的面积，公有

在主函数中输入长方形的宽和高，调用类的方法输出长方形的周长和面积。

输入
一个正整数n，表示n组案例。

每组案例由两个正整数w和h组成。

输出
针对每组案例，输出长方形的周长和面积，中间隔一个空格。

每组案例输出完都要换行。

样例输入
2

1 2

3 4

样例输出
6 2

14 12

提示说明
主函数中有这几句关键语句

Rectangle r;

cin>>r.w>>r.h;

cout<<r.getCir()<<' '<<r.getArea()<<endl;
*/

#include <iostream>
using namespace std;

// 定义长方形类
class Rectangle
{
private:
    int w; // 长方形的宽
    int h; // 长方形的高

public:
    // 构造函数，初始化宽和高
    Rectangle(int width, int height) : w(width), h(height) {}

    // 获取长方形的周长
    int getCir()
    {
        return 2 * (w + h); // 周长计算公式：2 * (宽 + 高)
    }

    // 获取长方形的面积
    int getArea()
    {
        return w * h; // 面积计算公式：宽 * 高
    }
};

int main()
{
    int n;    // 案例数量
    cin >> n; // 输入案例数量

    while (n--)
    {                  // 对于每组案例
        int w, h;      // 用于存储输入的宽和高
        cin >> w >> h; // 输入长方形的宽和高

        Rectangle r(w, h);                                // 创建一个Rectangle对象
        cout << r.getCir() << ' ' << r.getArea() << endl; // 输出周长和面积
    }

    return 0;
}