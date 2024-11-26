// Source : https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Date   : 2024-11-10

/**************************************************
 * 给你字符串 s 和整数 k 。
 *
 * 请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。
 * 英文中的 元音字母 为（a, e, i, o, u）。
 *
 * 示例 1：
 *   输入：s = "abciiidef", k = 3
 *   输出：3
 *   解释：子字符串 "iii" 包含 3 个元音字母。
 *
 * 示例 2：
 *   输入：s = "aeiou", k = 2
 *   输出：2
 *   解释：任意长度为 2 的子字符串都包含 2 个元音字母。
 *
 * 示例 3：
 *   输入：s = "leetcode", k = 3
 *   输出：2
 *   解释："lee"、"eet" 和 "ode" 都包含 2 个元音字母。
 *
 * 提示：
 *   - 1 <= s.length <= 10^5
 *   - s 由小写英文字母组成
 *   - 1 <= k <= s.length
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个长度为k的窗口
    2. 统计窗口内元音字母的数量
    3. 窗口向右滑动时:
       - 如果左边移出的是元音字母，计数减1
       - 如果右边移入的是元音字母，计数加1
    4. 记录过程中的最大计数

    时间复杂度分析：
    - 只需要遍历字符串一次，时间复杂度为 O(n)
    - 只使用了常数个变量，空间复杂度为 O(1)

    具体实现：
    1. 使用两个变量：
       - ans: 记录最大元音字母数
       - vowel: 记录当前窗口内的元音字母数
    2. 遍历字符串：
       - 如果当前字符是元音字母，vowel++
       - 当窗口形成后(i >= k-1)，更新ans
       - 移出窗口左边的字符时，如果是元音字母则vowel--
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        // ans 记录最大元音数量，vowel 记录当前窗口内的元音数量
        int ans = 0, vowel = 0;

        // 遍历字符串
        for (int i = 0; i < s.length(); i++)
        {
            // 检查新进入窗口的字符是否是元音
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u')
            {
                vowel++; // 如果是元音，计数加1
            }

            // 窗口未形成时，继续添加字符
            if (i < k - 1)
            {
                continue;
            }

            // 更新最大元音数量
            ans = max(ans, vowel);

            // 处理窗口左边即将移出的字符
            char out = s[i - k + 1];
            if (out == 'a' || out == 'e' || out == 'i' ||
                out == 'o' || out == 'u')
            {
                vowel--; // 如果移出的是元音，计数减1
            }
        }
        return ans; // 返回最大值
    }
};

int main()
{
    Solution s;
    string str = "abciiidef";
    int k = 3;
    cout << s.maxVowels(str, k) << endl; // 输出: 3

    str = "aeiou";
    k = 2;
    cout << s.maxVowels(str, k) << endl; // 输出: 2

    str = "leetcode";
    k = 3;
    cout << s.maxVowels(str, k) << endl; // 输出: 2

    return 0;
}
