/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 18:08:42
 * @LastEditTime: 2025-04-02 19:16:32
 * @FilePath: \C++\Algorithm\PTA\L1-012-计算指数.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 对任意给定的不超过 10 的正整数 n，要求你输出 2 的 n 次方。
 *
 * 输入格式：
 * 输入在一行中给出一个不超过 10 的正整数 n。
 *
 * 输出格式：
 * 在一行中按照格式 "2^n = 计算结果" 输出 2 的 n 次方的值。
 *
 * 示例 1：
 *   输入：5
 *   输出：2^5 = 32
 *   解释：2 的 5 次方等于 32
 *
 * 示例 2：
 *   输入：3
 *   输出：2^3 = 8
 *   解释：2 的 3 次方等于 8
 *
 * 提示：
 *   - 输入保证是 1 到 10 之间的整数
 *   - 可以使用 pow() 函数或直接计算
 *   - 注意输出格式中的空格和等号
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
    cout << "2^" << n << " = " << pow(2, n);

    return 0;
}