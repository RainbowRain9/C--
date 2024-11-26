/*
描述
定义一个长度为n的数组a，对于数组中的每个元素定义初值*(pa+i)=(i*i+i)%m。
数组元素的值都生成后，利用指针把数组中最大元素（可能不止一个）的值改成最小元素的值，
把最小元素（可能不止一个）的值改成最大元素的值。输出数组每个元素。

输入
只有一组案例。

两个正整数n和m。

输出
数组每个元素，每两个元素之间有一个空格，不要换行。

样例输入
10 7

样例输出
6 2 0 5 0 2 6 6 2 0

提示说明
数组原来是0 2 6 5 6 2 0 0 2 6，0是最小值，6是最大值。故所有的0变成6，所有的6变成0。

变换后的数组是6 2 0 5 0 2 6 6 2 0

*/

#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int *a = new int[n];
    int *pa = a;
    for (int i = 0; i < n; i++)
    {
        *(pa + i) = (i * i + i) % m;
    }
    int min = m, max = 0;
    for (int i = 0; i < n; i++)
    {
        if (min > *(pa + i))
        {
            min = *(pa + i);
        }
        if (max < *(pa + i))
        {
            max = *(pa + i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (*(pa + i) == min)
        {
            *(pa + i) = max;
        }
        else if (*(pa + i) == max)
        {
            *(pa + i) = min;
        }
        if (i != 0)
        {
            cout << " " << *(pa + i);
        }
        else
        {
            cout << *(pa + i);
        }
    }
    delete[] a;
    return 0;
}