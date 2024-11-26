// Source : https://leetcode.cn/problems/minimum-length-of-string-after-deleting-similar-ends/description/
// Date   : 2024-11-20
/*
 * @lc app=leetcode.cn id=1750 lang=cpp
 * @lcpr version=20003
 *
 * [1750] 删除字符串两端相同字符后的最短长度
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
class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int left = 0, right = n - 1;
        int ans = 0;
        while (left < right && s[left] == s[right])
        {
            char c = s[left];
            while (left <= right && s[left] == c)
            {
                left++;
            }
            while (left <= right && s[right] == c)
            {
                right--;
            }
        }
        ans = right - left + 1;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ca"\n
// @lcpr case=end

// @lcpr case=start
// "cabaabac"\n
// @lcpr case=end

// @lcpr case=start
// "aabccabba"\n
// @lcpr case=end

 */

