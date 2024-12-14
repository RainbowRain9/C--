// Source : https://leetcode.cn/problems/max-consecutive-ones-iii/
// Date   : 2024-11-12

/**************************************************
 * 题目描述：
 * 给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回数组中连续 1 的最大个数。
 *
 * 示例 1：
 *   输入：nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 *   输出：6
 *   解释：[1,1,1,0,0,1,1,1,1,1,1]
 *   粗体数字从 0 翻转到 1，最长的子数组长度为 6。
 *
 * 示例 2：
 *   输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 *   输出：10
 *   解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 *   粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 *
 * 提示：
 *   - 1 <= nums.length <= 105
 *   - nums[i] 不是 0 就是 1
 *   - 0 <= k <= nums.length
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口解决，窗口内最多包含k个0
    2. 维护窗口:
       - 右指针不断向右扩展窗口
       - 当窗口内0的个数超过k时，左指针右移直到窗口合法
    3. 记录过程中的最大窗口长度
    4. 窗口长度即为可能的最大连续1的个数

    时间复杂度分析：O(n)，其中n为数组长度
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0, zero = 0, left = 0;
        for (int right = 0; right < n; right++)
        {
            zero += 1 - nums[right];
            while (zero > k)
            {
                zero -= 1 - nums[left++];
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    // 测试用例1
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << s.longestOnes(nums1, 2) << endl; // 输出: 6

    // 测试用例2
    vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << s.longestOnes(nums2, 3) << endl; // 输出: 10

    return 0;
}