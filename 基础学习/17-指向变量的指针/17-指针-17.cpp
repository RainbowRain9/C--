/*
描述
定义一个m行n列的数组a，输入m*n个整数依次存放在数组中，然后使用指向二维数组的指针输出这个数组。

输入
只有一组案例。

先是两个正整数m和n，然后是m*n个整数，表示数组各元素的值。

输出
按照m行n列的方式输出这个数组。每行n个元素，共m行。
每两个元素之间要有空格，每行最后一个元素后面没有空格。每行输出完都要换行，包括最后一行。

样例输入
3 4

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
    int m, n;
    cin >> m >> n;
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