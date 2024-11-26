// Source : https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/
// Date   : 2024-11-14

/**************************************************
 * 题目描述：
 * 给你一个二进制数组 nums ，你需要从中删掉一个元素。
 * 请你在删掉一个元素的情况下，返回最长的且只包含 1 的非空子数组的长度。
 * 如果不存在这样的子数组，请返回 0 。
 *
 * 示例 1：
 *   输入：nums = [1,1,0,1]
 *   输出：3
 *   解释：删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。
 *
 * 示例 2：
 *   输入：nums = [0,1,1,1,0,1,1,0,1]
 *   输出：5
 *   解释：删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1]。
 *
 * 示例 3：
 *   输入：nums = [1,1,1]
 *   输出：2
 *   解释：你必须要删除一个元素。
 *
 * 提示：
 *   - 1 <= nums.length <= 10^5
 *   - nums[i] 要么是 0 要么是 1
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个可变长度的窗口
    2. 窗口内最多允许包含一个0
    3. 当窗口内0的个数超过1个时，左指针右移直到窗口内只有1个0
    4. 记录过程中的最大窗口长度，最后返回长度减1(因为必须删除一个元素)

    时间复杂度分析：
    - 只需要遍历一次数组，时间复杂度为O(n)
    - 只使用常数额外空间，空间复杂度为O(1)
*/

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0, left = 0, zero = 0;
        for (int right = 0; right < n; right++)
        {
            zero += 1 - nums[right];
            while(zero > 1)
            {
                zero -= 1 - nums[left++];
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};

int main()
{
    Solution s;

    // 测试用例1
    vector<int> nums1 = {1, 1, 0, 1};
    cout << s.longestSubarray(nums1) << endl; // 输出: 3

    // 测试用例2
    vector<int> nums2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << s.longestSubarray(nums2) << endl; // 输出: 5

    // 测试用例3
    vector<int> nums3 = {1, 1, 1};
    cout << s.longestSubarray(nums3) << endl; // 输出: 2

    return 0;
}