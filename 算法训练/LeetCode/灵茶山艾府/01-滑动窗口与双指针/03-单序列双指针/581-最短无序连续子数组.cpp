// Source : https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/description/
// Date   : 2024-11-23
/*
 * @lc app=leetcode.cn id=581 lang=cpp
 * @lcpr version=20003
 *
 * [581] 最短无序连续子数组
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
    int findUnsortedSubarray(vector<int> &nums)
    {
        if (is_sorted(nums.begin(), nums.end()))
        {
            return 0;
        }
        int n = nums.size();
        vector<int> nums1(nums);
        sort(nums1.begin(), nums1.end());
        int left = 0, right = n - 1;
        while (nums[left] == nums1[left])
            left++;
        while (nums[right] == nums1[right])
            right--;
        return right - left + 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,6,4,8,10,9,15]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
