/*
 * @Author: RainbowRain9
 * @Date: 2025-03-09 20:33:30
 * @LastEditTime: 2025-03-10 22:40:07
 * @FilePath: \C++\Algorithm\LeetCode\All\3-longest-substring-without-repeating-characters.cpp
 * @Description:
 */

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30100
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (40.42%)
 * Likes:    10473
 * Dislikes: 0
 * Total Accepted:    3.2M
 * Total Submissions: 7.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
 *
 *
 *
 * 示例 1:
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
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
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map;
        int left = 0, maxLen = 0;
        for (int right = 0; right < s.length(); right++)
        {
            if (map.find(s[right]) != map.end() && map[s[right]] >= left)
            {
                left = map[s[right]] + 1;
            }
            map[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    string test1 = "abcabcbb";
    cout << "Test 1: " << solution.lengthOfLongestSubstring(test1) << endl;

    string test2 = "bbbbb";
    cout << "Test 2: " << solution.lengthOfLongestSubstring(test2) << endl;

    string test3 = "pwwkew";
    cout << "Test 3: " << solution.lengthOfLongestSubstring(test3) << endl;
}

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
