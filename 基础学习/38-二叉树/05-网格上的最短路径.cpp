#include <iostream>
using namespace std;

int MinPath(int a[100][100], int m, int n)
{
    int dp[100][100] = {0};
    dp[0][0] = a[0][0];

    for (int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j - 1] + a[0][j];
    }

    for (int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i - 1][0] + a[i][0];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{
    int m, n, a[100][100] = {{1, 3, 1, 2, 1}, {1, 5, 1, 3, 1}, {4, 2, 1, 2, 3}, {1, 5, 3, 3, 1}, {4, 2, 1, 2, 1}};

    cin >> m >> n;

    cout << MinPath(a, m, n) << endl;

    return 0;
}