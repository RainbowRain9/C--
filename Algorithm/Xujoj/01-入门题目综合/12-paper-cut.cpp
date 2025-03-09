/*
问题描述
罗少有一张长方形的纸，他每次都会把这张纸剪成面积相同的两半（这两半也都是长方形），然后丢掉其中的一半。

罗少总共这样做了 n 次，最后剩下一张长为 a，宽为 b 的长方形，现在请你猜想一下，刚开始的那张纸的周长最短可能是多少。

输入描述
第一行是一个正整数 T 代表测试案例的数量。(1 <= T <= 1000)

每组案例包含三个正整数 n、a、b 含义如描述所述。(1 <= n、a、b <= 10)

输出描述
针对每组案例，输出刚开始的那张纸的周长最短可能是多少，然后换行。

样例输入
1

1 4 2

样例输出
16

提示说明
刚开始的那张纸可能是 长为4宽为4的长方形 或 长为8宽为2的长方形。

(4 + 4) × 2 < (8 + 2) × 2，所以周长最短可能为16。
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        long long length = max(a, b);
        long long width = min(a, b);

        for (int i = 0; i < n; i++)
        {
            if (length > width)
            {
                width *= 2;
            }
            else
            {
                length *= 2;
            }
        }

        cout << 2 * (length + width) << endl;
    }
    return 0;
}