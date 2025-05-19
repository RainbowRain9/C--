/*
 * @Author: RainbowRain9
 * @Date: 2025-04-26 17:46:35
 * @LastEditTime: 2025-04-26 17:52:56
 * @FilePath: \C++\Algorithm\Xujoj\text\4100米接力.cpp
 * @Description: 4*100米接力赛跑排名输出
 */
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

void rain()
{
    int m;
    cin >> m;
    vector<vector<int>> teams(m, vector<int>(4));
    vector<pair<int, int>> sums(m);

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> teams[i][j];
            sum += teams[i][j];
        }
        sums[i] = { sum, i };
    }

    sort(sums.begin(), sums.end());

    for (int i = 0; i < m; i++) {
        int team_idx = sums[i].second;
        for (int j = 0; j < 4; j++) {
            cout << teams[team_idx][j] << (j == 3 ? '\n' : ' ');
        }
    }
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