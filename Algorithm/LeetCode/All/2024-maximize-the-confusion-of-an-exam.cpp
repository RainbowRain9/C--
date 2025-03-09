// Source : https://leetcode.cn/problems/maximize-the-confusion-of-an-exam/
// Date   : 2024-11-14

/**************************************************
 * 题目描述：
 * 一位老师正在出一场由 n 道判断题构成的考试，每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。
 * 老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。
 * 给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。
 * 除此以外，还给你一个整数 k ，表示你能进行的最多操作次数。
 * 在一次操作中，你可以将 answerKey 中的任何一个字符替换为 'T' 或者 'F' 。
 * 请你返回在不超过 k 次操作的情况下，最大 连续 'T' 或者 'F' 的数目。
 *
 * 示例 1：
 *   输入：answerKey = "TTFF", k = 2
 *   输出：4
 *   解释：我们可以将两个 'F' 都变为 'T' ，得到 answerKey = "TTTT" 。
 *        总共有四个连续的 'T' 。
 *
 * 示例 2：
 *   输入：answerKey = "TFFT", k = 1
 *   输出：3
 *   解释：我们可以将最前面的 'T' 换成 'F' ，得到 answerKey = "FFFT" 。
 *        或者将最后一个 'T' 换成 'F' ，得到 answerKey = "TFFF" 。
 *        两种情况下，都有三个连续的 'F' 。
 *
 * 提示：
 *   - n == answerKey.length
 *   - 1 <= n <= 5 * 10^4
 *   - answerKey[i] 要么是 'T' ，要么是 'F'
 *   - 1 <= k <= n
 **************************************************/

/*
    解题思路：
    1. 使用滑动窗口解决此问题
    2. 维护一个窗口，使得窗口内需要修改的字符数不超过k
    3. 分别统计窗口内T和F的数量，当某个字符需要修改的次数超过k时收缩窗口
    4. 记录过程中的最大窗口长度即为答案

    时间复杂度分析：
    - 时间复杂度：O(n)，其中n为字符串长度
    - 空间复杂度：O(1)，只使用常数额外空间
*/

/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 * @lcpr version=20003
 *
 * [2024] 考试的最大困扰度
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
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int ans = 0, left = 0, cnt[2]{};
        for (int right = 0; right < answerKey.length(); right++)
        {
            cnt[answerKey[right] >> 1 & 1]++;
            while (cnt[0] > k && cnt[1] > k)
            {
                cnt[answerKey[left++] >> 1 & 1]--;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "TTFF"\n2\n
// @lcpr case=end

// @lcpr case=start
// "TFFT"\n1\n
// @lcpr case=end

// @lcpr case=start
// "TTFTTFTT"\n1\n
// @lcpr case=end

 */

int main()
{
    Solution s;
    
    // 测试用例1
    string answerKey1 = "TTFF";
    int k1 = 2;
    cout << "Test case 1: " << s.maxConsecutiveAnswers(answerKey1, k1) << endl;

    // 测试用例2
    string answerKey2 = "TFFT";
    int k2 = 1;
    cout << "Test case 2: " << s.maxConsecutiveAnswers(answerKey2, k2) << endl;

    // 测试用例3
    string answerKey3 = "TTFTTFTT";
    int k3 = 1;
    cout << "Test case 3: " << s.maxConsecutiveAnswers(answerKey3, k3) << endl;

    return 0;
}
