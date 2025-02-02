/*
问题描述
有N个小朋友排成一排，从前往后依次编号
1∼N

第0时刻1号小朋友有一个物品，在下一时刻他会传递至2号小朋友。

每一个小朋友接到物品后都会在下一时刻沿着当前传递的方向继续传递给下一个小朋友。

当物品到达队伍首部或队伍尾部时传递方向就会改变，队伍会沿改变后的方向继续传递物品。

比如当物品传递至N号小朋友后，传递方向将由从前向后传改为从后向前传。

请你求出第T个时刻物品在哪个小朋友手上。

输入描述
在一行中输入两个正整数N,T (N>=1,t<=10^18)

输出描述
在一行中输出一个整数表示第
T个时刻物品所在小朋友的编号。

样例输入
3 5

样例输出
2

提示说明
1→2→3→2→1→2
*/

#include <iostream>
using namespace std;

int main()
{
    long long n, t, ans, cycle;
    cin >> n >> t;

    if (n == 1)
        ans = 1;
    else
    {
        cycle = 2 * (n - 1);
        t = t % cycle;

        if (t <= n - 1)
        {
            ans = t + 1;
        }
        else
        {
            ans = n - (t - (n - 1));
        }
    }
    cout << ans << endl;

    return 0;
}