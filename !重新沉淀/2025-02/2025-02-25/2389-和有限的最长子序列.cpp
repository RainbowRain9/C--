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
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> answer(m);

        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        
        for (int i = 0; i < m; i++)
        {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (prefixSum[mid] <= queries[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            answer[i] = left;
        }

        return answer;
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
