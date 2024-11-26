// Source : https://leetcode.cn/problems/3sum/description/
// Date   : 2024-11-22
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=20003
 *
 * [15] 三数之和
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            int x = nums[i];
            if (i && x == nums[i - 1])
                continue;
            if (x + nums[i + 1] + nums[i + 2] > 0)
                break;
            if (x + nums[n - 2] + nums[n - 1] < 0)
                continue;
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int s = x + nums[j] + nums[k];
                if (s > 0)
                {
                    k--;
                }
                else if (s < 0)
                {
                    j++;
                }
                else
                {
                    ans.push_back({x, nums[j], nums[k]});
                    for (j++; j < k && nums[j] == nums[j - 1]; j++)
                        ;
                    for (k--; k > j && nums[k] == nums[k + 1]; k--)
                        ;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */
