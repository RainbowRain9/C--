/*
 * @Author: RainbowRain9
 * @Date: 2025-03-09 16:28:28
 * @LastEditTime: 2025-03-10 22:16:52
 * @FilePath: \C++\Algorithm\LeetCode\All\219-contains-duplicate-ii.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=219 lang=cpp
 * @lcpr version=30100
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode.cn/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (47.98%)
 * Likes:    741
 * Dislikes: 0
 * Total Accepted:    343.6K
 * Total Submissions: 716.2K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且
 * abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3,1], k = 3
 * 输出：true
 *
 * 示例 2：
 *
 * 输入：nums = [1,0,1,1], k = 1
 * 输出：true
 *
 * 示例 3：
 *
 * 输入：nums = [1,2,3,1,2,3], k = 2
 * 输出：false
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
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
    // bool containsNearbyDuplicate(vector<int> &nums, int k) // 哈希表
    // {
    //     unordered_map<int, int> map;
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (map.count(nums[i]) && i - map[nums[i]] <= k)
    //         {
    //             return true;
    //         }
    //         map[nums[i]] = i;
    //     }

    //     return false;
    // }
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> set;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i > k)
            {
                set.erase(nums[i]);
            }
            if (set.count(nums[i]))
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
    vector<int> nums1 = {1,2,3,1};
    cout << solution.containsNearbyDuplicate(nums1, 3) << endl;
    vector<int> nums2 = {1,0,1,1}; 
    cout << solution.containsNearbyDuplicate(nums2, 1) << endl;
    vector<int> nums3 = {1,2,3,1,2,3};
    cout << solution.containsNearbyDuplicate(nums3, 2) << endl;
}

/*
// @lcpr case=start
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

 */
