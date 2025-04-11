/*
 * @lc app=leetcode.cn id=204 lang=cpp
 * @lcpr version=30104
 *
 * [204] 计数质数
 *
 * https://leetcode.cn/problems/count-primes/description/
 *
 * algorithms
 * Medium (36.96%)
 * Likes:    1214
 * Dislikes: 0
 * Total Accepted:    302.4K
 * Total Submissions: 817.7K
 * Testcase Example:  '10'
 *
 * 给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 0
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 1
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 5 * 10^6
 * 
 * 
 */


#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> p(n, true);
        p[0] = p[1] = false;
        int count = 0;
        for (long long i = 2; i < n; i++) {
            if (p[i]) {
                count++;
                // 这行代码很重要:
                // 1. 使用 (long long) 避免 i*i 整数溢出
                // 2. i*i < n 优化了埃氏筛法 - 对于质数p，只需要从p*p开始标记其倍数
                //    因为小于p*p的p的倍数已经被更小的质数标记过了
                if (i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        p[j] = false;
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

