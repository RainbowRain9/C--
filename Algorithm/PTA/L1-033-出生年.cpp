/*
 * @Author: RainbowRain9
 * @Date: 2025-04-07 22:10:26
 * @LastEditTime: 2025-04-07 22:33:02
 * @FilePath: \C++\Algorithm\PTA\L1-033-出生年.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 *   根据出生年份y和不同数字个数n，计算需要多少年才能遇到满足条件的年份
 *   年份不足4位要补零，输出年龄x和满足条件的年份
 *
 * 示例 1：
 *   输入：1988 4
 *   输出：25 2013
 *   解释：从1988年开始，经过25年到2013年，才遇到4个数字都不同的年份
 *
 * 示例 2：
 *   输入：1 2
 *   输出：0 0001
 *   解释：公元1年（0001）本身就有2个不同数字0和1，所以不需要等待
 *
 * 提示：
 *   - y在[1, 3000]之间
 *   - n可以是2、3或4
 *   - 年份要按4位输出，不足补零
 *   - 不同数字个数要正好等于n
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
    int y, n;
    cin >> y >> n;
    int x = y;
    while (true) {
        string s = to_string(x);
        s.insert(0, 4 - s.size(), '0');
        unordered_set<char> set(s.begin(), s.end());
        if (set.size() == n) {
            break;
        }
        x++;
    }
    string s = to_string(x);
    s.insert(0, 4 - s.size(), '0');
    cout << x - y << " " << s;

    return 0;
}