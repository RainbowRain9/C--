// Source : https://leetcode.cn/problems/binary-subarrays-with-sum/description/
// Date   : 2024-11-19

/**************************************************
 * 题目描述：
 * 给你一个二元数组 nums 和一个整数 goal ，请你统计并返回有多少个和为 goal 的 非空 子数组。
 * 子数组 是数组的一段连续部分。
 *
 * 示例 1：
 *   输入：nums = [1,0,1,0,1], goal = 2
 *   输出：4
 *   解释：如下面所示，有 4 个满足题目要求的子数组：
 *   [1,0,1]、[1,0,1,0]、[0,1,0,1]、[1,0,1]
 *
 * 示例 2：
 *   输入：nums = [0,0,0,0,0], goal = 0
 *   输出：15
 *
 * 提示：
 *   - 1 <= nums.length <= 3 * 10^4
 *   - nums[i] 不是 0 就是 1
 *   - 0 <= goal <= nums.length
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个可变长度的窗口
    2. 由于要求和恰好等于goal，可以转化为"至少"的问题:
       - 统计和>=goal的子数组个数
       - 统计和>=goal+1的子数组个数
       - 两者相减即为和恰好等于goal的子数组个数

    时间复杂度分析：O(n)，其中n为数组长度
*/
/*
 * @lc app=leetcode.cn id=930 lang=cpp
 * @lcpr version=20003
 *
 * [930] 和相同的二元子数组
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
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    int atMost(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int left = 0, right = 0;
        int ans = 0, sum = 0;
        while (right < n)
        {
            sum += nums[right];
            while (sum > goal)
            {
                sum -= nums[left++];
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,1,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0,0]\n0\n
// @lcpr case=end

 */
