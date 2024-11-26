// Source : https://leetcode.cn/problems/remove-element/description/
// Date   : 2024-11-25
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 * @lcpr version=20003
 *
 * [27] 移除元素
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
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int k = 0;
        for (int x : nums)
        {
            if (x != val)
            {
                nums[k++] = x;
            }
        }
        return k;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

 */
