/*
 * @Author: RainbowRain9
 * @Date: 2025-03-19 19:28:13
 * @LastEditTime: 2025-03-21 14:42:26
 * @FilePath: \C++\Algorithm\LeetCode\All\162-find-peak-element.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=162 lang=cpp
 * @lcpr version=30104
 *
 * [162] 寻找峰值
 *
 * https://leetcode.cn/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (49.54%)
 * Likes:    1374
 * Dislikes: 0
 * Total Accepted:    464.1K
 * Total Submissions: 936.2K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 峰值元素是指其值严格大于左右相邻值的元素。
 *
 * 给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
 *
 * 你可以假设 nums[-1] = nums[n] = -∞ 。
 *
 * 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3,1]
 * 输出：2
 * 解释：3 是峰值元素，你的函数应该返回其索引 2。
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,1,3,5,6,4]
 * 输出：1 或 5
 * 解释：你的函数可以返回索引 1，其峰值元素为 2；
 * 或者返回索引 5， 其峰值元素为 6。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 1000
 * -2^31 <= nums[i] <= 2^31 - 1
 * 对于所有有效的 i 都有 nums[i] != nums[i + 1]
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
// TODO 2025-03-21:
// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // 使用二分查找法寻找峰值元素
        // 初始化左右指针,左指针指向-1,右指针指向数组最后一个元素
        int left = -1, right = nums.size() - 1;

        // 当左右指针相邻时退出循环
        while (left + 1 < right)
        {
            // 计算中间位置,避免整数溢出
            int mid = left + (right - left) / 2;

            // 如果中间元素大于其右侧元素
            // 说明峰值在左半部分(包括mid)
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            // 如果中间元素小于等于其右侧元素
            // 说明峰值在右半部分
            else
            {
                left = mid;
            }
        }

        // 最终right指向的位置即为峰值元素的索引
        // 因为题目保证相邻元素不相等,且数组两端可看作负无穷
        // 所以一定存在峰值元素
        return right;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << solution.findPeakElement(nums1) << endl;
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << solution.findPeakElement(nums2) << endl;
}

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,5,6,4]\n
// @lcpr case=end

 */
