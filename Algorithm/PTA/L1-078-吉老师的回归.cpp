/*
 * @Author: RainbowRain9
 * @Date: 2025-04-10 15:44:12
 * @LastEditTime: 2025-04-10 15:51:33
 * @FilePath: \C++\Algorithm\PTA\L1-078-吉老师的回归.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 吉老师回归天梯赛。每道题目用不超过500的字符串描述。
 * 吉老师按顺序看题做题,但如果题目字符串包含"qiandao"或"easy"(区分大小写)则跳过不做。
 * 给定N道题目和已完成M道题目,输出吉老师当前正在做的题目,或输出"Wo AK le"表示全部完成。
 *
 * 示例 1：
 *   输入：
 *   5 1
 *   L1-1 is a qiandao problem.
 *   L1-2 is so...easy.
 *   L1-3 is Easy.
 *   L1-4 is qianDao.
 *   Wow, such L1-5, so easy.
 *   输出：L1-4 is qianDao.
 *   解释：第1,2,3,5题包含关键词跳过,做完1题后正在做第4题
 *
 * 示例 2：
 *   输入：
 *   5 4
 *   L1-1 is a-qiandao problem.
 *   L1-2 is so easy.
 *   L1-3 is Easy.
 *   L1-4 is qianDao.
 *   Wow, such L1-5, so!!easy.
 *   输出：Wo AK le
 *   解释：所有题目都已完成或跳过
 *
 * 提示：
 *   - 1≤M≤N≤30
 *   - 题目字符串只包含可打印字符
 *   - 字符串长度不超过500
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
    int n, m;
    cin >> n >> m;
    cin.ignore();
    int cnt = 0;
    while (n--) {
        string s;
        getline(cin, s);
        if (s.find("qiandao") != string::npos || s.find("easy") != string::npos) {
            continue;
        }
        if (cnt == m) {
            cout << s;
            return 0;
        }
        cnt++;
    }
    cout << "Wo AK le";
    return 0;
}