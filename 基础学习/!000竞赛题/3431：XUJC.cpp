// Source : https://www.xujcoj.com/home/problem/detail/3431
// Date   : 2024-12-04

/**************************************************
 * 题目描述：
 * 小蓝在玩拼字母游戏，给你一个长度为 N 的字符串 S，从字符串 S 里挑选出 4 个字符构成 XUJC 便可以获得一分，
 * 如果构成了 XUJCUJC 则可以获得两分，请问小蓝最多能获得多少分？
 *
 * 示例 1：
 *   输入：13
 *        UJCXUJCBBXUJC
 *   输出：3
 *   解释：从给定的字符串中，我们可以拼出 1 个 XUJCUJC 和 1 个 XUJC，共计 3 分。
 *
 * 提示：
 *   - 输入的第一行包含一个正整数 N，表示字符串的长度
 *   - 第二行是长度为 N 的字符串 S，保证 S 中仅由大写字母构成
 *   - 对于 30% 的评测用例，0 < N ≤ 1e3
 *   - 对于 60% 的评测用例，0 < N ≤ 1e4
 *   - 对于 100% 的评测用例，0 < N ≤ 1e6
 **************************************************/

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
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, u = 0, j = 0, c = 0;
    for (auto v : s)
    {
        if (v == 'X')
            x++;
        if (v == 'U')
            u++;
        if (v == 'J')
            j++;
        if (v == 'C')
            c++;
    }
    int sum1 = 0, sum2 = 0;
    while (u > 0 && j > 0 && c > 0)
    {
        u--;
        j--;
        c--;
        sum1++;
    }
    while (x > 0 && sum1 > 0)
    {
        if (sum1 >= 2)
        {
            sum1 -= 2;
            x--;
            sum2 += 2;
        }
        else
        {
            x--;
            sum1--;
            sum2++;
        }
    }
    cout << sum2 << endl;

    return 0;
}