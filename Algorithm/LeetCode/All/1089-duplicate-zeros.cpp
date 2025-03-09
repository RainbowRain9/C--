// Source : https://leetcode.cn/problems/duplicate-zeros/description/
// Date   : 2024-11-25
/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 * @lcpr version=20003
 *
 * [1089] 复写零
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
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0, j = 0;
        // 统计复写后的长度
        for (; j < n; i++)
        {
            if (arr[i] == 0)
                j += 2;
            else
                j++;
        }
        i--;
        j--;
        // 从后往前复写
        while (i >= 0)
        {
            if (j < n)
                arr[j] = arr[i];
            if (arr[i] == 0)
            {
                j--;
                if (j < n)
                    arr[j] = 0;
            }
            i--;
            j--;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,2,3,0,4,5,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
