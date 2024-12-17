// Source : https://leetcode.cn/problems/interval-list-intersections/description/
// Date   : 2024-12-16
/*
 * @lc app=leetcode.cn id=986 lang=cpp
 * @lcpr version=20004
 *
 * [986] 区间列表的交集
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
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> result;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size())
        {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if (start <= end)
            {
                result.push_back({start, end});
            }
            if (firstList[i][1] < secondList[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[5,9]]\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[[4,8],[10,12]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,7]]\n[[3,10]]\n
// @lcpr case=end

 */
