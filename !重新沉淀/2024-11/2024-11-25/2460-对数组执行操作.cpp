// Source : https://leetcode.cn/problems/apply-operations-to-an-array/description/
// Date   : 2024-11-25
/*
 * @lc app=leetcode.cn id=2460 lang=cpp
 * @lcpr version=20003
 *
 * [2460] 对数组执行操作
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
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        // 先对原数组进行操作
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        // 将非零元素移到前面
        vector<int> ans(n);
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                ans[j++] = nums[i];
            }
        }
        
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

 */
