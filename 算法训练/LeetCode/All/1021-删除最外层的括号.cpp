// Source : https://leetcode.cn/problems/remove-outermost-parentheses/description/
// Date   : 2024-11-29
/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 * @lcpr version=20003
 *
 * [1021] 删除最外层的括号
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
    string removeOuterParentheses(string s)
    {
        string res;
        string stk;
        for (auto ch : s)
        {
            if (ch == '(')
            {
                if (!stk.empty())
                {
                    res += ch;
                }
                stk.push_back(ch);
            }
            else
            {
                stk.pop_back();
                if (!stk.empty())
                {
                    res += ch;
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "(()())(())"\n
// @lcpr case=end

// @lcpr case=start
// "(()())(())(()(()))"\n
// @lcpr case=end

// @lcpr case=start
// "()()"\n
// @lcpr case=end

 */
