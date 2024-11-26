// Source : https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/
// Date   : 2024-11-11

/**************************************************
 * 给你一个整数数组 nums 和一个正整数 k 。
 * 请你从 nums 中找出长度为 k 的子数组，使其中的元素互不相同，并返回满足该条件的子数组的最大元素和。
 * 如果不存在这样的子数组，返回 0 。
 *
 * 示例 1：
 *   输入：nums = [1,5,4,2,9,9,9], k = 3
 *   输出：15
 *   解释：nums 中长度为 3 的子数组是：
 *   - [1,5,4] 满足条件，和为 10
 *   - [5,4,2] 满足条件，和为 11
 *   - [4,2,9] 满足条件，和为 15
 *   - [2,9,9] 不满足条件，因为元素 9 出现重复
 *   - [9,9,9] 不满足条件，因为元素 9 出现重复
 *   因此，满足条件的最大子数组和为 15
 *
 * 示例 2：
 *   输入：nums = [4,4,4], k = 3
 *   输出：0
 *   解释：nums 中长度为 3 的子数组是：
 *   - [4,4,4] 不满足条件，因为元素 4 出现重复
 *   因此，没有满足条件的子数组，所以返回 0 。
 *
 * 提示：
 *   - 1 <= k <= nums.length <= 105
 *   - 1 <= nums[i] <= 105
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个长度为k的窗口
    2. 使用哈希表统计窗口内不同元素的个数
    3. 窗口向右滑动时:
       - 移除左边元素时，更新哈希表计数
       - 添加右边元素时，更新哈希表计数
    4. 当窗口内元素都不相同时，更新最大和

    时间复杂度分析：
    - 只需要遍历数组一次，时间复杂度为 O(n)
    - 使用哈希表存储窗口内元素，空间复杂度为 O(k)
*/

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnt;
        long long sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            cnt[nums[i]]++;
            if (i < k - 1)
                continue;
            if (cnt.size() == k)
            {
                ans = max(ans, sum);
            }
            int out = nums[i - k + 1];
            sum -= out;
            if (--cnt[out] == 0)
            {
                cnt.erase(out);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;

    // 测试用例1
    vector<int> nums1 = {1, 5, 4, 2, 9, 9, 9};
    cout << s.maximumSubarraySum(nums1, 3) << endl; // 输出: 15

    // 测试用例2
    vector<int> nums2 = {4, 4, 4};
    cout << s.maximumSubarraySum(nums2, 3) << endl; // 输出: 0

    return 0;
}