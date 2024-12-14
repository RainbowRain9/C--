// Source : https://leetcode.cn/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/description/
// Date   : 2024-11-23
/*
 * @lc app=leetcode.cn id=1577 lang=cpp
 * @lcpr version=20003
 *
 * [1577] 数的平方等于两数乘积的方法数
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
    int numTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        return f(nums1, nums2) + f(nums2, nums1);
    }

    int f(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        int n = nums2.size();
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < nums1.size(); i++)
        {
            long long x = (long long)nums1[i] * nums1[i];
            int j = 0, k = n - 1;
            while (j < k)
            {
                long long prod = (long long)nums2[j] * nums2[k];
                if (prod < x)
                    j++;
                else if (prod > x)
                    k--;
                else
                {
                    if (nums2[j] != nums2[k])
                    {
                        int left = 1, right = 1;
                        while (j + 1 < k && nums2[j] == nums2[j + 1])
                        {
                            left++;
                            j++;
                        }
                        while (k - 1 > j && nums2[k] == nums2[k - 1])
                        {
                            right++;
                            k--;
                        }
                        ans += left * right;
                        j++;
                        k--;
                    }
                    else
                    {
                        int count = k - j + 1;
                        ans += count * (count - 1) / 2;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [7,4]\n[5,2,8,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n[1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,8,3]\n[1,2,9,7]\n
// @lcpr case=end

// @lcpr case=start
// [4,7,9,11,23]\n[3,5,1024,12,18]\n
// @lcpr case=end

 */
