/*
描述
    实现一个最简单的计算器，支持加法和减法两种运算。仅需考虑输入输出为整数的情况，数据和运算结果不会超过int表示的范围。输入两个整数以及一个运算符（+,-）。输出运算结果。

输入
    两个整数m和n，以及一个运算符（只会是+或者-）

输出
    如果运算符是+，则输出m+n的值
    如果运算符是-，则输出m-n的值
    不要换行。

样例输入
    4 5 +

样例输出
    9
*/

#include <iostream>
using namespace std;
int main()
{
    int m, n;
    char a;
    cin >> m >> n >> a;
    if (a == '+')
    {
        cout << m + n;
    }
    else if (a == '-')
    {
        cout << m - n;
    }
    else
    {
        cout << "无效运算";
    }
    return 0;
}