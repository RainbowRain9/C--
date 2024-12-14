// Source : https://leetcode.cn/problems/sort-array-by-parity-ii/description/
// Date   : 2024-11-25
/*
 * @lc app=leetcode.cn id=922 lang=cpp
 * @lcpr version=20003
 *
 * [922] 按奇偶排序数组 II
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
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        int i = 0;
        for (int x : nums)
        {
            if (x % 2 == 0)
            {
                res[i] = x;
                i += 2;
            }
        }
        i = 1;
        for (int x : nums)
        {
            if (x % 2 == 1)
            {
                res[i] = x;
                i += 2;
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n
// @lcpr case=end

 */
