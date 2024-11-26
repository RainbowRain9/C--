// Source : https://leetcode.cn/problems/split-two-strings-to-make-palindrome/description/
// Date   : 2024-11-23
/*
 * @lc app=leetcode.cn id=1616 lang=cpp
 * @lcpr version=20003
 *
 * [1616] 分割两个字符串得到回文串
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
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j && s[i] == s[j])
            i++, j--;
        return i >= j;
    }

    bool check(string &a, string &b)
    {
        int i = 0, j = a.length() - 1;
        while (i < j && a[i] == b[j])
            i++, j--;
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    }

public:
    bool checkPalindromeFormation(string &a, string &b)
    {
        return check(a, b) || check(b, a);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "x"\n"y"\n
// @lcpr case=end

// @lcpr case=start
// "xbdef"\n"xecab"\n
// @lcpr case=end

// @lcpr case=start
// "ulacfd"\n"jizalu"\n
// @lcpr case=end

 */
