// Source : https://leetcode.cn/problems/minimum-window-substring/
// Date   : 2024-11-14

/**************************************************
 * 题目描述：
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
 * 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 *
 * 示例 1：
 *   输入：s = "ADOBECODEBANC", t = "ABC"
 *   输出："BANC"
 *   解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 * 示例 2：
 *   输入：s = "a", t = "a"
 *   输出："a"
 *   解释：整个字符串 s 本身就是最小覆盖子串。
 *
 * 示例 3：
 *   输入：s = "a", t = "aa"
 *   输出：""
 *   解释：t 中两个字符 'a' 均应包含在 s 的子串中，因此没有符合条件的子字符串，返回空字符串。
 *
 * 提示：
 *   - 1 <= s.length, t.length <= 105
 *   - s 和 t 由英文字母组成
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个可变长度的窗口
    2. 使用两个哈希表分别统计:
       - need: 记录t中每个字符需要的个数
       - window: 记录当前窗口中每个字符的个数
    3. 使用valid变量记录已经满足要求的字符个数
    4. 窗口滑动过程:
       - 右指针扩展窗口直到包含所有t中字符
       - 左指针收缩窗口以寻找最小覆盖子串
       - 更新最小覆盖子串的起始位置和长度

    时间复杂度分析：
    - 只需要遍历一次字符串s，时间复杂度为O(n)
    - 使用两个哈希表存储字符计数，空间复杂度为O(k)，k为字符集大小
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // 使用哈希表记录需要的字符及其个数
        unordered_map<char, int> need, window;
        for (char c : t)
        {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0; // 记录已经满足要求的字符个数
        int start = 0, len = INT_MAX;

        while (right < s.size())
        {
            // 扩大窗口
            char c = s[right];
            right++;
            
            // 更新窗口内字符计数
            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                {
                    valid++; // 该字符满足要求
                }
            }

            // 当所有字符都满足要求时,尝试缩小窗口
            while (valid == need.size())
            {
                // 更新最小覆盖子串
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }

                // 缩小窗口
                char d = s[left];
                left++;
                
                // 更新窗口内字符计数
                if (need.count(d))
                {
                    if (window[d] == need[d])
                    {
                        valid--; // 该字符不再满足要求
                    }
                    window[d]--;
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main()
{
    Solution s;

    // 测试用例1
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl; // 输出: "BANC"

    // 测试用例2
    cout << s.minWindow("a", "a") << endl; // 输出: "a"

    // 测试用例3
    cout << s.minWindow("a", "aa") << endl; // 输出: ""

    return 0;
}