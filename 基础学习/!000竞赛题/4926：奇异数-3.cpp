/*
问题描述
如果一个正整数的因数恰好有3个，则称该整数是一个奇异数。例如4的因子有1、2、4三个，故4是一个奇异数。

统计不大于m的正整数中，所有奇异数之和。

输入描述
这是一道多组案例的题目。一个正整数n，表示案例的数量。（n<=10）

每组案例由一个正整数m组成。（m<=100000）

输出描述
针对每组案例，输出一个整数，表示不大于m的正整数中，所有奇异数之和。

每组案例输出完都要换行。

样例输入
2

4

10

样例输出
4

13
*/

#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void StrangeNumbers(int m, int *s, int &count)
{
    count = 0;
    for (int i = 2; i * i <= m; i++)
    {
        if (isPrime(i))
        {
            s[count++] = i * i;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int count;
    int s[100000];

    while (n--)
    {
        int m;
        cin >> m;

        StrangeNumbers(m, s, count);

        int sum = 0;
        for (int i = 0; i < count; i++)
        {
            sum += s[i];
        }
        cout << sum << endl;
    }

    return 0;
}