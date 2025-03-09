// Date :  2024-11-
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=20003
 *
 * [3] 无重复字符的最长子串
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
    // 使用滑动窗口和哈希表解决无重复字符的最长子串问题
    // 时间复杂度: O(n), 空间复杂度: O(min(m,n))
    // n是字符串的长度，m是字符集的大小
    int lengthOfLongestSubstring(string s)
    {
        // 哈希表存储字符及其最后出现的索引位置
        unordered_map<char, int> map;

        // maxLength记录最长无重复子串的长度
        int maxLength = 0;

        // left指针表示当前无重复子串的起始位置
        int left = 0;

        // right指针遍历整个字符串
        for (int right = 0; right < s.length(); ++right)
        {
            // 如果当前字符已经在map中存在，且其索引大于等于left指针
            // 说明在当前窗口中存在重复字符
            if (map.find(s[right]) != map.end() && map[s[right]] >= left)
            {
                // 将left指针移动到重复字符的下一个位置
                left = map[s[right]] + 1;
            }

            // 更新当前字符的最新索引位置
            map[s[right]] = right;

            // 更新最长无重复子串的长度
            // right - left + 1 表示当前窗口的长度
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

// @lc code=end

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
