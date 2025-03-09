/*
问题描述
数学上规定多边形的对角线是不相邻的两个顶点之间的线段。求正n边形对角线的数量。
输入描述
多组案例。一个正整数n，表示案例的数量。（n<=20）

每组案例由一个正整数m组成，表示m边形。（3<=m<=100万）

输出描述
针对每组案例，输出一个整数，表示m边形对角线的数量。

每组案例输出完都要换行。

样例输入
2

4

10

样例输出
2

35
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        long long count = static_cast<long long>(m) * (m - 3) / 2;
        cout << count << endl;
    }

    return 0;
}