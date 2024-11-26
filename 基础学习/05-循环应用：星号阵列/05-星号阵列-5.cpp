/*
描述
    输出一个由*构成的阵列

输入
    两个正整数n和m

输出
    一个由*构成的n行m列的阵列，最后一行后面也要换行。

样例输入
    3 5

样例输出
    *****
    *****
    *****
*/

#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}