// Source : https://leetcode.cn/problems/valid-triangle-number/description/
// Date   : 2024-11-22
/*
 * @lc app=leetcode.cn id=611 lang=cpp
 * @lcpr version=20003
 *
 * [611] 有效三角形的个数
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
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int k = 2; k < n; k++)
        {
            int i = 0, j = k - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] > nums[k])
                {
                    ans += j - i;
                    j--;
                }
                else
                    i++;
            }
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,3,4]\n
// @lcpr case=end

 */
