/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 13:17:46
 * @LastEditTime: 2025-04-09 13:17:52
 * @FilePath: \C++\Algorithm\PTA\L1-049-天梯赛座位分配.cpp
 * @Description: 
 */

/**************************************************
 * 题目描述：
 * 天梯赛座位分配问题：为多所学校的参赛队员分配座位，要求同一学校的队员不能相邻。
 * 分配规则：
 * 1. 按学校顺序，依次分配每个学校的第一位队员
 * 2. 然后分配每个学校的第二位队员，以此类推
 * 3. 如果最后只剩一所学校，则其队员需要隔位就坐
 * 
 * 输入格式：
 * 第一行：参赛高校数 N
 * 第二行：N 个整数，表示每所高校的参赛队伍数
 * 
 * 输出格式：
 * 对于每所高校：
 * 第一行输出 "#X"（X为学校编号）
 * 随后每行输出一队队员的座位号，每行10个，空格分隔
 * 
 * 示例 1：
 *   输入：
 *   3
 *   3 4 2
 *   输出：
 *   #1
 *   1 4 7 10 13 16 19 22 25 28
 *   31 34 37 40 43 46 49 52 55 58
 *   61 63 65 67 69 71 73 75 77 79
 *   #2
 *   2 5 8 11 14 17 20 23 26 29
 *   32 35 38 41 44 47 50 53 56 59
 *   62 64 66 68 70 72 74 76 78 80
 *   82 84 86 88 90 92 94 96 98 100
 *   #3
 *   3 6 9 12 15 18 21 24 27 30
 *   33 36 39 42 45 48 51 54 57 60
 * 
 * 提示：
 *   - 高校数 N 不超过100
 *   - 每所高校的参赛队伍数不超过10
 *   - 每队有10位参赛选手
 *   - 座位号从1开始连续编号
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
    while(n--)
    {
        
    }

    return 0;
}