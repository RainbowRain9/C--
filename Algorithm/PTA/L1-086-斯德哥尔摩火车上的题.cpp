/*
 * @Author: RainbowRain9
 * @Date: 2025-04-10 17:14:29
 * @LastEditTime: 2025-04-10 17:19:22
 * @FilePath: \C++\Algorithm\PTA\L1-086-斯德哥尔摩火车上的题.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 给定两个数字字符串，判断通过以下算法处理后是否得到相同结果：
 * 1. 从第二个字符开始遍历字符串
 * 2. 如果当前字符与前一个字符的奇偶性相同
 * 3. 则取这两个字符的最大值加入结果字符串
 * 4. 如果结果相同则输出一个结果，否则分别输出两个结果
 *
 * 示例 1：
 *   输入：1112031584
 *        011102315849
 *   输出：112358
 *   解释：两个字符串经过算法处理后得到相同结果112358
 *
 * 示例 2：
 *   输入：111203158412334
 *        12341112031584
 *   输出：1123583
 *        112358
 *   解释：两个字符串处理后得到不同结果，需分别输出
 *
 * 提示：
 *   - 输入为两行数字字符串
 *   - 字符串长度不超过10^4
 *   - 输出结果保证非空
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

string f(string a)
{
    string s;
    for (int i = 1; i < a.length(); i++) {
        if (a[i] % 2 == a[i - 1] % 2) {
            s += max(a[i], a[i - 1]);
        }
    }
    return s;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (f(s1) == f(s2)) {
        cout << f(s1) << endl;
    } else {
        cout << f(s1) << endl;
        cout << f(s2) << endl;
    }

    return 0;
}