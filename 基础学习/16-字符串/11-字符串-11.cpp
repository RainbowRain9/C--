/*
描述
输入一个正整数n，然后输入n个字符串，最后输入一个正整数m（m<=n），要求输出第m个字符串

输入
一个正整数n，然后是n个字符串，最后是一个正整数m（m<=n）

输出
一个字符串，是输入的n个字符串中第m个字符串。不要换行。

样例输入
3

abc cd efg

2

样例输出
cd
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string *a = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    cout << a[m - 1];
    delete[] a;
    return 0;
}