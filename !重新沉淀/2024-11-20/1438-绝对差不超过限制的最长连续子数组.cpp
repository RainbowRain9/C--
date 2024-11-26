// Source : https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/
// Date   : 2024-11-20
/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 * @lcpr version=20003
 *
 * [1438] 绝对差不超过限制的最长连续子数组
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
    int longestSubarray(vector<int> &nums, int limit)
    {
        multiset<int> s;
        int n = nums.size();
        int left = 0, right = 0;
        int ans = 0;
        while (right < n)
        {
            s.insert(nums[right]);
            while (*s.rbegin() - *s.begin() > limit)
            {
                s.erase(s.find(nums[left++]));
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [8,2,4,7]\n4\n
// @lcpr case=end

// @lcpr case=start
// [10,1,2,4,7,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,2,4,4,2,2]\n0\n
// @lcpr case=end

 */
