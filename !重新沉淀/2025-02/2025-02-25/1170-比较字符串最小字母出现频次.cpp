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
        int n = queries.size();
        int m = words.size();
        vector<int> answer(n);
        vector<int> wordsF(m);

        for (int j = 0; j < m; j++)
        {
            wordsF[j] = calculateF(words[j]);
        }

        sort(wordsF.begin(), wordsF.end());

        for (int i = 0; i < n; i++)
        {
            int queryF = calculateF(queries[i]);
            
            // 使用二分查找找到第一个大于queryF的元素位置
            int left = 0, right = m;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (wordsF[mid] > queryF)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            
            // left现在指向第一个大于queryF的元素
            // m - left 就是大于queryF的元素个数
            answer[i] = m - left;
        }
        return answer;
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
