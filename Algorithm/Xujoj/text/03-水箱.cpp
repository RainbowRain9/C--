/*
 * @Author: RainbowRain9
 * @Date: 2025-05-10 15:11:04
 * @LastEditTime: 2025-05-10 15:11:10
 * @FilePath: \C++\Algorithm\Xujoj\text\03-水箱.cpp
 * @Description: 
 */
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

void rain() {
    int m, a, b, c, d;
    cin >> m >> a >> b >> c >> d;
    while(d--){
        a += c;
        a -= b;
        if (a > m) a = m;
        if (a < 0) a = 0;
    }
    cout << a << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        rain();
    }
    return 0;
}