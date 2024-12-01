// Source : https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
// Date   : 2024-11-29
/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=20003
 *
 * [1047] 删除字符串中的所有相邻重复项
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
    string removeDuplicates(string s)
    {
        string stk;
        for (auto ch : s)
        {
            if (!stk.empty() && stk.back() == ch)
            {
                stk.pop_back();
            }
            else
            {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

 */
