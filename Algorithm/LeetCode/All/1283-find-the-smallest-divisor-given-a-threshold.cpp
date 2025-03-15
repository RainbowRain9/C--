/*
 * @Author: RainbowRain9
 * @Date: 2025-03-15 19:23:13
 * @LastEditTime: 2025-03-15 20:59:53
 * @FilePath: \C++\Algorithm\LeetCode\All\1283-find-the-smallest-divisor-given-a-threshold.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=1283 lang=cpp
 * @lcpr version=30103
 *
 * [1283] 使结果不超过阈值的最小除数
 *
 * https://leetcode.cn/problems/find-the-smallest-divisor-given-a-threshold/description/
 *
 * algorithms
 * Medium (53.30%)
 * Likes:    138
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 47.6K
 * Testcase Example:  '[1,2,5,9]\n6'
 *
 * 给你一个整数数组 nums 和一个正整数 threshold  ，你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。
 *
 * 请你找出能够使上述结果小于等于阈值 threshold 的除数中 最小 的那个。
 *
 * 每个数除以除数后都向上取整，比方说 7/3 = 3 ， 10/2 = 5 。
 *
 * 题目保证一定有解。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,5,9], threshold = 6
 * 输出：5
 * 解释：如果除数为 1 ，我们可以得到和为 17 （1+2+5+9）。
 * 如果除数为 4 ，我们可以得到和为 7 (1+1+2+3) 。如果除数为 5 ，和为 5 (1+1+1+2)。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,3,5,7,11], threshold = 11
 * 输出：3
 *
 *
 * 示例 3：
 *
 * 输入：nums = [19], threshold = 5
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * 1 <= nums[i] <= 10^6
 * nums.length <= threshold <= 10^6
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
// TODO 2025-03-15:
// @lc code=start
class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int sum = 0;
            for (auto num : nums)
            {
                sum += (num + mid - 1) / mid;
            }
            if (sum <= threshold)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 5, 9};
    cout << solution.smallestDivisor(nums1, 6) << endl;

    vector<int> nums2 = {2, 3, 5, 7, 11};
    cout << solution.smallestDivisor(nums2, 11) << endl;

    vector<int> nums3 = {19};
    cout << solution.smallestDivisor(nums3, 5) << endl;
}

/*
// @lcpr case=start
// [1,2,5,9]\n6\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5,7,11]\n11\n
// @lcpr case=end

// @lcpr case=start
// [19]\n5\n
// @lcpr case=end

 */
