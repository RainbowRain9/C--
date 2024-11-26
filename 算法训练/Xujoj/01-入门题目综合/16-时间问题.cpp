/*
问题描述
有一个24小时制的电子表，最初显示的时间是 00:00，小调现在想知道 m 分钟后的时间是多少。

输入描述
第一行是一个正整数 T 代表测试案例的数量。(1 <= T <= 1000)

每组案例包含一个正整数 m 含义如描述所述。(1 <= m <= 1e9)

输出描述
针对每组案例，输出 m 分钟后的时间，然后换行。

样例输入
2

10

1200

样例输出
00:10

20:00
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long m;
        cin >> m;

        int hours = (m / 60) % 24;
        int minutes = m % 60;

        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << endl;
    }

    return 0;
}