#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

int dp(int C, int n, int w[], int v[])
{
    int dp[C + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= C; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return dp[C];
}

void rain()
{
    int C, n;
    cin >> C >> n;
    int w[n + 1], v[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    int result = dp(C, n, w, v);

    cout << result << endl;
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