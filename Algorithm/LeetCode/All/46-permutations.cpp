/*
 * @Author: RainbowRain9
 * @Date: 2025-03-31 15:33:03
 * @LastEditTime: 2025-03-31 15:34:13
 * @FilePath: \C++\Algorithm\LeetCode\All\46-permutations.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30104
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (79.83%)
 * Likes:    3079
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Ensure the initial array is sorted
        do
        {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
