/*
 * @Author: RainbowRain9
 * @Date: 2024-11-26 22:56:38
 * @LastEditTime: 2025-04-10 21:33:51
 * @FilePath: \C++\try.cpp
 * @Description: 
 */
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
    }
    sort(a.rbegin(),a.rend());
    for (int i : a) {
        cout << i << (i == a.back() ? "" : " ");
    }
    return 0;
}