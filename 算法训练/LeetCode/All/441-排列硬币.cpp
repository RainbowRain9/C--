// Source : https://leetcode.cn/problems/arranging-coins/description/
// Date   : 2024-11-29
/*
 * @lc app=leetcode.cn id=441 lang=cpp
 * @lcpr version=20003
 *
 * [441] 排列硬币
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
    int arrangeCoins(int n)
    {
        // 使用二分查找
        long left = 1, right = n;
        while (left <= right)
        {
            // 1. 计算中间行数
            long mid = left + (right - left) / 2;

            // 2. 计算填满mid行需要的硬币总数
            long sum = mid * (mid + 1) / 2;

            // 3. 判断并调整搜索范围
            if (sum == n)
                return mid; // 刚好填满
            if (sum > n)
            { // 硬币不够用
                right = mid - 1;
            }
            else
            { // 还有剩余硬币
                left = mid + 1;
            }
        }
        return right; // 返回最后一个能完整填满的行数
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */
