/*
问题描述
已知平面直角坐标系中有一条直线ax+by=c。求该直线与x轴、y轴围成的三角形的面积。

输入描述
只有一组案例。

三个浮点数a，b，c（绝对值均不大于10000）。

输出描述
一个浮点数，表示直线ax+by=c与x轴、y轴围成的三角形的面积（与准确值的误差在0.01范围之内都算正确）。

如果无法围成三角形，那么输出-1。

不要换行。

样例输入
1 2 3

样例输出
2.25

提示说明
输出范围在2.24~2.26之间都会被判为正确。
*/

#include <iostream>
using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    float length = c / a;
    float height = c / b;
    float area = abs(length * height / 2);
    if (a == 0 || b == 0 || c == 0 || area == 0)
        cout << -1;
    else
        cout << area;

    return 0;
}