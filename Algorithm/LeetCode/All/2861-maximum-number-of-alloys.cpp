/*
 * @Author: RainbowRain9
 * @Date: 2025-03-18 22:07:57
 * @LastEditTime: 2025-03-18 22:46:03
 * @FilePath: \C++\Algorithm\LeetCode\All\2861-maximum-number-of-alloys.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 * @lcpr version=30103
 *
 * [2861] 最大合金数
 *
 * https://leetcode.cn/problems/maximum-number-of-alloys/description/
 *
 * algorithms
 * Medium (47.44%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    21.4K
 * Total Submissions: 44.8K
 * Testcase Example:  '3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,0]\n[1,2,3]'
 *
 * 假设你是一家合金制造公司的老板，你的公司使用多种金属来制造合金。现在共有 n 种不同类型的金属可以使用，并且你可以使用 k
 * 台机器来制造合金。每台机器都需要特定数量的每种金属来创建合金。
 *
 * 对于第 i 台机器而言，创建合金需要 composition[i][j] 份 j 类型金属。最初，你拥有 stock[i] 份 i
 * 类型金属，而每购入一份 i 类型金属需要花费 cost[i] 的金钱。
 *
 * 给你整数 n、k、budget，下标从 1 开始的二维数组 composition，两个下标从 1 开始的数组 stock 和
 * cost，请你在预算不超过 budget 金钱的前提下，最大化 公司制造合金的数量。
 *
 * 所有合金都需要由同一台机器制造。
 *
 * 返回公司可以制造的最大合金数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], stock =
 * [0,0,0], cost = [1,2,3]
 * 输出：2
 * 解释：最优的方法是使用第 1 台机器来制造合金。
 * 要想制造 2 份合金，我们需要购买：
 * - 2 份第 1 类金属。
 * - 2 份第 2 类金属。
 * - 2 份第 3 类金属。
 * 总共需要 2 * 1 + 2 * 2 + 2 * 3 = 12 的金钱，小于等于预算 15 。
 * 注意，我们最开始时候没有任何一类金属，所以必须买齐所有需要的金属。
 * 可以证明在示例条件下最多可以制造 2 份合金。
 *
 *
 * 示例 2：
 *
 * 输入：n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], stock =
 * [0,0,100], cost = [1,2,3]
 * 输出：5
 * 解释：最优的方法是使用第 2 台机器来制造合金。
 * 要想制造 5 份合金，我们需要购买：
 * - 5 份第 1 类金属。
 * - 5 份第 2 类金属。
 * - 0 份第 3 类金属。
 * 总共需要 5 * 1 + 5 * 2 + 0 * 3 = 15 的金钱，小于等于预算 15 。
 * 可以证明在示例条件下最多可以制造 5 份合金。
 *
 *
 * 示例 3：
 *
 * 输入：n = 2, k = 3, budget = 10, composition = [[2,1],[1,2],[1,1]], stock =
 * [1,1], cost = [5,5]
 * 输出：2
 * 解释：最优的方法是使用第 3 台机器来制造合金。
 * 要想制造 2 份合金，我们需要购买：
 * - 1 份第 1 类金属。
 * - 1 份第 2 类金属。
 * 总共需要 1 * 5 + 1 * 5 = 10 的金钱，小于等于预算 10 。
 * 可以证明在示例条件下最多可以制造 2 份合金。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n, k <= 100
 * 0 <= budget <= 10^8
 * composition.length == k
 * composition[i].length == n
 * 1 <= composition[i][j] <= 100
 * stock.length == cost.length == n
 * 0 <= stock[i] <= 10^8
 * 1 <= cost[i] <= 100
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
// TODO 2025-03-18: 
// @lc code=start
class Solution
{
public:
    // 计算可以制造的最大合金数量
    // n: 金属种类数
    // budget: 预算
    // composition: 每个机器制造一份合金所需的各类金属数量
    // stock: 每种金属的初始库存
    // cost: 每种金属的单位成本
    int maxNumberOfAlloys(int n, int, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
    {
        int ans = 0;
        // 最大可能制造的合金数量 = 最少的库存金属数量 + 预算能买到的数量
        int mx = ranges::min(stock) + budget;
        
        // 遍历每个机器的配方
        for (auto &comp : composition)
        {
            // 检查是否能制造num份合金
            auto check = [&](long long num) -> bool
            {
                long long money = 0;
                // 计算每种金属的花费
                for (int i = 0; i < n; i++)
                {
                    // 如果库存不足,需要购买
                    if (stock[i] < comp[i] * num)
                    {
                        // 计算需要购买的金属花费
                        money += (comp[i] * num - stock[i]) * cost[i];
                        if (money > budget)
                        {
                            return false;
                        }
                    }
                }
                return true;
            };
            
            // 二分查找最大可制造数量
            int left = ans, right = mx + 1;
            while (left + 1 < right)
            { // 开区间写法
                int mid = left + (right - left) / 2;
                (check(mid) ? left : right) = mid;
            }
            ans = left;
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,0]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,100]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n10\n[[2,1],[1,2],[1,1]]\n[1,1]\n[5,5]\n
// @lcpr case=end

 */
