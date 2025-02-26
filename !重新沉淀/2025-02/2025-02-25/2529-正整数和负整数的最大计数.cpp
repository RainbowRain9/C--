// Source : https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/description/
// Date   : 2025-02-25
/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 * @lcpr version=20004
 *
 * [2529] 正整数和负整数的最大计数
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
    int maximumCount(vector<int> &nums)
    {
        // 使用二分查找找到第一个大于等于0的元素位置
        int firstNonNeg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        // 使用二分查找找到第一个大于0的元素位置
        int firstPos = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        // 负数的数量就是第一个非负数的索引
        int neg = firstNonNeg;
        // 正数的数量就是总长度减去第一个正数的索引
        int pos = nums.size() - firstPos;
        
        return max(pos, neg);
    }
    // End of Selection
};
// @lc code=end

/*
// @lcpr case=start
// [-2,-1,-1,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-3,-2,-1,0,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,20,66,1314]\n
// @lcpr case=end

 */
