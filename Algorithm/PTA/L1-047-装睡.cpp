/*
 * @Author: RainbowRain9
 * @Date: 2025-04-08 22:54:56
 * @LastEditTime: 2025-04-08 23:05:19
 * @FilePath: \C++\Algorithm\PTA\L1-047-装睡.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 通过分析呼吸频率和脉搏判断是否装睡。正常人睡眠时呼吸频率15-20次/分钟，
 * 脉搏50-70次/分钟。给定N个人的姓名、呼吸频率和脉搏，找出至少一项指标
 * 不在正常范围内的人。
 *
 * 输入格式：
 * 第一行正整数N（≤10），随后N行，每行包含姓名（≤3英文字母）、
 * 呼吸频率和脉搏（≤100正整数）
 *
 * 输出格式：
 * 按输入顺序输出不符合条件的人名，每行一个
 *
 * 示例 1：
 *   输入：
 *   4
 *   Amy 15 70
 *   Tom 14 60
 *   Joe 18 50
 *   Zoe 21 71
 *   输出：
 *   Tom
 *   Zoe
 *   解释：
 *   Tom的呼吸频率14不在15-20范围内
 *   Zoe的脉搏71不在50-70范围内
 *
 * 提示：
 *   - 注意边界条件判断
 *   - 姓名长度不超过3个字符
 *   - 所有输入值都是正整数
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
        string name;
        int a, b;
        cin >> name >> a >> b;
        if ((a < 15 || a > 20) || (b < 50 || b > 70)) {
            cout << name << endl;
        }
    }

    return 0;
}