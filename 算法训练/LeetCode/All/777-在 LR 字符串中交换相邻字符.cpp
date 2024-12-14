// Source : https://leetcode.cn/problems/swap-adjacent-in-lr-string/description/
// Date   : 2024-12-14
/*
 * @lc app=leetcode.cn id=777 lang=cpp
 * @lcpr version=20004
 *
 * [777] 在 LR 字符串中交换相邻字符
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
    bool canTransform(string start, string result)
    {
        string s = start, t = result;
        s.erase(remove(s.begin(), s.end(), 'X'), s.end());
        t.erase(remove(t.begin(), t.end(), 'X'), t.end());
        if (s != t)
        {
            return false;
        }
        for (int i = 0, j = 0; i < start.length(); i++)
        {
            if (start[i] == 'X')
            {
                continue;
            }
            while (result[j] == 'X')
            {
                j++;
            }
            if (i != j && (start[i] == 'L') != (i > j))
            {
                return false;
            }
            j++;
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "RXXLRXRXL"\n"XRLXXRRLX"\n
// @lcpr case=end

// @lcpr case=start
// "X"\n"L"\n
// @lcpr case=end

 */
