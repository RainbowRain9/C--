// Source : https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/description/
// Date   : 2025-02-18

/**************************************************
 * 题目描述：
 * 给你两个正整数数组 spells 和 potions，长度分别为 n 和 m，其中 spells[i] 表示第 i 个咒语的强度，
 * potions[j] 表示第 j 个药水的强度。同时给定一个整数 success。
 * 一个咒语和药水的组合是成功的，当且仅当咒语强度与药水强度的乘积大于或等于 success。
 * 请你返回一个长度为 n 的数组 pairs，其中 pairs[i] 是能够与第 i 个咒语组成成功组合的药水数目。
 *
 * 示例 1：
 *   输入：spells = [5,1,3], potions = [1,2,3,4,5], success = 7
 *   输出：[4,0,3]
 *   解释：
 *   - 第 0 个咒语：5 * [1,2,3,4,5] = [5,10,15,20,25]，其中 4 个 >= 7
 *   - 第 1 个咒语：1 * [1,2,3,4,5] = [1,2,3,4,5]，其中 0 个 >= 7
 *   - 第 2 个咒语：3 * [1,2,3,4,5] = [3,6,9,12,15]，其中 3 个 >= 7
 *
 * 示例 2：
 *   输入：spells = [3,1,2], potions = [8,5,8], success = 16
 *   输出：[2,0,2]
 *   解释：
 *   - 第 0 个咒语：3 * [8,5,8] = [24,15,24]，其中 2 个 >= 16
 *   - 第 1 个咒语：1 * [8,5,8] = [8,5,8]，其中 0 个 >= 16
 *   - 第 2 个咒语：2 * [8,5,8] = [16,10,16]，其中 2 个 >= 16
 *
 * 提示：
 *   - n == spells.length
 *   - m == potions.length
 *   - 1 <= n, m <= 10^5
 *   - 1 <= spells[i], potions[i] <= 10^5
 *   - 1 <= success <= 10^10
 **************************************************/

/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 * @lcpr version=30005
 *
 * [2300] 咒语和药水的成功对数
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
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n, 0);
        
        // 先对药水数组排序，便于二分查找
        sort(potions.begin(), potions.end());
        
        for (int i = 0; i < n; i++)
        {
            // 计算当前咒语需要的最小药水强度
            // 使用 ceil(success / spell) 来找到满足条件的最小药水强度
            // 注意处理整数除法的向上取整
            long long minPotion = (success + spells[i] - 1) / spells[i];
                    
            // 二分查找第一个大于等于 minPotion 的药水
            auto it = ranges::lower_bound(potions, minPotion);
            
            // 计算满足条件的药水数量
            pairs[i] = potions.end() - it;
        }
        
        return pairs;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,1,3]\n[1,2,3,4,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2]\n[8,5,8]\n16\n
// @lcpr case=end

 */
