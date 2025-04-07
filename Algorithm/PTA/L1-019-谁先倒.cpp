/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 22:26:33
 * @LastEditTime: 2025-04-02 22:34:46
 * @FilePath: \C++\Algorithm\PTA\L1-019-谁先倒.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 划拳游戏判断谁先醉倒。两人轮流划拳，当一方比划的数字等于两人喊出的数字之和时，该方输并喝一杯酒。
 * 根据两人的酒量和划拳记录，判断谁先醉倒，并输出另一人喝了多少杯。
 *
 * 示例 1：
 *   输入：
 *   1 1
 *   6
 *   8 10 9 12
 *   5 10 5 10
 *   3 8 5 12
 *   12 18 1 13
 *   4 16 12 15
 *   15 1 1 16
 *   输出：
 *   A
 *   1
 *   解释：
 *   甲在第二轮后喝了两杯，超过酒量1杯，先醉倒。乙只喝了1杯。
 *
 * 提示：
 *   - 酒量不超过100
 *   - 划拳记录不超过100轮
 *   - 数字均为不超过100的正整数
 *   - 保证有一个人会倒下
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
    int at, bt;
    cin >> at >> bt;
    int an = 0, bn = 0;
    bool a = 1, b = 1;
    int n;
    cin >> n;
    while (n--)
    {
        int ac, ad, bc, bd;
        cin >> ac >> ad >> bc >> bd;
        if (ad == bd)
        {
            continue;
        }
        int sum = ac + bc;
        if (sum == ad)
        {
            an++;
        }
        if (sum == bd)
        {
            bn++;
        }
        if (an > at)
        {
            a = 0;
            break;
        }
        if (bn > bt)
        {
            b = 0;
            break;
        }
    }
    if (a)
    {
        cout << "B" << endl;
        cout << an << endl;
    }
    if (b)
    {
        cout << "A" << endl;
        cout << bn << endl;
    }
    return 0;
}