// Source : https://leetcode.cn/problems/powx-n/description/
// Date   : 2024-11-29
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 * @lcpr version=20003
 *
 * [50] Pow(x, n)
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    double myPow(double x, int N)
    {
        double ans = 1;
        long long n = N;
        if (n < 0)
        {
            n = -n;
            x = 1 / x;
        }
        while (n)
        {
            if (n & 1)
                ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2.00000\n10\n
// @lcpr case=end

// @lcpr case=start
// 2.10000\n3\n
// @lcpr case=end

// @lcpr case=start
// 2.00000\n-2\n
// @lcpr case=end

 */
