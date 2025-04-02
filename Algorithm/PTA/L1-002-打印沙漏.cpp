/*
 * @Author: RainbowRain9
 * @Date: 2025-04-01 15:35:42
 * @LastEditTime: 2025-04-01 22:31:46
 * @FilePath: \C++\Algorithm\PTA\L1-002-打印沙漏.cpp
 * @Description: https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805145370476544
 */
/**************************************************
 * 题目描述：
 * 本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个"*"，要求按下列格式打印
 *
 * *****
 *  ***
 *   *
 *  ***
 * *****
 *
 * 所谓"沙漏形状"，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；
 * 符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。
 *
 * 给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。
 *
 * 输入格式:
 * 输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。
 *
 * 输出格式:
 * 首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。
 *
 * 示例 1：
 *   输入：19 *
 *   输出：
 *   *****
 *    ***
 *     *
 *    ***
 *   *****
 *   2
 *   解释：使用17个*打印沙漏，剩余2个未使用
 *
 * 提示：
 *   - 注意计算最大可用符号数
 *   - 注意输出格式的空格对齐
 *   - 注意最后要输出剩余符号数
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
// TODO 2025-04-01: 
// 1 7 17
//  x = sum * 2 - 1
//  sum += i
//  i += 2
int main()
{
    int n;
    char s;
    cin >> n >> s;

    // 初始化变量
    int sum = 0, x = 0, a = 1;

    // 计算最大可用符号数
    for (int i = 1;; i += 2)
    {
        int next_sum = sum + i;
        int next_x = next_sum * 2 - 1;
        if (next_x > n)
            break;
        a = i;
        sum = next_sum;
        x = next_x;
    }

    // 打印上半部分
    for (int i = a; i >= 1; i -= 2)
    {
        for (int j = 0; j < (a - i) / 2; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << s;
        }
        cout << endl;
    }

    // 打印下半部分(如果a>1)
    if (a > 1)
    {
        for (int i = 3; i <= a; i += 2)
        {
            for (int j = 0; j < (a - i) / 2; j++)
            {
                cout << " ";
            }
            for (int j = 0; j < i; j++)
            {
                cout << s;
            }
            cout << endl;
        }
    }

    cout << n - x << endl;

    return 0;
}