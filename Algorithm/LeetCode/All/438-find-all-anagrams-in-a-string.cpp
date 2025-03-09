/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30100
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (53.59%)
 * Likes:    1614
 * Dislikes: 0
 * Total Accepted:    614.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
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
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (s.size() < p.size()) return ans;
        
        unordered_map<char, int> cnt, window;
        for (int i = 0; i < p.size(); i++)
        {
            cnt[p[i]]++;
        }
        int match = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (cnt.count(c))
            {
                window[c]++;
                if (window[c] == cnt[c])
                {
                    match++;
                }
            }
            
            if (i >= p.size())
            {
                char a = s[i - p.size()];
                if (cnt.count(a))
                {
                    if (window[a] == cnt[a])
                    {
                        match--;
                    }
                    window[a]--;
                }
            }
            
            if (i >= p.size() - 1 && match == cnt.size())
            {
                ans.push_back(i - p.size() + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */

