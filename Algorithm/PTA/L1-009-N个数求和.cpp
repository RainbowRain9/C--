/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 16:36:45
 * @LastEditTime: 2025-04-02 17:43:20
 * @FilePath: \C++\Algorithm\PTA\L1-009-N个数求和.cpp
 * @Description: https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805133597065216&page=0
 */
/**************************************************
 * 题目描述：
 * 本题要求计算N个有理数的和，并以最简分数形式输出结果。
 * 输入格式：
 * - 第一行：正整数N（≤100）
 * - 第二行：N个有理数，格式为a1/b1 a2/b2 ...
 * 输出格式：
 * - 结果的最简形式：整数部分 分数部分
 * - 如果整数部分为0，只输出分数部分
 * - 分数部分要求分子小于分母，且无公因子
 *
 * 示例 1：
 *   输入：
 *   5
 *   2/5 4/15 1/30 -2/60 8/3
 *   输出：
 *   3 1/3
 *   解释：
 *   2/5 + 4/15 + 1/30 - 2/60 + 8/3 = 3 1/3
 *
 * 示例 2：
 *   输入：
 *   2
 *   4/3 2/3
 *   输出：
 *   2
 *   解释：
 *   4/3 + 2/3 = 2
 *
 * 示例 3：
 *   输入：
 *   3
 *   1/3 -1/6 1/8
 *   输出：
 *   7/24
 *   解释：
 *   1/3 - 1/6 + 1/8 = 7/24
 *
 * 提示：
 *   - 所有分子和分母都在长整型范围内
 *   - 负数的符号一定出现在分子前面
 *   - 需要考虑约分和整数部分提取
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
    long long x = 0, y = 1;
    while (n--)
    {
        long long a, b;
        char s;
        cin >> a >> s >> b;
        long long lcm = y * b / __gcd(y, b);
        x = x * (lcm / y) + a * (lcm / b);
        y = lcm;
        long long g = __gcd(abs(x), y);
        x /= g;
        y /= g;
    }
    if (x == 0)
    {
        cout << "0" << endl;
    }
    else if (abs(x) < y)
    {
        cout << x << "/" << y << endl;
    }
    else
    {
        long long integer = x / y;
        long long remainder = abs(x) % y;
        if (remainder == 0)
        {
            cout << integer << endl;
        }
        else
        {
            cout << integer << " " << remainder << "/" << y << endl;
        }
    }

    return 0;
}