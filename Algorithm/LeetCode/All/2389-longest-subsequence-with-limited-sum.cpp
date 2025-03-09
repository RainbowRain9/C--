// Source : https://leetcode.cn/problems/longest-subsequence-with-limited-sum/description/
// Date   : 2025-02-24
/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 * @lcpr version=30006
 *
 * [2389] 和有限的最长子序列
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
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());

        vector<long long> prefix;
        long long sum = 0;
        for (auto num : nums)
        {
            sum += num;
            prefix.push_back(sum);
        }

        vector<int> ans;
        for (auto q : queries)
        {
            auto it = upper_bound(prefix.begin(), prefix.end(), q);
            ans.push_back(it - prefix.begin());
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,2,1]\n[3,10,21]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,5]\n[1]\n
// @lcpr case=end

 */
