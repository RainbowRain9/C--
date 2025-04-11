/*
 * @Author: RainbowRain9
 * @Date: 2025-04-11 22:40:24
 * @LastEditTime: 2025-04-11 22:51:08
 * @FilePath: \C++\Algorithm\LeetCode\All\43-multiply-strings.cpp
 * @Description:
 */
/*
 * @lc app=leetcode.cn id=43 lang=cpp
 * @lcpr version=30104
 *
 * [43] 字符串相乘
 *
 * https://leetcode.cn/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.48%)
 * Likes:    1417
 * Dislikes: 0
 * Total Accepted:    380.6K
 * Total Submissions: 852.9K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 *
 * 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
 *
 *
 *
 * 示例 1:
 *
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 *
 * 示例 2:
 *
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num1.length, num2.length <= 200
 * num1 和 num2 只能由数字组成。
 * num1 和 num2 都不包含任何前导零，除了数字0本身。
 *
 *
 */

#include <bits/stdc++.h>
#include <string>
#include <vector>     // 添加 vector 头文件
#include <algorithm> // 添加 algorithm 头文件 (为了 reverse 或 fill)

using namespace std;

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2)
    {
        // 处理特殊情况：任何一个数为 "0"，结果都是 "0"
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int n = num1.size();
        int m = num2.size();
        // 结果向量，低位在前，最大长度为 n + m
        vector<int> result(n + m, 0);

        // 1. 将字符串转为 vector<int>，低位在前
        vector<int> v1(n), v2(m);
        for(int i=0; i<n; ++i) v1[i] = num1[n-1-i] - '0'; // num1 的个位在 v1[0]
        for(int i=0; i<m; ++i) v2[i] = num2[m-1-i] - '0'; // num2 的个位在 v2[0]

        // 2. 计算乘积并累加到 result，暂不处理进位
        for (int i = 0; i < n; ++i) { // 遍历 v1 的每一位
            for (int j = 0; j < m; ++j) { // 遍历 v2 的每一位
                // v1[i] * v2[j] 的结果应该加到 result 的第 i+j 位上
                result[i + j] += v1[i] * v2[j];
            }
        }

        // 3. 处理进位
        int carry = 0;
        for (int k = 0; k < n + m; ++k) { // 遍历 result 向量处理进位
            int current_val = result[k] + carry; // 当前位的值加上来自低位的进位
            result[k] = current_val % 10;       // 当前位只保留个位数
            carry = current_val / 10;           // 计算新的进位给高位
        }
        // 理论上最高位的进位 carry 已经被加到 result[n+m-1] 后的更高位（如果需要的话）
        // 但因为 vector 大小是 n+m，最高有效位最多在 result[n+m-1]

        // 4. 寻找结果的最高有效位
        int start_index = n + m - 1;
        // 从最高位开始，跳过前导零 (vector 中是后缀零)
        while (start_index > 0 && result[start_index] == 0) {
            start_index--;
        }

        // 5. 将结果 vector 转换回字符串
        string ans = "";
        // 从最高有效位开始，逆序添加到字符串
        for (int k = start_index; k >= 0; --k) {
            ans += to_string(result[k]);
        }

        return ans;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "2"\n"3"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n"456"\n
// @lcpr case=end

 */
