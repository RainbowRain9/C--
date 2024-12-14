// Source : https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
// Date   : 2024-11-29
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=20003
 *
 * [84] 柱状图中最大的矩形
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
    int largestRectangleArea(vector<int> &heights)
    {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        stack<int> st;
        st.push(0);
        int ans = 0;

        for (int i = 1; i < heights.size(); i++)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int cur = st.top();
                st.pop();
                int height = heights[cur];
                int width = i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */
