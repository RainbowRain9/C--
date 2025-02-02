/*
问题描述
【问题】万花筒的初始形状如下图所示，其中的圆圈代表万花筒的闪烁点，每旋转一次万花筒形状就演变一次，演变的规则是在末端再生出同样的形状，求第 n 次旋转后有多少个闪烁点？



【想法】每次旋转都是在上一次旋转的每个分支端点多了 2 个闪烁点,设 Sn 表示第 n 次旋转的闪烁点个数，初始时有 4 个闪烁点，有 3 个分支端点，每次旋转都是在上一次旋转的每个分支端点又多了 2 个闪烁点，得到如下递推关系式：





输入描述
输入旋转次数n

输出描述
第 n 次旋转后有多少个闪烁点

样例输入
2

样例输出
22

提示说明
最后需要回车换行。
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 4;
    int temp;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            temp = 2;
        }
        else
            temp *= 2;
        sum += 3 * temp;
    }
    cout << sum << endl;

    return 0;
}
