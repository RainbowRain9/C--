// Source : https://leetcode.cn/problems/length-of-longest-subarray-with-at-most-k-frequency/
// Date   : 2024-11-11

/**************************************************
 * 题目描述：
 * 给你一个整数数组 nums 和一个整数 k 。
 * 请你找出 nums 中最长子数组的长度，该子数组中每个元素最多出现 k 次。
 *
 * 示例 1：
 *   输入：nums = [1,2,3,1,2,3,1,2], k = 2
 *   输出：6
 *   解释：子数组 [1,2,3,1,2,3] 满足每个元素最多出现 2 次。
 *   其长度为 6 ，为最长子数组。
 *
 * 示例 2：
 *   输入：nums = [1,2,1,2,1,2,1,2], k = 1
 *   输出：2
 *   解释：子数组 [1,2] 满足每个元素最多出现 1 次。
 *   其长度为 2 ，为最长子数组。
 *
 * 示例 3：
 *   输入：nums = [5,5,5,5,5,5,5], k = 4
 *   输出：4
 *   解释：子数组 [5,5,5,5] 满足每个元素最多出现 4 次。
 *   其长度为 4 ，为最长子数组。
 *
 * 提示：
 *   - 1 <= nums.length <= 105
 *   - 1 <= nums[i] <= 109
 *   - 1 <= k <= nums.length
 **************************************************/

/*
    解题思路：
    使用滑动窗口解决此问题。维护一个窗口，使窗口内每个元素出现次数不超过k。
    - 使用哈希表记录窗口内每个元素的出现次数
    - 右指针不断向右移动，更新元素出现次数
    - 当某个元素出现次数超过k时，左指针向右移动，减少该元素出现次数
    - 每次更新最长子数组长度

    时间复杂度分析：O(n)，其中n为数组长度
*/

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnt;
        int ans = 0, left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            cnt[nums[right]]++;
            while (cnt[nums[right]] > k)
            {
                cnt[nums[left++]]--;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    // 创建Solution对象
    Solution solution;

    // 测试用例
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;

    // 输出测试用例
    cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i < nums.size() - 1)
            cout << ",";
    }
    cout << "], k = " << k << endl;

    // 调用方法获取结果
    int result = solution.maxSubarrayLength(nums, k);

    // 输出结果
    cout << "Output: " << result << endl;

    // 输出解释
    cout << "Explanation: 子数组 [1,2,3,1,2,3] 满足每个元素最多出现 2 次，长度为 6。" << endl;

    return 0;
}