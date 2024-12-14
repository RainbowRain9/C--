// Source : https://leetcode.cn/problems/subarrays-with-k-different-integers/description/
// Date   : 2024-01-11

/**************************************************
 * 题目描述：
 * 给定一个正整数数组 nums 和一个整数 k，返回 nums 中 「好子数组」 的数目。
 * 如果 nums 的某个子数组中不同整数的个数恰好为 k，则称之为 「好子数组 」。
 * 子数组是数组的连续部分。
 *
 * 示例 1：
 *   输入：nums = [1,2,1,2,3], k = 2
 *   输出：7
 *   解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
 *
 * 示例 2：
 *   输入：nums = [1,2,1,3,4], k = 3
 *   输出：3
 *   解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4]
 *
 * 提示：
 *   - 1 <= nums.length <= 2 * 10^4
 *   - 1 <= nums[i], k <= nums.length
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口统计每个子数组中不同整数的个数
    2. 当子数组中不同整数的个数等于k时，该子数组为好子数组
    3. 使用两个滑动窗口，分别统计最多包含k个不同整数和最多包含k-1个不同整数的子数组个数
    4. 两者之差即为恰好包含k个不同整数的子数组个数

    时间复杂度分析：O(n)，其中n为数组长度
*/
/*
 * @lc app=leetcode.cn id=992 lang=cpp
 * @lcpr version=20003
 *
 * [992] K 个不同整数的子数组
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
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return f(nums, k - 1) - f(nums, k);
    }
    int f(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0, right = 0;
        unordered_map<int, int> cnt;
        int ans = 0;
        while (right < n)
        {
            int x = nums[right];
            cnt[x]++;
            while (cnt.size() > k)
            {
                int y = nums[left++];
                if (--cnt[y] == 0)
                {
                    cnt.erase(y);
                }
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
// [1,2,1,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,4]\n3\n
// @lcpr case=end

 */
