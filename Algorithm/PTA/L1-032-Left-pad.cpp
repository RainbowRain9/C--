/**************************************************
 * 题目描述：Left-pad 字符串填充
 * 实现一个字符串左填充功能，在字符串前填充指定字符到指定长度
 *
 * 示例 1：
 *   输入：
 *     15 _
 *     I love GPLT
 *   输出：
 *     ____I love GPLT
 *   解释：
 *     在字符串"I love GPLT"前填充下划线_，使总长度达到15
 *
 * 示例 2：
 *   输入：
 *     4 *
 *     this is a sample for cut
 *   输出：
 *      cut
 *   解释：
 *     当目标长度小于原字符串长度时，从右边截取相应长度的字符
 *
 * 提示：
 *   - 目标长度 N ≤ 10^4
 *   - 填充字符可以是任意可打印字符
 *   - 原字符串可能包含空格
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
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
    char c;
    cin >> n >> c;
    cin.ignore();
    string s;
    getline(cin, s);
    if (n > s.size()) {
        cout << string(n - s.size(), c) << s;
    } else {
        cout << s.substr(s.size() - n);
    }

    return 0;
}