/*
 * @Author: RainbowRain9
 * @Date: 2025-03-13 23:00:00
 * @LastEditTime: 2025-03-15 17:08:51
 * @FilePath: \C++\Algorithm\LeetCode\All\1011-capacity-to-ship-packages-within-d-days.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 * @lcpr version=30103
 *
 * [1011] 在 D 天内送达包裹的能力
 *
 * https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/description/
 *
 * algorithms
 * Medium (62.75%)
 * Likes:    646
 * Dislikes: 0
 * Total Accepted:    114.4K
 * Total Submissions: 181.6K
 * Testcase Example:  '[1,2,3,4,5,6,7,8,9,10]\n5'
 *
 * 传送带上的包裹必须在 days 天内从一个港口运送到另一个港口。
 *
 * 传送带上的第 i 个包裹的重量为
 * weights[i]。每一天，我们都会按给出重量（weights）的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
 *
 * 返回能在 days 天内将传送带上的所有包裹送达的船的最低运载能力。
 *
 *
 *
 * 示例 1：
 *
 * 输入：weights = [1,2,3,4,5,6,7,8,9,10], days = 5
 * 输出：15
 * 解释：
 * 船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
 * 第 1 天：1, 2, 3, 4, 5
 * 第 2 天：6, 7
 * 第 3 天：8
 * 第 4 天：9
 * 第 5 天：10
 *
 * 请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9),
 * (10) 是不允许的。
 *
 *
 * 示例 2：
 *
 * 输入：weights = [3,2,2,4,1,4], days = 3
 * 输出：6
 * 解释：
 * 船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
 * 第 1 天：3, 2
 * 第 2 天：2, 4
 * 第 3 天：1, 4
 *
 *
 * 示例 3：
 *
 * 输入：weights = [1,2,3,1,1], days = 4
 * 输出：3
 * 解释：
 * 第 1 天：1
 * 第 2 天：2
 * 第 3 天：3
 * 第 4 天：1, 1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= days <= weights.length <= 5 * 10^4
 * 1 <= weights[i] <= 500
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
    int shipWithinDays(vector<int> &weights, int days)
    {
        int total = 0, maxWeight = 0;
        for (auto weight : weights)
        {
            total += weight;
            maxWeight = max(maxWeight, weight);
        }
        int left = maxWeight, right = total;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 检查当前运载能力是否可行
            int currentDay = 1;
            int currentLoad = 0;
            // 遍历所有包裹重量
            for (auto weight : weights)
            {
                // 如果当前载重加上新包裹超过运载能力限制
                if (currentLoad + weight > mid)
                {
                    // 需要新的一天来运送
                    currentDay++;
                    // 新一天的载重从当前包裹开始
                    currentLoad = weight;
                }
                else
                {
                    // 当前这天可以继续装载这个包裹
                    currentLoad += weight;
                }
            }
            // 根据所需天数调整搜索范围
            if (currentDay <= days)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

int main()
{
    Solution solution;

    // Test case 1: [1,2,3,4,5,6,7,8,9,10], 5 days -> Expected output: 15
    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    cout << "Test case 1: " << solution.shipWithinDays(weights1, days1) << endl;

    // Test case 2: [3,2,2,4,1,4], 3 days -> Expected output: 6
    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    cout << "Test case 2: " << solution.shipWithinDays(weights2, days2) << endl;

    // Test case 3: [1,2,3,1,1], 4 days -> Expected output: 3
    vector<int> weights3 = {1, 2, 3, 1, 1};
    int days3 = 4;
    cout << "Test case 3: " << solution.shipWithinDays(weights3, days3) << endl;

    // Test case 4: [100], 1 day -> Expected output: 100
    vector<int> weights4 = {100};
    int days4 = 1;
    cout << "Test case 4: " << solution.shipWithinDays(weights4, days4) << endl;

    // Test case 5: [5,5,5,5,5], 2 days -> Expected output: 15
    vector<int> weights5 = {5, 5, 5, 5, 5};
    int days5 = 2;
    cout << "Test case 5: " << solution.shipWithinDays(weights5, days5) << endl;
}

/*
// @lcpr case=start
// [1,2,3,4,5,6,7,8,9,10]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,4,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,1]\n4\n
// @lcpr case=end

 */
