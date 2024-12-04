// Source : https://www.xujcoj.com/home/problem/detail/3420
// Date   : 2024-12-04

/**************************************************
 * 题目描述：
 * 计算1到2022之间所有质数各个位置上的数字之和的总和。
 * 例如质数13，它的各个位置上的数字之和为1 + 3 = 4。
 *
 * 示例 1：
 *   输入：无
 *   输出：123 (示例答案)
 *   解释：这是一道结果填空的题，只需要算出结果后提交即可。
 *
 * 示例 2：
 *   输入：无
 *   输出：只需提交一个整数答案
 *   解释：提交时只填写这个整数，填写多余的内容将无法得分。
 *
 * 提示：
 *   - 需要计算1到2022之间的所有质数
 *   - 对每个质数计算其各位数字之和
 *   - 最后计算所有质数的各位数字之和的总和
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
    if (n == 2)
        return true;
    if (n <= 1 || n % 2 == 0)
        return false;
    for (int i = 3; i <= n / i; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int sum = 0;
    for (int i = 2; i <= 2022; i++)
    {
        if (isPrime(i))
        {
            int num = i;
            while (num)
            {
                sum += num % 10;
                num /= 10;
            }
        }
    }
    cout << sum << endl;

    return 0;
}