// Source : https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/
// Date   : 2024-11-11

/**************************************************
 * 几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。
 * 每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。
 * 你的点数就是你拿到手中的所有卡牌的点数之和。
 * 给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。
 *
 * 示例 1：
 *   输入：cardPoints = [1,2,3,4,5,6,1], k = 3
 *   输出：12
 *   解释：第一次行动，不管拿哪张牌，你的点数总是 1 。但是，先拿最右边的牌将会最大化你的可获得点数。
 *   最优策略是拿右边的三张牌，最终点数为 1 + 6 + 5 = 12 。
 *
 * 示例 2：
 *   输入：cardPoints = [2,2,2], k = 2
 *   输出：4
 *   解释：无论你拿起哪两张牌，可获得的点数总是 4 。
 *
 * 示例 3：
 *   输入：cardPoints = [9,7,7,9,7,7,9], k = 7
 *   输出：55
 *   解释：你必须拿起所有卡牌，可以获得的点数为所有卡牌的点数之和。
 *
 * 提示：
 *   - 1 <= cardPoints.length <= 10^5
 *   - 1 <= cardPoints[i] <= 10^4
 *   - 1 <= k <= cardPoints.length
 **************************************************/

/*
    解题思路：
    1. 这道题可以转化为滑动窗口问题
    2. 我们需要从数组两端取k个数，那么剩下的n-k个数必然是连续的
    3. 我们可以用滑动窗口找出长度为n-k的连续子数组，使其和最小
    4. 最终答案就是数组总和减去最小的子数组和

    时间复杂度分析：
    - 需要遍历数组一次，时间复杂度为 O(n)
    - 只需要常数个变量，空间复杂度为 O(1)
*/

#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        // 维护一个大小为 n-k 的滑动窗口
        int sum = 0;        // 当前窗口内的元素和
        int ans = INT_MAX;  // 记录窗口内元素和的最小值
        int total = 0;      // 数组所有元素的和
        int n = cardPoints.size();

        for (int i = 0; i < n; i++)
        {
            sum += cardPoints[i];      // 将当前元素加入窗口
            total += cardPoints[i];     // 累加总和
            
            // 在窗口未形成前跳过
            if (i < n - k - 1)
                continue;
                
            ans = min(ans, sum);       // 更新窗口最小值
            sum -= cardPoints[i - n + k + 1];  // 移除窗口最左边的元素
        }

        // 特殊情况处理：当k等于数组长度时，需要取所有元素
        if (k == n)
        {
            ans = 0;
        }
        
        // 返回总和减去连续子数组最小和
        return total - ans;
    }
};

int main()
{
    Solution s;
    vector<int> cardPoints1 = {1, 2, 3, 4, 5, 6, 1};
    cout << s.maxScore(cardPoints1, 3) << endl; // 输出: 12

    vector<int> cardPoints2 = {2, 2, 2};
    cout << s.maxScore(cardPoints2, 2) << endl; // 输出: 4

    vector<int> cardPoints3 = {9, 7, 7, 9, 7, 7, 9};
    cout << s.maxScore(cardPoints3, 7) << endl; // 输出: 55

    return 0;
}
