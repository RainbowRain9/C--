/*
 * @Author: RainbowRain9
 * @Date: 2025-04-08 20:38:50
 * @LastEditTime: 2025-04-08 20:45:08
 * @FilePath: \C++\Algorithm\PTA\L1-044-稳赢.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 *
 *
 * 示例 1：
 *   输入：
 *   输出：
 *   解释：
 *
 * 示例 2：
 *   输入：
 *   输出：
 *   解释：
 *
 * 提示：
 *   -
 *   -
 *   -
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
    int k;
    cin >> k;
    string s;
    int cnt = 0;
    while (cin >> s) {
        if (s == "End") {
            break;
        }
        cnt++;
        if (cnt % (k + 1) == 0) {
            cout << s << endl;
        } else {
            if (s == "ChuiZi") {
                cout << "Bu" << endl;
            } else if (s == "JianDao") {
                cout << "ChuiZi" << endl;
            } else {
                cout << "JianDao" << endl;
            }
        }
    }

    return 0;
}