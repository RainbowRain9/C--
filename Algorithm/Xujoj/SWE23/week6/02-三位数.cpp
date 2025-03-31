/*
 * @Author: RainbowRain9
 * @Date: 2025-03-31 14:38:28
 * @LastEditTime: 2025-03-31 15:20:35
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week6\02-三位数.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 将1到9共9个数分成三组，分别组成三个三位数，且使这三个三位数构成 1: 2: 3 的比例，
 * 试求出所有满足条件的三个三位数。
 *
 * 输入描述：
 * 无
 *
 * 输出描述：
 * 从小到大依次输出所有满足条件的三个三位数，三位数之间以空格隔开，每一行输出一组三位数。
 *
 * 样例输入：
 * 无
 *
 * 样例输出：
 * 192 384 576
 * 219 438 657
 *
 * 提示：
 * - 每个数字1-9只能使用一次
 * - 三个三位数必须满足1:2:3的比例关系
 * - 输出结果需要按从小到大顺序排列
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

bool funtion1(string s)
{
    vector<bool> digits(9, false);
    for (char c : s)
    {
        int num = c - '0';
        if (num == 0 || digits[num - 1])
        {
            return false;
        }
        digits[num - 1] = true;
    }
    return true;
}

bool funtion2(string s)
{
    sort(s.begin(), s.end());
    if (s == "123456789")
        return true;
    return false;
}

bool funtion3(string s)
{
    string target = "123456789";
    do
    {
        if (s == target)
            return true;
    } while (next_permutation(target.begin(), target.end()));
    return false;
}

int main()
{
    for (int i = 123; i <= 329; i++)
    {
        int j = i * 2, k = i * 3;
        if (j > 999 || k > 999)
            continue;
        string combined = to_string(i) + to_string(j) + to_string(k);
        if (funtion1(combined))
        {
            cout << i << " " << j << " " << k << endl;
        }
    }

    return 0;
}