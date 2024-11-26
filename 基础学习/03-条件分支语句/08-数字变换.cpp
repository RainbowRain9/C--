/*
描述
    输入一个浮点数，如果该浮点数没有小数部分（也就是说该数字是整数），
    则输出该数字的三倍，否则输出比该数字小的最大整数。

输入
    一个浮点数

输出
    如果该浮点数没有小数部分（也就是说该数字是整数），
    则输出该数字的三倍，否则输出比该数字小的最大整数。
    不要换行。

样例输入
    3

样例输出
    9
*/

#include <iostream>
using namespace std;

int main()
{
    float a;
    cin >> a;
    if (a == static_cast<int>(a))
    {
        cout << 3 * a;
    }
    else
    {
        cout << static_cast<int>(a);
    }
    return 0;
}