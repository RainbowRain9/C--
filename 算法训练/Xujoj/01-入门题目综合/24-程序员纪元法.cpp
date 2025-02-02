/*
问题描述
如果把1970年1月1日看作第1天，1970年1月2日看作第2天，...，1971年1月1日看作第366天，那么a年b月c日是第几天？

输入描述
一个正整数n，表示有n组案例。

每组案例由3个正整数a、b、c组成，其中保证a年b月c日是一个晚于1970年1月1日的合法日期，且不会超过公元3199年12月31日。

输出描述
针对每组案例，输出一个正整数，表示a年b月c日是上述纪元法的第几天。

每组案例输出完都要换行。

样例输入
2

1970 1 2

1971 1 1

样例输出
2

366
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int y, m, d, day = 0;
        cin >> y >> m >> d;

        // 计算整年的天数
        day += (y - 1970) * 365;

        // 计算闰年数
        for (int i = 1970; i < y; i++)
        {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
                day++;
        }

        // 每个月的天数
        int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // 如果当年是闰年，2月改为29天
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            months[2] = 29;

        // 加上当年已过去的月份的天数
        for (int i = 1; i < m; i++)
            day += months[i];

        // 加上当月的天数
        day += d;

        cout << day << endl;
    }
    return 0;
}