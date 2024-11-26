/*
描述
输入两个整数，存放在变量a和b中。

定义一个指向变量a的指针pa，一个指向变量b的指针pb，利用pa和pb两个指针交换a和b的值，再输出a和b的值。

输入
只有一组案例。

两个整数a和b。

输出
两个整数，表示交换后的a和b，中间间隔一个空格，不要换行。

样例输入
3 5

样例输出
5 3
*/

#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int *pa = &a, *pb = &b;
    swap(pa, pb);
    cout << *pa << " " << *pb;
}