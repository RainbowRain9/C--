/*
描述
用冒泡法实现。

把n个数字按照从大到小的顺序输出。

输入
只有一组案例。

一个正整数n，然后是n个整数。

输出
按照从大到小的顺序输出这n个数字，每两个数字之间有一个空格，最后一个数字后面没有空格或换行。

样例输入
5

1 2 3 4 5

样例输出
5 4 3 2 1
*/

#include <iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bubbleSort(a, n);
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        if (f)
        {
            cout << a[i];
            f = false;
        }
        else
        {
            cout << " " << a[i];
        }
    }
    delete[] a;
    return 0;
}