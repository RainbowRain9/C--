// Source : https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/description/
// Date   : 2024-11-19

/**************************************************
 * 题目描述：
 * 给你两个字符串 word1 和 word2 。如果一个字符串能通过重新排列字符串中的字符得到另一个字符串，
 * 我们称这两个字符串 可互相转换 。
 * 比方说，"abcde" 和 "bcdae" 可以互相转换，但是 "abcde" 和 "bcde" 不能互相转换。
 * 请你统计有多少 word1 的 非空子字符串 可以通过重新排列字符得到 word2 。
 * 如果重新排列一个子字符串能得到 word2 若干次，这些重排结果都只被计数 一次 。
 * 返回 word1 的子字符串可以重排得到 word2 的方案数。
 *
 * 示例 1：
 *   输入：word1 = "bcca", word2 = "abc"
 *   输出：1
 *   解释：word1 中只有子字符串 "bcc" 可以通过重新排列得到 word2 。
 *
 * 示例 2：
 *   输入：word1 = "abcabc", word2 = "abc"
 *   输出：4
 *   解释：word1 中以下子字符串可以通过重新排列得到 word2 ：
 *   - "abc" 从下标 0 开始
 *   - "cba" 从下标 1 开始
 *   - "cab" 从下标 2 开始
 *   - "abc" 从下标 3 开始
 *
 * 提示：
 *   - 1 <= word1.length <= 10^5
 *   - 1 <= word2.length <= 10^5
 *   - word1 和 word2 仅由小写英文字母组成
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口统计word1中长度等于word2的子串
    2. 对每个子串判断是否可以重排得到word2
    3. 使用哈希表记录已经出现过的子串，避免重复计数

    时间复杂度分析：O(n)，其中n为word1的长度
*/
/*
 * @lc app=leetcode.cn id=3298 lang=cpp
 * @lcpr version=20003
 *
 * [3298] 统计重新排列后包含另一个字符串的子字符串数目 II
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
    long long validSubstringCount(string word1, string word2)
    {
        if (word1.length() < word2.length())
        {
            return 0;
        }
        int cnt[26]{};
        for (char b : word2)
        {
            cnt[b - 'a']++;
        }
        int less = 0;
        for (int c : cnt)
        {
            if (c > 0)
            {
                less++;
            }
        }
        long long ans = 0;
        int left = 0;
        for (char b : word1)
        {
            cnt[b - 'a']--;
            if (cnt[b - 'a'] == 0)
            {
                less--;
            }
            while (less == 0)
            {
                char out = word1[left++];
                if (cnt[out - 'a'] == 0)
                {
                    less++;
                }
                cnt[out - 'a']++;
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "bcca"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"aaabc"\n
// @lcpr case=end

 */
