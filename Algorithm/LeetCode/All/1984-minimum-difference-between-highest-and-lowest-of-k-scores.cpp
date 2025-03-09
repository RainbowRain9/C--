// Source : https://leetcode.cn/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
// Date   : 2024-11-11

/**************************************************
 * 给你一个下标从 0 开始的整数数组 nums ，其中 nums[i] 表示第 i 名学生的分数。另给你一个整数 k 。
 *
 * 从数组中选出任意 k 名学生的分数，使这 k 个分数间最高分和最低分的差值达到最小化。
 * 返回可能的最小差值。
 *
 * 示例 1：
 *   输入：nums = [90], k = 1
 *   输出：0
 *   解释：选择 1 名学生的分数，最高分和最低分之间的差值必为 0 。
 *
 * 示例 2：
 *   输入：nums = [9,4,1,7], k = 2
 *   输出：2
 *   解释：选择 2 名学生的分数，有 6 种方案：
 *   - [9,4,1,7] 选择第 0 和第 1 名学生的分数，最高分与最低分之差为 9 - 4 = 5
 *   - [9,4,1,7] 选择第 0 和第 2 名学生的分数，最高分与最低分之差为 9 - 1 = 8
 *   - [9,4,1,7] 选择第 0 和第 3 名学生的分数，最高分与最低分之差为 9 - 7 = 2
 *   - [9,4,1,7] 选择第 1 和第 2 名学生的分数，最高分与最低分之差为 4 - 1 = 3
 *   - [9,4,1,7] 选择第 1 和第 3 名学生的分数，最高分与最低分之差为 7 - 4 = 3
 *   - [9,4,1,7] 选择第 2 和第 3 名学生的分数，最高分与最低分之差为 7 - 1 = 6
 *   可能的最小差值是 2
 *
 * 提示：
 *   - 1 <= k <= nums.length <= 1000
 *   - 0 <= nums[i] <= 105
 **************************************************/

/*
    解题思路：
    1. 先将数组排序
    2. 使用滑动窗口法，维护一个长度为k的窗口
    3. 窗口内的最大值和最小值就是窗口的首尾元素
    4. 遍历所有窗口，找出最小差值

    时间复杂度分析：
    - 排序需要 O(nlogn) 的时间复杂度
    - 遍历数组需要 O(n) 的时间复杂度
    - 总时间复杂度为 O(nlogn)
    - 只使用了常数个变量，空间复杂度为 O(1)
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int tmp;
        for (int i = 0; i < nums.size() - k + 1; i++)
        {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {90};
    cout << s.minimumDifference(nums1, 1) << endl; // 输出: 0

    vector<int> nums2 = {9, 4, 1, 7};
    cout << s.minimumDifference(nums2, 2) << endl; // 输出: 2

    return 0;
}