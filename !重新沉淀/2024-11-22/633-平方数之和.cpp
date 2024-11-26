// Source : https://leetcode.cn/problems/sum-of-square-numbers/description/
// Date   : 2024-11-22
/*
 * @lc app=leetcode.cn id=633 lang=cpp
 * @lcpr version=20003
 *
 * [633] 平方数之和
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
    bool judgeSquareSum(int c)
    {
        long long left = 0, right = sqrt(c);
        while (left <= right)
        {
            long long sum = left * left + right * right;
            if (sum == c)
                return true;
            if (sum > c)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
