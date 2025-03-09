// Source : https://leetcode.cn/problems/count-the-number-of-good-subarrays/description/
// Date   : 2024-11-19

/**************************************************
 * 题目描述：
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 nums 的好子数组的数目。
 * 一个子数组 arr 如果有 至少 k 对下标 (i, j) 满足 i < j 且 arr[i] == arr[j] ，那么称它是一个 好子数组 。
 * 子数组 是原数组中一个连续非空的元素序列。
 *
 * 示例 1：
 *   输入：nums = [1,1,1,1,1], k = 10
 *   输出：1
 *   解释：唯一的好子数组是这个数组本身。
 *
 * 示例 2：
 *   输入：nums = [3,1,4,3,2,2,4], k = 2
 *   输出：4
 *   解释：总共有 4 个不同的好子数组：
 *   - [3,1,4,3] 有 2 对。
 *   - [3,1,4,3,2] 有 2 对。
 *   - [1,4,3,2,2] 有 2 对。
 *   - [4,3,2,2,4] 有 2 对。
 *
 * 提示：
 *   - 1 <= nums.length <= 105
 *   - 1 <= nums[i], k <= 109
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口统计每个子数组中相同元素对的个数
    2. 当子数组中相同元素对的个数大于等于k时，该子数组为好子数组
    3. 对于每个右端点，统计以其为右端点的好子数组的个数

    时间复杂度分析：O(n)，其中n为数组长度
*/
/*
 * @lc app=leetcode.cn id=2537 lang=cpp
 * @lcpr version=20003
 *
 * [2537] 统计好子数组的数目
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> cnt;
        int pairs = 0, left = 0;
        long long ans = 0;
        for (int x : nums)
        {
            pairs += cnt[x]++;
            while (pairs >= k)
            {
                pairs -= --cnt[nums[left]];
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,1,1]\n10\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,3,2,2,4]\n2\n
// @lcpr case=end

 */
