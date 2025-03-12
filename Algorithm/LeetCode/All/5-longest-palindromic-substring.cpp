/*
 * @Author: RainbowRain9
 * @Date: 2025-03-11 22:04:52
 * @LastEditTime: 2025-03-11 22:33:32
 * @FilePath: \C++\Algorithm\LeetCode\All\5-longest-palindromic-substring.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30101
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (38.89%)
 * Likes:    7572
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 4.9M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
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
// TODO 2025-03-11: 5.最长回文子串
using namespace std;

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        string res = "";
        for (int i = 0; i < n; i++)
        {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i + 1);
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;
    }

    string palindrome(string s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
// @lc code=end

int main()
{
    Solution solution;
    string test1 = "babad";
    cout << solution.longestPalindrome(test1) << endl;
    string test2 = "cbbd";
    cout << solution.longestPalindrome(test2) << endl;
}

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
