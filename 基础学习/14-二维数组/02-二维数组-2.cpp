/*
描述
定义一个100*100的二维数组a，为数组中的元素分别赋值1, -2, 3, -4, …, -10000。
输入两个整数x和y，输出a[x][y]的值（x和y保证是合法的下标值）。

输入
一个正整数n，表示n组案例。

每组案例由两个整数x和y组成。

输出
一个整数，表示a[x][y]的值。

每组案例输出完都要换行。

样例输入
2

0 0

99 99

样例输出
1

-10000
*/

#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        int a[100][100];
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                if (j % 2 == 0)
                {
                    a[i][j] = (i * 100 + j + 1);
                }
                else
                {
                    a[i][j] = -(i * 100 + j + 1);
                }
            }
            
        }
        cout << a[x][y] << endl;
    }
    return 0;
}