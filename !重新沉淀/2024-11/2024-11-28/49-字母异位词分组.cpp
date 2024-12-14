// Source : https://leetcode.cn/problems/group-anagrams/description/
// Date   : 2024-11-28
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=20003
 *
 * [49] 字母异位词分组
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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto &str : strs)
        {
            string key = str;
            ranges::sort(key);
            mp[key].push_back(str);
        }
        vector<vector<string>> ans;
        ans.reserve(mp.size());
        for (auto &[_, value] : mp)
        {
            ans.push_back(value);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */
