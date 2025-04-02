/*
 * @Author: RainbowRain9
 * @Date: 2025-04-01 22:43:22
 * @LastEditTime: 2025-04-01 22:49:40
 * @FilePath: \C++\Algorithm\PTA\L1-004-计算摄氏温度.cpp
 * @Description: https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805142086336512&page=0
 */
/**************************************************
 * 题目描述：
 * 给定一个华氏温度F，本题要求编写程序，计算对应的摄氏温度C。
 * 计算公式：C=5×(F−32)/9。题目保证输入与输出均在整型范围内。
 *
 * 输入格式:
 * 输入在一行中给出一个华氏温度。
 *
 * 输出格式:
 * 在一行中按照格式“Celsius = C”输出对应的摄氏温度C的整数值。
 *
 * 示例 1：
 *   输入：150
 *   输出：Celsius = 65
 *   解释：根据公式计算 (150-32)*5/9 = 65
 *
 * 提示：
 *   - 输入输出均为整数
 *   - 注意公式中的运算顺序
 *   - 输出格式要求严格匹配
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
    int F;
    cin >> F;
    int C = 5 * (F - 32) / 9;
    cout << "Celsius = " << C;

    return 0;
}