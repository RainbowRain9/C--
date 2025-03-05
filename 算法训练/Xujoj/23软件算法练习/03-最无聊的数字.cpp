// Source : https://xujcoj.com/home/contest/2127/problem/3
// Date   : 2025-03-03

/**************************************************
 * 题目描述：
 * 小明上"算法设计与分析"的课程很无聊，就在白纸上写下一串连续的整数：1、2、3、4、5、6、7、8、9、10...
 * 突然，他想到一个小游戏，可以统计这些数字中1的出现次数，并且考虑用算法来实现。
 *
 * 示例 1：
 *   输入：10
 *   输出：2
 *   解释：从1到10中，数字1出现了2次(1和10)
 *
 * 提示：
 *   - 输入为所写出的最大整数n
 *   - n <= 10^9
 *   - 输出1的出现次数，以换行符结束
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
    long long cnt = 0;
    long long pos = 1;
    while (n >= pos)
    {
        long long m = n / (pos * 10);
        cnt += m * pos;
        long long r = n % (pos * 10);
        if (r >= pos)
        {
            cnt += min(pos, r - pos + 1);
        }
        pos *= 10;
    }
    cout << cnt << endl;
    return 0;
}