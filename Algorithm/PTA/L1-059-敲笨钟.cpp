/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 20:30:27
 * @LastEditTime: 2025-04-09 21:04:11
 * @FilePath: \C++\Algorithm\PTA\L1-059-敲笨钟.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 微博上有个自称"大笨钟V"的家伙，每天敲钟催促码农们爱惜身体早点睡觉。
 * 为了增加敲钟的趣味性，还会糟改几句古诗词。其糟改的方法为：去网上搜寻压"ong"韵的古诗词，
 * 把句尾的三个字换成"敲笨钟"。
 *
 * 示例 1：
 *   输入：
 *   5
 *   xun zhang zhai ju lao diao chong, xiao yue dang lian gua yu gong.
 *   tian sheng wo cai bi you yong, qian jin san jin huan fu lai.
 *   xue zhui rou zhi leng wei rong, an xiao chen jing shu wei long.
 *   zuo ye xing chen zuo ye feng, hua lou xi pan gui tang dong.
 *   ren xian gui hua luo, ye jing chun shan kong.
 *   输出：
 *   xun zhang zhai ju lao diao chong, xiao yue dang lian qiao ben zhong.
 *   Skipped
 *   xue zhui rou zhi leng wei rong, an xiao chen jing qiao ben zhong.
 *   Skipped
 *   Skipped
 *   解释：
 *   只有第1、3句是压"ong"韵的，需要将下半句末尾改为"qiao ben zhong"
 *
 * 提示：
 *   - 输入N不超过20
 *   - 每个字的拼音不超过6个字符
 *   - 每行字符总长度不超过100
 *   - 下半句诗至少有3个字
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
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        vector<string> gs;
        string py;
        for (char c : s) {
            if (c == ' ') {
                if (!py.empty()) {
                    gs.push_back(py);
                    py.clear();
                }
            } else {
                py += c;
            }
        }
        if (!py.empty()) {
            gs.push_back(py);
        }
        int cnt = 0;
        for (string v : gs) {
            if (v.find("ong,") != string::npos || v.find("ong.") != string::npos) {
                cnt++;
            }
        }
        if (cnt < 2) {
            cout << "Skipped" << endl;
        } else {
            int m = gs.size();
            gs[m - 1] = "zhong.";
            gs[m - 2] = "ben";
            gs[m - 3] = "qiao";
            for (string v : gs) {
                cout << v << (v == gs.back() ? "\n" : " ");
            }
        }
    }

    return 0;
}