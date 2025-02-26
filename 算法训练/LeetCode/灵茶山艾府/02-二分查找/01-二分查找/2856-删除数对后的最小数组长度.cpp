// Source : https://leetcode.cn/problems/minimum-array-length-after-pair-removals/description/
// Date   : 2025-02-25
/*
 * @lc app=leetcode.cn id=2856 lang=cpp
 * @lcpr version=30006
 *
 * [2856] 删除数对后的最小数组长度
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
    int minLengthAfterRemovals(vector<int> &nums)
    {
        int n = nums.size();
        int x = nums[n / 2];
        int max_cnt = ranges::upper_bound(nums, x) - ranges::lower_bound(nums, x);

        int other_cnt = n - max_cnt;

        if (max_cnt <= other_cnt)
        {
            return n % 2;
        }
        else
        {
            return max_cnt - other_cnt;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,2,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1000000000,1000000000]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,4,4]\n
// @lcpr case=end

 */
