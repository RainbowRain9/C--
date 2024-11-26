/*
描述
输入两个整数，存放在变量a、b中。

定义一个指向变量a的指针pa，一个指向变量b的指针pb，利用pa和pb两个指针输出这两个整数的和。

输入
只有一组案例。

两个整数a和b。

输出
利用指针输出a、b的和。不要换行。

样例输入
2 3

样例输出
5
*/

#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int *pa = &a, *pb = &b;
    cout << *pa + *pb;
    return 0;
}