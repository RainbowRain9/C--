/*
描述
    输出一个由*构成的阵列

输入
    一个正整数n

输出
    一个由*构成的n行n列的空心的阵列。最后一行结束完要换行。

样例输入
    5

样例输出
    *****
    *   *
    *   *
    *   *
    *****
*/

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || j == 1 || i == n || j == n)
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