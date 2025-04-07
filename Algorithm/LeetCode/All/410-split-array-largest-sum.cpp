/*
 * @Author: RainbowRain9
 * @Date: 2025-03-15 17:11:00
 * @LastEditTime: 2025-03-15 18:06:15
 * @FilePath: \C++\Algorithm\LeetCode\All\410-split-array-largest-sum.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=410 lang=cpp
 * @lcpr version=30103
 *
 * [410] 分割数组的最大值
 *
 * https://leetcode.cn/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (60.59%)
 * Likes:    1035
 * Dislikes: 0
 * Total Accepted:    100.8K
 * Total Submissions: 166.2K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * 给定一个非负整数数组 nums 和一个整数 k ，你需要将这个数组分成 k 个非空的连续子数组，使得这 k 个子数组各自和的最大值 最小。
 *
 * 返回分割后最小的和的最大值。
 *
 * 子数组 是数组中连续的部份。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [7,2,5,10,8], k = 2
 * 输出：18
 * 解释：
 * 一共有四种方法将 nums 分割为 2 个子数组。
 * 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
 * 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3,4,5], k = 2
 * 输出：9
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,4,4], k = 3
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 10^6
 * 1 <= k <= min(50, nums.length)
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
// TODO 2025-03-15: 410.分割数组的最大值
// @lc code=start
class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long left = 0, right = 0;
        for (auto num : nums)
        {
            left = max(left, (long long)num);
            right += num;
        }

        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            int count = 1;
            long long curr_sum = 0;
            for (auto num : nums)
            {
                if (curr_sum + num > mid)
                {
                    count++;
                    curr_sum = num;
                    if (count > k)
                        break;
                }
                else
                {
                    curr_sum += num;
                }
            }
            if (count > k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums1 = {7, 2, 5, 10, 8};
    cout << solution.splitArray(nums1, 2) << endl; // Expected: 18

    vector<int> nums2 = {1, 2, 3, 4, 5}; 
    cout << solution.splitArray(nums2, 2) << endl; // Expected: 9

    vector<int> nums3 = {1, 4, 4};
    cout << solution.splitArray(nums3, 3) << endl; // Expected: 4
}

/*
// @lcpr case=start
// [7,2,5,10,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,4]\n3\n
// @lcpr case=end

 */
