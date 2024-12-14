// Source : https://leetcode.cn/problems/continuous-subarrays/description/
// Date   : 2024-11-19

/**************************************************
 * 题目描述：
 * 给你一个下标从 0 开始的整数数组 nums 。如果满足下述条件，则称子数组是 不间断 的：
 * - 对于子数组中的每个相邻元素对，两个元素的差的绝对值小于或等于 2 。
 * 返回 nums 中所有 不间断 子数组的数目。
 * 子数组是数组中的一个连续元素序列。
 *
 * 示例 1：
 *   输入：nums = [5,4,2,4]
 *   输出：8
 *   解释：不间断子数组有：[5], [4], [2], [4], [5,4], [4,2], [2,4], [4,2,4]
 *        - [5] 是不间断子数组，因为它只包含一个元素。
 *        - [4] 是不间断子数组，因为它只包含一个元素。
 *        - [2] 是不间断子数组，因为它只包含一个元素。
 *        - [4] 是不间断子数组，因为它只包含一个元素。
 *        - [5,4] 是不间断子数组，因为 |5-4| <= 2 。
 *        - [4,2] 是不间断子数组，因为 |4-2| <= 2 。
 *        - [2,4] 是不间断子数组，因为 |2-4| <= 2 。
 *        - [4,2,4] 是不间断子数组，因为 |4-2| <= 2 且 |2-4| <= 2 。
 *
 * 示例 2：
 *   输入：nums = [1,2,3]
 *   输出：6
 *   解释：不间断子数组有：[1], [2], [3], [1,2], [2,3], [1,2,3]
 *        - 所有长度为 1 的子数组都是不间断子数组。
 *        - [1,2] 是不间断子数组，因为 |1-2| <= 2 。
 *        - [2,3] 是不间断子数组，因为 |2-3| <= 2 。
 *        - [1,2,3] 是不间断子数组，因为 |1-2| <= 2 且 |2-3| <= 2 。
 *
 * 提示：
 *   - 1 <= nums.length <= 10^5
 *   - 1 <= nums[i] <= 10^9
 **************************************************/

/*
    解题思路：
    使用滑动窗口来解决这个问题。维护一个窗口，使得窗口内的最大值和最小值的差不超过2。
    对于每个右端点，找到最左边的位置，使得从这个位置到右端点的子数组是不间断的。
    这样，对于每个右端点，可以计算出以它为右端点的不间断子数组的数目。

    时间复杂度分析：O(n)，其中n是数组的长度。
*/
/*
 * @lc app=leetcode.cn id=2762 lang=cpp
 * @lcpr version=20003
 *
 * [2762] 不间断子数组
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
    long long continuousSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        map<int, int> cnt;
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            cnt[nums[right]]++;
            while (cnt.rbegin()->first - cnt.begin()->first > 2)
            {
                int y = nums[left++];
                if (--cnt[y] == 0)
                {
                    cnt.erase(y);
                }
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,4,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
