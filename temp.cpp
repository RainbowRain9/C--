#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int N = 1e7 + 5;
bool p[N];

int qpow(int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void sieve(int n)
{
    for (int i = 2; i < n; i++) {
        p[i] = true;
    }
    p[0] = p[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (p[i]) {
            for (int j = i * i; j <= n; j += i) {
                p[j] = false;
            }
        }
    }
}

void rain()
{
    int n;
    cin >> n;
    int exponent;
    if (n == 0) {
        exponent = -1;
    } else {
        exponent = n - 1;
    }
    if (exponent < 0) {
        cout << 0 << endl;
    } else {
        int result = qpow(2, exponent);
        cout << result << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        rain();
    }
    return 0;
}