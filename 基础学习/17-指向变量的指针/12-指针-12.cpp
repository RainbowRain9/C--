/*
描述
定义一个长度为m的数组，输入m个整数，再输入一个整数b，定义一个指向数组a的指针pa，
利用指针把数组a中所有值等于b的元素修改成0，最后输出数组a各元素的值。

输入
只有一组案例。

一个正整数m，然后是m个整数，最后是一个整数b。

输出
把这m个整数中等于b的数字改成0，然后输出这m个整数。每两个数之间有一个空格，不要换行。

样例输入
4

1 2 4 2

2

样例输出
1 0 4 0
*/

#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int b;
    int *a = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    cin >> b;
    for (int i = 0; i < m; i++)
    {
        if (*(a + i) == b)
        {
            *(a + i) = 0;
        }
        if (i != 0)
        {
            cout << " " << *(a + i);
        }
        else
        {
            cout << *(a + i);
        }
    }
    return 0;
}