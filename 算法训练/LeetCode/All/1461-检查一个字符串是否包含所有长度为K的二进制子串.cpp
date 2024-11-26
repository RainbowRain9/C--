// Source : https://leetcode.cn/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Date   : 2024-11-11

/**************************************************
 * 给你一个二进制字符串 s 和一个整数 k。如果所有长度为 k 的二进制字符串都是 s 的子串，
 * 请返回 true，否则请返回 false。
 *
 * 示例 1：
 *   输入：s = "00110110", k = 2
 *   输出：true
 *   解释：长度为 2 的二进制串包括 "00"、"01"、"10" 和 "11"。它们分别是 s 中下标为 0、1、3、2 开始的长度为 2 的子串。
 *
 * 示例 2：
 *   输入：s = "0110", k = 1
 *   输出：true
 *   解释：长度为 1 的二进制串包括 "0" 和 "1"，显然它们都是 s 的子串。
 *
 * 示例 3：
 *   输入：s = "0110", k = 2
 *   输出：false
 *   解释：长度为 2 的二进制串 "00" 没有出现在 s 中。
 *
 * 提示：
 *   - 1 <= s.length <= 5 * 10^5
 *   - s[i] 不是 '0' 就是 '1'
 *   - 1 <= k <= 20
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口法，维护一个长度为k的窗口
    2. 使用哈希集合记录所有出现过的k位二进制串
    3. 最后判断哈希集合的大小是否等于2^k
       - 如果等于2^k，说明所有可能的k位二进制串都出现过
       - 否则说明有些k位二进制串没有出现过

    时间复杂度分析：
    - 需要遍历字符串一次，时间复杂度为 O(n)
    - 需要存储所有不同的k位二进制串，空间复杂度为 O(2^k)
*/

#include <string>
#include <unordered_set>
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        // 获取字符串长度
        int n = s.length();
        // 用哈希集合存储所有出现过的k位二进制串
        unordered_set<string> set;
        // 当前窗口内的字符串
        string tmp;
        // 遍历字符串
        for (int i = 0; i < n; i++)
        {
            // 将当前字符加入窗口
            tmp += s[i];
            // 如果窗口长度不足k，继续遍历
            if (i < k - 1)
                continue;
            // 将当前窗口内的k位二进制串加入集合
            set.insert(tmp);
            // 移除窗口最左侧字符，准备下一次滑动
            tmp.erase(0, 1);
        }
        // 判断是否所有可能的k位二进制串都出现过
        // 如果集合大小等于2^k，说明所有可能的组合都出现过
        return set.size() == pow(2, k);
    }
};

int main()
{
    Solution s;
    cout << s.hasAllCodes("00110110", 2) << endl; // 输出: 1 (true)
    cout << s.hasAllCodes("0110", 1) << endl;     // 输出: 1 (true)
    cout << s.hasAllCodes("0110", 2) << endl;     // 输出: 0 (false)
    return 0;
}