/*
 * @Author: RainbowRain9
 * @Date: 2025-04-12 16:22:56
 * @LastEditTime: 2025-04-12 17:59:18
 * @FilePath: \C++\Algorithm\Xujoj\text\完全平方数-6.cpp
 * @Description:
 */
#include <algorithm>
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

const int N = 100005;
vector<bool> p(N);

void ppow()
{
    static bool initialized = false;
    if (!initialized) {
        fill(all(p), false);
        for (int i = 0; i * i < N; i++) {
            p[i * i] = true;
        }
        initialized = true;
    }
    for (int i = 0; i * i < N; i++) {
        p[i * i] = true;
    }
}

// void print(vector<bool> p, int n)
// {
//     bool found = false;
//     for (int i = 0; i < n; i++) {
//         if (p[i]) {
//             cout << i << " is a perfect square" << endl;
//             found = true;
//         }
//     }
// }

void rain()
{
    int m, a;
    cin >> a >> m;
    int cnt = 0;
    for (int i = 0; i <= m; i++) {
        int res = a * i;
        if (res >= N) {
            if (res < 0)
                continue;
            long long root = static_cast<long long>(sqrt(res));
            if (root * root == res) {
                cnt++;
            }
        } else if (res < 0) {
            continue;
        } else {
            if (p[res]) {
                cnt++;
            }
        }
    }
    cout << cnt - 1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ppow();
    int _ = 1;
    cin >> _;
    while (_--) {
        rain();
    }
    return 0;
}