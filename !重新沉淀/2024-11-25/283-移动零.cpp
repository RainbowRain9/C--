// Source : https://leetcode.cn/problems/move-zeroes/description/
// Date   : 2024-11-25
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=20003
 *
 * [283] 移动零
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
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[k++] = nums[i];
            }
        }
        while (k < n)
        {
            nums[k++] = 0;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
