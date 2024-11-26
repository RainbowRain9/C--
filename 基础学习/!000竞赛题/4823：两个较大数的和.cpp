/*
问题描述
输入三个整数，输出其中较大的两个数之和

输入描述
三个整数，绝对值均不大于10000。

输出描述
一个整数，表示三个数中较大的两个数之和。

不要换行。

样例输入
2

-10

-3

样例输出
-1
*/

#include <iostream>
using namespace std;

void sort(int &a, int &b, int &c)
{
    int t;
    if (a > b)
    {
        t = a;
        a = b;
        b = t;
    }
    if (a > c)
    {
        t = a;
        a = c;
        c = t;
    }
    if (b > c)
    {
        t = b;
        b = c;
        c = t;
    }
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    sort(a, b, c);
    cout << b + c;
    return 0;
}