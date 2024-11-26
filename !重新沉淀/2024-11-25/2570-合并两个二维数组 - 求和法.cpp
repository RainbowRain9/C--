// Source : https://leetcode.cn/problems/merge-two-2d-arrays-by-summing-values/description/
// Date   : 2024-11-25
/*
 * @lc app=leetcode.cn id=2570 lang=cpp
 * @lcpr version=20003
 *
 * [2570] 合并两个二维数组 - 求和法
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
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for (auto &v : nums1)
        {
            mp[v[0]] += v[1];
        }
        for (auto &v : nums2)
        {
            mp[v[0]] += v[1];
        }
        for (auto &[id, val] : mp)
        {
            ans.push_back({id, val});
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2],[2,3],[4,5]]\n[[1,4],[3,2],[4,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,4],[3,6],[5,5]]\n[[1,3],[4,3]]\n
// @lcpr case=end

 */
