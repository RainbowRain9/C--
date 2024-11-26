/*
问题描述
给你一个整数，输出它的相反数。

输入描述
第一行是一个正整数 T 代表测试案例的数量。(1 <= T <= 10)

每组案例包含一个整数 n。

对于 33% 的数据，n 的绝对值小于 1e9。

对于 66% 的数据，n 的绝对值小于 1e18。

对于 100% 的数据，n 的绝对值小于 1e27。

输出描述
针对每组案例，输出 n 的相反数，然后换行。

样例输入
2

1

-1

样例输出
-1

1
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a;
        cin >> a;
        long long opposite = -a;
        cout << opposite << endl;
    }
    
    return 0;
}