// Source : https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/description/
// Date   : 2024-11-19

/**************************************************
 * 题目描述：
 * 给你一个字符串 s ，由字符 'a'、'b'、'c' 组成，请你返回 a、b、c 至少出现 k 次的子序列的最短长度。
 * 如果不存在这样的子序列，返回 -1 。
 *
 * 示例 1：
 *   输入：s = "aabaaaacaabc", k = 2
 *   输出：8
 *   解释：从 s 的首尾取 "aaaaaabc" 可以得到一个长度为 8 的子序列。
 *   该子序列包含 a 4 次、b 1 次、c 1 次。
 *   可以证明无法找到满足每个字符至少出现 2 次的更短子序列。
 *
 * 示例 2：
 *   输入：s = "a", k = 1
 *   输出：1
 *   解释：最短子序列是 "a" ，其长度为 1 。
 *
 * 提示：
 *   - 1 <= s.length <= 10^5
 *   - s 仅由字母 'a'、'b'、'c' 组成
 *   - 0 <= k <= s.length
 **************************************************/
/*
 * @lc app=leetcode.cn id=2516 lang=cpp
 * @lcpr version=20003
 *
 * [2516] 每种字符至少取 K 个
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
    int takeCharacters(string s, int k)
    {
        int n = s.length();
        int cnt[3]{};
        for (char c : s)
        {
            cnt[c - 'a']++;
        }
        if (cnt[0] < k || cnt[1] < k || cnt[2] < k)
        {
            return -1; // 字母个数不足 k
        }
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++)
        {
            cnt[s[right] - 'a']--;
            while (cnt[s[right] - 'a'] < k)
            {
                cnt[s[left] - 'a']++;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return n - ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aabaaaacaabc"\n2\n
// @lcpr case=end

// @lcpr case=start
// "a"\n1\n
// @lcpr case=end

 */
