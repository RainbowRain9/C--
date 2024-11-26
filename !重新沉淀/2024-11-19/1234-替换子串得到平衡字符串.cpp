// Source : https://leetcode.cn/problems/replace-the-substring-for-balanced-string/description/
// Date   : 2024-11-18

/**************************************************
 * 题目描述：
 * 有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。
 * 假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。
 * 给你一个字符串 s，请你返回使 s 成为「平衡字符串」的最少替换次数。
 * 任何字符都可以替换成任何字符。
 *
 * 示例 1：
 *   输入：s = "QWER"
 *   输出：0
 *   解释：s 已经是平衡的了。
 *
 * 示例 2：
 *   输入：s = "QQWE"
 *   输出：1
 *   解释：我们需要把一个 'Q' 替换成 'R'。
 *
 * 示例 3：
 *   输入：s = "QQQW"
 *   输出：2
 *   解释：我们可以把前面的 "QQ" 替换成 "ER"。
 *
 * 提示：
 *   - 1 <= s.length <= 10^5
 *   - s.length 是 4 的倍数
 *   - s 中只含有 'Q', 'W', 'E', 'R' 四种字符
 **************************************************/

/*
    解题思路：
    使用滑动窗口解决此问题。
    1. 统计每个字符出现的次数，目标是每个字符出现n/4次
    2. 维护一个窗口，该窗口内的字符可以被替换
    3. 当窗口外的字符数量都不超过n/4时，说明窗口内的字符可以被替换成需要的字符
    4. 维护最小的窗口长度，即为答案

    时间复杂度分析：O(n)，其中n为字符串长度
*/
/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 * @lcpr version=20003
 *
 * [1234] 替换子串得到平衡字符串
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
private:
    bool isBalanced(const int cnt[], int partial)
    {
        return cnt['Q'] <= partial && cnt['W'] <= partial &&
               cnt['E'] <= partial && cnt['R'] <= partial;
    }

public:
    int balancedString(string s)
    {
        int n = s.length();
        int cnt[128]{};
        int partial = n / 4;
        for (char c : s)
        {
            cnt[c]++;
        }
        if (isBalanced(cnt, partial)) return 0;
        int left = 0, ans = n, right = 0;
        while (right < n)
        {
            char c = s[right];
            cnt[c]--;
            while (left <= right && isBalanced(cnt, partial))
            {
                ans = min(ans, right - left + 1);
                char v = s[left];
                cnt[v]++;
                left++;
            }
            right++;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "QWER"\n
// @lcpr case=end

// @lcpr case=start
// "QQWE"\n
// @lcpr case=end

// @lcpr case=start
// "QQQW"\n
// @lcpr case=end

// @lcpr case=start
// "QQQQ"\n
// @lcpr case=end

 */

int main()
{
    Solution solution;
    string s = "QQER";
    cout << solution.balancedString(s) << endl;
    return 0;
}