// Source : https://xujcoj.com/home/contest/2127/problem/4
// Date   : 2025-03-03

/**************************************************
 * 题目描述：
 * 有 m 个学生去旅行，晚上遇到了住房问题。已知双人房每间 a 元，三人房每间 b 元，
 * 在保证所有学生都有房间住的前提下，请你帮忙算一下他们的最小开支。
 *
 * 示例 1：
 *   输入：
 *   2
 *   4 2 3
 *   5 1 3
 *   输出：
 *   4
 *   3
 *   解释：
 *   第一组测试用例中，4个学生可以住2间双人房，总开支为2+2=4元
 *   第二组测试用例中，5个学生可以住1间双人房和1间三人房，总开支为1+2=3元
 *
 * 提示：
 *   - 1 <= n <= 50，n为测试用例数量
 *   - 1 <= m,a,b <= 1e9，m为学生数量，a为双人房价格，b为三人房价格
 *   - 需要考虑如何组合双人房和三人房以获得最小开支
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
    while (n--)
    {
        long long m, a, b;
        cin >> m >> a >> b;

        if (3 * a > 2 * b)
        {
            long long cost = (m / 3) * b;

            if (m % 3 == 1)
            {
                cost += min(b, a);
            }
            else if (m % 3 == 2)
            {
                cost += min(b, a);
            }
            cout << cost << endl;
        }
        else
        {
            cout << (m / 2 + (m % 2)) * a << endl;
        }
    }
    return 0;
}
