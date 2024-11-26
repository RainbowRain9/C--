// Source : https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/
// Date   : 2024-11-13

/**************************************************
 * 题目描述：
 * 给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，
 * 然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。
 * 如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。
 *
 * 示例 1：
 *   输入：nums = [1,1,4,2,3], x = 5
 *   输出：2
 *   解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
 *
 * 示例 2：
 *   输入：nums = [5,6,7,8,9], x = 4
 *   输出：-1
 *
 * 示例 3：
 *   输入：nums = [3,2,20,1,1,3], x = 10
 *   输出：5
 *   解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
 *
 * 提示：
 *   - 1 <= nums.length <= 105
 *   - 1 <= nums[i] <= 104
 *   - 1 <= x <= 109
 **************************************************/

/*
    解题思路：
    1. 问题转化：找到最短的左右两端子数组，使其和为x
    2. 等价于找到最长的连续子数组，使其和为sum(nums)-x
    3. 使用滑动窗口维护这个连续子数组
    4. 如果找到这样的子数组，返回n-len(子数组)，否则返回-1

    时间复杂度分析：O(n)，其中n为数组长度
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        int target = sum - x;
        if (target < 0)
            return -1;
        if (target == 0)
            return n;

        int left = 0, len = -1, len_max = 0;
        for (int right = 0; right < n; right++)
        {
            len_max += nums[right];
            while (len_max > target)
            {
                len_max -= nums[left++];
            }
            if (len_max == target)
            {
                len = max(len, right - left + 1);
            }
        }
        return len == -1 ? -1 : n - len;
    }
};

int main()
{
    Solution s;

    // 测试用例1
    vector<int> nums1 = {1, 1, 4, 2, 3};
    cout << s.minOperations(nums1, 5) << endl; // 输出: 2

    // 测试用例2
    vector<int> nums2 = {5, 6, 7, 8, 9};
    cout << s.minOperations(nums2, 4) << endl; // 输出: -1

    // 测试用例3
    vector<int> nums3 = {3, 2, 20, 1, 1, 3};
    cout << s.minOperations(nums3, 10) << endl; // 输出: 5

    return 0;
}