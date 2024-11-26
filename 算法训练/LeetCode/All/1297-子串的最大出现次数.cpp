// Source : https://leetcode.cn/problems/maximum-number-of-occurrences-of-a-substring/
// Date   : 2024-11-11

/**************************************************
 * 给你一个字符串 s ，请你返回满足以下条件且出现次数最大的任意子串的出现次数：
 * - 子串中不同字母的数目必须小于等于 maxLetters 。
 * - 子串的长度必须等于 minSize 。
 * - 子串的长度必须小于等于 maxSize 。
 *
 * 示例 1：
 *   输入：s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
 *   输出：2
 *   解释：子串 "aab" 在原字符串中出现了 2 次。
 *   它满足所有的要求：2 个不同的字母，长度为 3 （在 minSize 和 maxSize 范围内）。
 *
 * 示例 2：
 *   输入：s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
 *   输出：2
 *   解释：子串 "aaa" 在原字符串中出现了 2 次，且它们有重叠部分。
 *
 * 示例 3：
 *   输入：s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
 *   输出：3
 *
 * 示例 4：
 *   输入：s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
 *   输出：0
 *
 * 提示：
 *   - 1 <= s.length <= 10^5
 *   - 1 <= maxLetters <= 26
 *   - 1 <= minSize <= maxSize <= min(26, s.length)
 *   - s 只包含小写英文字母。
 **************************************************/

/*
    解题思路：
    1. 关键发现：如果一个长度为 k 的子串出现了 x 次，那么包含这个子串的更长子串出现次数不会超过 x 次
    2. 因此只需要考虑长度为 minSize 的子串即可
    3. 使用滑动窗口法:
       - 维护一个长度为 minSize 的窗口
       - 用哈希表统计窗口内不同字符的数量
       - 用另一个哈希表统计满足条件的子串出现次数
    4. 返回出现次数的最大值

    时间复杂度分析：
    - 需要遍历字符串一次，时间复杂度为 O(n)
    - 使用了哈希表存储子串，空间复杂度为 O(n)
*/

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
        // map1用于统计满足条件的子串出现次数
        unordered_map<string, int> map1;
        // map2用于统计当前窗口内字符出现次数
        unordered_map<char, int> map2;
        // tmp存储当前窗口的子串
        string tmp;
        // ans记录最大出现次数
        int ans = 0;
        int n = s.length();
        
        // 遍历所有可能的长度为minSize的窗口
        for (int i = 0; i < n - minSize + 1; i++)
        {
            // 获取当前窗口的子串
            tmp = s.substr(i, minSize);
            // 清空字符计数map
            map2.clear();
            // 统计子串中每个字符的出现次数
            for (char c : tmp)
            {
                map2[c]++;
            }
            
            // 如果不同字符数量不超过maxLetters
            if (map2.size() <= maxLetters)
            {
                // 更新子串出现次数并更新最大值
                map1[tmp]++;
                ans = max(ans, map1[tmp]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.maxFreq("aababcaab", 2, 3, 4) << endl; // 输出: 2
    cout << s.maxFreq("aaaa", 1, 3, 3) << endl;      // 输出: 2
    cout << s.maxFreq("aabcabcab", 2, 2, 3) << endl; // 输出: 3
    cout << s.maxFreq("abcde", 2, 3, 3) << endl;     // 输出: 0
    return 0;
}
