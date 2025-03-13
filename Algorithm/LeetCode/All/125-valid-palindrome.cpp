/*
 * @Author: RainbowRain9
 * @Date: 2025-03-12 13:37:22
 * @LastEditTime: 2025-03-13 19:43:59
 * @FilePath: \C++\Algorithm\LeetCode\All\125-valid-palindrome.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * @lcpr version=30101
 *
 * [125] 验证回文串
 *
 * https://leetcode.cn/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (47.68%)
 * Likes:    781
 * Dislikes: 0
 * Total Accepted:    663.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
 *
 * 字母和数字都属于字母数字字符。
 *
 * 给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入: s = "A man, a plan, a canal: Panama"
 * 输出：true
 * 解释："amanaplanacanalpanama" 是回文串。
 *
 *
 * 示例 2：
 *
 * 输入：s = "race a car"
 * 输出：false
 * 解释："raceacar" 不是回文串。
 *
 *
 * 示例 3：
 *
 * 输入：s = " "
 * 输出：true
 * 解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
 * 由于空字符串正着反着读都一样，所以是回文串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 2 * 10^5
 * s 仅由可打印的 ASCII 字符组成
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string c;
        for (auto v : s)
        {
            if (isalnum(v))
            {
                c.push_back(tolower(v));
            }
        }
        int left = 0, right = c.size() - 1;
        while (left <= right)
        {
            if (c[left] != c[right])
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    string test1 = "A man, a plan, a canal: Panama";
    cout << "Test 1: " << solution.isPalindrome(test1) << endl;
    
    string test2 = "race a car"; 
    cout << "Test 2: " << solution.isPalindrome(test2) << endl;
    
    string test3 = " ";
    cout << "Test 3: " << solution.isPalindrome(test3) << endl;
}

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
