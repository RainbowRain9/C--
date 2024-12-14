// Source : https://leetcode.cn/problems/watering-plants-ii/description/
// Date   : 2024-11-20
/*
 * @lc app=leetcode.cn id=2105 lang=cpp
 * @lcpr version=20003
 *
 * [2105] 给植物浇水 II
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
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        int n = plants.size();
        int curA = capacityA, curB = capacityB;
        int left = 0, right = n - 1;
        int ans = 0;
        while (left < right)
        {
            if (curA < plants[left])
            {
                curA = capacityA;
                ans++;
            }
            curA -= plants[left++];
            if (curB < plants[right])
            {
                curB = capacityB;
                ans++;
            }
            curB -= plants[right--];
        }
        if (left == right)
        {
            if (max(curA, curB) < plants[left])
            {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,2,3,3]\n5\n5\n
// @lcpr case=end

// @lcpr case=start
// [2,2,3,3]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n10\n8\n
// @lcpr case=end

 */
