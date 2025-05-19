/*
 * @Author: RainbowRain9
 * @Date: 2025-05-19 15:38:01
 * @LastEditTime: 2025-05-19 15:57:15
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\week12\02-最大子段和1.cpp
 * @Description: 
 */
#include <bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using namespace std;

void rain() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int ans = 0; 
    int temp = 0; 
    
    for (int i = 0; i < n; i++) {
        temp = max(0, temp + a[i]);
        ans = max(ans, temp);
    }
    
    cout << ans << endl;
}

signed main() {
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