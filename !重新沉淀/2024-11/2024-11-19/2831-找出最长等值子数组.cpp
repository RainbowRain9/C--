// Source : https://leetcode.cn/problems/find-the-longest-equal-subarray/description/
// Date   : 2024-11-19

/**************************************************
 * 题目描述：
 * 给你一个下标从 0 开始的数组 nums 和一个整数 k 。
 * 如果一个子数组内所有元素都相等，则认为这个子数组是一个 等值子数组 。
 * 请你返回 nums 中最长等值子数组的长度，但你最多可以删除 k 个元素。
 *
 * 示例 1：
 *   输入：nums = [1,3,2,3,1,3], k = 3
 *   输出：3
 *   解释：要想得到最长等值子数组，可以删除下标 2 和下标 4 的元素。
 *   删除后，nums 变为 [1,3,3,3] ，其中 [3,3,3] 是最长等值子数组，长度为 3 。
 *
 * 示例 2：
 *   输入：nums = [1,1,2,2,1,1], k = 2
 *   输出：4
 *   解释：要想得到最长等值子数组，可以删除下标 2 和下标 3 的元素。
 *   删除后，nums 变为 [1,1,1,1] ，其中 [1,1,1,1] 是最长等值子数组，长度为 4 。
 *
 * 提示：
 *   - 1 <= nums.length <= 10^5
 *   - 1 <= nums[i] <= nums.length
 *   - 0 <= k <= nums.length
 **************************************************/

/*
    解题思路：
    1. 对于每个值，找出所有相同值的位置，组成一个数组
    2. 对于每个位置数组，用滑动窗口找出最长的等值子数组
    3. 窗口内的位置差减去窗口大小就是需要删除的元素个数
    4. 如果需要删除的元素个数小于等于k，则更新最大长度

    时间复杂度分析：O(n)，其中n为数组长度
*/
/*
 * @lc app=leetcode.cn id=2831 lang=cpp
 * @lcpr version=20003
 *
 * [2831] 找出最长等值子数组
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
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            pos[x].push_back(i - pos[x].size());
        }

        int ans = 0;
        for (auto &p : pos)
        {
            int left = 0;
            for (int right = 0; right < p.size(); right++)
            {
                while (p[right] - p[left] > k)
                {
                    left++;
                }
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,2,3,1,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,2,1,1]\n2\n
// @lcpr case=end

 */
