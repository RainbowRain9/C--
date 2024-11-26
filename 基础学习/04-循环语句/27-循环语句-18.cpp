/*
描述
    输入两个正整数m和n，输出从m加到n的结果（m保证比n小，统计总和时需要包括m和n）

输入
    两个正整数m和n

输出
    一个正整数，代表从m加到n的结果

样例输入
    2 4

样例输出
    9
*/

#include <iostream>
using namespace std;

int main ()
{
    int m, n;
    cin >> m >> n;
    int sum = 0;

    while (m <= n)
    {
        sum += m;
        ++m;
    }
    
    cout << sum;

    return 0;
}