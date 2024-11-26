/*
描述
写一个函数模板（function template），参数是4个相同类型的参数，把前两个参数看成一个点的坐标，
后两个参数看成另一个点的坐标，函数返回两点之间的距离（浮点数）。

主函数中分别输入两组值，调用函数输出结果。


输入
一共有8个数字。

首先是四个浮点数a、b、c、d

然后是四个整数e、f、g、h

输出
先输出点(a,b)到点(c,d)的距离，换行。

然后输出点(e,f)到点(g,h)的距离，换行。

输出结果与标准答案相差0.001之内即可。

样例输入
1.5 3.5 5.5 7.5

3 4 5 6

样例输出
5.65685

2.82843
*/

#include <iostream>
#include <cmath>
using namespace std;
void y(float a, float b, float c,float d)
{
    float s;
    s = (c - a) * (c - a) + (d - b) * (d - b);
    cout << sqrt(s) << endl;
}
void x(int e, int f, int g, int h)
{
    float r;
    r = (g - e) * (g - e) + (h - f) * (h - f);
    cout << sqrt(r) << endl;
}

int main()
{
    float a, b, c, d;
    int e, f, g, h;
    cin >> a >> b >> c >> d;
    cin >> e >> f >> g >> h;
    y(a, b, c, d);
    x(e, f, g, h);
    return 0;
}