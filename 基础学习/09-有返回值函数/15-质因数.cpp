/*
描述
定义：一个数字a的质因数是指能整除a而且是质数的数字，注意1并不是质数。
给定一个整数，如果这个数字的质因数的个数为1，则输出Yes，否则输出No。

输入
一个正整数n，表示测试案例的数量。

然后是n组案例，每组案例有一个正整数m。（m<=10000）

输出
针对每组案例，如果m的质因数的个数为1，则输出Yes，否则输出No。

每组案例输出完要换行。

样例输入
3
6
27
5

样例输出
No
Yes
Yes

提示说明
6的质因数有2和3，
27的质因数只有3，
5的质因数只有5。
*/

#include <iostream>
using namespace std;
bool isPrime(int a)
{
    if (a < 2) return false;
    if (a == 2) return true;
    if (a % 2 == 0) return false;
    for (int i = 3; i * i <= a; i += 2)
    {
        if (a % i == 0) return false;
    }
    return true;
}

int main ()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        int temp = 0;
        cin >> m;
        for (int i = 2; i <= m; i++)
        {
            if (isPrime(i) && m % i == 0)
            {
                temp++;
            }
            
        }
        if (temp == 1)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout << endl;
    }
    return 0;
}