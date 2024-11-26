
/*
描述
输入一个整数，如果这个数字比100大，那么输出yes，否则输出no

输入
一个整数n

输出
如果n比100大，那么输出yes，否则输出no

样例输入
50

样例输出
no
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    if (n > 100)
    {
        cout << "yes";
    }
    else 
    {
        cout << "no";
    }
    
}