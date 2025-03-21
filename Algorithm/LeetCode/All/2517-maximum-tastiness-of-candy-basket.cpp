/*
 * @Author: RainbowRain9
 * @Date: 2025-03-19 17:54:00
 * @LastEditTime: 2025-03-19 19:22:04
 * @FilePath: \C++\Algorithm\LeetCode\All\2517-maximum-tastiness-of-candy-basket.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 * @lcpr version=30104
 *
 * [2517] 礼盒的最大甜蜜度
 *
 * https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/description/
 *
 * algorithms
 * Medium (71.78%)
 * Likes:    183
 * Dislikes: 0
 * Total Accepted:    27.6K
 * Total Submissions: 38K
 * Testcase Example:  '[13,5,1,8,21,2]\n3'
 *
 * 给你一个正整数数组 price ，其中 price[i] 表示第 i 类糖果的价格，另给你一个正整数 k 。
 *
 * 商店组合 k 类 不同 糖果打包成礼盒出售。礼盒的 甜蜜度 是礼盒中任意两种糖果 价格 绝对差的最小值。
 *
 * 返回礼盒的 最大 甜蜜度。
 *
 *
 *
 * 示例 1：
 *
 * 输入：price = [13,5,1,8,21,2], k = 3
 * 输出：8
 * 解释：选出价格分别为 [13,5,21] 的三类糖果。
 * 礼盒的甜蜜度为 min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8 。
 * 可以证明能够取得的最大甜蜜度就是 8 。
 *
 *
 * 示例 2：
 *
 * 输入：price = [1,3,1], k = 2
 * 输出：2
 * 解释：选出价格分别为 [1,3] 的两类糖果。
 * 礼盒的甜蜜度为 min(|1 - 3|) = min(2) = 2 。
 * 可以证明能够取得的最大甜蜜度就是 2 。
 *
 *
 * 示例 3：
 *
 * 输入：price = [7,7,7,7], k = 2
 * 输出：0
 * 解释：从现有的糖果中任选两类糖果，甜蜜度都会是 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= k <= price.length <= 10^5
 * 1 <= price[i] <= 10^9
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
    int maximumTastiness(vector<int> &price, int k)
    {
        // 获取糖果数组的长度
        int n = price.size();
        
        // 对价格数组进行排序,方便后续处理
        ranges::sort(price);
        
        // 定义检查函数,用于判断是否能找到k个糖果,使它们之间的最小差值>=tastiness
        auto check = [&](int tastiness)
        {
            // prev记录上一个选中的糖果价格,初始化为一个很小的数
            int prev = INT_MIN >> 1;
            // cnt记录已选择的糖果数量
            int cnt = 0;
            
            // 遍历所有糖果
            for (auto p : price)
            {
                // 如果当前糖果与上一个选中糖果的价格差>=tastiness
                if (p - prev >= tastiness)
                {
                    // 选择当前糖果
                    cnt++;
                    // 更新上一个选中糖果的价格
                    prev = p;
                }
            }
            // 判断是否能选够k个糖果
            return cnt >= k;
        };

        // 二分查找最大甜蜜度
        // left为最小可能的甜蜜度(0)
        int left = 0,
            // right为最大可能的甜蜜度(最大价格差+1)
            right = price[n - 1] - price[0] + 1;
        
        // 二分查找,当区间大小>1时继续
        while (left + 1 < right)
        {
            // 计算中间值
            int mid = left + (right - left) / 2;
            // 如果mid是可行的甜蜜度,则尝试更大的值;否则尝试更小的值
            (check(mid) ? left : right) = mid;
        }
        
        // 返回最大可行的甜蜜度
        return left;
    }
    // End of Selection
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [13,5,1,8,21,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n2\n
// @lcpr case=end

 */
