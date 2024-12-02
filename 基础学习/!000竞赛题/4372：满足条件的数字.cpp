// Source : https://www.xujcoj.com/home/problem/detail/4372
// Date   : 2024-12-01

/**************************************************
 * 题目描述：
 * 从1-2023中找出满足以下至少两个条件的整数个数:
 * 1. 是回文数(正着写和反着写看上去都一样的数,如121,252)
 * 2. 各个数位之和是奇数(如124的各个数位之和为1+2+4=7)
 * 3. 不是质数(除了1和它本身外还有其他因数的数)
 *
 * 示例 1：
 *   输入：无
 *   输出：答案数字
 *   解释：如55满足条件1和3,151满足条件1和2,24不满足(只符合3),17不满足(都不符合)
 *
 * 示例 2：
 *   输入：无
 *   输出：答案数字
 *   解释：这是一道填空题,只需输出最终答案即可
 *
 * 提示：
 *   - 范围是1-2023
 *   - 需要满足三个条件中的至少两个
 *   - 条件包括:回文数、数位和为奇数、非质数
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

bool hw(int i)
{
    string s = to_string(i);
    int len = s.length();
    for (int k = 0; k < len / 2; k++)
    {
        if (s[k] != s[len - 1 - k])
            return false;
    }
    return true;
}

bool sw(int i)
{
    int sum = 0;
    int num = i;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum % 2 == 1;
}

bool isPrime(int i)
{
    if (i == 2)
        return true;
    if (i < 2 || i % 2 == 0)
        return false;
    for (int j = 3; j * j <= i; j += 2)
    {
        if (i % j == 0)
            return false;
    }
    return true;
}

int main()
{
    int n = 0;
    for (int i = 1; i <= 2023; i++)
    {
        int cnt = 0;
        if (hw(i)) cnt++;
        if (sw(i)) cnt++;
        if (!isPrime(i)) cnt++;
        if (cnt >= 2) n++;
    }
    cout << n << endl;
    return 0;
}