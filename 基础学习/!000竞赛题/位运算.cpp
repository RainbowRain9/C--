#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        long long c;
        cin >> c;
        long long min_diff = LLONG_MAX;
        long long a_best = 0, b_best = c;
        for (long long a = 0; a <= c; a++)
        {
            long long b = c - a;
            if ((a | b) == c)
            {
                long long diff = abs(a - b);
                if (diff < min_diff)
                {
                    min_diff = diff;
                    if (min_diff == 0)
                    {
                        break;
                    }
                }
            }
        }
        cout << min_diff << "\n";
    }
    return 0;
}