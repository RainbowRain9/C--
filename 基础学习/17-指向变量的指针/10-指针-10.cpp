/*
描述
定义一个长度为m的整型数组a，各元素的值分别为2,4,6,…,2m，利用指针求数组中各元素的和

输入
只有一组案例。

一个正整数m。

输出
一个整数，表示数组中各元素的和。不要换行。

样例输入
3

样例输出
12
*/

#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int sum = 0;

    for (int j = 2; j <= 2 * m; j += 2)
    {
        sum += j;
    }
    cout << sum;
    return 0;
}