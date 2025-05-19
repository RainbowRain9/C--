#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

int q(int x, int y)
{
    if (x == 0)
        return 1;
    if (y == 1)
        return 1;
    if (x < y)
        return q(x, x);
    return q(x, y - 1) + q(x - y, y);
}

void rain()
{
    int x, y;
    cin >> x >> y;
    cout << q(x, y) << endl;
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