/*
问题描述
有一个a行b列的网格，其中每个1*1的格子都是同样大小的正方形。问总共有多少个正方形。（注意不仅仅是1*1的a*b个正方形）

输入描述
一个正整数n，表示案例的数量。

每组案例由两个正整数a、b组成，其中a<=10000, b<=10000

输出描述
针对每组案例，输出一个整数，表示矩形的数量。

每组案例输出完都要换行。

样例输入
3

1 2

2 2

10000 9000

样例输出
2

5

283545001500
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        long long total = 0;
        int minSide = min(a, b);
        for (int k = 1; k <= minSide; k++)
        {
            total += (a - k + 1) * (b - k + 1);
        }
        cout << total << endl;
    }

    return 0;
}