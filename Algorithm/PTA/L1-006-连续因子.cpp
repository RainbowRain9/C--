/*
 * @Author: RainbowRain9
 * @Date: 2025-04-01 23:05:18
 * @LastEditTime: 2025-04-02 15:31:39
 * @FilePath: \C++\Algorithm\PTA\L1-006-连续因子.cpp
 * @Description: https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805138600869888&page=0
 */
/**************************************************
 * 题目描述：
 * 一个正整数 N 的因子中可能存在若干连续的数字。给定任一正整数 N，
 * 要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。
 *
 * 示例 1：
 *   输入：630
 *   输出：
 *   3
 *   5*6*7
 *   解释：630 可以分解为 3×5×6×7，其中 5、6、7 是 3 个连续的数字
 *
 * 提示：
 *   - 1 < N < 2^31
 *   - 如果 N 是质数，则最长连续因子序列就是 N 本身
 *   - 需要输出长度最长的连续因子序列，如果长度相同则输出最小的序列
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

bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    if (n == 2 || isPrime(n))
    {
        cout << 1 << endl;
        cout << n << endl;
        return 0;
    }
    int maxLen = 0;
    int first = 0;
    int sqrtn = sqrt(n);
    
    int maxStart = min(sqrtn, 100);
    
    for (int i = 2; i <= maxStart; i++)
    {
        long long product = 1;
        
        for (int j = 0, cur = i; j < 20 && cur <= sqrtn + 1; j++, cur++)
        {
            product *= cur;
            if (product > n || product <= 0)
                break;
            
            if (n % product == 0)
            {
                int curLen = j + 1;
                if (curLen > maxLen)
                {
                    maxLen = curLen;
                    first = i;
                }
            }
        }
    }
    
    if (maxLen == 0)
    {
        cout << 1 << endl
             << n << endl;
        return 0;
    }

    cout << maxLen << endl;
    for (int i = 0; i < maxLen; i++)
    {
        if (i > 0)
            cout << "*";
        cout << first + i;
    }
    cout << endl;

    return 0;
}