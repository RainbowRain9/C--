// Source : https://leetcode.cn/problems/permutation-in-string/description/
// Date   : 2025-03-06
/*
 * @lc app=leetcode.cn id=567 lang=cpp
 * @lcpr version=30100
 *
 * [567] 字符串的排列
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> map, window;
        int valid = 0, ans = 0;
        for (auto v : s1)
        {
            map[v]++;
        }

        for (int i = 0; i < s2.length(); i++)
        {
            char c = s2[i];
            if (map.count(c))
            {
                window[c]++;
                if (window[c] == map[c])
                    valid++;
            }
            if (i >= s1.length() - 1)
            {
                if (valid == map.size())
                    return true;
                char d = s2[i - s1.length() + 1];
                if (map.count(d))
                {
                    if (window[d] == map[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool result = solution.checkInclusion(s1, s2);
    cout << "Result: " << result << endl;
}

/*
// @lcpr case=start
// "eidbaooo"\n
// @lcpr case=end

// @lcpr case=start
// "eidboaoo"\n
// @lcpr case=end

 */
