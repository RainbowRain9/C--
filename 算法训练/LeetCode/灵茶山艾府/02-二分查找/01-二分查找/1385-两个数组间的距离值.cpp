// Source : https://leetcode.cn/problems/find-the-distance-value-between-two-arrays/description/
// Date   : 2024-11-25
/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 * @lcpr version=20003
 *
 * [1385] 两个数组间的距离值
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
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int ans = 0;
        for (int x : arr1)
        {
            bool valid = true;
            for (int y : arr2)
            {
                if (abs(x - y) <= d)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
                ans++;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,8]\n[10,9,1,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,3]\n[-4,-3,6,10,20,30]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1,100,3]\n[-5,-2,10,-3,7]\n6\n
// @lcpr case=end

 */
