/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 15:47:33
 * @LastEditTime: 2025-04-02 16:39:20
 * @FilePath: \C++\Algorithm\PTA\L1-008-求整数段和.cpp
 * @Description: https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805135224455168&page=0
 */
/**************************************************
 * 题目描述：
 * 给定两个整数A和B，输出从A到B的所有整数以及这些数的和。
 *
 * 输入格式：
 * 输入在一行中给出2个整数A和B，其中−100≤A≤B≤100，其间以空格分隔。
 *
 * 输出格式：
 * 首先顺序输出从A到B的所有整数，每5个数字占一行，每个数字占5个字符宽度，向右对齐。
 * 最后在一行中按Sum = X的格式输出全部数字的和X。
 *
 * 示例 1：
 *   输入：-3 8
 *   输出：
 *     -3   -2   -1    0    1
 *      2    3    4    5    6
 *      7    8
 *   Sum = 30
 *   解释：输出从-3到8的所有整数，每行5个数字，最后输出它们的和30。
 *
 * 提示：
 *   - 注意数字的格式化输出，每个数字占5个字符宽度
 *   - 注意换行时机，每5个数字换一行
 *   - 最后要输出所有数字的和
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
// TODO 2025-04-02: 
int main()
{
    int a, b;
    cin >> a >> b;
    int sum = 0;
    int cnt = 0;
    for (int i = a; i <= b; i++)
    {
        printf("%5d", i);
        sum += i;
        cnt++;
        if (cnt % 5 == 0 || i == 2)
        {
            printf("\n");
        }
    }
    cout << "Sum = " << sum << endl;

    return 0;
}