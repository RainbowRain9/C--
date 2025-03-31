/*
 * @Author: RainbowRain9
 * @Date: 2025-03-31 20:27:11
 * @LastEditTime: 2025-03-31 20:27:24
 * @FilePath: \C++\Algorithm\LeetCode\All\31-next-permutation.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30104
 *
 * [31] 下一个排列
 *
 * https://leetcode.cn/problems/next-permutation/description/
 *
 * algorithms
 * Medium (40.11%)
 * Likes:    2669
 * Dislikes: 0
 * Total Accepted:    613.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3]'
 *
 * 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
 *
 *
 * 例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
 *
 *
 * 整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列
 * 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
 *
 *
 * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
 * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
 * 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
 *
 *
 * 给你一个整数数组 nums ，找出 nums 的下一个排列。
 *
 * 必须 原地 修改，只允许使用额外常数空间。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
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
    void nextPermutation(vector<int> &nums)
    {
        ranges::next_permutation(nums);
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 3};
    solution.nextPermutation(nums1);
    cout << "Next permutation of [1,2,3]: ";
    for (int num : nums1)
        cout << num << " ";
    cout << endl;

    vector<int> nums2 = {3, 2, 1};
    solution.nextPermutation(nums2);
    cout << "Next permutation of [3,2,1]: ";
    for (int num : nums2)
        cout << num << " ";
    cout << endl;

    vector<int> nums3 = {1, 1, 5};
    solution.nextPermutation(nums3);
    cout << "Next permutation of [1,1,5]: ";
    for (int num : nums3)
        cout << num << " ";
    cout << endl;
}

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */
