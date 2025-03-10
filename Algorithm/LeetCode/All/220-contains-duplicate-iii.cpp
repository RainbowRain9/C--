/*
 * @Author: RainbowRain9
 * @Date: 2025-03-09 16:56:44
 * @LastEditTime: 2025-03-10 22:17:11
 * @FilePath: \C++\Algorithm\LeetCode\All\220-contains-duplicate-iii.cpp
 * @Description: 
 */
/*
 * @lc app=leetcode.cn id=220 lang=cpp
 * @lcpr version=30100
 *
 * [220] 存在重复元素 III
 *
 * https://leetcode.cn/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Hard (30.85%)
 * Likes:    750
 * Dislikes: 0
 * Total Accepted:    107.5K
 * Total Submissions: 346.6K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * 给你一个整数数组 nums 和两个整数 indexDiff 和 valueDiff 。
 *
 * 找出满足下述条件的下标对 (i, j)：
 *
 *
 * i != j,
 * abs(i - j) <= indexDiff
 * abs(nums[i] - nums[j]) <= valueDiff
 *
 *
 * 如果存在，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
 * 输出：true
 * 解释：可以找出 (i, j) = (0, 3) 。
 * 满足下述 3 个条件：
 * i != j --> 0 != 3
 * abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
 * abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
 * 输出：false
 * 解释：尝试所有可能的下标对 (i, j) ，均无法满足这 3 个条件，因此返回 false 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 1 <= indexDiff <= nums.length
 * 0 <= valueDiff <= 10^9
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
// TODO 2025-03-09:太难
// @lc code=start
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        int n = nums.size();
        set<int> set;
        for (int i = 0; i < n; i++)
        {
            if (i > indexDiff)
            {
                set.erase(nums[i - indexDiff - 1]);
            }

            auto it = set.lower_bound(nums[i] - valueDiff);
            if (it != set.end() && *it <= nums[i] + valueDiff)
            {
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 1};
    cout << solution.containsNearbyAlmostDuplicate(nums1, 3, 0) << endl; // true
    
    vector<int> nums2 = {1, 5, 9, 1, 5, 9};
    cout << solution.containsNearbyAlmostDuplicate(nums2, 2, 3) << endl; // false
}

/*
// @lcpr case=start
// [1,2,3,1]\n3\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,5,9,1,5,9]\n2\n3\n
// @lcpr case=end

 */
