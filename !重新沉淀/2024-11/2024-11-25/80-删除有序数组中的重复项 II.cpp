// Source : https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/description/
// Date   : 2024-11-25
/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=20003
 *
 * [80] 删除有序数组中的重复项 II
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
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();
        int k = 2;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] != nums[k - 2])
            {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */
