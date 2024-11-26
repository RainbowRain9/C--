// Source : https://leetcode.cn/problems/reverse-string/description/
// Date   : 2024-11-20
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=20003
 *
 * [344] 反转字符串
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
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            swap(s[left++], s[right--]);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */
