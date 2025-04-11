/*
 * @Author: RainbowRain9
 * @Date: 2024-11-26 22:56:38
 * @LastEditTime: 2025-04-11 23:38:05
 * @FilePath: \C++\try.cpp
 * @Description:
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int N = 1e7 + 5;
bool p[N];
vector<int> primes;

void sieve(int n)
{
    for (int i = 0; i <= n; i++) {
        p[i] = true;
    }
    p[0] = p[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (p[i]) {
            for (int j = i * i; j <= n; j += i) {
                p[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (p[i]) {
            primes.push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve(1000000);
    long long L = 2333, R = 23333333333333LL;
    int ans = 0;
    
    for (int i = 0; i < primes.size(); i++) {
        long long p = primes[i];
        if (p * p > R)
            break;

        for (int j = i + 1; j < primes.size(); j++) {
            long long q = primes[j];
            long long num = p * p * q * q;
            if (num > R)
                break;
            if (num >= L)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}