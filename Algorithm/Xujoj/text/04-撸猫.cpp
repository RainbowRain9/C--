#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

void rain()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
    }
    int sum = 0;
    int max_a = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] > max_a) {
            max_a = a[i];
        }
    }
    int t = sum;
    int max_t = 2 * max_a;
    cout << max(t, max_t);
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