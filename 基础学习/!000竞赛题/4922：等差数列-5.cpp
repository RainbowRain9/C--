/*
问题描述
有一个等差数列，首项是a，公差是d，尾项是一个不大于b的最大合法值。求数列的和。

输入描述
这是一道多组案例的题目。一个正整数n，表示案例的数量。（n<=1000）

每组案例由3个整数a、b、d构成，含义见问题描述。（-1e8<=a<=b<=1e8，1<=d<=1e8）

输出描述
针对每组案例，输出对应的等差数列所有项之和。

每组案例输出完都要换行。

样例输入
2

1 12 3

-100000000 100000000 1

样例输出
22

0
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b, d;
        cin >> a >> b >> d;

        long long m = (b - a) / d + 1;
        long long sum = m * (2 * a + (m - 1) * d) / 2;

        cout << sum << endl;
    }

    return 0;
}