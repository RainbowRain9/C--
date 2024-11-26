// Source : https://leetcode.cn/problems/find-the-longest-semi-repetitive-substring/
// Date   : 2024-01-07

/**************************************************
 * 题目描述：给你一个下标从 0 开始的字符串 s ，请你返回 s 中最长的半重复子字符串的长度。
 * 如果一个字符串中 至多一对 相邻字符相等，则认为该字符串是半重复字符串。
 *
 * 示例 1：
 *   输入：s = "52233"
 *   输出：4
 *   解释：最长的半重复子字符串是 "5223" ，长度为 4 。
 *        注意 "5223" 只包含一对相邻相等字符。
 *
 * 示例 2：
 *   输入：s = "5494"
 *   输出：4
 *   解释：s 就是一个半重复字符串，因为不存在相邻相等字符。
 *
 * 示例 3：
 *   输入：s = "1111111"
 *   输出：2
 *   解释：最长的半重复子字符串是 "11" ，长度为 2 。
 *
 * 提示：
 *   - 1 <= s.length <= 50
 *   - s 仅由数字组成
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口，窗口内最多只能有一对相邻相等的字符
    2. 右指针不断向右扩展，记录窗口内相邻相等字符的数量
    3. 当窗口内相邻相等字符超过1对时，左指针右移直到窗口重新满足条件
    4. 在过程中维护最大窗口长度

    时间复杂度分析：O(n)，其中n为字符串长度
*/

#include <string>
#include <unordered_set>
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int ans = 1, left = 0, cnt = 0;
        for (int right = 1; right < s.length(); right++)
        {
            if (s[right] == s[right - 1])
                cnt++;
            while (cnt > 1)
            {
                if (s[left + 1] == s[left])
                {
                    cnt--;
                }

                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // 测试用例
    cout << solution.longestSemiRepetitiveSubstring("52233") << endl;   // 4
    cout << solution.longestSemiRepetitiveSubstring("5494") << endl;    // 4
    cout << solution.longestSemiRepetitiveSubstring("1111111") << endl; // 2

    return 0;
}