/*
描述
把字符串中的小写字符凑成一个新的字符串输出。

输入
一个正整数n，表示有n组案例。

每组案例由一个字符串构成。

输出
针对每组案例，把字符串中的小写字符凑成一个新的字符串输出。

每组案例输出完都要换行。

样例输入
1

y2Bc5cDe

样例输出
ycce
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a, b;
        cin >> a;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] >= 'a' && a[i] <= 'z')
            {
                b += a[i];
            }
        }
        cout << b << endl;
    }

    return 0;
}