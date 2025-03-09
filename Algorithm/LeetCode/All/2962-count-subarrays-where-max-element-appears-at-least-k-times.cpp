// Source : https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/
// Date   : 2024-11-13

/**************************************************
 * 题目描述：
 * 给你一个长度为 n 的整数数组 nums 和一个整数 k 。
 * 统计有多少满足下述条件的下标对 (l, r) ：
 * - 0 <= l <= r <= n - 1
 * - nums[l..r] 的最大元素等于 max ，其中 max 是子数组的最大元素。
 * - nums[l..r] 中，max 出现至少 k 次。
 * 返回满足条件的下标对数目。
 *
 * 示例 1：
 *   输入：nums = [1,3,2,3,3], k = 2
 *   输出：6
 *   解释：包含最大值 3 至少 2 次的子数组为：[1,3,2,3]、[1,3,2,3,3]、[3,2,3]、[3,2,3,3]、[2,3,3] 和 [3,3]
 *
 * 示例 2：
 *   输入：nums = [1,4,2,1], k = 3
 *   输出：0
 *   解释：不存在包含任何值至少 3 次的子数组。
 *
 * 提示：
 *   - 1 <= nums.length <= 105
 *   - 1 <= nums[i] <= 106
 *   - 1 <= k <= nums.length
 **************************************************/

/*
    解题思路：
    1. 先找到数组中的最大值max
    2. 使用滑动窗口统计包含max至少k次的子数组个数:
       - 右指针不断向右扩展窗口
       - 当窗口内max的个数达到k时，以右端点为结尾的所有子数组都是合法的
       - 当窗口内max的个数小于k时，继续扩展窗口
    3. 统计所有合法子数组的个数

    时间复杂度分析：O(n)，其中n为数组长度
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        // 找到数组中的最大值
        int mx = *max_element(nums.begin(), nums.end());

        long long ans = 0;
        int cnt = 0, left = 0;

        // 遍历数组,右指针不断向右扩展窗口
        for (int right = 0; right < nums.size(); right++)
        {
            // 统计窗口内最大值的个数
            if (nums[right] == mx)
            {
                cnt++;
            }

            // 当窗口内包含k个最大值时,收缩左边界直到不满足条件
            while (cnt >= k)
            {
                if (nums[left] == mx)
                {
                    cnt--;
                }
                left++;
            }

            ans += left;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    // 测试用例1
    vector<int> nums1 = {1, 3, 2, 3, 3};
    cout << s.countSubarrays(nums1, 2) << endl; // 输出: 6

    // 测试用例2
    vector<int> nums2 = {1, 4, 2, 1};
    cout << s.countSubarrays(nums2, 3) << endl; // 输出: 0

    return 0;
}