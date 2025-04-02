/*
 * @Author: RainbowRain9
 * @Date: 2025-04-01 22:32:39
 * @LastEditTime: 2025-04-01 22:40:41
 * @FilePath: \C++\Algorithm\PTA\L1-003-个位数统计.cpp
 * @Description: https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805143738892288&page=0
 */
/**************************************************
 * 题目描述：
 * 给定一个k位整数N，统计每种不同的个位数字出现的次数。
 *
 * 示例 1：
 *   输入：100311
 *   输出：
 *   0:2
 *   1:3
 *   3:1
 *   解释：数字0出现2次，1出现3次，3出现1次
 *
 * 示例 2：
 *   输入：1234567890
 *   输出：
 *   0:1
 *   1:1
 *   2:1
 *   3:1
 *   4:1
 *   5:1
 *   6:1
 *   7:1
 *   8:1
 *   9:1
 *   解释：每个数字都恰好出现1次
 *
 * 提示：
 *   - 输入数字可能非常大，不能直接用整数类型存储
 *   - 需要统计0-9每个数字出现的次数
 *   - 输出需要按数字升序排列
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
    unordered_map<long long, long long> mp;
    string n;
    cin >> n;
    for (auto &&i : n)
    {
        long long digit = i - '0';
        mp[digit]++;
    }
    for (long long i = 0; i < 10; i++)
    {
        if (mp.count(i))
        {
            cout << i << ":" << mp[i] << endl;
        }
    }

    return 0;
}