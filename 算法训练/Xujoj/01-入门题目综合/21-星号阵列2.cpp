/*
问题描述
输出一个边长为m个星号的空心菱形。

输入描述
只有一组案例。

一个正整数m（2<=m<=15），表示菱形的边长是m个星号。

输出描述
边长为m个星号的空心菱形。每行最后一个星号后面不能有多余的空格，最后一行星号输出后需要换行。

样例输入
4

样例输出
   *
  * *
 *   *
*     *
 *   *
  * *
   *
*/

#include <iostream>
using namespace std;

int main()
{
    int m;
    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m - i; j++)
        {
            cout << " ";
        }
        cout << "*";

        if (i > 1)
        {
            for (int j = 1; j <= 2 * i - 3; j++)
            {
                cout << " ";
            }
            cout << "*";
        }

        cout << endl;
    }

    for (int i = m - 1; i >= 1; i--)
    {
        for (int j = 1; j <= m - i; j++)
        {
            cout << " ";
        }

        cout << "*";

        if (i > 1)
        {
            for (int j = 1; j <= 2 * i - 3; j++)
            {
                cout << " ";
            }
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}