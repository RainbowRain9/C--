// Source : https://www.xujcoj.com/home/problem/detail/4374
// Date   : 2024-12-01

/**************************************************
 * 题目描述：
 * 国王将金币作为工资发放给骑士。第一天发1枚金币，之后两天每天发2枚金币，再之后三天每天发3枚金币，
 * 以此类推。当连续n天每天收到n枚金币后，接下来的n+1天里每天收到n+1枚金币。
 * 计算在前k天里骑士一共获得了多少枚金币。
 *
 * 示例 1：
 *   输入：
 *   2
 *   6
 *   1000
 *   输出：
 *   14
 *   29820
 *   解释：
 *   第一个测试用例k=6:
 *   第1天收到1枚金币
 *   第2-3天每天收到2枚金币
 *   第4-6天每天收到3枚金币
 *   总计: 1 + 2*2 + 3*3 = 14枚金币
 *
 * 提示：
 *   - 1 ≤ k ≤ 10^18
 *   - 1 ≤ T ≤ 10000
 *   - 答案需要对10^9+7取模
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

int main()
{
    int T;
    cin >> T;
    const int MOD = 1000000007;

    while (T--)
    {
        long long k;
        cin >> k;

        // 二分查找最大的n,使得前n组天数和<=k
        long long left = 1, right = 2000000;
        while (left < right)
        {
            long long mid = (left + right + 1) / 2;
            // 避免溢出的天数计算
            long long days = 0;
            if (mid <= 2000)
            { // 小数据直接计算
                days = mid * (mid + 1) / 2;
            }
            else
            {
                // 大数据时需要判断是否超过k
                if (mid > 1000000)
                {
                    right = mid - 1;
                    continue;
                }
                days = mid;
                days = (days * (mid + 1)) / 2;
            }

            if (days <= k)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        long long n = left;
        long long days = n * (n + 1) / 2;

        // 计算前n组的金币总和
        long long sum = n;
        sum = (sum * (n + 1)) % MOD;
        sum = (sum * (2 * n + 1)) % MOD;
        sum = sum * 166666668 % MOD;

        // 处理剩余天数
        if (k > days)
        {
            long long remain = k - days;
            sum = (sum + (n + 1) * remain % MOD) % MOD;
        }

        cout << sum << endl;
    }
    return 0;
}