/*https://www.luogu.com.cn/problem/P1047*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int l, m;
    cin >> l >> m;

    // 初始化一个大小为 l + 1 的 vector，初始值为 1
    vector<int> a(l + 1, 1);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        // 将区间 [u, v] 内的所有位置标记为 0
        for (int i = u; i <= v; i++)
        {
            a[i] = 0;
        }
    }

    int n = 0;
    // 统计剩余的树的数量
    for (int j = 0; j <= l; j++)
    {
        if (a[j] == 1)
        {
            n++;
        }
    }

    cout << n << endl;

    return 0;
}