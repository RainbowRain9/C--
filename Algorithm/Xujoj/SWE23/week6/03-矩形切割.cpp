/*
 * @Author: RainbowRain9
 * @Date: 2025-03-31 15:35:09
 * @LastEditTime: 2025-03-31 15:36:18
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week6\03-矩形切割.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 给定一个矩形，通过不断切割最大正方形的方式将其分割成若干正方形，
 * 求最终得到的正方形数量。
 *
 * 示例 1：
 *   输入：2 1
 *   输出：2
 *   解释：2x1的矩形可以分割成1个1x1和1个1x1的正方形
 *
 * 示例 2：
 *   输入：6 4
 *   输出：3
 *   解释：6x4的矩形可以分割成1个4x4和2个2x2的正方形
 *
 * 提示：
 *   - 输入的两个数代表矩形的长和宽
 *   - 每次切割都取当前矩形能切割的最大正方形
 *   - 最终输出正方形数量
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
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    if (a > b)
    {
        swap(a, b);
    }
    while (a > 0)
    {
        cnt++;
        b -= a;
        if (a > b)
        {
            swap(a, b);
        }
    }
    cout << cnt;

    return 0;
}