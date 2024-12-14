// Source : https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray/
// Date   : 2024-11-11

/**************************************************
 * 给你一个整数数组 nums 和两个正整数 m 和 k 。
 *
 * 请你找出 nums 中长度为 k 的所有子数组，请你在这些子数组中找出元素各不相同的子数组的数目 至少为 m 个的子数组。
 * 在满足条件的子数组中，找出元素和的最大值。
 *
 * 如果不存在满足条件的子数组，返回 0 。
 *
 * 子数组是数组中的一个连续元素序列。
 *
 * 示例 1：
 *   输入：nums = [2,6,7,3,1,7], m = 3, k = 4
 *   输出：18
 *   解释：总共有 3 个长度为 4 的子数组，元素各不相同：
 *   - nums[0..3] = [2,6,7,3]，元素和为 18
 *   - nums[1..4] = [6,7,3,1]，元素和为 17
 *   - nums[2..5] = [7,3,1,7]，元素和为 18
 *   其中有 3 个子数组的元素各不相同，所以 m = 3 的条件满足。
 *   在这些子数组中，最大的元素和为 18 。
 *
 * 示例 2：
 *   输入：nums = [5,9,9,2,4,5,4], m = 1, k = 3
 *   输出：23
 *   解释：总共有 5 个长度为 3 的子数组：
 *   - nums[0..2] = [5,9,9] ，元素和为 23
 *   - nums[1..3] = [9,9,2] ，元素和为 20
 *   - nums[2..4] = [9,2,4] ，元素和为 15
 *   - nums[3..5] = [2,4,5] ，元素和为 11
 *   - nums[4..6] = [4,5,4] ，元素和为 13
 *   其中有 3 个子数组的元素各不相同。
 *   在元素各不相同的子数组中，最大的元素和为 23 。
 *
 * 提示：
 *   - k <= nums.length <= 105
 *   - 1 <= m <= k <= nums.length
 *   - 1 <= nums[i] <= 109
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个长度为k的窗口
    2. 使用哈希表统计窗口内不同元素的个数
    3. 窗口向右滑动时:
       - 移除左边元素时，更新哈希表计数
       - 添加右边元素时，更新哈希表计数
    4. 当窗口内不同元素个数大于等于m时，更新最大和

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
    long long maxSum(vector<int> &nums, int m, int k)
    {
        long long ans = 0, sum = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            cnt[nums[i]]++;
            if (i < k - 1) continue;
            if (cnt.size() >= m)
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
    vector<int> nums1 = {2, 6, 7, 3, 1, 7};
    cout << s.maxSum(nums1, 3, 4) << endl; // 输出: 18

    vector<int> nums2 = {5, 9, 9, 2, 4, 5, 4};
    cout << s.maxSum(nums2, 1, 3) << endl; // 输出: 23

    return 0;
}
