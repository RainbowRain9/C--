/*
 * @Author: RainbowRain9
 * @Date: 2025-03-09 21:11:45
 * @LastEditTime: 2025-03-09 21:37:57
 * @FilePath: \C++\Algorithm\LeetCode\All\977-squares-of-a-sorted-array.cpp
 * @Description: 
 */
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30100
 *
 * [977] 有序数组的平方
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (68.73%)
 * Likes:    1057
 * Dislikes: 0
 * Total Accepted:    769.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 *
 * 示例 2：
 *
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 已按 非递减顺序 排序
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
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
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        int p = n - 1;
        while (left <= right)
        {
            int a = nums[left] * nums[left];
            int b = nums[right] * nums[right];
            if (a < b)
            {
                result[p] = b;
                right--;
            }
            else
            {
                result[p] = a;
                left++;
            }
            p--;
        }
        return result;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = solution.sortedSquares(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
}

/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */
