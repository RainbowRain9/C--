/*
 * @Author: RainbowRain9
 * @Date: 2025-03-17 22:00:25
 * @LastEditTime: 2025-03-17 22:28:46
 * @FilePath: \C++\Algorithm\LeetCode\All\275-h-index-ii.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=275 lang=cpp
 * @lcpr version=30103
 *
 * [275] H 指数 II
 *
 * https://leetcode.cn/problems/h-index-ii/description/
 *
 * algorithms
 * Medium (45.03%)
 * Likes:    362
 * Dislikes: 0
 * Total Accepted:    120.1K
 * Total Submissions: 268.1K
 * Testcase Example:  '[0,1,3,5,6]'
 *
 * 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数，citations 已经按照 升序排列
 * 。计算并返回该研究者的 h 指数。
 *
 * h 指数的定义：h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （n 篇论文中）至少 有 h
 * 篇论文分别被引用了至少 h 次。
 *
 * 请你设计并实现对数时间复杂度的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 * 输入：citations = [0,1,3,5,6]
 * 输出：3
 * 解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
 * 由于研究者有3篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3 。
 *
 * 示例 2：
 *
 * 输入：citations = [1,2,100]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == citations.length
 * 1 <= n <= 10^5
 * 0 <= citations[i] <= 1000
 * citations 按 升序排列
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
// TODO 2025-03-17:
// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int left = 0, right = n + 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (citations[n - mid] < mid) // 为什么是[n-mid]
            {                             // 为什么这里不能取等，只能在left取等
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return left;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> citations1 = {0, 1, 3, 5, 6};
    cout << "H-Index for [0,1,3,5,6]: " << solution.hIndex(citations1) << endl;

    vector<int> citations2 = {1, 2, 100};
    cout << "H-Index for [1,2,100]: " << solution.hIndex(citations2) << endl;

    vector<int> citations3 = {0, 0, 0};
    cout << "H-Index for [0,0,0]: " << solution.hIndex(citations3) << endl;

    vector<int> citations4 = {10};
    cout << "H-Index for [10]: " << solution.hIndex(citations4) << endl;
}

/*
// @lcpr case=start
// [0,1,3,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,100]\n
// @lcpr case=end

 */
