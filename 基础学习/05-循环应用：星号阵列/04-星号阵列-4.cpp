/*
描述
    输出一个由*构成的阵列

输入
    一个正整数n

输出
    一个由*构成的n行的阵列，其中第一行有1个*，第二行有3个*，...，第n行有2n-1个*，最后一行后面也要换行。

样例输入
    3

样例输出
    *
    ***
    *****
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    
    return 0;
}