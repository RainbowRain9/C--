// Source : https://leetcode.cn/problems/long-pressed-name/description/
// Date   : 2024-12-07
/*
 * @lc app=leetcode.cn id=925 lang=cpp
 * @lcpr version=20004
 *
 * [925] 长按键入
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
    bool isLongPressedName(string name, string typed)
    {
        int i = 0, j = 0;
        int n = name.length();
        int m = typed.length();
        while (j < m)
        {
            if (i < n && name[i] == typed[j])
            {
                i++;
                j++;
            }
            else if (j > 0 && typed[j] == typed[j - 1])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        return i == n;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "alex"\n"aaleex"\n
// @lcpr case=end

// @lcpr case=start
// "saeed"\n"ssaaedd"\n
// @lcpr case=end

 */
