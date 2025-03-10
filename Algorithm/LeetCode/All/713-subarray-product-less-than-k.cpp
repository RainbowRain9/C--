/*
 * @Author: RainbowRain9
 * @Date: 2025-03-08 20:43:15
 * @LastEditTime: 2025-03-10 22:49:13
 * @FilePath: \C++\Algorithm\LeetCode\All\713-subarray-product-less-than-k.cpp
 * @Description:
 */

/*
 * @lc app=leetcode.cn id=713 lang=cpp
 * @lcpr version=30100
 *
 * [713] 乘积小于 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (51.71%)
 * Likes:    842
 * Dislikes: 0
 * Total Accepted:    139.7K
 * Total Submissions: 266.4K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 *
 *
 * 示例 1：
 *
 * 输入：nums = [10,5,2,6], k = 100
 * 输出：8
 * 解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2]、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
 * 需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3], k = 0
 * 输出：0
 *
 *
 *
 * 提示: 
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 10^6
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
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int total = 1;
        int left = 0, cnt = 0;
        for (int right = 0; right < n; right++)
        {
            int num = nums[right];
            total *= num;
            while (total >= k && left <= right)
            {
                total /= nums[left];
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << solution.numSubarrayProductLessThanK(nums, k) << endl;
}

/*
// @lcpr case=start
// [10,5,2,6]\n100\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n0\n
// @lcpr case=end

 */
