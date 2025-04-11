/*
 * @Author: RainbowRain9
 * @Date: 2025-04-07 20:23:49
 * @LastEditTime: 2025-04-07 20:27:21
 * @FilePath: \C++\Algorithm\PTA\L1-029-是不是太胖了.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 计算一个人的标准体重，公式为：(身高 - 100) * 0.9，结果转换为市斤（乘以2）
 * 并保留1位小数
 *
 * 示例 1：
 *   输入：169
 *   输出：124.2
 *   解释：(169 - 100) * 0.9 * 2 = 124.2
 *
 * 提示：
 *   - 输入范围：100 < H ≤ 300
 *   - 输出保留1位小数
 *   - 注意单位转换（公斤转市斤）
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
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
    float H;
    cin >> H;
    float W = (H - 100) * 0.9 * 2;
    printf("%.1f", W);

    return 0;
}