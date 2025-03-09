// Source : https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
// Date   : 2025-03-06

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30100
 *
 * [438] 找到字符串中所有字母异位词
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

int main()
{
    Solution solution;
    // your test code here
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = solution.findAnagrams(s, p);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
}

/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */
