/*
描述
输入一个字符串，输出所有ASCII码为偶数的字符。

输入
一个正整数n，表示有n组案例。

每组案例中有一个字符串。

输出
针对每组案例，输出所有ASCII码为偶数的字符。

每组案例输出完都要换行。

样例输入
1

aabccddd

样例输出
bddd
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
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] % 2 == 0)
            {
                cout << a[i];
            }
        }
        cout << endl;
    }

    return 0;
}