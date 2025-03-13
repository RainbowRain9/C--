/*
 * @Author: RainbowRain9
 * @Date: 2025-03-12 14:54:58
 * @LastEditTime: 2025-03-13 19:54:46
 * @FilePath: \C++\Algorithm\LeetCode\All\75-sort-colors.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30101
 *
 * [75] 颜色分类
 *
 * https://leetcode.cn/problems/sort-colors/description/
 *
 * algorithms
 * Medium (61.90%)
 * Likes:    1891
 * Dislikes: 0
 * Total Accepted:    741.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 *
 * 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 *
 *
 *
 *
 * 必须在不使用库内置的 sort 函数的情况下解决这个问题。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] 为 0、1 或 2
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
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
// TODO 2025-03-12: 75.颜色分类
// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        for (int curr = 0; curr <= right;)
        {
            if (nums[curr] == 0)
            {
                swap(nums[left], nums[curr]);
                left++;
                curr++;
            }
            else if (nums[curr] == 2)
            {
                swap(nums[right], nums[curr]);
                right--;
            }
            else
            {
                curr++;
            }
        }
    }
    //     void sortColors(vector<int> &nums)
    //     {
    //         int n = nums.size();
    //         int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    //         for (auto i : nums)
    //         {
    //             if (i == 0)
    //             {
    //                 cnt0++;
    //             }
    //             if (i == 1)
    //             {
    //                 cnt1++;
    //             }
    //             if (i == 2)
    //             {
    //                 cnt2++;
    //             }
    //         }
    //         for (int i = 0; i < n; i++)
    //         {
    //             if (cnt0 > 0)
    //             {
    //                 nums[i] = 0;
    //                 cnt0--;
    //             }
    //             else
    //             {
    //                 if (cnt1 > 0)
    //                 {
    //                     nums[i] = 1;
    //                     cnt1--;
    //                 }
    //                 else
    //                 {
    //                     nums[i] = 2;
    //                     cnt2--;
    //                 }
    //             }
    //         }
    //     }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums = {1,0,2};
    solution.sortColors(nums);
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */
