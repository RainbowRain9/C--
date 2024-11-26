// Source : https://leetcode.cn/problems/count-number-of-nice-subarrays/description/
// Date   : 2024-11-20

/**************************************************
 * 题目描述：
 * 给你一个整数数组 nums 和一个整数 k。如果某个连续子数组中恰好有 k 个奇数数字，
 * 我们就认为这个子数组是「优美子数组」。请返回这个数组中「优美子数组」的数目。
 *
 * 示例 1：
 *   输入：nums = [1,1,2,1,1], k = 3
 *   输出：2
 *   解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1]
 *
 * 示例 2：
 *   输入：nums = [2,4,6], k = 1
 *   输出：0
 *   解释：数组中不包含任何奇数，所以不存在优美子数组。
 *
 * 提示：
 *   - 1 <= nums.length <= 50000
 *   - 1 <= nums[i] <= 10^5
 *   - 1 <= k <= nums.length
 **************************************************/
/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 * @lcpr version=20003
 *
 * [1248] 统计「优美子数组」
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
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return f(nums, k - 1) - f(nums, k);
    }
    int f(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int cnt = 0;
        int ans = 0;
        while (right < n)
        {
            if (nums[right] % 2 != 0)
                cnt++;
            while (left <= right && cnt > k)
            {
                if (nums[left] % 2 != 0)
                    cnt--;
                left++;
            }
            right++;
            ans += left;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6]\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,1,2,2,1,2,2,2]\n2\n
// @lcpr case=end

 */
