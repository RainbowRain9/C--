// Source : https://leetcode.cn/problems/minimum-absolute-sum-difference/description/
// Date   : 2025-02-26
/*
 * @lc app=leetcode.cn id=1818 lang=cpp
 * @lcpr version=30008
 *
 * [1818] 绝对差值和
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
    static constexpr int mod = 1000000007;

    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> res(nums1);
        ranges::sort(res);
        long long sum = 0;
        int maxn = 0;
        for (int i = 0; i < n; i++)
        {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            int j = ranges::lower_bound(res.begin(), res.end(), nums2[i]) - res.begin();
            if (j < n)
            {
                maxn = max(maxn, diff - abs(res[j] - nums2[i]));
            }
            if (j > 0)
            {
                maxn = max(maxn, diff - abs(nums2[i] - res[j - 1]));
            }
        }
        return (sum - maxn + mod) % mod;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,7,5]\n[2,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6,8,10]\n[2,4,6,8,10]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,4,4,2,7]\n[9,3,5,1,7,4]\n
// @lcpr case=end

 */
