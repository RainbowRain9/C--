/*https://www.luogu.com.cn/problem/P1047*/

#include <iostream>
using namespace std;

int main()
{
    int l, m, n = 0;
    cin >> l >> m;
    int a[l];
    for (int i = 0; i <= l; i++)
    {
        a[i] = 1;
    }
    
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        for (int i = u; i <= v; i++)
        {
            a[i] = 0;
        }
    }
    
    for (int j = 0; j <= l; j++)
    {
        if (a[j] == 1)
        {
            n++;
        }
    }
    cout << n;

    return 0;
}