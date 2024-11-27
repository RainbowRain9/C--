// Source : https://leetcode.cn/problems/merge-sorted-array/description/
// Date   : 2024-11-27
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 * @lcpr version=20003
 *
 * [88] 合并两个有序数组
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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p = m - 1;
        int q = n - 1;
        int k = m + n - 1;
        while (q >= 0)
        {
            if (p >= 0 && nums1[p] > nums2[q])
            {
                nums1[k--] = nums1[p--];
            }
            else
            {
                nums1[k--] = nums2[q--];
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,0,0,0]\n3\n[2,5,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n[]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n[1]\n1\n
// @lcpr case=end

 */
