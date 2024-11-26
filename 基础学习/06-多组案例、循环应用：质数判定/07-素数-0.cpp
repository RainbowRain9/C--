/*
描述
    输入n个数字，判断哪些是素数，哪些不是素数

输入
    一个正整数n，表示n组案例。

    每组案例中有一个整数m。

输出
    针对每组案例，如果m是素数则输出1，否则输出0。每组案例输出完都要换行。

样例输入
    3
    10
    11
    -4

样例输出
    0
    1
    0 

提示说明
    10不是素数，11是素数
    注意：素数必须是大于等于2以上的数字，且除了1和自身以外没有别的因数。
    小于2的数字一定不是素数。
*/

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        if (m <= 1)
        {
            cout << "0";
        }
        else if (m == 2)
        {
            cout  << "1";
        }
        else if (m % 2 == 0)
        {
            cout << "0";
        }
        
        else
        {
            int isPrime = 1;
            for (int j = 3; j <= sqrt(m); j += 2)
            {
                if (m % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
            cout << isPrime;
        }
        cout << endl;
        
    }
    
    return 0;
}