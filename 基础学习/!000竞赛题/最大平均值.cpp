#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
long long a[MAXN], sum[MAXN];
int n, m;

bool check(long long x)
{
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i] - x;
    }

    long long minSum = 0;
    for (int i = m; i <= n; i++)
    {
        minSum = min(minSum, sum[i - m]);
        if (sum[i] - minSum >= 0)
            return true;
    }
    return false;
}

int solve()
{
    cin >> n >> m;
    long long left = -1000000, right = 1000000;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    while (left < right)
    {
        long long mid = (left + right + 1) / 2;
        if (check(mid))
            left = mid;
        else
            right = mid - 1;
    }

    return left;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cout << solve() << endl;
    }
    return 0;
}
