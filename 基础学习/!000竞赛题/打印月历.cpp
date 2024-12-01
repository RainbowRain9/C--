// Source : https://xujcoj.com/home/contest/2008/problem/5
// Date   : 2024-11-30

/*********************************************************
题目:打印月历
时间限制：1000ms  内存限制：65536kb
总通过人数: 1  总提交人数: 1

题目描述
已知1900年1月1日是周一。
现在给定年份和月份，请你打印当月的月历。

输入
两个正整数y,m分别表示年和月。(1900≤y≤5000,1≤m≤12)

输出
第一行和最后一行是27个=。
第二行每个星期标题由三个字母表示,分别为周日到周六,每两个星期标题由空格分开。
以下若干行日期,日期和星期标题右对齐,前补空格。
每行最后一个字符后面没有空格,否则会格式错误。

样例输入
2024 10

样例输出
===========================
Sun Mon Tue Wed Thu Fri Sat
          1   2   3   4   5
  6   7   8   9  10  11  12
 13  14  15  16  17  18  19
 20  21  22  23  24  25  26
 27  28  29  30  31
===========================

思路:
1. 计算从1900年1月1日到给定日期的总天数
2. 总天数对7取余得到星期几
3. 根据年月计算当月天数
4. 按格式要求打印月历

*********************************************************/

using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

int main()
{
    int y, m;
    cin >> y >> m;

    // 计算从1900年1月1日到给定日期的总天数
    int totalDays = 0;

    // 先计算整年的天数
    for (int i = 1900; i < y; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
        {
            totalDays += 366;
        }
        else
        {
            totalDays += 365;
        }
    }

    // 再加上当年过去的月份的天数
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    {
        daysInMonth[1] = 29;
    }

    for (int i = 0; i < m - 1; i++)
    {
        totalDays += daysInMonth[i];
    }

    // 计算1号是星期几(0-6表示周日到周六)
    int firstDay = totalDays % 7;

    // 打印月历
    cout << "===========================" << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;

    // 打印空格
    for (int i = 0; i < firstDay; i++)
    {
        cout << "    ";
    }

    // 打印日期
    int currentDay = 1;
    int currentPos = firstDay;

    while (currentDay <= daysInMonth[m - 1])
    {
        printf("%3d", currentDay);
        if (currentPos < 6)
        {
            cout << " ";
            currentPos++;
        }
        else
        {
            cout << endl;
            currentPos = 0;
        }
        currentDay++;
    }

    // 如果最后一行没有换行则补充换行
    if (currentPos != 0)
        cout << endl;

    cout << "===========================" << endl;

    return 0;
}