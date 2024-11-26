// Source : https://leetcode.cn/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/description/
// Date   : 2024-11-23
/*
 * @lc app=leetcode.cn id=923 lang=cpp
 * @lcpr version=20003
 *
 * [923] 三数之和的多种可能
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
    const int mod = 1000000007;
    int threeSumMulti(vector<int> &arr, int target)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int x = arr[i];
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = x + arr[j] + arr[k];
                if (sum < target)
                    j++;
                else if (sum > target)
                    k--;
                else if (arr[j] == arr[k])
                {
                    int tmp = k - j + 1;
                    ans = (ans + tmp * (tmp - 1) / 2) % mod;
                    break;
                }
                else
                {
                    int cnt1 = 1, cnt2 = 1;
                    while (arr[j + 1] == arr[j++])
                        cnt1++;
                    while (arr[k - 1] == arr[k--])
                        cnt2++;
                    ans = (ans + cnt1 * cnt2) % mod;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2,2,3,3,4,4,5,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,2,2,2]\n5\n
// @lcpr case=end

 */
