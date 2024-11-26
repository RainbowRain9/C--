// Source : https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/
// Date   : 2024-11-12

/**************************************************
 * 题目描述：
 * 给你一个下标从 0 开始的整数数组 nums 和一个 非负 整数 k 。
 * 在一步操作中，你可以执行下述操作之一：
 * - 选中 nums 中的一个元素，将它的值减小或者增大 最多 k 。
 * 数组的 美丽值 定义为数组中由相等元素组成的最长子序列的长度。
 * 返回你可以得到的数组的最大可能美丽值。
 * 注意：你可以对每个元素多次使用上述操作。
 *
 * 示例 1：
 *   输入：nums = [4,6,1,2], k = 2
 *   输出：3
 *   解释：在这个示例中，我们执行以下操作：
 *   - 选中 nums[1] ，将它的值减小 2 ，得到 nums = [4,4,1,2] 。
 *   - 选中 nums[3] ，将它的值增大 2 ，得到 nums = [4,4,1,4] 。
 *   nums 现在有了长度为 3 的相等元素子序列。
 *   可以证明 3 是我们能得到的最大美丽值。
 *
 * 示例 2：
 *   输入：nums = [1,1,1,1], k = 10
 *   输出：4
 *   解释：在这个示例中，数组已经有了最大美丽值 4 ，我们不需要执行任何操作。
 *
 * 提示：
 *   - 1 <= nums.length <= 105
 *   - 0 <= nums[i], k <= 105
 **************************************************/

/*
    解题思路：
    1. 对于每个数字x，我们可以将范围在[x-k, x+k]内的所有数字都变成x
    2. 问题转化为找到一个值x，使得在nums中有最多的数字可以通过加减k变成x
    3. 可以使用滑动窗口来解决:
       - 先将数组排序
       - 维护一个窗口，使窗口内的最大值和最小值之差不超过2k
       - 这样窗口内的所有数都可以变成同一个值
    4. 窗口的大小就是可能的美丽值

    时间复杂度分析：O(nlogn)，主要是排序的时间复杂度
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        // 获取数组长度
        int n = nums.size();
        // 对数组进行排序,方便使用滑动窗口
        sort(nums.begin(),nums.end());
        // ans记录最大美丽值,left为滑动窗口左边界
        int ans = 0, left = 0;
        // right为滑动窗口右边界
        for (int right = 0; right < n; right++)
        {
            // 当窗口内最大值与最小值的差超过2k时
            // 说明窗口内的数无法都变成同一个值
            // 需要收缩左边界
            while (nums[right] - nums[left] > 2 * k)
            {
                left++;
            }
            // 更新最大美丽值
            // 当前窗口大小为right-left+1
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    Solution s;

    // 测试用例1
    vector<int> nums1 = {4, 6, 1, 2};
    cout << s.maximumBeauty(nums1, 2) << endl; // 输出: 3

    // 测试用例2
    vector<int> nums2 = {1, 1, 1, 1};
    cout << s.maximumBeauty(nums2, 10) << endl; // 输出: 4

    return 0;
}