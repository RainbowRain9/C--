/*
描述
输入一个整数，存放在变量a中。

定义一个指向变量a的指针pa，利用pa把a的值变成原来的5倍，然后输出a的值。

输入
仅有一组案例。

一个整数a。

输出
a变化后的值。不要换行。

样例输入
1

样例输出
5
*/

#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int *pa = &a;
    *pa *= 5;
    cout << *pa;
    return 0;
}