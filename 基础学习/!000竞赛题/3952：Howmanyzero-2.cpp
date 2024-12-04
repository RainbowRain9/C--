// Source : https://www.xujcoj.com/home/problem/detail/3952
// Date   : 2024-12-03

/**************************************************
 * 题目描述：
 * 给出两个正整数 n 和 m，计算 n! × (n+1)! × ... × (m-1)! × m! 的末尾有多少个零。
 * 其中 n! 表示 n 的阶乘，例如 5! = 1 * 2 * 3 * 4 * 5 = 120
 *
 * 示例 1：
 *   输入：3 6
 *   输出：2
 *   解释：3! × 4! × 5! × 6! = 6 * 24 * 120 * 720 = 12441600，末尾有两个零
 *
 * 提示：
 *   - 1 ≤ n ≤ m ≤ 2e9
 *   - 对于 20% 的用例：1 ≤ n ≤ m ≤ 6
 *   - 对于 40% 的用例：1 ≤ n ≤ m ≤ 8
 *   - 对于 60% 的用例：1 ≤ n ≤ m ≤ 1e5
 *   - 对于 80% 的用例：1 ≤ n ≤ m ≤ 1e8
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

int jc(int a)
{
    int num = 1;
    for (int i = 1; i <= a; i++)
    {
        num *= i;
    }
    return num;
}

int main()
{
    int a, b;
    cin >> a >> b;
    long long sum = 1;
    for (int i = a; i <= b; i++)
    {
        sum *= jc(i);
    }
    string s = to_string(sum);
    reverse(s.begin(), s.end());
    int cnt = 0;
    for (char c : s)
    {
        if (c == '0')
            cnt++;
        if (c != '0')
            break;
    }

    cout << cnt << endl;
    return 0;
}