/*
 * @Author: RainbowRain9
 * @Date: 2025-03-31 15:45:17
 * @LastEditTime: 2025-03-31 20:18:41
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week6\04-How-many-zero-2.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 给出两个正整数 n 和 m，计算 n! × (n+1)! × ... × (m-1)! × m! 的末尾有多少个零。
 *
 * 示例 1：
 *   输入：3 6
 *   输出：2
 *   解释：3! × 4! × 5! × 6! = 6 * 24 *120 * 720 = 12441600，末尾有两个零
 *
 * 示例 2：
 *   输入：5 5
 *   输出：1
 *   解释：5! = 120，末尾有一个零
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
#define int long long
using namespace std;
int f(int n)
{
    int ans = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        int a = n / i;
        int b = n % i + 1;
        ans += i * a * (a - 1) / 2 + a * b;
    }
    return ans;
}

void work()
{
    int n, m;
    cin >> n >> m;
    cout << f(m) - f(n - 1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        work();
    }
    return 0;
}