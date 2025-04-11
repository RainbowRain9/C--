/*
 * @Author: RainbowRain9
 * @Date: 2025-04-08 08:14:13
 * @LastEditTime: 2025-04-08 08:34:12
 * @FilePath: \C++\Algorithm\PTA\L1-037-A除以B.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 给定两个绝对值不超过100的整数A和B，要求按照"A/B=商"的格式输出结果。
 *
 * 示例 1：
 *   输入：-1 2
 *   输出：-1/2=-0.50
 *   解释：分母为正数，直接输出结果，保留两位小数
 *
 * 示例 2：
 *   输入：1 -3
 *   输出：1/(-3)=-0.33
 *   解释：分母为负数，用括号括起来，保留两位小数
 *
 * 示例 3：
 *   输入：5 0
 *   输出：5/0=Error
 *   解释：分母为零，输出Error
 *
 * 提示：
 *   - 输入的两个整数绝对值不超过100
 *   - 需要处理分母为负数、正数和零三种情况
 *   - 输出结果保留两位小数
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
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
    int a, b;
    cin >> a >> b;
    if (b == 0) {
        cout << a << "/" << b << "=Error";
    } else if (b < 0) {
        cout << a << "/(" << b << ")=";
        if (a == 0) {
            cout << 0;
        } else {
            cout << fixed << setprecision(2) << (double)a / b;
        }
    } else {
        cout << a << "/" << b << "=";
        if (a == 0) {
            cout << 0;
        } else {
            cout << fixed << setprecision(2) << (double)a / b;
        }
    }
    cout << endl;

    return 0;
}