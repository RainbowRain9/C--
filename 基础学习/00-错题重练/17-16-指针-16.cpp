/*
描述
定义一个3行4列的数组a，输入12个整数依次存放在数组中，然后使用指向二维数组的指针输出这个数组。

输入
12个整数，表示数组中各个元素的值。

输出
按照3行4列的方式输出这个数组。每行4个元素，共3行。
每两个元素之间要有空格，每行最后一个元素后面没有空格。每行输出完都要换行，包括最后一行。

样例输入
1 2 3 4 5 6 7 8 9 10 11 12

样例输出
1 2 3 4

5 6 7 8

9 10 11 12
*/

#include <iostream>
using namespace std;
int main()
{
    const int m = 3, n = 4;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
            if (j == n - 1)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }
    return 0;
}