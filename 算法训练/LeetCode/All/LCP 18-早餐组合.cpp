// Source : https://leetcode.cn/problems/2vYnGI/description/
// Date   : 2024-11-25

/**************************************************
 * 题目描述：
 * 小扣在秋日市集选择了一家早餐摊位，一维整型数组 staple 中记录了每种主食的价格，一维整型数组 drinks 中记录了每种饮品的价格。
 * 小扣的计划选择一份主食和一款饮品，且花费不超过 x 元。请返回小扣共有多少种购买方案。
 * 注意：答案需要以 1e9 + 7 (1000000007) 为底取模，即对 1000000007 取余
 *
 * 示例 1：
 *   输入：staple = [10,20,5], drinks = [5,5,2], x = 15
 *   输出：6
 *   解释：小扣有 6 种购买方案，所选主食与所选饮品在数组中对应的下标分别是：
 *        第 1 种方案：staple[0] + drinks[0] = 10 + 5 = 15；
 *        第 2 种方案：staple[0] + drinks[1] = 10 + 5 = 15；
 *        第 3 种方案：staple[0] + drinks[2] = 10 + 2 = 12；
 *        第 4 种方案：staple[2] + drinks[0] = 5 + 5 = 10；
 *        第 5 种方案：staple[2] + drinks[1] = 5 + 5 = 10；
 *        第 6 种方案：staple[2] + drinks[2] = 5 + 2 = 7。
 *
 * 提示：
 *   - 1 <= staple.length <= 10^5
 *   - 1 <= drinks.length <= 10^5
 *   - 1 <= staple[i], drinks[i] <= 10^5
 *   - 1 <= x <= 2*10^5
 **************************************************/

/*
    解题思路：
    1. 对主食和饮品数组分别排序
    2. 对每个主食价格，用二分查找找到不超过剩余金额的最大饮品价格下标
    3. 累加每个主食对应的饮品数量

    时间复杂度：O(nlogn)，其中 n 为数组长度
*/
/*
 * @lc app=leetcode.cn id=LCP 18 lang=cpp
 * @lcpr version=20003
 *
 * [LCP 18] 早餐组合
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
    int breakfastNumber(vector<int> &staple, vector<int> &drinks, int x)
    {
        const int MOD = 1000000007;
        long ans = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        
        // 双指针法
        int i = 0, j = drinks.size() - 1;
        while (i < staple.size() && j >= 0)
        {
            int sum = staple[i] + drinks[j];
            if (sum <= x)
            {
                // 当前主食可以和drinks[0...j]的所有饮品组合
                i++;
                ans = (ans + j + 1) % MOD;
            }
            else
            {
                // 当前组合总价超过预算,需要减小饮品价格
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,20,5]\n[5,5,2]\n15`>\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1]\n[8,9,5,1]\n9`>\n
// @lcpr case=end

 */
