/*
描述
通过重载函数（overloaded function），返回两个数字的相减结果。

第一个重载接受2个int类型参数，函数返回两个数字的相减结果（整数）。

第二个重载接受2个double类型参数，函数返回两个数字的相减结果（浮点数）。

主函数中分别输入两组值，调用函数输出结果。

输入
一共有4个数字。

首先是两个浮点数a、b

然后是两个整数c、d

输出
先输出a-b的值，换行。

然后输出c-d的值，换行。

样例输入
3.5 2.3

3 1

样例输出
1.2

2
*/

#include <iostream>
using namespace std;

int sub(int a, int b)
{
    return a - b;
}
double sub(double a, double b)
{
    return a - b;
}

int main()
{
    float a, b;
    int c, d;
    cin >> a >> b >> c >> d;
    cout << sub(a, b) << endl;
    cout << sub(c, d) << endl;
    return 0;
}