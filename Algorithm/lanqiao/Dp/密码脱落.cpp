/*
 * @Author: RainbowRain9
 * @Date: 2025-04-11 09:05:21
 * @LastEditTime: 2025-04-11 09:29:26
 * @FilePath: \C++\Algorithm\Lanqiao\Dp\密码脱落.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * X星球的考古学家发现了一批古代留下来的密码。这些密码是由A、B、C、D四种植物的种子串成的序列。
 * 这些密码串当初应该是前后对称的（镜像串）。由于年代久远，其中许多种子脱落了，可能会失去镜像特征。
 * 给定一个现在看到的密码串，计算从当初的状态至少脱落多少个种子，才可能变成现在的样子。
 *
 * 示例 1：
 *   输入：ABCBA
 *   输出：0
 *   解释：当前字符串已经是回文串，不需要脱落任何种子
 *
 * 示例 2：
 *   输入：ABDCDCBABC
 *   输出：3
 *   解释：需要脱落至少3个种子才能形成回文串
 *
 * 提示：
 *   - 输入为一行字符串，只包含A、B、C、D四种字符
 *   - 字符串长度不大于1000
 *   - 时间限制1s，空间限制256M
 **************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    string s1 = s;
    reverse(s1.begin(), s1.end());
    if (s == s1) {
        cout << 0 << "\n";
        return 0;
    }

    int n = s.size();
    const int N = 1005;
    vector<vector<int>> dp(N, vector<int>(N));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] == s1[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    int r = n - dp[n][n];
    cout << r << "\n";

    return 0;
}