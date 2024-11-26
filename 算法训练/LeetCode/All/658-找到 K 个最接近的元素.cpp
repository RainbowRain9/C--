// Source : https://leetcode.cn/problems/find-k-closest-elements/description/
// Date   : 2024-11-22
/*
 * @lc app=leetcode.cn id=658 lang=cpp
 * @lcpr version=20003
 *
 * [658] 找到 K 个最接近的元素
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
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        int left = 0, right = n - k;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        vector<int> nums;
        for (int i = left; i < left + k; i++)
        {
            nums.push_back(arr[i]);
        }
        return nums;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,4,5]\n4\n-1\n
// @lcpr case=end

 */
