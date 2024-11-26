/*
描述
输入一个字符串，按字符ASCII码从小到大顺序重新排列字符串并输出。

输入
只有一组案例。

由一个字符串构成。

输出
一个字符串，字符串里的字符按照ASCII码从小到大顺序排列。不要换行。

样例输入
crab

样例输出
abcr
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
    string a;
    cin >> a;
    int b = a.length();
    for (int i = 0; i < b; i++)
    {
        for (int j = i + 1; j < b; j++)
        {
            int b = a[i];
            int c = a[j];
            if (b > c)
            {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < b; i++)
    {
        cout << a[i];
    }

    return 0;
}