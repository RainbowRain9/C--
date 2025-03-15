/*
 * @Author: RainbowRain9
 * @Date: 2025-03-13 14:52:15
 * @LastEditTime: 2025-03-14 22:43:32
 * @FilePath: \C++\Algorithm\LeetCode\All\704-binary-search.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 * @lcpr version=30101
 *
 * [704] 二分查找
 *
 * https://leetcode.cn/problems/binary-search/description/
 *
 * algorithms
 * Easy (55.92%)
 * Likes:    1662
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.4M
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的
 * target，如果目标值存在返回下标，否则返回 -1。
 *
 *
 * 示例 1:
 *
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 *
 *
 * 示例 2:
 *
 * 输入: nums = [-1,0,3,5,9,12], target = 2
 * 输出: -1
 * 解释: 2 不存在 nums 中因此返回 -1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 你可以假设 nums 中的所有元素是不重复的。
 * n 将在 [1, 10000]之间。
 * nums 的每个元素都将在 [-9999, 9999]之间。
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
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target) // 方法1：使用ranges::lower_bound
    {
        // 获取数组大小
        int n = nums.size();
        // 使用lower_bound找到第一个大于等于target的位置
        auto it = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // 如果找到的位置有效且等于target则返回下标，否则返回-1
        return it < nums.size() && nums[it] == target ? it : -1;
    }
    // int search(vector<int> &nums, int target) // 方法2：使用二分查找
    // {
    //     // 初始化左右边界
    //     int left = 0, right = nums.size() - 1;
    //     // 当左边界小于等于右边界时继续查找
    //     while (left <= right) {
    //         // 计算中间位置，避免溢出
    //         int mid = left + (right - left) / 2;
    //         // 如果找到目标值，返回下标
    //         if (nums[mid] == target) {
    //             return mid;
    //         }
    //         // 如果中间值小于目标值，在右半部分继续查找
    //         else if (nums[mid] < target) {
    //             left = mid + 1;
    //         }
    //         // 如果中间值大于目标值，在左半部分继续查找
    //         else {
    //             right = mid - 1;
    //         }
    //     }
    //     // 未找到目标值，返回-1
    //     return -1;
    // }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << solution.search(nums, target) << endl;
}

/*
// @lcpr case=start
// [-1,0,3,5,9,12]\n9\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,3,5,9,12]\n2\n
// @lcpr case=end

 */
