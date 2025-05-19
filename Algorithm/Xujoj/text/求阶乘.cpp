/*
 * @Author: RainbowRain9
 * @Date: 2025-04-26 16:15:26
 * @LastEditTime: 2025-04-26 17:38:18
 * @FilePath: \C++\Algorithm\Xujoj\text\求阶乘.cpp
 * @Description: 计算阶乘的最后10位非零数字
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
    int result = 1;
    const int MOD = 10000000000LL; 
    for (int i = 1; i <= m; i++) {
        result = (result * i) % MOD;
        while (result % 10 == 0 && result != 0) {
            result /= 10;
        }
    }

    if (result == 0) {
        cout << 0 << endl;
    } else {
        cout << result << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        rain();
    }
    return 0;
}