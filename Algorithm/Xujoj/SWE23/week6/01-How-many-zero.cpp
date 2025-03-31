/*
 * @Author: RainbowRain9
 * @Date: 2025-03-31 14:37:20
 * @LastEditTime: 2025-03-31 14:51:43
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week6\01-How-many-zero.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 计算 n 的阶乘后面有多少个 0，例如 5! = 1 * 2 * 3 * 4 * 5 = 120，后面就有一个 0。
 *
 * 输入描述：
 * 输入一个不大于 100 的正整数 n。
 *
 * 输出描述：
 * 输出 n! 后面有多少个 0，不用换行。
 *
 * 示例 1：
 *   输入：5
 *   输出：1
 *   解释：5! = 120，末尾有1个0
 *
 * 示例 2：
 *   输入：10
 *   输出：2
 *   解释：10! = 3628800，末尾有2个0
 *
 * 提示：
 *   - 0的个数由因子5的个数决定
 *   - 需要计算1到n中5的倍数的个数
 *   - 注意25,125等包含多个5因子的情况
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
    int cnt5 = 0;
    for (int i = 1; i <= n; i++)
    {
        int b = i;

        while (b != 0)
        {
            if (b % 5 == 0)
            {
                cnt5++;
            }
            else
                break;
            b /= 5;
        }
    }
    cout << cnt5;
    return 0;
}