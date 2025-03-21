/*
 * @Author: RainbowRain9
 * @Date: 2025-03-17 21:09:17
 * @LastEditTime: 2025-03-17 21:09:23
 * @FilePath: \C++\Algorithm\LeetCode\All\2529-maximum-count-of-positive-integer-and-negative-integer.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 * @lcpr version=30103
 *
 * [2529] 正整数和负整数的最大计数
 *
 * https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/description/
 *
 * algorithms
 * Easy (71.51%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    49.2K
 * Total Submissions: 69K
 * Testcase Example:  '[-2,-1,-1,1,2,3]'
 *
 * 给你一个按 非递减顺序 排列的数组 nums ，返回正整数数目和负整数数目中的最大值。
 *
 *
 * 换句话讲，如果 nums 中正整数的数目是 pos ，而负整数的数目是 neg ，返回 pos 和 neg二者中的最大值。
 *
 *
 * 注意：0 既不是正整数也不是负整数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [-2,-1,-1,1,2,3]
 * 输出：3
 * 解释：共有 3 个正整数和 3 个负整数。计数得到的最大值是 3 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [-3,-2,-1,0,0,1,2]
 * 输出：3
 * 解释：共有 2 个正整数和 3 个负整数。计数得到的最大值是 3 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [5,20,66,1314]
 * 输出：4
 * 解释：共有 4 个正整数和 0 个负整数。计数得到的最大值是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2000
 * -2000 <= nums[i] <= 2000
 * nums 按 非递减顺序 排列。
 *
 *
 *
 *
 * 进阶：你可以设计并实现时间复杂度为 O(log(n)) 的算法解决此问题吗？
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
// TODO 2025-03-17
// @lc code=start
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int n = nums.size();
        int neg = ranges::lower_bound(nums, 0) - nums.begin();
        int pos = nums.end() - ranges::upper_bound(nums, 0);
        return max(neg, pos);
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> test1 = {-2, -1, -1, 1, 2, 3};
    cout << "Test 1: " << solution.maximumCount(test1) << endl;  // Expected output: 3

    vector<int> test2 = {-3, -2, -1, 0, 0, 1, 2};
    cout << "Test 2: " << solution.maximumCount(test2) << endl;  // Expected output: 3

    vector<int> test3 = {5, 20, 66, 1314};
    cout << "Test 3: " << solution.maximumCount(test3) << endl;  // Expected output: 4

    vector<int> test4 = {-5, -4, -3, -2};
    cout << "Test 4: " << solution.maximumCount(test4) << endl;  // Expected output: 4

    vector<int> test5 = {0, 0, 0, 0};
    cout << "Test 5: " << solution.maximumCount(test5) << endl;  // Expected output: 0
}

/*
// @lcpr case=start
// [-2,-1,-1,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-3,-2,-1,0,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,20,66,1314]\n
// @lcpr case=end

 */
