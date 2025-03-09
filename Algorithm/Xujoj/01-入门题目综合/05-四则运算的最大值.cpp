/*
问题描述
输入两个非0的整数，输出这两个数加减乘除结果中的最大值。其中减法和除法只能是第一个数在前，第二个数在后。

输入描述
只有一组案例。

两个整数a和b（均不为0，且绝对值不大于10000）。

输出描述
一个浮点数，表示a+b、a-b、a*b、a/b中的最大值，其中a/b要按浮点数的运算结果。（与精确值的误差范围在0.01之内的都算正确）

不要换行。

样例输入
4 5

样例输出
20
*/

#include <iostream>
using namespace std;

int main()
{
    float a, b;
    cin >> a >> b;
    float num = a + b;
    if (a - b > num)
        num = a - b;
    if (a * b > num)
        num = a * b;
    if (a / b > num)
        num = a / b;

    cout << num;

    return 0;
}