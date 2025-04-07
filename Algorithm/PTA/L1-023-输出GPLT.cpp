/*
 * @Author: RainbowRain9
 * @Date: 2025-04-04 20:20:46
 * @LastEditTime: 2025-04-04 20:29:56
 * @FilePath: \C++\Algorithm\PTA\L1-023-输出GPLT.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，
 * 按GPLTGPLT....这样的顺序输出，并忽略其它字符。若某种字符已经输出完，则余下
 * 的字符仍按GPLT的顺序打印，直到所有字符都被输出。
 *
 * 输入格式：
 * 输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。
 *
 * 输出格式：
 * 在一行中按题目要求输出排序后的字符串。题目保证输出非空。
 *
 * 示例 1：
 *   输入：pcTclnGloRgLrtLhgljkLhGFauPewSKgt
 *   输出：GPLTGPLTGLTGLGLL
 *   解释：按GPLT顺序输出所有G、P、L、T字符，直到所有字符都被输出
 *
 * 提示：
 *   - 不区分大小写
 *   - 按GPLT顺序循环输出
 *   - 当某种字符用尽后继续按顺序输出剩余字符
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int cntG = 0, cntP = 0, cntL = 0, cntT = 0;
    for (auto a : s)
    {
        int c = toupper(a);
        if (c == 'G')
        {
            cntG++;
        }
        if (c == 'P')
        {
            cntP++;
        }
        if (c == 'L')
        {
            cntL++;
        }
        if (c == 'T')
        {
            cntT++;
        }
    }
    while (cntG != 0 || cntP != 0 || cntL != 0 || cntT != 0)
    {
        if (cntG > 0)
        {
            cout << "G";
            cntG--;
        }
        if (cntP > 0)
        {
            cout << "P";
            cntP--;
        }
        if (cntL > 0)
        {
            cout << "L";
            cntL--;
        }
        if (cntT > 0)
        {
            cout << "T";
            cntT--;
        }
    }

    return 0;
}