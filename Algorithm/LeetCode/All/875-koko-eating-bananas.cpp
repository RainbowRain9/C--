/*
 * @Author: RainbowRain9
 * @Date: 2025-03-13 22:14:00
 * @LastEditTime: 2025-03-15 17:09:05
 * @FilePath: \C++\Algorithm\LeetCode\All\875-koko-eating-bananas.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=875 lang=cpp
 * @lcpr version=30103
 *
 * [875] 爱吃香蕉的珂珂
 *
 * https://leetcode.cn/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (49.73%)
 * Likes:    673
 * Dislikes: 0
 * Total Accepted:    174.9K
 * Total Submissions: 350.2K
 * Testcase Example:  '[3,6,7,11]\n8'
 *
 * 珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。
 *
 * 珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k
 * 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
 *
 * 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
 *
 * 返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：piles = [3,6,7,11], h = 8
 * 输出：4
 *
 *
 * 示例 2：
 *
 * 输入：piles = [30,11,23,4,20], h = 5
 * 输出：30
 *
 *
 * 示例 3：
 *
 * 输入：piles = [30,11,23,4,20], h = 6
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= piles.length <= 10^4
 * piles.length <= h <= 10^9
 * 1 <= piles[i] <= 10^9
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
// @lc code=start
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // 找到最大香蕉堆，作为二分查找的上界
        int maxPile = 0;
        for (int pile : piles)
        {
            maxPile = max(maxPile, pile);
        }
        // 特殊情况处理
        if (h == piles.size())
            return maxPile;

        // 二分查找
        int left = 1, right = maxPile;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 计算以当前速度吃完所有香蕉需要的时间
            int total = 0;
            for (int pile : piles)
            {
                total += (pile + mid - 1) / mid; // 向上取整
            }

            if (total <= h)
            {
                right = mid - 1; // 尝试更小的速度
            }
            else
            {
                left = mid + 1; // 需要更大的速度
            }
        }
        return left;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << solution.minEatingSpeed(piles, h) << endl;
}

/*
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */
