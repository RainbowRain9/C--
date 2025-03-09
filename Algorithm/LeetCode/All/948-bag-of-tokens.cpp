// Source : https://leetcode.cn/problems/bag-of-tokens/description/
// Date   : 2024-11-23
/*
 * @lc app=leetcode.cn id=948 lang=cpp
 * @lcpr version=20003
 *
 * [948] 令牌放置
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
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int n = tokens.size();
        int score = 0, ans = 0;
        sort(tokens.begin(), tokens.end());
        int left = 0, right = n - 1;
        while (left <= right)
        {
            if (power >= tokens[left])
            {
                power -= tokens[left];
                score++;
                left++;
                ans = max(ans, score);
            }
            else if (score > 0 && power < tokens[left])
            {
                score--;
                power += tokens[right];
                right--;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [100]\n50\n
// @lcpr case=end

// @lcpr case=start
// [200,100]\n150\n
// @lcpr case=end

// @lcpr case=start
// [100,200,300,400]\n200\n
// @lcpr case=end

 */
