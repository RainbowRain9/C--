// Source : https://leetcode.cn/problems/3sum-closest/description/
// Date   : 2024-11-22
/*
 * @lc app=leetcode.cn id=16 lang=cpp
 * @lcpr version=20003
 *
 * [16] 最接近的三数之和
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
    int threeSumClosest(vector<int> &nums, int target)
    {
        // 先排序
        sort(nums.begin(), nums.end());
        // 初始化答案为前三个数之和
        int ans = nums[0] + nums[1] + nums[2];

        // 固定第一个数x
        for (int i = 0; i < n - 2; i++)
        {
            int x = nums[i];
            // j,k双指针分别指向剩余区间的两端
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = x + nums[j] + nums[k];
                // 如果当前和比之前找到的更接近target，就更新答案
                if (abs(sum - target) < abs(ans - target))
                {
                    ans = sum;
                }
                // 根据sum和target的关系移动指针
                if (sum < target)
                    j++; // 和太小，左指针右移
                else if (sum > target)
                    k--; // 和太大，右指针左移
                else
                    return target; // 找到完全相等的情况，直接返回
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,2,1,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n1\n
// @lcpr case=end

 */
