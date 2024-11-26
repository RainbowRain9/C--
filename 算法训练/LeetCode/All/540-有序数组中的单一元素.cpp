// Source : https://leetcode.cn/problems/single-element-in-a-sorted-array/
// Date   : 2024-11-10

/**************************************************
 * 题目描述：
 * 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
 * 请你找出并返回只出现一次的那个数。
 * 你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
 *
 * 示例 1：
 *   输入：nums = [1,1,2,3,3,4,4,8,8]
 *   输出：2
 *   解释：只有 2 出现了一次
 *
 * 示例 2：
 *   输入：nums = [3,3,7,7,10,11,11]
 *   输出：10
 *   解释：只有 10 出现了一次
 *
 * 提示：
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

    时间复杂度分析：
    - 时间复杂度：O(log n)，使用二分查找
    - 空间复杂度：O(1)，只使用常数额外空间
*/

/*
 * @lc app=leetcode.cn id=540 lang=cpp
 * @lcpr version=20003
 *
 * [540] 有序数组中的单一元素
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
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + ((right - left) / 2);
            mid -= mid & 1;  // 将mid调整为偶数

            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

// @lc code=end

/*
// @lcpr case=start
// [1,1,2,3,3,4,4,8,8]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,7,7,10,11,11]\n
// @lcpr case=end
*/

int main() {
    Solution s;
    
    // 测试用例1：单一元素在中间位置
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Test case 1: " << s.singleNonDuplicate(nums1) << endl;

    // 测试用例2：单一元素在倒数第二个位置
    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "Test case 2: " << s.singleNonDuplicate(nums2) << endl;

    // 测试用例3：单一元素在最后一个位置
    vector<int> nums3 = {1, 1, 2, 2, 4, 4, 5, 5, 9};
    cout << "Test case 3: " << s.singleNonDuplicate(nums3) << endl;

    return 0;
}
