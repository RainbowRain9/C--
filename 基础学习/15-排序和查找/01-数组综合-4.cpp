/*
描述
用选择法实现。

把n个数字按照从小到大的顺序输出。

输入
只有一组案例。

一个正整数n，然后是n个整数。

输出
按照从小到大的顺序输出这n个数字，每两个数字之间有一个空格，最后一个数字后面没有空格或换行。

样例输入
5

5 4 3 2 1

样例输出
1 2 3 4 5
*/

#include <iostream>
using namespace std;
template <typename T>
void selectSort(T a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selectSort(a, n);
    bool t = true;
    for (int i = 0; i < n; i++)
    {
        if (t)
        {
            cout << a[i];
            t = false;
        }
        else
        {
            cout << " " << a[i];
        }
    }
    return 0;
}