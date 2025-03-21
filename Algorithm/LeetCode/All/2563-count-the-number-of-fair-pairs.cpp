/*
 * @Author: RainbowRain9
 * @Date: 2025-03-17 21:40:10
 * @LastEditTime: 2025-03-17 22:01:50
 * @FilePath: \C++\Algorithm\LeetCode\All\2563-count-the-number-of-fair-pairs.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 * @lcpr version=30103
 *
 * [2563] 统计公平数对的数目
 *
 * https://leetcode.cn/problems/count-the-number-of-fair-pairs/description/
 *
 * algorithms
 * Medium (41.05%)
 * Likes:    99
 * Dislikes: 0
 * Total Accepted:    19.6K
 * Total Submissions: 45.9K
 * Testcase Example:  '[0,1,7,4,4,5]\n3\n6'
 *
 * 给你一个下标从 0 开始、长度为 n 的整数数组 nums ，和两个整数 lower 和 upper ，返回 公平数对的数目 。
 *
 * 如果 (i, j) 数对满足以下情况，则认为它是一个 公平数对 ：
 *
 *
 * 0 <= i < j < n，且
 * lower <= nums[i] + nums[j] <= upper
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [0,1,7,4,4,5], lower = 3, upper = 6
 * 输出：6
 * 解释：共计 6 个公平数对：(0,3)、(0,4)、(0,5)、(1,3)、(1,4) 和 (1,5) 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,7,9,2,5], lower = 11, upper = 11
 * 输出：1
 * 解释：只有单个公平数对：(2,3) 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * nums.length == n
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= lower <= upper <= 10^9
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
// TODO 2025-03-17: 
// @lc code=start
class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        // 0,1,4,4,5,7
        int n = nums.size();
        long long count = 0;
        ranges::sort(nums);
        for (int i = 0; i < n; i++)
        {
            auto a = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
            auto b = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
            count += b - a;
        }

        return count;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums1 = {0, 1, 7, 4, 4, 5};
    int lower1 = 3, upper1 = 6;
    cout << "Test case 1: " << solution.countFairPairs(nums1, lower1, upper1) << endl;

    vector<int> nums2 = {1, 7, 9, 2, 5};
    int lower2 = 11, upper2 = 11;
    cout << "Test case 2: " << solution.countFairPairs(nums2, lower2, upper2) << endl;
}

/*
// @lcpr case=start
// [0,1,7,4,4,5]\n3\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,7,9,2,5]\n11\n11\n
// @lcpr case=end

 */
