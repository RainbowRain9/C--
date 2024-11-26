/*
问题描述
有4个非负整数a、b、c、d，问是否能把这四个数两两分一组，第一组中两个数相除的结果等于第二组中两个数相除的结果？

这里的相除结果指的是数学上的除法结果，不是整除，不是只保留整数部分。

输入描述
4个非负整数a、b、c、d。（均不大于10000）

输出描述
如果能满足问题描述中的要求，则输出Yes，否则输出No。

不要换行。

样例输入
1 5 2 10

样例输出
Yes
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == 0 && b == 0 && c == 0 || a == 0 && b == 0 && d == 0 || c == 0 && b == 0 && d == 0 || c == 0 && a == 0 && d == 0)
    {
        cout << "No";
    }

    else if (a * d == b * c || a * c == b * d || a * b == c * d)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}