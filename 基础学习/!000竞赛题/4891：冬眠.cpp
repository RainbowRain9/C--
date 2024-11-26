/*
问题描述
已知某种虫子，如果连续3天的气温都低于10度就会进入冬眠，直到来年才会醒来。

现在已知从9月27日到10月6日连续10天的气温，并且9月26日和10月7日的温度都高于10度，问虫子会在哪天进入冬眠

输入描述
10个整数，表示从9月27日到10月6日连续10天的气温。（均在正常气温范围内）

输出描述
如果虫子会在这10天的某天进入冬眠，则输出改天的日期，格式是：月份.日期，例如10.1

如果虫子不会在这10天进入冬眠，则输出No

不要换行。

样例输入
15 10 5 1 3 12 7 5 1 -2

样例输出
10.1
*/

#include <iostream>
using namespace std;

int main()
{
    int date[10], a;
    int temp = 0;
    bool flag = false;
    for (int i = 0; i < 10; i++)
    {
        cin >> date[i];
    }
    for (int i = 0; i < 10; i++)
    {
        if (date[i] < 10)
        {
            temp++;
        }
        else
        {
            temp = 0;
        }
        if (temp == 3)
        {
            flag = true;
            a = i + 1;
            break;
        }
    }
    if (flag)
    {
        if (a > 4)
        {
            cout << 10 << "." << a - 4;
        }
        else
        {
            cout << 9 << "." << 26 + a;
        }
    }
    else
    {
        cout << "No";
    }

    return 0;
}