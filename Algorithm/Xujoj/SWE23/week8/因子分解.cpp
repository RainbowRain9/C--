#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
int cnt = 0;

void f(int n, int m)
{
    if (n == 1)
        cnt++;
    else {
        for (int i = m; i <= n; i++) {
            if (n % i == 0) {
                f(n / i, i);
            }
        }
    }
}

void rain()
{
    int n;
    cin >> n;
    f(n, 2);
    cout << cnt;
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