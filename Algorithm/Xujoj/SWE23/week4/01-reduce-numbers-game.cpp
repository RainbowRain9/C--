/*
 * @Author: RainbowRain9
 * @Date: 2025-03-17 14:39:17
 * @LastEditTime: 2025-03-17 15:02:45
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week4\01-reduce-numbers-game.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * Stan和Ollie正在玩一种数字游戏。给定两个正整数M和N，从Stan开始，从其中较大的一个数，
 * 减去较小的数的正整数倍，当然，得到的数不能小于0。然后是Ollie，对刚才得到的数，和M，
 * N中较小的那个数，再进行同样的操作……直到一个人得到了0，他就取得了胜利。
 *
 * 示例 1：
 *   输入：25 7
 *   输出：Stan wins
 *   解释：
 *   Start：25 7
 *   Stan： 11 7
 *   Ollie：4  7
 *   Stan： 4  3
 *   Ollie：1  3
 *   Stan： 1  0
 *   Stan赢得了游戏的胜利
 *
 * 提示：
 *   - 两个正整数M、N（不超过长整型）
 *   - 从Stan开始轮流操作
 *   - 每次操作从较大数减去较小数的正整数倍
 *   - 先得到0的人获胜
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
    int m, n;
    cin >> m >> n;

    bool role = true;
    if (m < n)
    {
        swap(m, n);
    }

    while (n != 0)
    {
        if (n >= 2 * n || m == n)
        {
            break;
        }
        m -= n;
        if (m < n)
        {
            swap(m, n);
        }
        !role;
    }

    if (role)
    {
        cout << "Stan wins" << endl;
    }
    else
    {
        cout << "Ollie wins" << endl;
    }

    return 0;
}