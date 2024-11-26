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
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.length();
        int ans_left = -1, ans_right = m;
        int cnt[128]{};
        int less = 0;
        for (char c : t)
        {
            if (cnt[c] == 0)
            {
                less++; // 有 less 种字母的出现次数 < t 中的字母出现次数
            }
            cnt[c]++;   
        }

        int left = 0;
        for (int right = 0; right < m; right++)
        {                      // 移动子串右端点
            char c = s[right]; // 右端点字母
            cnt[c]--;          // 右端点字母移入子串
            if (cnt[c] == 0)
            {
                // 原来窗口内 c 的出现次数比 t 的少，现在一样多
                less--;
            }
            while (less == 0)
            { // 涵盖：所有字母的出现次数都是 >=
                if (right - left < ans_right - ans_left)
                {                    // 找到更短的子串
                    ans_left = left; // 记录此时的左右端点
                    ans_right = right;
                }
                char x = s[left]; // 左端点字母
                if (cnt[x] == 0)
                {
                    // x 移出窗口之前，检查出现次数，
                    // 如果窗口内 x 的出现次数和 t 一样，
                    // 那么 x 移出窗口后，窗口内 x 的出现次数比 t 的少
                    less++;
                }
                cnt[x]++; // 左端点字母移出子串
                left++;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
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