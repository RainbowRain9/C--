/*
输入描述
m n（两个自然数）

输出描述
k:最大公约数

样例输入
48 36

样例输出
12

提示说明
输出不换行
*/

#include <iostream>
using namespace std;

int gcd(int m, int n)
{
    while (m % n != 0)
    {
        int k = m % n;
        m = n;
        n = k;
    }
    return n;
}
int main()
{
    int m, n;
    cin >> m >> n;
    cout << gcd(m, n);
    return 0;
}