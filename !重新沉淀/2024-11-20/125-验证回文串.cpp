// Source : https://leetcode.cn/problems/valid-palindrome/description/
// Date   : 2024-11-20
/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * @lcpr version=20003
 *
 * [125] 验证回文串
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
    bool isPalindrome(string s)
    {
        string a;
        for (char c : s)
        {
            if (isalnum(c))
                a += tolower(c);
        }
        int left = 0, right = a.length() - 1;
        while (left <= right)
        {
            if (a[left++] != a[right--])
                return false;
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

// @lcpr case=start
// " "\n
// @lcpr case=end

 */
