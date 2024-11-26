/*
问题描述
用一个6位数表示的年份月份，例如202410表示2024年10月，202001表示2020年1月。

现在有两个用6位整数a和b表示的年份月份，求这两个日期之间包含了多少个月？

输入描述
这是一道多组案例的题目。一个正整数n，表示案例的数量。（n<=1000）

每组案例由两个正整数a和b组成。（a和b都是6位数，且都是合法的年份月份，年份范围在1000~9999，b表示的日期不会早于a表示的日期）

输出描述
针对每组案例，输出两个整数，表示a和b表示的两个日期之间包含了多少个月（不含头尾月份、包含头尾月份两个值），以空格相隔。

每组案例输出完都要换行。

样例输入
2

202401 202410

202312 202401

样例输出
8 10

0 2
*/

#include <iostream>
using namespace std;

void Date(int date, int &year, int &month)
{
    year = date / 100;
    month = date % 100;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;

        int y1, m1, y2, m2;
        Date(a, y1, m1);
        Date(b, y2, m2);

        int Mouth1 = (y2 - y1) * 12 + (m2 - m1) + 1;

        int Mouth2 = max(0, Mouth1 - 2);

        cout << Mouth2 << " " << Mouth1 << endl;
    }

    return 0;
}