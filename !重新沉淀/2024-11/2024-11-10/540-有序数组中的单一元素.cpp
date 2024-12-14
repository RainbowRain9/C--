// Source : https://leetcode.cn/problems/single-element-in-a-sorted-array/
// Date   : 2024-11-10

/**************************************************
 * 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
 *
 * 请你找出并返回只出现一次的那个数。
 *
 * 你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
 *
 * 示例 1:
 *   输入: nums = [1,1,2,3,3,4,4,8,8]
 *   输出: 2
 *
 * 示例 2:
 *   输入: nums = [3,3,7,7,10,11,11]
 *   输出: 10
 *
 * 提示:
 *   - 1 <= nums.length <= 10^5
 *   - 0 <= nums[i] <= 10^5
 *   - nums 中的每个元素出现两次，唯有一个元素出现一次
 **************************************************/

/*
    解题思路：
    1. 由于要求 O(log n) 时间复杂度，考虑使用二分查找
    2. 观察数组特点:
       - 除了一个数外，其他数都出现两次
       - 数组有序
       - 单一元素之前，成对元素的第一个数的下标为偶数
       - 单一元素之后，成对元素的第一个数的下标为奇数
    3. 二分查找过程:
       - 如果 mid 是偶数，则比较 nums[mid] 和 nums[mid+1]
       - 如果 mid 是奇数，则比较 nums[mid] 和 nums[mid-1]
       - 根据比较结果确定单一元素在左半部分还是右半部分
    4. 时间复杂度为 O(log n)，空间复杂度为 O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            mid -= mid & 1;
            if (nums[mid] == nums[mid + 1])
            {
                left = mid + 2;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << s.singleNonDuplicate(nums) << endl;

    nums = {3, 3, 7, 7, 10, 11, 11};
    cout << s.singleNonDuplicate(nums) << endl;

    nums = {1, 1, 2, 2, 4, 4, 5, 5, 9};
    cout << s.singleNonDuplicate(nums) << endl;

    return 0;
}
