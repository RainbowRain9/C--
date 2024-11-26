/*
描述
输入一个整数，如果这个数字是奇数，那么输出yes，否则输出no。

输入
一个整数n

输出
如果n是奇数，那么输出yes，否则输出no

样例输入
5

样例输出
yes
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "no";
    }

    else
    {
        cout << "yes";
    }
    
    return 0;
}