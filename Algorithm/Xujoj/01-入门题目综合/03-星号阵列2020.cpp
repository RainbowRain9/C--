/*
问题描述
输入一个不小于5的正奇数n，输出星号阵列：2020。

输入描述
只有一组案例。案例由一个不小于5的正奇数n组成。

输出描述
星号阵列：2020，其中每个数字由n*n的星号阵列表示，每个数字的星号阵列之间间隔一个空列。最后一行星号输出完后要换行。

样例输入
5
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 4; j++)
        {
            if (j == n || j == 2 * n || j == 3 * n)
            {
                cout << " ";
            }
            if (i == 0 || (i == n / 2 && (j < n || (j < 3 * n && j >= 2 * n))) || i == n - 1 || j == n || j == 2 * n - 1 || j == 3 * n || j == 4 * n - 1 || ((j == n - 1 || j == 3 * n - 1) && i <= n / 2) || ((j == 0 || j == 2 * n) && i >= n / 2))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}