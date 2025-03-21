/*
 * @Author: RainbowRain9
 * @Date: 2025-03-18 22:46:20
 * @LastEditTime: 2025-03-19 17:53:41
 * @FilePath: \C++\Algorithm\LeetCode\All\2439-minimize-maximum-of-array.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=2439 lang=cpp
 * @lcpr version=30103
 *
 * [2439] 最小化数组中的最大值
 *
 * https://leetcode.cn/problems/minimize-maximum-of-array/description/
 *
 * algorithms
 * Medium (42.96%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    13.8K
 * Total Submissions: 31.2K
 * Testcase Example:  '[3,7,1,6]'
 *
 * 给你一个下标从 0 开始的数组 nums ，它含有 n 个非负整数。
 *
 * 每一步操作中，你需要：
 *
 *
 * 选择一个满足 1 <= i < n 的整数 i ，且 nums[i] > 0 。
 * 将 nums[i] 减 1 。
 * 将 nums[i - 1] 加 1 。
 *
 *
 * 你可以对数组执行 任意 次上述操作，请你返回可以得到的 nums 数组中 最大值 最小 为多少。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [3,7,1,6]
 * 输出：5
 * 解释：
 * 一串最优操作是：
 * 1. 选择 i = 1 ，nums 变为 [4,6,1,6] 。
 * 2. 选择 i = 3 ，nums 变为 [4,6,2,5] 。
 * 3. 选择 i = 1 ，nums 变为 [5,5,2,5] 。
 * nums 中最大值为 5 。无法得到比 5 更小的最大值。
 * 所以我们返回 5 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [10,1]
 * 输出：10
 * 解释：
 * 最优解是不改动 nums ，10 是最大值，所以返回 10 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 2 <= n <= 10^5
 * 0 <= nums[i] <= 10^9
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
// TODO 2025-03-19: 
// @lc code=start
class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        // check函数用于检查给定的limit值是否可行
        // 即是否可以通过操作使数组中的最大值不超过limit
        auto check = [&](int limit) -> bool
        {
            // extra表示当前位置无法通过limit限制需要向前传递的值
            long long extra = 0;
            // 从后向前遍历数组
            for (int i = nums.size() - 1; i > 0; i--)
            {
                // 对于当前位置i，计算需要向前传递的值
                // nums[i] + extra表示当前位置的值加上后面传递来的值
                // 如果超过了limit，差值就需要向前传递
                // 使用max确保extra不会为负数
                extra = max(nums[i] + extra - limit, 0LL);
            }
            // 最后检查第一个元素加上传递来的值是否不超过limit
            return nums[0] + extra <= limit;
        };

        // 二分查找可行的最小limit值
        // left初始为-1，right初始为数组中的最大值
        int left = -1, right = *max_element(nums.begin(), nums.end());
        
        // 二分查找的经典模板
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            // 如果mid值可行，说明答案可能在左半部分
            // 否则答案在右半部分
            (check(mid) ? right : left) = mid;
        }
        
        // 返回找到的最小可行值
        return right;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums1 = {3,7,1,6};
    cout << solution.minimizeArrayValue(nums1) << endl; // Expected: 5
    
    vector<int> nums2 = {10,1}; 
    cout << solution.minimizeArrayValue(nums2) << endl; // Expected: 10
}

/*
// @lcpr case=start
// [3,7,1,6]\n
// @lcpr case=end

// @lcpr case=start
// [10,1]\n
// @lcpr case=end

 */
