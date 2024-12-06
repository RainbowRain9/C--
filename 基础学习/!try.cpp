#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, L, R, q;
    cin >> n >> L >> R >> q;

    // vector<int> a(n, 20); // 修正了vector初始化语法
    // 使用差分数组来优化区间修改
    vector<int> diff(n + 1, 0); // 差分数组
    vector<int> temp(n, 20);    // 存储温度的数组

    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;

        // for (int i = l - 1; i <= r - 1; i++) // 修正了0-based索引
        // {
        //     a[i] += x;
        // }
        diff[l - 1] += x; // 区间起点增加x
        diff[r] -= x;     // 区间终点后减少x
    }
    // 通过差分数组还原温度变化
    int change = 0;
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        // if (a[i] >= L && a[i] <= R) // 使用输入的L和R作为范围
        // {
        //     count++;
        // }
        change += diff[i]; // 累加变化量
        temp[i] += change; // 计算最终温度
        if (temp[i] >= L && temp[i] <= R)
        {
            count++;
        }
    }
    cout << count << endl;
}