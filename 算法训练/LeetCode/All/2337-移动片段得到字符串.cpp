// Source : https://leetcode.cn/problems/move-pieces-to-obtain-a-string/description/
// Date   : 2024-12-11
/*
 * @lc app=leetcode.cn id=2337 lang=cpp
 * @lcpr version=20004
 *
 * [2337] 移动片段得到字符串
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
    bool canChange(string start, string target)
    {
        string s = start, t = target;
        s.erase(remove(s.begin(), s.end(), '_'), s.end());
        t.erase(remove(t.begin(), t.end(), '_'), t.end());
        if (s != t)
        {
            return false;
        }
        for (int i = 0, j = 0; i < start.length(); i++)
        {
            if (start[i] == '_')
            {
                continue;
            }
            while (target[j] == '_')
            {
                j++;
            }
            if (i != j && (start[i] == 'L') == (i < j))
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
// "_L__R__R_"\n"L______RR"\n
// @lcpr case=end

// @lcpr case=start
// "R_L_"\n"__LR"\n
// @lcpr case=end

// @lcpr case=start
// "_R"\n"R_"\n
// @lcpr case=end

 */
