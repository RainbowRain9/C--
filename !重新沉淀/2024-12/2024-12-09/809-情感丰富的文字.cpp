// Source : https://leetcode.cn/problems/expressive-words/description/
// Date   : 2024-12-09
/*
 * @lc app=leetcode.cn id=809 lang=cpp
 * @lcpr version=20004
 *
 * [809] 情感丰富的文字
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
    int expressiveWords(string s, vector<string> &words)
    {
        int ans = 0;
        for (const string &word : words)
        {
            if (isExpressive(s, word))
            {
                ans++;
            }
        }
        return ans;
    }

    bool isExpressive(const string &s, const string &word)
    {
        int i = 0, j = 0;
        while (i < s.length() && j < word.length())
        {
            if (s[i] != word[j])
            {
                return false;
            }

            int s_cnt = 1;
            while (i + 1 < s.length() && s[i] == s[i + 1])
            {
                s_cnt++;
                i++;
            }

            int w_cnt = 1;
            while (j + 1 < word.length() && word[j] == word[j + 1])
            {
                w_cnt++;
                j++;
            }

            if (s_cnt < w_cnt || (s_cnt < 3 && s_cnt != w_cnt))
            {
                return false;
            }

            i++;
            j++;
        }

        return i == s.length() && j == word.length();
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["hello", "hi", "helo"]\n
// @lcpr case=end

 */
