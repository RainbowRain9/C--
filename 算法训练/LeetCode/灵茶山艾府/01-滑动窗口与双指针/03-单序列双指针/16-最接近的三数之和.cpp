// Source : https://leetcode.cn/problems/3sum-closest/description/
// Date   : 2024-11-22
/*
 * @lc app=leetcode.cn id=16 lang=cpp
 * @lcpr version=20003
 *
 * [16] 最接近的三数之和
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
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++)
        {
            int x = nums[i];
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = x + nums[j] + nums[k];
                if (abs(sum - target) < abs(ans - target))
                {
                    ans = sum;
                }
                if (sum < target)
                {
                    j++;
                }
                else if (sum > target)
                {
                    k--;
                }
                else
                {
                    return target;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,2,1,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n1\n
// @lcpr case=end

 */
