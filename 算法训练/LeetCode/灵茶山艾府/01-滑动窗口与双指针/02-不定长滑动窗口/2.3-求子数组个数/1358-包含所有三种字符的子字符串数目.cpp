// Source : https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/solution/bao-han-suo-you-san-chong-zi-fu-de-zi-zi-fu-chuan-/
// Date   : 2024-11-18

/**************************************************
 * 题目描述：
 * 给你一个字符串 s ，它只包含三种字符 a, b 和 c 。
 * 请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。
 *
 * 示例 1：
 *   输入：s = "abcabc"
 *   输出：10
 *   解释：包含 a，b 和 c 各至少一次的子字符串为 "abc", "abca", "abcab", "abcabc",
 *        "bca", "bcab", "bcabc", "cab", "cabc" 和 "abc" (相同的子字符串算多次)。
 *
 * 示例 2：
 *   输入：s = "aaacb"
 *   输出：3
 *   解释：包含 a，b 和 c 各至少一次的子字符串为 "aaacb", "aacb" 和 "acb" 。
 *
 * 提示：
 *   - 3 <= s.length <= 5 x 10^4
 *   - s 只包含字符 a，b 和 c
 **************************************************/

/*
    解题思路：
    使用滑动窗口解决此问题。
    1. 维护一个窗口，统计窗口内a,b,c三个字符的出现次数
    2. 当窗口内包含所有三种字符时，以right为右端点的所有子串都是合法的
    3. 收缩左边界，继续寻找新的合法子串

    时间复杂度分析：O(n)，其中n为字符串长度
*/
/*
 * @lc app=leetcode.cn id=1358 lang=cpp
 * @lcpr version=20003
 *
 * [1358] 包含所有三种字符的子字符串数目
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
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        int cnt[3] = {0};
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++)
        {
            cnt[s[right] - 'a']++;
            while (cnt[0] && cnt[1] && cnt[2])
            {
                ans += n - right;
                cnt[s[left++] - 'a']--;
            }
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcabc"\n
// @lcpr case=end

// @lcpr case=start
// "aaacb"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

int main()
{
    Solution solution;
    string s = "abcabc";
    cout << solution.numberOfSubstrings(s) << endl;
    return 0;
}
