// Source : https://leetcode.cn/problems/maximum-erasure-value/
// Date   : 2024-11-14

/**************************************************
 * 题目描述：
 * 给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之和。
 * 返回 只删除一个 子数组可获得的 最大得分 。
 * 如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它就是 a 的一个子数组。
 *
 * 示例 1：
 *   输入：nums = [4,2,4,5,6]
 *   输出：17
 *   解释：最优子数组是 [2,4,5,6]
 *
 * 示例 2：
 *   输入：nums = [5,2,1,2,5,2,1,2,5]
 *   输出：8
 *   解释：最优子数组是 [5,2,1] 或 [1,2,5]
 *
 * 提示：
 *   - 1 <= nums.length <= 10^5
 *   - 1 <= nums[i] <= 10^4
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口和哈希集合来维护不重复的子数组
    2. 右指针不断向右扩展，将元素加入集合和当前和
    3. 当遇到重复元素时，左指针右移直到删除重复元素
    4. 维护最大得分

    时间复杂度分析：O(n)，其中n为数组长度
*/

/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 * @lcpr version=20003
 *
 * [1695] 删除子数组的最大得分
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
#include <string>
#include <cmath>

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // 使用哈希集合记录窗口中出现过的元素
        unordered_set<int> seen;
        // maxSum记录最大得分,currentSum记录当前窗口得分
        int maxSum = 0, currentSum = 0;
        // 左指针,用于收缩窗口
        int left = 0;
        
        // 右指针遍历数组
        for (int right = 0; right < nums.size(); right++) {
            // 当遇到重复元素时,不断移除左边元素直到没有重复
            while (seen.count(nums[right])) {
                currentSum -= nums[left]; // 从当前和中减去左边元素
                seen.erase(nums[left]); // 从集合中移除左边元素
                left++; // 左指针右移
            }
            currentSum += nums[right]; // 将当前元素加入窗口和
            seen.insert(nums[right]); // 将当前元素加入集合
            maxSum = max(maxSum, currentSum); // 更新最大得分
        }
        
        return maxSum; // 返回最大得分
    }
};

// @lc code=end

/*
// @lcpr case=start
// [4,2,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [5,2,1,2,5,2,1,2,5]\n
// @lcpr case=end
*/

int main()
{
    Solution solution;
    vector<int> nums = {4,2,4,5,6};
    cout << solution.maximumUniqueSubarray(nums) << endl;
    return 0;
}