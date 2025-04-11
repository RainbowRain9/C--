/*
 * @Author: RainbowRain9
 * @Date: 2025-04-10 17:32:18
 * @LastEditTime: 2025-04-10 17:59:14
 * @FilePath: \C++\Algorithm\PTA\L1-094-剪切粘贴.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 实现一个具有剪切和粘贴功能的文本编辑工具。
 * 每次操作分为两步：
 * 1. 剪切：给定起始和结束位置，将对应字符串放入剪贴板并从原字符串删除
 * 2. 粘贴：给定插入位置的前后字符串，将剪贴板内容插入到匹配位置
 *
 * 示例 1：
 *   输入：
 *   AcrosstheGreatWall,wecanreacheverycornerintheworld
 *   5
 *   10 18 ery cor
 *   32 40 , we
 *   1 6 tW all
 *   14 18 rnerr eache
 *   1 1 e r
 *   输出：
 *   he,allcornetrrwecaneacheveryGreatWintheworldAcross
 *   解释：
 *   每次操作包含剪切和粘贴两步，按顺序执行5次操作
 *
 * 提示：
 *   - 原始字符串长度 ≤ 200
 *   - 操作次数 N: 1 ≤ N ≤ 100
 *   - 插入位置前后字符串长度 ≤ 5
 *   - 如有多个可插入位置，选择最靠近字符串开头的位置
 *   - 如找不到插入位置，则插入到字符串末尾
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
    string s;
    cin >> s;
    int n;
    cin >> n;
    while (n--) {
        int pos1, pos2;
        string s1, s2, s3;
        cin >> pos1 >> pos2 >> s1 >> s2;
        pos1--;
        s3 = s.substr(pos1, pos2 - pos1);
        s.erase(pos1, pos2 - pos1);
        string target = s1 + s2;
        auto pos = s.find(target);
        // 如果找不到插入位置，则插入到字符串末尾
        if (pos == string::npos) {
            s.append(s3);
        }
        // 否则在找到的位置后插入剪切的字符串
        else {
            s.insert(pos + s1.length(), s3);
        }
    }
    cout << s << endl;
    return 0;
}