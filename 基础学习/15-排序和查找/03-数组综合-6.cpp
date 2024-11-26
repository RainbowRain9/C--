/*
描述
把n个数字中最小5个数字的和输出出来

输入
只有一组案例。

一个正整数n，然后是n个整数。（n>=5）

输出
一个整数，表示最小5个数字的和。不要换行。

样例输入
10

1 2 3 4 5 6 7 8 9 10

样例输出
15
*/

#include <iostream>
using namespace std;
template <typename T>
void bubSort(T a[], int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (a[j] > a[j + 1])
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
    bubSort(a, n);
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += a[i];
    }
    cout << sum;
    return 0;
}