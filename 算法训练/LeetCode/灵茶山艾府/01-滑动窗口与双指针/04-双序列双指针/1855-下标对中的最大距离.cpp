// Source :https://leetcode.cn/problems/maximum-distance-between-a-pair-of-values/description/
// Date   : 2024-11-27
/*
 * @lc app=leetcode.cn id=1855 lang=cpp
 * @lcpr version=20003
 *
 * [1855] 下标对中的最大距离
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
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = 0; i < n1; i++)
        {
            int left = i;
            int right = n2 - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums1[i] <= nums2[mid])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            if (right >= i)
            {
                ans = max(ans, right - i);
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [55,30,5,4,2]\n[100,20,10,10,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n[10,10,1]\n
// @lcpr case=end

// @lcpr case=start
// [30,29,19,5]\n[25,25,25,25,25]\n
// @lcpr case=end

 */
