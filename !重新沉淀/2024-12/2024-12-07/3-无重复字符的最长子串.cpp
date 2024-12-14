// Source : https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
// Date   : 2024-12-07
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=20003
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int n = s.size();
        int left = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (mp.count(c) && mp[c] >= left)
            {
                left = mp[c] + 1;
            }
            mp[c] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

// @lc code=end

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
