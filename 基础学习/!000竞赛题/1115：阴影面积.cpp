/*
问题描述
左右两侧均为正方形，给出
a
,
b
a,b请你计算下图中阴影部分面积。



输入描述
在一行中输入两个正整数


输出描述
在一行中输出一个浮点数表示阴影部分的面积，输出时需要保留一位小数。

样例输入
2 1

样例输出
2.0
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a, b, num;
    float s, s1, s2, s3;
    cin >> a >> b;
    s = (a + b) * a;
    s1 = a * a / 2;
    s2 = (a + b) * b / 2;
    s3 = (a - b) * b / 2;
    num = s - s1 - s2 - s3;
    cout << fixed << setprecision(1) << num;

    return 0;
}