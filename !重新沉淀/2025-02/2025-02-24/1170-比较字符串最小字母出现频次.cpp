// Source : https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/description/
// Date   : 2025-02-24
/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 * @lcpr version=30006
 *
 * [1170] 比较字符串最小字母出现频次
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
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> wordFreq;
        for (auto word : words)
        {
            wordFreq.push_back(calculateF(word));
        }
        sort(wordFreq.begin(), wordFreq.end());

        vector<int> res;
        for (auto &query : queries)
        {
            int fq = calculateF(query);
            auto it = upper_bound(wordFreq.begin(), wordFreq.end(), fq);
            res.push_back(wordFreq.end() - it);
        }
        return res;
    }

private:
    int calculateF(const string &s)
    {
        char minChar = 'z';
        int count = 0;
        for (auto c : s)
        {
            if (c < minChar)
            {
                minChar = c;
                count = 1;
            }
            else if (c == minChar)
            {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["cbd"]\n["zaaaz"]\n
// @lcpr case=end

// @lcpr case=start
// ["bbb","cc"]\n["a","aa","aaa","aaaa"]\n
// @lcpr case=end

 */
