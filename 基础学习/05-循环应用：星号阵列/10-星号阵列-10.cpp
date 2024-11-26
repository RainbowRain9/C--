/*
描述
    输出一个星号阵列

输入
    一个正整数n

输出
    n行n列，其中奇数行的奇数列是+，奇数行的偶数列是-，偶数行的奇数列是-，偶数行的偶数列是+。
    最后一行结尾处也要换行。

样例输入
    4

样例输出
    +-+-

    -+-+

    +-+-

    -+-+
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
            if ((i % 2 == 1 && j % 2 == 1) || (i % 2 == 0 && j % 2 == 0))
            {
                cout << "+";
            }
            if ((i % 2 == 1 && j % 2 == 0) || (i % 2 == 0 && j % 2 == 1))
            {
                cout << "-";
            }
            
        }
        cout << endl;
    }
    
    return 0;
}