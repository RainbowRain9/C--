/*
 * @lc app=leetcode.cn id=372 lang=cpp
 * @lcpr version=30104
 *
 * [372] 超级次方
 *
 * https://leetcode.cn/problems/super-pow/description/
 *
 * algorithms
 * Medium (56.31%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    53K
 * Total Submissions: 94.4K
 * Testcase Example:  '2\n[3]'
 *
 * 你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
 *
 *
 *
 * 示例 1：
 *
 * 输入：a = 2, b = [3]
 * 输出：8
 *
 *
 * 示例 2：
 *
 * 输入：a = 2, b = [1,0]
 * 输出：1024
 *
 *
 * 示例 3：
 *
 * 输入：a = 1, b = [4,3,3,8,5,2]
 * 输出：1
 *
 *
 * 示例 4：
 *
 * 输入：a = 2147483647, b = [2,0,0]
 * 输出：1198
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= a <= 2^31 - 1
 * 1 <= b.length <= 2000
 * 0 <= b[i] <= 9
 * b 不含前导 0
 *
 *
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
using ll = long long;
class Solution {
public:
    ll qpow(ll a, ll b, ll mod)
    {
        ll res = 1;
        while (b) {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b)
    {
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();
        int part1 = qpow(a, last, 1337);
        int part2 = qpow(superPow(a,b), 10, 1337);
        return (part1 * part2) % 1337;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 2\n[3]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,0]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[4,3,3,8,5,2]\n
// @lcpr case=end

// @lcpr case=start
// 2147483647\n[2,0,0]\n
// @lcpr case=end

 */
