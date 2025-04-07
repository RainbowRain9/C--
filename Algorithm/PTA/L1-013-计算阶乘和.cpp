/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 19:18:53
 * @LastEditTime: 2025-04-02 19:21:30
 * @FilePath: \C++\Algorithm\PTA\L1-013-计算阶乘和.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 对于给定的正整数N，需要你计算 S=1!+2!+3!+...+N!。
 *
 * 输入格式：
 * 输入在一行中给出一个不超过10的正整数N。
 *
 * 输出格式：
 * 在一行中输出S的值。
 *
 * 示例 1：
 *   输入：3
 *   输出：9
 *   解释：1! + 2! + 3! = 1 + 2 + 6 = 9
 *
 * 示例 2：
 *   输入：5
 *   输出：153
 *   解释：1! + 2! + 3! + 4! + 5! = 1 + 2 + 6 + 24 + 120 = 153
 *
 * 提示：
 *   - N的取值范围为1到10
 *   - 阶乘计算可能会快速增大，但N<=10时结果在int范围内
 *   - 可以使用循环结构实现阶乘和的计算
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
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = 1;
        for (int j = 1; j <= i; j++)
        {
            temp *= j;
        }
        sum += temp;
    }
    cout << sum;

    return 0;
}