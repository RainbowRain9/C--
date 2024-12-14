// Source : https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i/description/
// Date   : 2024-11-19

/**************************************************
 * 题目描述：
 * 给你一个二进制字符串 s 和一个正整数 k 。
 * 如果子字符串中所有的 1 都互不相邻，并且子字符串中 1 的个数正好为 k ，那么我们称这个子字符串是一个 k 约束子字符串。
 * 返回 s 中 k 约束子字符串的数目。
 * 子字符串是一个字符串中一段连续的字符序列。
 *
 * 示例 1：
 *   输入：s = "10101", k = 1
 *   输出：4
 *   解释：符合要求的子字符串如下：
 *   - "1" 从下标 0 开始，长度为 1
 *   - "1" 从下标 2 开始，长度为 1
 *   - "1" 从下标 4 开始，长度为 1
 *   - "10101" 从下标 0 开始，长度为 5
 *
 * 示例 2：
 *   输入：s = "1010101", k = 2
 *   输出：2
 *   解释：符合要求的子字符串如下：
 *   - "101" 从下标 0 开始，长度为 3
 *   - "101" 从下标 2 开始，长度为 3
 *
 * 示例 3：
 *   输入：s = "11111", k = 1
 *   输出：0
 *   解释：没有 k 约束子字符串。
 *
 * 提示：
 *   - 1 <= s.length <= 50
 *   - s[i] 要么是 '0' 要么是 '1' 。
 *   - 1 <= k <= s.length
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口统计每个子字符串中1的个数
    2. 检查子字符串中的1是否互不相邻
    3. 当满足条件时，计数加1

    时间复杂度分析：O(n^2)，其中n为字符串长度
*/
/*
 * @lc app=leetcode.cn id=3258 lang=cpp
 * @lcpr version=20003
 *
 * [3258] 统计满足 K 约束的子字符串数量 I
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
    int countKConstraintSubstrings(string s, int k)
    {
        int n = s.length();
        int left = 0;
        int cnt[2]{};
        int ans = 0;
        for (int right = 0; right < n; right++)
        {
            cnt[s[right] & 1]++;
            while (cnt[0] > k && cnt[1] > k)
            {
                cnt[s[left] & 1]--;
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "10101"\n1\n
// @lcpr case=end

// @lcpr case=start
// "1010101"\n2\n
// @lcpr case=end

// @lcpr case=start
// "11111"\n1\n
// @lcpr case=end

 */
