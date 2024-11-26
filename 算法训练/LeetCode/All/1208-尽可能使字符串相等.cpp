// Source : https://leetcode.cn/problems/get-equal-substrings-within-budget/
// Date   : 2024-11-14

/**************************************************
 * 题目描述：
 * 给你两个长度相同的字符串，s 和 t。
 * 将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。
 * 用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。
 * 如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。
 * 如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。
 *
 * 示例 1：
 *   输入：s = "abcd", t = "bcdf", maxCost = 3
 *   输出：3
 *   解释：s 中的 "abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。
 *
 * 示例 2：
 *   输入：s = "abcd", t = "cdef", maxCost = 3
 *   输出：1
 *   解释：s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为 1。
 *
 * 示例 3：
 *   输入：s = "abcd", t = "acde", maxCost = 0
 *   输出：1
 *   解释：你无法作出任何改动，所以最大长度为 1。
 *
 * 提示：
 *   - 1 <= s.length, t.length <= 10^5
 *   - 0 <= maxCost <= 10^6
 *   - s 和 t 都只含小写英文字母
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个可变长度的窗口
    2. 计算每个位置字符转换的开销
    3. 当窗口内总开销超过maxCost时，左指针右移直到窗口合法
    4. 记录过程中的最大窗口长度

    时间复杂度分析：
    - 只需要遍历一次字符串，时间复杂度为O(n)
    - 只使用常数额外空间，空间复杂度为O(1)
*/

/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 * @lcpr version=20003
 *
 * [1208] 尽可能使字符串相等
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
#include <string>
#include <cmath>

// class Solution {
// public:
//     int equalSubstring(string s, string t, int maxCost) {
//         int n = s.length();
//         int ans = 0, cost = 0, left = 0;
//         for (int right = 0; right < n; right++) {
//             cost += abs(s[right] - t[right]);
//             while (cost > maxCost) {
//                 cost -= abs(s[left] - t[left]);
//                 left++;
//             }
//             ans = max(ans, right - left + 1);
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.length();
        int left = 0, right = 0;
        int ans = 0, cost = 0;
        while (right < n)
        {
            cost += abs(s[right] - t[right]);
            right++;
            while (cost > maxCost)
            {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcd"\n"bcdf"\n3\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"cdef"\n3\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"acde"\n0\n
// @lcpr case=end
*/

int main()
{
    Solution s;

    // 测试用例1
    cout << s.equalSubstring("abcd", "bcdf", 3) << endl; // 输出: 3

    // 测试用例2
    cout << s.equalSubstring("abcd", "cdef", 3) << endl; // 输出: 1

    // 测试用例3
    cout << s.equalSubstring("abcd", "acde", 0) << endl; // 输出: 1

    return 0;
}