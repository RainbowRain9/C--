/*
 * @Author: RainbowRain9
 * @Date: 2025-04-12 15:01:00
 * @LastEditTime: 2025-04-12 17:27:52
 * @FilePath: \C++\Algorithm\Xujoj\text\三体星人的单词.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 三体星人的单词由若干个字母构成，每个字母最多使用一次。
 * 已知总共有m个字母，问能够组成多少个不同的单词？
 *
 * 示例 1：
 *   输入：
 *   2
 *   3
 *   100
 *   输出：
 *   15
 *   30307831
 *   解释：
 *   第一组案例中，不妨设三个字母是A、B、C，则组成的单词有15个：
 *   A、B、C、AB、AC、BA、BC、CA、CB、ABC、ACB、BAC、BCA、CAB、CBA
 *
 * 提示：
 *   - 这是一道多组案例的题目
 *   - n表示案例的数量，n<=100
 *   - m表示字母的数量，m<=1e6
 *   - 结果需要对100000007取模
 **************************************************/

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

const int MOD = 100000007;

void solve()
{
    int m;
    cin >> m;
    int ans = 0;
    int total_sum = 0;
    int pk = 1;

    for (int k = 0; k < m; ++k) {
        int factor = m - k;
        pk = (pk * factor) % MOD;
        total_sum = (total_sum + pk) % MOD;
    }

    cout << total_sum << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}