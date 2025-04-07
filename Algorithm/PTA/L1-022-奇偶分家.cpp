/*
 * @Author: RainbowRain9
 * @Date: 2025-04-04 20:17:21
 * @LastEditTime: 2025-04-04 20:17:23
 * @FilePath: \C++\Algorithm\PTA\L1-022-奇偶分家.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 给定N个正整数，请统计奇数和偶数各有多少个？
 *
 * 输入格式：
 * 输入第一行给出一个正整N（≤1000）；第2行给出N个非负整数，以空格分隔。
 *
 * 输出格式：
 * 在一行中先后输出奇数的个数、偶数的个数。中间以1个空格分隔。
 *
 * 示例 1：
 *   输入：
 *   9
 *   88 74 101 26 15 0 34 22 77
 *   输出：
 *   3 6
 *   解释：
 *   在给定的9个数字中，有3个奇数（101,15,77）和6个偶数（88,74,26,0,34,22）
 *
 * 提示：
 *   - N的取值范围是1到1000
 *   - 输入的数字都是非负整数
 *   - 输出格式要求奇数个数在前，偶数个数在后，中间用空格分隔
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt1 = 0, cnt2 = 0;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
        {
            cnt2++;
        }
        else
        {
            cnt1++;
        }
    }
    cout << cnt1 << " " << cnt2;

    return 0;
}