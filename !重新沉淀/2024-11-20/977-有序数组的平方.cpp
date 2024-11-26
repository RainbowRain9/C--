// Source :
// Date   : 2024-11-
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=20003
 *
 * [977] 有序数组的平方
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
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        int p = n - 1;
        vector<int> res(n);
        while (left <= right)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                res[p] = nums[left] * nums[left];
                left++;
            }
            else
            {
                res[p] = nums[right] * nums[right];
                right--;
            }
            p--;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */
