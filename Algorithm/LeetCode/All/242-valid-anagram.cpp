// Source : https://leetcode.cn/problems/valid-anagram/description/
// Date   : 2024-11-28
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=20003
 *
 * [242] 有效的字母异位词
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
    bool isAnagram(string s, string t)
    {
        if (t.size() != s.size())
            return false;
        vector<int> cnt(26);
        for (auto c : s)
        {
            cnt[c - 'a']++;
        }
        for (auto c : t)
        {
            cnt[c - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */
