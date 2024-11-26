/*
描述
输入一个字符串，输出字符串的最后一个字符

输入
一个正整数n，表示有n组案例。

每组案例中有一个字符串。

输出
针对每组案例，输出字符串的最后一个字符。

每组案例输出完都要换行。

样例输入
2

abc

e

样例输出
c

e
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a;
        cin >> a;
        cout << a[a.length() - 1] << endl;
    }
    return 0;
}