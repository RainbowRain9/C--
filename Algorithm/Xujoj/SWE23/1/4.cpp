/**************************************************
 * 题目描述：
 * 学校里每天会在固定时间响铃，给定一个时间段[a:b, c:d]，
 * 计算在这个时间段内能听到多少次铃声。
 * 铃声时间为:
 * 8:00、8:45、8:55、9:40、10:00、10:45、10:55、11:40、
 * 12:30、13:15、13:25、14:10、14:30、15:15、15:25、16:10、
 * 16:30、17:15、17:25、18:10、19:30、20:15、20:25、21:10
 *
 * 示例 1：
 *   输入：2
 *        8 0 9 0
 *        0 0 23 59
 *   输出：3
 *        24
 *   解释：第一组案例在8:00到9:00期间会听到8:00、8:45、8:55三次铃声
 *        第二组案例会听到一整天的所有铃声，共24次
 *
 * 提示：
 *   - n <= 100
 *   - 输入的时间保证合法
 *   - 起始时间不会晚于结束时间
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

bool f(int t)
{
    if (t == 800 || t == 845 || t == 855 || t == 940 || t == 1000 || t == 1045 || t == 1055 || t == 1140 || t == 1230 || t == 1315 || t == 1325 || t == 1410 || t == 1430 || t == 1515 || t == 1525 || t == 1610 || t == 1630 || t == 1715 || t == 1725 || t == 1810 || t == 1930 || t == 2015 || t == 2025 || t == 2110)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int time1 = a * 100 + b;
        int time2 = c * 100 + d;
        int cnt = 0;
        for (int t = time1; t <= time2; t++)
        {
            if (f(t))
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}