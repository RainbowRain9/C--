// Source : https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string/description/
// Date   : 2024-11-15

/**************************************************
 * 题目描述：
 * 给你一个二进制字符串 s 和一个正整数 k 。
 * 如果一个字符串满足以下条件，我们称它是 美丽的 ：
 * - 字符串的长度为 k 。
 * - 字符串中 1 的个数等于 k 。
 *
 * 令 len 为 s 中最短美丽子字符串的长度。
 * 返回长度等于 len 的 s 的美丽子字符串中字典序最小的一个。如果 s 中不存在美丽子字符串，返回一个空字符串。
 *
 * 示例 1：
 *   输入：s = "100011001", k = 3
 *   输出："11001"
 *   解释：有 3 个美丽子字符串：
 *   - "10001" 从下标 0 开始
 *   - "11001" 从下标 4 开始
 *   - "11001" 从下标 4 开始
 *   长度为 5 的美丽子字符串是最短的。字典序最小的长度为 5 的美丽子字符串是 "11001" 。
 *
 * 示例 2：
 *   输入：s = "1011", k = 2
 *   输出："11"
 *   解释：有 3 个美丽子字符串：
 *   - "11" 从下标 2 开始
 *   - "101" 从下标 0 开始
 *   - "11" 从下标 2 开始
 *   长度为 2 的美丽子字符串是最短的。字典序最小的长度为 2 的美丽子字符串是 "11" 。
 *
 * 提示：
 *   - 1 <= s.length <= 100
 *   - 1 <= k <= s.length
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口遍历所有可能的子串
    2. 对于每个子串,检查其中1的个数是否等于k
    3. 记录所有满足条件的子串中最短的长度
    4. 在所有最短长度的子串中找出字典序最小的一个

    时间复杂度分析：O(n^2)，其中n为字符串长度
*/
/*
 * @lc app=leetcode.cn id=2904 lang=cpp
 * @lcpr version=20003
 *
 * [2904] 最短且字典序最小的美丽子字符串
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
    string shortestBeautifulSubstring(string s, int k)
    {
        int n = s.length();
        string ans = "";
        int minLen = n + 1;

        // 滑动窗口
        int count = 0; // 窗口内1的个数
        int l = 0, r = 0;

        while (r < n)
        {
            // 扩大窗口
            if (s[r] == '1')
            {
                count++;
            }

            // 当找到一个美丽子串时
            while (count >= k)
            {
                if (count == k)
                {
                    string sub = s.substr(l, r - l + 1);
                    int len = r - l + 1;

                    // 更新答案:更短的子串或相同长度但字典序更小的子串
                    if (len < minLen || (len == minLen && sub < ans))
                    {
                        minLen = len;
                        ans = sub;
                    }
                }

                // 缩小窗口
                if (s[l] == '1')
                {
                    count--;
                }
                l++;
            }
            r++;
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "100011001"\n3\n
// @lcpr case=end

// @lcpr case=start
// "1011"\n2\n
// @lcpr case=end

// @lcpr case=start
// "000"\n1\n
// @lcpr case=end

 */

int main()
{
    Solution solution;
    string s = "100011001";
    int k = 3;
    string result = solution.shortestBeautifulSubstring(s, k);
    cout << result << endl;
    return 0;
}
