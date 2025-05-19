/*
 * @Author: RainbowRain9
 * @Date: 2025-04-14 14:46:17
 * @LastEditTime: 2025-04-14 14:49:40
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week8\二叉树问题.cpp
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
    int x, y;
    cin >> x >> y;
    vector<int> a;
    while (x) {
        a.push_back(x);
        x /= 2;
    }
    while (y) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == y) {
                cout << y;
                return;
            }
        }
        y /= 2;
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