/*
描述
斐波那契数列是这样一组有规律的数字：1、1、2、3、5、8、13、21、34、…。
这组数字的前两项都是1，从第三项开始，每个数字都是前两个数字的和。

输出数列的第n项。

输入
一个正整数n

输出
一个整数，表示数列的第n项。不要换行

样例输入
4

样例输出
3
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int* a = new int [n];
    a[0] = 1;
    a[1] = 1;
    bool f = true;
    for (int i = 2; i < n; i++)
    {
        a[i] = a[i - 2] + a[i - 1];
    }
    cout << a[n-1];
    return 0;
}