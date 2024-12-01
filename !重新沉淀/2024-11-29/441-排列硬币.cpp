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
        long long left = 1, right = n;
        while (left < right)
        {
            long long mid = (right + left + 1) / 2;
            long long ans = (1 + mid) * mid / 2;
            if (n >= ans)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
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
