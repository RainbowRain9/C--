/*
 * @Author: RainbowRain9
 * @Date: 2025-05-05 14:47:15
 * @LastEditTime: 2025-05-05 15:04:12
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week10\均分糖果.cpp
 * @Description:
 */
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MOD = 1e7 + 5;

int qpow(int a, int b, int c)
{
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % c;
        }
        a = a * a % c;
        b >>= 1;
    }
    return res;
}

void rain()
{
    int a, b, c;
    cin >> a >> b >> c;
    int res;
    if (b == 0) {
        if (c == 1) {
            res = 0;
        } else {
            res = 1;
        }
    } else {
        res = qpow(a, b, c);
    }
    cout << res << endl;
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