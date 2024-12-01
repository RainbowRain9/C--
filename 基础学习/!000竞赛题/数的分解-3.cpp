// Source : https://xujcoj.com/home/contest/2008/problem/4
// Date   : 2024/01/08

/*********************************************************
题目:数的分解-3
时间限制：1000ms  内存限制：65536kb
总通过人数: 1  总提交人数: 1

题目描述
给你一个正整数n，问能否把n分解成3个互不相同且大于1的正整数乘积。

输入
第一行输入一个整数T，表示测试用例的数量。(1≤T≤1000)
接下来T行，每行输入一个正整数n。(1≤n≤10^9)

输出
针对每组案例，若能把n分解成3个互不相同且大于1的正整数乘积，输出YES，否则输出NO。

样例输入
2
12
30

样例输出
NO
YES

提示
不要用Python提交本题

思路:
1. 对于每个数n，尝试找到3个不同的因子
2. 从最小的因子2开始尝试
3. 如果能找到3个不同的因子且乘积等于n，则输出YES
4. 否则输出NO
*********************************************************/

using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

bool f(int n)
{
    for (int i = 2; i * i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int temp = n / i;
            for (int j = i + 1; j * j <= temp; j++)
            {
                if (temp % j == 0)
                {
                    int k = temp / j;
                    if (k > j)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (f(n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
