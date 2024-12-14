// Source : https://leetcode.cn/problems/maximize-the-confusion-of-an-exam/
// Date   : 2024-11-14

/**************************************************
 * 题目描述：
 * 一位老师正在出一场由 n 道判断题构成的考试，每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。
 * 老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。
 * 给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。除此以外，还给你一个整数 k ，表示你能进行的最多操作次数。
 * 在一次操作中，你可以将 answerKey 中的一个字符替换为 'T' 或者 'F' 。
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
    1. 使用滑动窗口，分别求出最长连续T和最长连续F
    2. 对于每个字符，如果不是目标字符，需要一次操作将其变为目标字符
    3. 当窗口内需要的操作次数超过k时，需要收缩左边界
    4. 返回两种情况的最大值

    时间复杂度分析：O(n)，其中n为字符串长度
*/

#include <string>
#include <unordered_set>
#include <cmath>
#include <iostream>
using namespace std;

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

int main()
{
    Solution solution;
    string answerKey = "TFFF";
    int k = 2;
    cout << solution.maxConsecutiveAnswers(answerKey, k) << endl;
    return 0;
}