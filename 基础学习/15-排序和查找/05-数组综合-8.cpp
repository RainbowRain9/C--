/*
描述
把n个数字中最小的数字和最大的数字交换，其他数字的位置保持不变，输出变化后的n个数字。
只会有一个最大的数和一个最小的数。

输入
只有一组案例。

一个正整数n，然后是n个整数。

输出
把n个数字中最小的数字和最大的数字交换，其他数字的位置保持不变，输出变化后的n个数字。

每个数字之间用一个空格间隔，最后一个数字后面没有空格或者换行。

样例输入
5

1 2 3 4 5

样例输出
5 2 3 4 1
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int min = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < a[min])
        {
            min = i;
        }
        if (a[i] > a[max])
        {
            max = i;
        }
    }
    swap(a[max], a[min]);
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            cout << a[i] << " ";
        }
        else
        {
            cout << a[i];
        }
    }

    return 0;
}