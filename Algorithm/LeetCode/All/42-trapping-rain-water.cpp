// Source : https://leetcode.cn/problems/trapping-rain-water/description/
// Date   : 2024-11-23
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=20003
 *
 * [42] 接雨水
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
    // 双指针
    //  int trap(vector<int> &height)
    //  {
    //      int n = height.size();
    //      int ans = 0;
    //      int pre_max = 0, suf_max = 0;
    //      int left = 0, right = n - 1;
    //      while (left <= right)
    //      {
    //          pre_max = max(pre_max, height[left]);
    //          suf_max = max(suf_max, height[right]);
    //          if (pre_max < suf_max)
    //          {
    //              ans += pre_max - height[left++];
    //          }
    //          else
    //          {
    //              ans += suf_max - height[right--];
    //          }
    //      }
    //      return ans;
    //  }

    // 单调栈
    int trap(vector<int> &height)
    {
        int ans = 0;
        stack<int> st;
        int n = height.size();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && height[i] >= height[st.top()])
            {
                int bottom_h = height[st.top()];
                st.pop();
                if (st.empty())
                {
                    break;
                }
                int left = st.top();
                int dh = min(height[left], height[i]) - bottom_h;
                ans += dh * (i - left - 1);
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
