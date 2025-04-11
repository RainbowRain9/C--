/*
 * @Author: RainbowRain9
 * @Date: 2025-04-10 15:34:13
 * @LastEditTime: 2025-04-10 15:38:32
 * @FilePath: \C++\Algorithm\PTA\L1-077-大笨钟的心情.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 大笨钟根据心情指数回答问题。给定24小时的心情指数，
 * 当被问到某个时间点时，如果心情指数>50输出Yes，否则输出No。
 *
 * 示例 1：
 *   输入：
 *   80 75 60 50 20 20 20 20 55 62 66 51 42 33 47 58 67 52 41 20 35 49 50 63
 *   17
 *   7
 *   3
 *   15
 *   -1
 *   输出：
 *   52 Yes
 *   20 No
 *   50 No
 *   58 Yes
 *   解释：
 *   每次查询输出当前时间点的心情指数和Yes/No
 *
 * 提示：
 *   - 24个整数表示每小时的心情指数，范围[0,100]
 *   - 查询时间点范围[0,23]，非法时间点表示结束
 *   - 心情指数>50输出Yes，否则输出No
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    vector<int> hh(24);
    for (int i = 0; i < 24; i++) {
        cin >> hh[i];
    }
    int n;
    while (cin >> n) {
        if (n < 0 || n > 23) {
            break;
        }
        cout << hh[n] << " " << (hh[n] > 50 ? "Yes" : "No") << endl;
    }

    return 0;
}