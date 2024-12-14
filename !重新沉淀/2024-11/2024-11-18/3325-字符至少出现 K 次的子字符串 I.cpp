// Source : https://leetcode.cn/problems/count-substrings-with-k-frequency-characters-i/description/
// Date   : 2024-11-18

/**************************************************
 * 题目描述：
 * 给你一个字符串 s 和一个整数 k。
 * 请你求出 s 中有多少个子字符串，满足其中每一个字符出现的频率都是 k。
 *
 * 示例 1：
 *   输入：s = "abacb", k = 2
 *   输出：1
 *   解释：子字符串 "aba" 是唯一一个满足每个字符出现频率为 2 的子字符串。
 *
 * 示例 2：
 *   输入：s = "abcde", k = 1
 *   输出：5
 *   解释：每个长度为 1 的子字符串都满足每个字符出现频率为 1。
 *
 * 提示：
 *   - 1 <= s.length <= 100
 *   - 1 <= k <= s.length
 *   - s 只包含小写英文字母
 **************************************************/

/*
    解题思路：
    1. 枚举所有可能的子字符串
    2. 对每个子字符串统计字符频率
    3. 检查是否所有出现的字符频率都为k

    时间复杂度分析：O(n^3)，其中n为字符串长度
*/
/*
 * @lc app=leetcode.cn id=3325 lang=cpp
 * @lcpr version=20003
 *
 * [3325] 字符至少出现 K 次的子字符串 I
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
    int numberOfSubstrings(string s, int k)
    {
        int n = s.length();
        int cnt[26]{};
        int left = 0, ans = 0;
        for (char c : s)
        {
            cnt[c - 'a']++;
            while (cnt[c - 'a'] == k)
            {
                cnt[s[left] - 'a']--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abacb"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n1\n
// @lcpr case=end

 */
