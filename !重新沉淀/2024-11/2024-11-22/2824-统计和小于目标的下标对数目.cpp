// Source : https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/description/
// Date   : 2024-11-22
/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 * @lcpr version=20003
 *
 * [2824] 统计和小于目标的下标对数目
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
    int countPairs(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        int ans = 0;
        sort(nums.begin(), nums.end());
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum < target)
            {
                ans += right - left;
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,1,2,3,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [-6,2,5,-2,-7,-1,3]\n-2\n
// @lcpr case=end

 */
