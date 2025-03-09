/*
问题描述
输出一个边长为 m 的正六边形。

输入描述
一个正整数 m 代表正六边形的边长。(2 <= m <= 20)

输出描述
一个边长为 m 的正六边形，每行最后一个星号后面没有空格，最后一行输出完成以后也要换行。

样例输入
3

样例输出
  ***
 *   *
*     *
 *   *
  ***
*/
#include <iostream>
using namespace std;

int main()
{
    int m;
    cin >> m;

    // 上半部分（不包括中间一行）
    for (int i = 0; i <= m - 1; i++)
    {
        // 打印前导空格
        for (int j = 0; j < m - i - 1; j++)
        {
            cout << " ";
        }

        // 打印星号和中间的空格
        if (i == 0)
        {
            for (int k = 0; k < m; k++)
            {
                cout << "*";
            }
        }
        else
            cout << "*";
        if (i > 0)
        {
            for (int j = 0; j < m + 2 * (i - 1); j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }

    // 下半部分
    for (int i = m - 2; i >= 0; i--)
    {
        // 打印前导空格
        for (int j = 0; j < m - i - 1; j++)
        {
            cout << " ";
        }

        // 打印星号和中间的空格
        if (i == 0)
        {
            for (int k = 0; k < m; k++)
            {
                cout << "*";
            }
        }
        else
            cout << "*";
        if (i > 0)
        {
            for (int j = 0; j < m + 2 * (i - 1); j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
