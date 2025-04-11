/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 16:38:09
 * @LastEditTime: 2025-04-09 16:56:07
 * @FilePath: \C++\Algorithm\PTA\L1-053-电子汪.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 为电子宠物汪做一个模拟程序，根据两堆小球的个数计算和，并用汪星人的叫声给出答案
 *
 * 示例 1：
 *   输入：2 1
 *   输出：Wang!Wang!Wang!
 *   解释：2+1=3，所以输出3个Wang!
 *
 * 示例 2：
 *   输入：5 4
 *   输出：Wang!Wang!Wang!Wang!Wang!Wang!Wang!Wang!Wang!
 *   解释：5+4=9，所以输出9个Wang!
 *
 * 提示：
 *   - 输入的两个数都在[1,9]范围内
 *   - 输出是A+B个连续的"Wang!"
 *   - 注意输出没有空格
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
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    while (sum--) {
        cout << "Wang!";
    }

    return 0;
}   