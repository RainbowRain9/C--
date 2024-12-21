// Source : https://xujcoj.com/home/contest/2070/problem/5
// Date   : 2024-12-21

/**************************************************
 * 题目描述：
 * "水仙花数"指的是一个n位正整数，如果该数各个位置上的数字的n次方之和等于该数字，
 * 则称该数字是"水仙花数"。
 *
 * 例如153是一个3位正整数，该数各个位置上的数字分别是1、5、3，它们的3次方之和等于153，
 * 故153是"水仙花数"。
 *
 * 按从小到大的顺序输出小于10亿的所有水仙花数。
 *
 * 示例 1：
 *   输入：无
 *   输出：1
 *        153
 *        370
 *        371
 *        407
 *        ...
 *   解释：这些数都满足水仙花数的定义
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

bool flower(string n)
{
    long long sum = 0;
    int len = n.length();
    for (auto c : n)
    {
        int digit = c - '0';
        long long power = 1;
        for (int i = 0; i < len; i++)
        {
            power *= digit;
        }
        sum += power;
    }
    return sum == stoll(n);
}

int main()
{
    for (int i = 1; i < 1000000000; i++)
    {
        string n = to_string(i);
        if (flower(n))
            cout << i << endl;
    }

    return 0;
}