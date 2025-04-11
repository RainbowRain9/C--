/*
 * @Author: RainbowRain9
 * @Date: 2025-04-08 09:31:26
 * @LastEditTime: 2025-04-08 19:51:51
 * @FilePath: \C++\Algorithm\PTA\L1-043-阅览室.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 天梯图书阅览室请你编写一个简单的图书借阅统计程序。当读者借书时，管理员输入书号并按下S键，程序开始计时；当读者还书时，管理员输入书号并按下E键，程序结束计时。书号为不超过1000的正整数。当管理员将0作为书号输入时，表示一天工作结束，你的程序应输出当天的读者借书次数和平均阅读时间。
 *
 * 注意：由于线路偶尔会有故障，可能出现不完整的纪录，即只有S没有E，或者只有E没有S的纪录，系统应能自动忽略这种无效纪录。另外，题目保证书号是书的唯一标识，同一本书在任何时间区间内只可能被一位读者借阅。
 *
 * 输入样例：
 * 3
 * 1 S 08:10
 * 2 S 08:35
 * 1 E 10:00
 * 2 E 13:16
 * 0 S 17:00
 * 0 S 17:00
 * 3 E 08:10
 * 1 S 08:20
 * 2 S 09:00
 * 1 E 09:20
 * 0 E 17:00
 * 输出样例：
 * 2 196
 * 0 0
 * 1 60
 * 解释：
 * 第一组数据：2次有效借阅，总阅读时间392分钟，平均196分钟
 * 第二组数据：0次有效借阅
 * 第三组数据：1次有效借阅，阅读时间60分钟
 *
 * 提示：
 *   - 书号为不超过1000的正整数，0表示一天结束
 *   - 只有S和E都存在的记录才有效
 *   - 时间按递增顺序给出
 *   - 同一本书在任何时间区间内只可能被一位读者借阅
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int m;
        vector<pair<bool, int>> time(1001, {false, 0});
        int count = 0, total = 0;
        while (cin >> m) {
            char c, d;
            int hh, mm, t;
            cin >> c >> hh >> d >> mm;
            t = hh * 60 + mm;
            if (c == 'S') {
                time[m].first = true;
                time[m].second = t;
            } else if (c == 'E' && time[m].first) {
                total += t - time[m].second; 
                count++;
                time[m].first = false;
            }
            if (m == 0) {
                if (count == 0) {
                    cout << "0 0" << endl;
                } else {
                    cout << count << " " << (int)(total * 1.0 / count + 0.5) << endl; 
                }
                break;
            }
        }
    }
    return 0;
}