/*
 * @Author: RainbowRain9
 * @Date: 2025-04-08 08:05:44
 * @LastEditTime: 2025-04-08 08:08:24
 * @FilePath: \C++\Algorithm\PTA\L1-035-情人节.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 情人节朋友圈贴中，第2个和第14个点赞的人需要请客。
 * 给定点赞顺序的名单，找出需要请客的两个人。
 *
 * 输入格式：
 * 按点赞顺序给出人名，每人占一行，不超过10个英文字母。
 * 以英文句点.结束输入。
 *
 * 输出格式：
 * 1. 如果有第2和第14个人：输出"A and B are inviting you to dinner..."
 * 2. 如果只有第2个人：输出"A is the only one for you..."
 * 3. 如果连第2个人都没有：输出"Momo... No one is for you ..."
 *
 * 示例 1：
 *   输入：
 *   GaoXZh
 *   Magi
 *   Einst
 *   Quark
 *   LaoLao
 *   FatMouse
 *   ZhaShen
 *   fantacy
 *   latesum
 *   SenSen
 *   QuanQuan
 *   whatever
 *   whenever
 *   Potaty
 *   hahaha
 *   .
 *   输出：
 *   Magi and Potaty are inviting you to dinner...
 *   解释：
 *   第2个是Magi，第14个是Potaty
 *
 * 示例 2：
 *   输入：
 *   LaoLao
 *   FatMouse
 *   whoever
 *   .
 *   输出：
 *   FatMouse is the only one for you...
 *   解释：
 *   只有第2个FatMouse，没有第14个
 *
 * 示例 3：
 *   输入：
 *   LaoLao
 *   .
 *   输出：
 *   Momo... No one is for you ...
 *   解释：
 *   连第2个人都没有
 *
 * 提示：
 *   - 输入人数不确定，以.结束
 *   - 每个人名不超过10个英文字母
 *   - 需要记录第2和第14个点赞的人
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
    string n;
    int cnt = 0;
    string s1, s2;
    while (cin >> n) {
        if (n == ".") {
            break;
        }
        cnt++;
        if (cnt == 2) {
            s1 = n;
        }
        if (cnt == 14) {
            s2 = n;
        }
    }
    if (cnt >= 2 && cnt < 14) {
        cout << s1 << " is the only one for you...";
    } else if (cnt < 2) {
        cout << "Momo... No one is for you ...";
    } else {
        cout << s1 << " and " << s2 << " are inviting you to dinner...";
    }

    return 0;
}