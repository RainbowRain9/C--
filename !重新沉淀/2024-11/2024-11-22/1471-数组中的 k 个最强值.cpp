// Source : https://leetcode.cn/problems/the-k-strongest-values-in-an-array/description/
// Date   : 2024-11-22
/*
 * @lc app=leetcode.cn id=1471 lang=cpp
 * @lcpr version=20003
 *
 * [1471] 数组中的 k 个最强值
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
    vector<int> getStrongest(vector<int> &arr, int k)
    {
        int n = arr.size();
        int left = 0, right = n - 1;
        sort(arr.begin(), arr.end());
        int m = arr[(n - 1) / 2];
        vector<int> nums;
        while (nums.size() < k)
        {
            int x = arr[left], y = arr[right];
            if (abs(x - m) > abs(y - m))
            {
                nums.push_back(x);
                left++;
            }
            else if (abs(x - m) < abs(y - m))
            {
                nums.push_back(y);
                right--;
            }
            else
            {
                if (x > y)
                {
                    nums.push_back(x);
                    left++;
                }
                else
                {
                    nums.push_back(y);
                    right--;
                }
            }
        }
        return nums;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,1,3,5,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [6,7,11,7,6,8]\n5\n
// @lcpr case=end

// @lcpr case=start
// [6,-3,7,2,11]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-7,22,17,3]\n2\n
// @lcpr case=end

 */
