/*
描述
把从某个数字开始起的10个素数存放在数组中，然后输出这10个素数的总和

输入
一个正整数n，表示n组案例。

每组案例由一个正整数m组成。

输出
针对每组案例，输出一个整数，表示大于等于m的最小10个不同素数的和。

每组案例输出完都要换行。

样例输入
1

4

样例输出
192

提示说明
5+7+11+13+17+19+23+29+31+37=192
*/

#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        int sum = 0;
        int temp = 0;
        int number[10];
        cin >> m;
        for (int i = m; ; i++)
        {
            if (isPrime(i))
            {
                sum += i;
                temp++;
                if (temp == 10)
                {
                    break;
                }
            }
            
        }
        cout << sum << endl;
    }
    return 0;
}