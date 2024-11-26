/*
描述
输入一个整数m，输出比m小的最大的素数。

输入
一个正整数n，表示测试案例的数量。

每组测试案例中有一个整数m。

输出
针对每组案例，输出一个整数，表示比m小的最大的素数。如果比m小的数字里没有素数，则输出-1。

每组案例输出完都要换行。

样例输入
3
11
15
0

样例输出
7
13
-1
*/

#include <iostream>
using namespace std;
bool isPrime(int m){
    if (m <= 1) return false;
    if (m == 2) return true;
    if (m % 2 == 0) return false;
    if (m > 2)
    {
        for (int i = 3; i * i <= m; i += 2)
        {
            if (m % i == 0) return false;
        }
        return true;
    }
}

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, max = 0;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            if (isPrime(j))
            {
                max = j;
            }
        }
        if (max == 0)
        {
            cout << "-1";
        }
        else
        {
            cout << max;
        }
        cout << endl;
    }
    return 0;
}