// Source : https://xujcoj.com/home/contest/2070/problem/4
// Date   : 2024-12-21

/**************************************************
 * 题目描述：
 * 定义某一个十年指的是从尾数0的年份的第1天到尾数是9的年份的最后1天。
 * 例如2024年12月21日所在的十年是从2020年1月1日到2029年12月31日。
 * 求某个日期是所在十年的第几天。
 *
 * 示例 1：
 *   输入：2020 1 1
 *   输出：1
 *   解释：2020年1月1日是2020-2029这个十年的第1天
 *
 * 示例 2：
 *   输入：2024 12 21
 *   输出：1817
 *   解释：2024年12月21日是2020-2029这个十年的第1817天
 *
 * 提示说明：
 *   能被4整除且不能被100整除，或者能被400整除且不能被3200整除的年份是闰年
 **************************************************/

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
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long y, m, d;
        cin >> y >> m >> d;
        long long day = 0;

        long long startyear = y - (y % 10);
        for (long long year = startyear; year < y; year++)
        {
            long long allday = 365;
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 3200 != 0))
            {
                allday = 366;
            }
            day += allday;
        }

        long long mouth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y % 3200 != 0))
        {
            mouth[2] = 29;
        }
        for (int j = 1; j < m; j++)
        {
            day += mouth[j];
        }
        day += d;
        cout << day << endl;
    }

    return 0;
}