/*
问题描述
输入4个整数，不调整这4个数的顺序，在这4个数的两两之间添加加号或者减号（一共添加了3个符号），希望能够让组成的计算表达式的结果为0。

问：有没有这种可能性？

注意：如果一个数是负数，在组成计算表达式时，会在这个负数的两边添加上括号()，以保证符合数学上写表达式的规范。

输入描述
4个整数

输出描述
如果有可能计算出0，那么输出Yes，否则输出No。

输出后不要换行。

样例输入
4 -6 3 1

样例输出
Yes

提示说明
4+(-6)+3-1
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b + c + d == 0)
    {
        cout << "Yes";
    }
    else if (a - b + c + d == 0)
    {
        cout << "Yes";
    }
    else if (a - b - c + d == 0)
    {
        cout << "Yes";
    }
    else if (a - b + c - d == 0)
    {
        cout << "Yes";
    }
    else if (a + b - c + d == 0)
    {
        cout << "Yes";
    }
    else if (a + b - c - d == 0)
    {
        cout << "Yes";
    }
    else if (a + b + c - d == 0)
    {
        cout << "Yes";
    }
    else if (a - b - c - d == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}