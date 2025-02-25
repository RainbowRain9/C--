// Source : https://www.luogu.com.cn/problem/P1007
// Date   : 2025-01-22

/**************************************************
 * 题目描述：
 * 给定一座长度为L的独木桥,桥上有N个士兵,每个士兵都在不同的整数坐标位置。
 * 士兵以速度1向某个方向移动,当两个士兵相遇时会同时转身继续移动。
 * 士兵到达坐标0或L+1时即离开独木桥。
 * 求所有士兵全部离开独木桥所需的最短时间和最长时间。
 *
 * 示例 1：
 *   输入：
 *   4
 *   2
 *   1 3
 *   输出：
 *   2 4
 *   解释：
 *   最短时间2:两个士兵分别向外移动,1号士兵向左,3号士兵向右
 *   最长时间4:两个士兵相向而行,在位置2相遇后转身,再各自移动到终点
 *
 * 提示：
 *   - 1 <= L <= 5000
 *   - 0 <= N <= 5000
 *   - N <= L
 *   - 初始时没有两个士兵在同一位置
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
    int L, N;
    cin >> L >> N;

    if (N == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }

    vector<int> pos(N);
    for (int i = 0; i < N; i++)
    {
        cin >> pos[i];
    }

    int minTime = 0;
    for (int i = 0; i < N; i++)
    {
        minTime = max(minTime, min(pos[i], L + 1 - pos[i]));
    }

    int maxTime = 0;
    for (int i = 0; i < N; i++)
    {
        maxTime = max(maxTime, max(pos[i], L + 1 - pos[i]));
    }

    cout << minTime << " " << maxTime << endl;
    return 0;
}