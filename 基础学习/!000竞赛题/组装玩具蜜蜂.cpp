// Source : https://xujcoj.com/home/contest/2070/problem/1
// Date   : 2024-12-21

/**************************************************
 * 题目描述：
 * 一只玩具蜜蜂包含以下组件：头*1，身体*1，翅膀*4，腿*6，触须*2。
 * Tom正在组装玩具蜜蜂，每a分钟可以组装一只玩具蜜蜂。问经过b分钟后一共组装了几只玩具蜜蜂。
 *
 * 示例 1：
 *   输入：2
 *        100 100 100 100 100
 *        5 11
 *        10 10 10 10 10
 *        3 10
 *   输出：2
 *        1
 *   解释：第二组案例中，经过3分钟组装了第一只蜜蜂后，腿组件就不够装第二只蜜蜂了。
 *
 * 提示：
 *   - 这是一道多组案例的题目
 *   - n表示案例的数量，n<=1000
 *   - 每组案例包含5个非负整数(头、身体、翅膀、腿、触须原材料的数量)和2个正整数a,b
 *   - 所有输入数据均不大于1e8
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
        long long x1, x2, x3, x4, x5;
        cin >> x1 >> x2 >> x3 >> x4 >> x5;
        long long a, b;
        cin >> a >> b;
        long long ans = min({x1, x2, x3 / 4, x4 / 6, x5 / 2});
        ans = min(ans, b / a);
        cout << ans << endl;
    }

    return 0;
}