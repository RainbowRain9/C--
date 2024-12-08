/*
问题描述
这道题目很简单，你只需要输出 n 个 n 按位异或的结果就可以了。

输入描述
第一行是一个正整数 T 代表测试案例的数量。(1 ≤ T ≤ 1000)

每组案例包含一个正整数 n。(1 ≤ n ≤ 1e9)

输出描述
针对每组案例，输出 n 个 n 按位异或的结果，然后换行。

样例输入
1

3

样例输出
3

提示说明
3 ^ 3 ^ 3 = 3
*/

#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long n;
        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            n = (n ^ n);
        }

        cout << n << endl;
    }

    return 0;
}