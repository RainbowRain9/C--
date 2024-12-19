// Source : https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// Date   : 2024-12-18
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=20004
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    int lower_bound(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
        {
            return {-1, -1};
        }
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
