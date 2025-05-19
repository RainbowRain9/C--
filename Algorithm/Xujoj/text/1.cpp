/*
 * @Author: RainbowRain9
 * @Date: 2025-05-10 15:02:27
 * @LastEditTime: 2025-05-10 17:21:03
 * @FilePath: \C++\Algorithm\Xujoj\text\1.cpp
 * @Description:
 */
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

void rain()
{
    int c, d, e, f, m, q;
    cin >> c >> d >> e >> f >> m >> q;

    int sum = 0;
    int curr = c;

    vector<bool> exists(f, false);
    exists[c] = true;

    for (int i = 1; i < m; i++) {
        curr = (curr * d + e) % f;
        exists[curr] = true;
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x < f && exists[x]) {
            sum += x;
        }
    }

    cout << sum;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        rain();
    }
    return 0;
}