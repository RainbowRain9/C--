// Source : https://leetcode.cn/problems/find-smallest-letter-greater-than-target/description/
// Date   : 2024-12-18
/*
 * @lc app=leetcode.cn id=744 lang=cpp
 * @lcpr version=20004
 *
 * [744] 寻找比目标字母大的最小字母
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
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int left = 0, right = letters.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (left == letters.size())
            return letters[0];
        return letters[left];
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["c", "f"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// ["c","f","j"]\n"c"\n
// @lcpr case=end

// @lcpr case=start
// ["x","x","y","y"]\n"z"\n
// @lcpr case=end

 */
