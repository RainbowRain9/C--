// Source : https://leetcode.cn/problems/sort-array-by-parity/description/
// Date   : 2024-11-25
/*
 * @lc app=leetcode.cn id=905 lang=cpp
 * @lcpr version=20003
 *
 * [905] 按奇偶排序数组
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
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                res.push_back(nums[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 1)
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
