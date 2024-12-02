// Source : https://www.xujcoj.com/home/problem/detail/4373
// Date   : 2024-12-01

/**************************************************
 * 题目描述：
 * 定义f(x)为x的所有正因子之和。例如f(6)=1+2+3+6=12。
 * 给定一个正整数n，计算从1到n的所有f(i)的和，即∑(i=1到n)f(i)。
 *
 * 示例 1：
 *   输入：6
 *   输出：33
 *   解释： f(1)=1
 *         f(2)=1+2=3
 *         f(3)=1+3=4
 *         f(4)=1+2+4=7
 *         f(5)=1+5=6
 *         f(6)=1+2+3+6=12
 *         总和=1+3+4+7+6+12=33
 *
 * 提示：
 *   - 对于30%的测试用例，1 ≤ n ≤ 1000
 *   - 对于70%的测试用例，1 ≤ n ≤ 200000
 *   - 对于100%的测试用例，1 ≤ n ≤ 3000000
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

    vector<long long> f(n + 1, 1);

    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            f[j] += i;
        }
    }

    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += f[i];
    }

    cout << sum << endl;
    return 0;
}