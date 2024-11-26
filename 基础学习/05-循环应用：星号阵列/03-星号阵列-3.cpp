/*
描述
    输出一个由*构成的阵列

输入
    一个正整数n

输出
    一个由*构成的n行的阵列，其中第一行有n个*，第二行有n-1个*，...，第n行有1个*，
    最后一行后面也要换行。

样例输入
    3

样例输出
    ***
    **
    *
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1 - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}