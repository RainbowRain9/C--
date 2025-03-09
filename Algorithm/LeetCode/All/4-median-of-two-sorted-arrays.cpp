// Source : https://leetcode.cn/problems/median-of-two-sorted-arrays/
// Date   : 2024-11-07

/**************************************************
 * 题目描述：
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 * 请你找出并返回这两个正序数组的中位数。
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 * 示例 1：
 *   输入：nums1 = [1,3], nums2 = [2]
 *   输出：2.00000
 *   解释：合并数组 = [1,2,3] ，中位数 2
 *
 * 示例 2：
 *   输入：nums1 = [1,2], nums2 = [3,4]
 *   输出：2.50000
 *   解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 * 提示：
 *   - nums1.length == m
 *   - nums2.length == n
 *   - 0 <= m <= 1000
 *   - 0 <= n <= 1000
 *   - 1 <= m + n <= 2000
 *   - -106 <= nums1[i], nums2[i] <= 106
 **************************************************/

/*
    解题思路：
    1. 使用二分查找的思想，在较短的数组上进行二分
    2. 通过二分找到一个分割线，使得:
       - 分割线左边的元素都小于右边的元素
       - 分割线左边的元素个数等于右边的元素个数(或多一个)
    3. 时间复杂度为 O(log(min(m,n)))，满足要求

    时间复杂度分析：
    - 时间复杂度：O(log(min(m,n)))，在较短数组上进行二分查找
    - 空间复杂度：O(1)，只使用常数额外空间
*/

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=20003
 *
 * [4] 寻找两个正序数组的中位数
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
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 确保 nums1 是较短的数组，如果不是则交换
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;

        // 在 nums1 上进行二分查找
        while (left <= right) {
            // i 是 nums1 的分割线，j 是 nums2 的分割线
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            // 获取分割线左右的值，处理边界情况
            int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
            int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

            // 找到合适的分割线：左边最大值小于等于右边最小值
            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                // 如果总长度为奇数，返回左半部分的最大值
                if ((m + n) % 2 == 1) {
                    return max(nums1LeftMax, nums2LeftMax);
                }
                // 如果总长度为偶数，返回左半部分最大值和右半部分最小值的平均数
                return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
            }
            // 分割线需要左移
            else if (nums1LeftMax > nums2RightMin) {
                right = i - 1;
            }
            // 分割线需要右移
            else {
                left = i + 1;
            }
        }
        // 由于题目保证一定有解，所以不会走到这里
        return 0.0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end
*/

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 2};
    nums2 = {3, 4}; 
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
