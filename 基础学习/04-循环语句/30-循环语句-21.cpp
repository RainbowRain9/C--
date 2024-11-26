/*
描述
    输入三个正整数a、b、c，输出比a小的能被b或者c整除的数字中最大的数字。

输入
    三个正整数a、b、c

输出
    比a小的能被b或者c整除的数字中最大的数字

样例输入
    20 6 7

样例输出
    18
*/

#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    while (a--)
    {
        if (a % b == 0 || a % c == 0)
        {
            cout << a;
            break;
        }
    }
    
    return 0;
}