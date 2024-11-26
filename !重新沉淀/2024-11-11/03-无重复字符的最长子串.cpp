// Source : https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// Date : 2024-11-12

/*********************************************************
    给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。

    示例 1:
        输入: s = "abcabcbb"
        输出: 3
        解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

    示例 2:
        输入: s = "bbbbb"
        输出: 1
        解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

    示例 3:
        输入: s = "pwwkew"
        输出: 3
        解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
             请注意，你的答案必须是子串的长度，"pwke" 是一个子序列，不是子串。
*********************************************************/

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution
{
public:
    // 使用滑动窗口解决无重复字符的最长子串问题
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> window;
        int ans = 0, left = 0;
        for (int right = 0; right < s.length(); right++)
        {
            char c = s[right];
            while (window.count(c))
            {
                window.erase(left++);
            }
            window.insert(c);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    // 创建Solution对象
    Solution solution;

    // 测试用例
    string s = "abcabcbb";

    // 输出测试用例
    cout << "Input: s = \"" << s << "\"" << endl;

    // 调用lengthOfLongestSubstring方法获取结果
    int result = solution.lengthOfLongestSubstring(s);

    // 输出结果
    cout << "Output: " << result << endl;

    // 输出解释
    cout << "Explanation: 因为无重复字符的最长子串是 \"abc\"，所以其长度为 " << result << "。" << endl;

    return 0;
}
