/*
描述
移除数组中重复的数字，按在数组中出现的顺序输出。

输入
只有一组案例。

一个正整数n，表示数组中元素的个数，然后是n个整数，表示数组中各元素的值。

输出
输出数组各元素，但相同的值只在第一次出现时输出。每两个值之间保留一个空格。不要换行。

样例输入
10

4 1 3 2 1 3 2 1 3 5

样例输出
4 1 3 2 5
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    bool b[n] = {false};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                b[i] = true;
            }
        }
        if (!b[i])
        {
            if (i != 0)
            {
                cout << " " << a[i];
            }
            else
            {
                cout << a[i];
            }
        }
    }
    delete[] a;
    return 0;
}