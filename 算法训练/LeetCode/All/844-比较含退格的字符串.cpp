// Source : https://leetcode.cn/problems/backspace-string-compare/description/
// Date   : 2024-12-16
/*
 * @lc app=leetcode.cn id=844 lang=cpp
 * @lcpr version=20004
 *
 * [844] 比较含退格的字符串
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
    bool backspaceCompare(string s, string t)
    {
        return build(s) == build(t);
    }

    string build(string str)
    {
        string ret;
        for (auto ch : str)
        {
            if (ch != '#')
            {
                ret.push_back(ch);
            }
            else if (!ret.empty())
            {
                ret.pop_back();
            }
        }
        return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ab#c"\n"ad#c"\n
// @lcpr case=end

// @lcpr case=start
// "ab##"\n"c#d#"\n
// @lcpr case=end

// @lcpr case=start
// "a#c"\n"b"\n
// @lcpr case=end

 */
