// Source : https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/
// Date   : 2024-11-14

/**************************************************
 * 题目描述：
 * 给你一个字符串 s ，请你找出一个满足下述条件且长度最大的子字符串：
 * 每个字符在子字符串中出现次数不超过 2 次。
 * 返回满足上述条件的子字符串的长度。
 *
 * 示例 1：
 *   输入：s = "bcbbbcba"
 *   输出：4
 *   解释：以下子字符串满足每个字符出现次数不超过两次的条件：
 *   - "bcbbbcba" 长度为 1
 *   - "bcbbbcba" 长度为 2
 *   - "bcbbbcba" 长度为 3
 *   - "bcbbbcba" 长度为 4
 *   其中最长的子字符串长度为 4 。
 *
 * 示例 2：
 *   输入：s = "aaaa"
 *   输出：2
 *   解释：以下子字符串满足每个字符出现次数不超过两次的条件：
 *   - "aaaa" 长度为 1
 *   - "aaaa" 长度为 2
 *   其中最长的子字符串长度为 2 。
 *
 * 提示：
 *   - 1 <= s.length <= 100
 *   - s 仅由小写英文字母组成
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个可变长度的窗口
    2. 使用数组记录窗口内每个字符出现的次数
    3. 当某个字符出现次数超过2次时，左指针右移直到该字符次数不超过2
    4. 记录过程中的最大窗口长度

    时间复杂度分析：
    - 只需要遍历一次字符串，时间复杂度为O(n)
    - 使用固定大小的数组记录字符出现次数，空间复杂度为O(1)
*/

#include <string>
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int cnt[128]{};
        int n = s.length();
        int ans = 0, left = 0;
        for (int right = 0; right < n; right++)
        {
            cnt[s[right]]++;
            while (cnt[s[right]] > 2)
            {
                cnt[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    Solution s;

    // 测试用例1
    cout << s.maximumLengthSubstring("bcbbbcba") << endl; // 输出: 4

    // 测试用例2
    cout << s.maximumLengthSubstring("aaaa") << endl; // 输出: 2

    return 0;
}