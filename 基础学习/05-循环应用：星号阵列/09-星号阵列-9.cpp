/*
描述
    输出一个由数字构成的阵列

输入
    一个正整数n（n<10）

输出
    一个由数字构成的n行的阵列，其中第一行是1，第二行是12，...，第n行是123...直到n，最后一行后面也要换行。

样例输入
    3

样例输出
    1
    12
    123
*/

#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
    
    return 0;
}