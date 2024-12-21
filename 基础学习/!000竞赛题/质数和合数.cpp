// Source : https://xujcoj.com/home/contest/2070/problem/3
// Date   : 2024-12-21

/**************************************************
 * 题目描述：
 * 质数也称为素数，指的是一个正整数仅有1和自己两个因子。
 * 合数指的是一个正整数除了1和自己以外，还有别的因子。
 * 计算m个整数中有几个质数几个合数。
 *
 * 示例 1：
 *   输入：
 *   1
 *   5
 *   3 4 5 6 7
 *   输出：
 *   3 2
 *   解释：3、5、7是质数，4、6是合数
 **************************************************/

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
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n == 2)
        return true;
    if (n < 2 || n % 2 == 0)
        return false;
    for (int i = 3; i <= n / i; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;

            if (isPrime(x))
                cnt1++;
            else if (x > 1)
                cnt2++;
        }
        cout << cnt1 << " " << cnt2 << endl;
    }
    return 0;
}
