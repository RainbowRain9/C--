/*
描述
输入一个n*n的二维数组，输出主对角线上的n个元素的和（即a[0][0]+a[1][1]+...+a[n-1][n-1]）

输入
只有一组案例。

一个正整数n，表示二维数组是n行n列的，然后是n*n个整数，表示数组各元素的值。

输出
一个整数，表示主对角线上的n个元素的和（即a[0][0]+a[1][1]+...+a[n-1][n-1]）。不要换行。

样例输入
3

1 2 3 4 5 6 7 8 9

样例输出
15
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n][n];
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (i == j)
            {
                sum += a[i][j];
            }
            
        }
        
    }
    cout << sum;
    return 0;
}