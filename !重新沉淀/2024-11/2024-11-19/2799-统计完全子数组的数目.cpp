// Source : https://leetcode.cn/problems/count-complete-subarrays-in-an-array/description/
// Date   : 2024-11-19

/**************************************************
 * 题目描述：
 * 给你一个由 正 整数组成的数组 nums 。
 * 如果数组中的某个子数组满足下述条件，则称之为 完全子数组 ：
 * - 子数组中不同元素的数目等于 nums 中不同元素的数目。
 * 返回 nums 中 完全子数组 的数目。
 * 子数组 是数组中的一个连续非空序列。
 *
 * 示例 1：
 *   输入：nums = [1,3,1,2,2]
 *   输出：4
 *   解释：完全子数组如下：[1,3,1,2]、[1,3,1,2,2]、[3,1,2] 和 [3,1,2,2]。
 *
 * 示例 2：
 *   输入：nums = [5,5,5,5]
 *   输出：10
 *   解释：数组仅包含值 5 ，所以任意子数组都包含相同数目的不同元素。子数组总数为 10 。
 *
 * 提示：
 *   - 1 <= nums.length <= 1000
 *   - 1 <= nums[i] <= 2000
 **************************************************/

/*
    解题思路：
    1. 先统计原数组中不同元素的个数
    2. 使用滑动窗口统计每个子数组中不同元素的个数
    3. 当子数组中不同元素个数等于原数组时，该子数组为完全子数组

    时间复杂度分析：O(n^2)，其中n为数组长度
*/
/*
 * @lc app=leetcode.cn id=2799 lang=cpp
 * @lcpr version=20003
 *
 * [2799] 统计完全子数组的数目
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
class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int m = unordered_set<int>(nums.begin(), nums.end()).size();
        unordered_map<int, int> cnt;
        int left = 0;
        int ans = 0;
        for (int num : nums)
        {
            cnt[num]++;
            while (cnt.size() == m)
            {
                int x = nums[left++];
                if (--cnt[x] == 0)
                {
                    cnt.erase(x);
                }
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

 */
