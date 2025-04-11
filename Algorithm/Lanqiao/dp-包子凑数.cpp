
/**************************************************
 * 题目描述：
 * 小明每天早晨在一家包子铺吃早餐。包子铺有N种蒸笼，第i种蒸笼能放Ai个包子。
 * 每种蒸笼数量无限。当顾客想买X个包子时，大叔会选择若干笼使总数为X。
 * 有些数量可能无法凑出，求这样的数的个数。
 *
 * 示例 1：
 *   输入：
 *   2
 *   4
 *   5
 *   输出：
 *   6
 *   解释：凑不出的数目包括：1, 2, 3, 6, 7, 11
 *
 * 示例 2：
 *   输入：
 *   2
 *   4
 *   6
 *   输出：
 *   INF
 *   解释：所有奇数都凑不出来，所以有无限多个
 *
 * 提示：
 *   - 1 ≤ N ≤ 100
 *   - 1 ≤ Ai ≤ 100
 *   - 如果凑不出的数目有无限多个，输出INF
 **************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
    }
    int g = __gcd(a[0], a[1]);
    for (int i : a) {
        g = __gcd(g, i);
    }
    if (g > 1) {
        cout << "INF\n";
        return 0;
    }
    // cout << g << "\n";

    const int maxn = 10005;
    int cnt = 0;
    vector<bool> dp(maxn);
    dp[0] = true;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0 && dp[i - a[j]]) {
                dp[i] = true;
                break;
            }
        }
        if (!dp[i]) {
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}