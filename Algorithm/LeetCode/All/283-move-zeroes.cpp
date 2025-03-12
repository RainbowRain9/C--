/*
 * @Author: RainbowRain9
 * @Date: 2025-03-11 20:15:23
 * @LastEditTime: 2025-03-11 20:18:35
 * @FilePath: \C++\Algorithm\LeetCode\All\283-move-zeroes.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30101
 *
 * [283] 移动零
 *
 * https://leetcode.cn/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.83%)
 * Likes:    2498
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2.5M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 *
 * 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 *
 *
 *
 * 示例 1:
 *
 * 输入: nums = [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 *
 *
 * 示例 2:
 *
 * 输入: nums = [0]
 * 输出: [0]
 *
 *
 *
 * 提示:
 *
 *
 *
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 *
 * 进阶：你能尽量减少完成的操作次数吗？
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
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int slow = 0, fast = 0;
        while (slow <= fast && fast < n)
        {
            if (nums[fast] != 0)
            {
                swap(nums[slow++], nums[fast]);
            }
            fast++;
        }
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
