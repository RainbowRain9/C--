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

#include <string>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> seen;
        int maxSum = 0, currentSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            while (seen.count(nums[right]))
            {
                currentSum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }
            currentSum += nums[right];
            seen.insert(nums[right]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4, 2, 4, 5, 6};
    cout << solution.maximumUniqueSubarray(nums) << endl;
    return 0;
}