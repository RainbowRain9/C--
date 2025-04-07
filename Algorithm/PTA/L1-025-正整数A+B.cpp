/*
 * @Author: RainbowRain9
 * @Date: 2025-04-04 20:52:36
 * @LastEditTime: 2025-04-04 21:20:02
 * @FilePath: \C++\Algorithm\PTA\L1-025-正整数A+B.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 求两个正整数A和B的和，其中A和B都在区间[1,1000]。
 * 输入可能包含非正整数或无效字符，需要处理这些情况。
 *
 * 示例 1：
 *   输入：123 456
 *   输出：123 + 456 = 579
 *   解释：两个输入都是有效正整数
 *
 * 示例 2：
 *   输入：22. 18
 *   输出：? + 18 = ?
 *   解释：第一个输入包含小数点，不是有效正整数
 *
 * 示例 3：
 *   输入：-100 blabla bla...33
 *   输出：? + ? = ?
 *   解释：两个输入都无效
 *
 * 提示：
 *   - 输入保证至少存在一个空格
 *   - B不会是空字符串
 *   - 需要处理各种无效输入情况
 *   - 输出格式要严格匹配要求
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

bool isValidNumber(const string &s)
{
    if (s.empty())
        return false;

    for (auto c : s)
    {
        if (!isdigit(c))
            return false;
    }

    int num = stoi(s);
    if (num < 1 || num > 1000)
    {
        return false;
    }
    return true;
}

int main()
{
    string a, b;
    cin >> a;
    cin.ignore();
    getline(cin, b);
    bool m = isValidNumber(a);
    bool n = isValidNumber(b);
    
    if (m && n)
    {
        cout << a << " + " << b << " = " << stoi(a) + stoi(b);
    }
    else if (!m && n)
    {
        cout << "? + " << b << " = ?";
    }
    else if (m && !n)
    {
        cout << a << " + ? = ?";
    }
    else
    {
        cout << "? + ? = ?";
    }

    return 0;
}