// Source : https://leetcode.cn/problems/4xy4Wx/description/
// Date   : 2024-11-22

/**************************************************
 * 题目描述：
 * 小力将 N 个零件的报价存于数组 nums。小力预算为 target，假定小力仅购买两个零件，要求购买零件的花费不超过预算，请问他有多少种采购方案。
 * 注意：答案需要对 1e9 + 7 (1000000007) 取余
 *
 * 示例 1：
 *   输入：nums = [2,5,3,5], target = 6
 *   输出：1
 *   解释：预算内仅能购买 nums[0] = 2 与 nums[2] = 3 这两个零件。
 *
 * 示例 2：
 *   输入：nums = [2,2,1,9], target = 10
 *   输出：4
 *   解释：符合预算的采购方案如下:
 *   nums[0] = 2, nums[1] = 2
 *   nums[0] = 2, nums[2] = 1
 *   nums[1] = 2, nums[2] = 1
 *   nums[2] = 1, nums[3] = 9
 *
 * 提示：
 *   - 2 <= nums.length <= 10^5
 *   - 1 <= nums[i], target <= 10^5
 **************************************************/

/*
    解题思路：
    1. 排序后使用双指针
    2. 左右指针分别指向数组两端
    3. 如果两数之和小于target,则left到right-1都是合法方案
    4. 如果两数之和大于target,则right左移

    时间复杂度分析：O(nlogn)
*/
/*
 * @lc app=leetcode.cn id=LCP 28 lang=cpp
 * @lcpr version=20003
 *
 * [LCP 28] 采购方案
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
class Solution
{
public:
    int purchasePlans(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        long long ans = 0;
        const int MOD = 1e9 + 7;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum <= target)
            {
                ans = (ans + right - left) % MOD;
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,5,3,5]\n6`>\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,9]\n10`>\n
// @lcpr case=end

 */
