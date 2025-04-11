/*
 * @Author: RainbowRain9
 * @Date: 2025-04-07 19:53:20
 * @LastEditTime: 2025-04-07 19:56:39
 * @FilePath: \C++\Algorithm\PTA\L1-028-判断素数.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 *
 *
 * 示例 1：
 *   输入：
 *   输出：
 *   解释：
 *
 * 示例 2：
 *   输入：
 *   输出：
 *   解释：
 *
 * 提示：
 *   -
 *   -
 *   -
 **************************************************/

#include <iostream>
using namespace std;

// 快速幂计算
long long quickPow(long long a, long long n, long long mod)
{
    long long ans = 1;
    while (n) {
        if (n & 1)
            ans = (__int128)ans * a % mod;
        a = (__int128)a * a % mod;
        n >>= 1;
    }
    return ans;
}

// Miller-Rabin素数测试
bool millerRabin(long long n)
{
    if (n < 3 || n % 2 == 0)
        return n == 2;

    // 将n-1分解为d*(2^r)
    long long d = n - 1;
    int r = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    // 用几个小素数做测试基底就足够了
    const int primes[7] = { 2, 3, 5, 7, 11, 13, 17 };

    for (int i = 0; i < 7; i++) {
        long long a = primes[i];
        if (a >= n)
            break;

        long long x = quickPow(a, d, n);
        if (x == 1 || x == n - 1)
            continue;

        bool flag = false;
        for (int j = 0; j < r - 1; j++) {
            x = (__int128)x * x % n;
            if (x == n - 1) {
                flag = true;
                break;
            }
        }
        if (!flag)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while (n--) {
        long long m;
        cin >> m;
        if (millerRabin(m)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}