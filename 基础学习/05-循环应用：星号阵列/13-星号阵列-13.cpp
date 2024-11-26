/*
描述
    输出一个空心漏斗形状的星号阵列

输入
    一个正奇数n

输出
    n行阵列，呈现上下最宽、中间最窄的空心漏斗形状。
    最后一行结束后也要换行。每行最后一个星号输出后不要输出额外的空格。

样例输入
    7

样例输出
*******
 *   *
  * *
   *
  * *
 *   *
*******
*/

#include <iostream>
using namespace std;

int main ()
{
    int n, m;
    cin >> n;
    m = n / 2 + 1;

    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < i; k++)
        {
            cout << " ";
        }
        
        for (int j = 0; j < 2 * (m - i) - 1; j++)
        {
            if (j == 0 || i == 0 || i == m - 1 || j == 2 * (m - i) - 2)
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

    for (int i = 0; i < m - 1; i++)
    {
        for (int k = 0; k < m - i - 2; k++)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * i + 3; j++)
        {
            if (j == 0 || i == m - 2 || j == 2 * i + 2)
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