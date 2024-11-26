/*https://www.luogu.com.cn/problem/P5594*/

#include <iostream>
using namespace std;
bool a[1005][1005];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int day;
    int num;
    while (n--)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> day;
            a[day][j] = 1;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        num = 0;
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j])
                num++;
        }
        cout << num << " ";
    }

    return 0;
}