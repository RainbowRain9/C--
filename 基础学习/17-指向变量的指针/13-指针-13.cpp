/*
描述
从键盘输入整数m，创建含有m个元素的整型数组a，从键盘输入m个整数，利用指向数组的指针pa计算数组a中所有元素的总和并输出。

输入
只有一组案例。

一个正整数m，表示数组的长度，然后是m个整数，表示数组中的元素值。

输出
利用指针计算数组中所有元素的总和并输出。不要换行。

样例输入
4 1 2 3 4

样例输出
10
*/

#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int *a = new int [m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += *(a + i);
    }
    cout << sum;
}