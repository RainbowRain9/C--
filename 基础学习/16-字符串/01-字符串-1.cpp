/*
描述
输入一个字符串（不带空格、\t、换行符，以后不额外说明的情况下，默认都是这样），输出字符串的长度

输入
一个正整数n，表示有n组案例。

每组案例中有一个字符串。

输出
针对每组案例，输出字符串的长度。

每组案例输出完都要换行。

样例输入
2

abc

e

样例输出
3

1
*/

#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a;
        cin >> a;
        cout << a.length() << endl;
    }
    return 0;
}