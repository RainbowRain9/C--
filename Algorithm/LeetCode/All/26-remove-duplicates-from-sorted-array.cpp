/*
 * @Author: RainbowRain9
 * @Date: 2025-03-10 22:54:44
 * @LastEditTime: 2025-03-11 13:22:14
 * @FilePath: \C++\Algorithm\LeetCode\All\26-remove-duplicates-from-sorted-array.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 * @lcpr version=30100
 *
 * [26] 删除有序数组中的重复项
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (57.30%)
 * Likes:    3678
 * Dislikes: 0
 * Total Accepted:    2.1M
 * Total Submissions: 3.6M
 * Testcase Example:  '[1,1,2]'
 *
 * 给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序
 * 应该保持 一致 。然后返回 nums 中唯一元素的个数。
 *
 * 考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
 *
 *
 * 更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums
 * 的大小不重要。
 * 返回 k 。
 *
 *
 * 判题标准:
 *
 * 系统会用下面的代码来测试你的题解:
 *
 * int[] nums = [...]; // 输入数组
 * int[] expectedNums = [...]; // 长度正确的期望答案
 *
 * int k = removeDuplicates(nums); // 调用
 *
 * assert k == expectedNums.length;
 * for (int i = 0; i < k; i++) {
 * ⁠   assert nums[i] == expectedNums[i];
 * }
 *
 * 如果所有断言都通过，那么您的题解将被 通过。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,1,2]
 * 输出：2, nums = [1,2,_]
 * 解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0,0,1,1,1,2,2,3,3,4]
 * 输出：5, nums = [0,1,2,3,4]
 * 解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4
 * 。不需要考虑数组中超出新长度后面的元素。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 已按 非严格递增 排列
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int slow = 0, len = 0;
        for (int fast = 0; fast < n; fast++)
        {
            if (nums[slow] != nums[fast] && slow <= fast)
            {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "Original array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    int newLength = solution.removeDuplicates(nums);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "New length: " << newLength << endl;
}

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */
