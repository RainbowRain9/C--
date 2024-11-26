/*
描述
输入一个字符串，输出数组下标为偶数的所有字符。

输入
一个正整数n，表示有n组案例。

每组案例中有一个字符串。

输出
针对每组案例，输出数组下标为偶数的所有字符。

每组案例输出完都要换行。

样例输入
1

abcdefg

样例输出
aceg
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
        for (int i = 0; i < a.length(); i += 2)
        {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}