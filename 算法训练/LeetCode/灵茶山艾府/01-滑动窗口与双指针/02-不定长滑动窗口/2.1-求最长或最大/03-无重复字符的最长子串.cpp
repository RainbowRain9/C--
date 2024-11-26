// Source : https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// Date : 2024-11-11

/************************************
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
************************************/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution1
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

class Solution2
{
public:
    // 使用滑动窗口解决无重复字符的最长子串问题
    int lengthOfLongestSubstring(string s)
    {
        // 使用哈希集合作为滑动窗口,记录窗口中的所有字符
        unordered_set <char> window;
        // ans记录最长无重复子串的长度,left为窗口左边界
        int ans = 0, left = 0;
        // 获取字符串长度
        int n = s.length();
        // right为窗口右边界,向右扩展窗口
        for (int right = 0; right < n; right++)
        {
            // 获取当前字符
            char c = s[right];
            // 如果窗口中已存在当前字符,则不断移除左边界字符直到窗口中不含重复字符
            while (window.count(c))
            {
                window.erase(s[left++]);
            }
            // 将当前字符加入窗口
            window.insert(c);
            // 更新最长无重复子串的长度
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};


int main()
{
    // 创建Solution对象
    Solution2 solution;
    
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
