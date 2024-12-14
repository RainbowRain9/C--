// Source : https://leetcode.cn/problems/maximum-score-of-a-good-subarray/description/
// Date   : 2024-11-25
/*
 * @lc app=leetcode.cn id=1793 lang=cpp
 * @lcpr version=20003
 *
 * [1793] 好子数组的最大分数
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
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = nums[k];
        int min_h = nums[k];
        int left = k, right = k;

        for (int i = 0; i < n - 1; i++)
        {
            if (right == n - 1 || left && nums[left - 1] > nums[right + 1])
            {
                min_h = min(min_h, nums[--left]);
            }
            else
            {
                min_h = min(min_h, nums[++right]);
            }
            ans = max(ans, min_h * (right - left + 1));
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,7,4,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,5,4,5,4,1,1,1]\n0\n
// @lcpr case=end

 */
