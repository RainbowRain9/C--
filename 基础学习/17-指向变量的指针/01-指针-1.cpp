/*
描述
输入一个整数，存放在变量a中。

定义一个指向变量a的指针pa，利用pa输出a的值。

输入
仅有一组案例。

一个整数a。

输出
利用指针pa输出a的值。不要换行。

样例输入
3

样例输出
3
*/

#include <iostream>
using namespace std;
int main()
{
    int a;
    int *pa;
    cin >> a;
    pa = &a;
    cout << *pa;
    return 0;
}