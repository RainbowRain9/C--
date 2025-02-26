// Source : https://leetcode.cn/problems/count-the-number-of-fair-pairs/description/
// Date   : 2025-02-25
/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 * @lcpr version=30006
 *
 * [2563] 统计公平数对的数目
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
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        ranges::sort(nums);
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            auto it1 = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto it2 = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            sum += it2 - it1;
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,7,4,4,5]\n3\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,7,9,2,5]\n11\n11\n
// @lcpr case=end

 */

