// Source : https://leetcode.cn/problems/find-the-k-beauty-of-a-number/
// Date   : 2024-11-11

/**************************************************
 * 一个整数 num 的 k 美丽值定义为 num 中符合以下条件的子字符串数目：
 * - 子字符串长度为 k 。
 * - 子字符串能被 num 整除。
 *
 * 给你整数 num 和 k ，请你返回 num 的 k 美丽值。
 *
 * 注意：
 * - 允许有前导 0 。
 * - 子字符串是一个数字的连续数字序列。
 *
 * 示例 1：
 *   输入：num = 240, k = 2
 *   输出：2
 *   解释：以下是 num 里长度为 k 的子字符串：
 *   - "24" ：24 能被 240 整除
 *   - "40" ：40 能被 240 整除
 *   所以，k 美丽值为 2 。
 *
 * 示例 2：
 *   输入：num = 430043, k = 2
 *   输出：2
 *   解释：以下是 num 里长度为 k 的子字符串：
 *   - "43" ：43 能被 430043 整除
 *   - "30" ：30 不能被 430043 整除
 *   - "00" ：0 不能被 430043 整除
 *   - "04" ：4 不能被 430043 整除
 *   - "43" ：43 能被 430043 整除
 *   所以，k 美丽值为 2 。
 *
 * 提示：
 *   - 1 <= num <= 109
 *   - 1 <= k <= num.length
 **************************************************/

/*
    解题思路：
    1. 将数字转为字符串，使用滑动窗口法，维护一个长度为k的窗口
    2. 对每个窗口内的子串:
       - 转换为数字
       - 判断是否能被原数整除
    3. 统计满足条件的子串数量

    时间复杂度分析：
    - 需要遍历字符串一次，时间复杂度为 O(n)
    - 只使用了常数个变量，空间复杂度为 O(1)
*/

#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        string nums = to_string(num);
        string s;
        int cnt = 0;
        for (int i = 0; i < nums.length(); i++)
        {
            s += nums[i];
            if (i < k - 1)
                continue;
            int val = stoi(s);
            if (val != 0 && num % val == 0)
                cnt++;
            s.erase(0, 1);
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    cout << s.divisorSubstrings(240, 2) << endl;    // 输出: 2
    cout << s.divisorSubstrings(430043, 2) << endl; // 输出: 2
    return 0;
}