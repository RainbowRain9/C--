/*
 * @Author: RainbowRain9
 * @Date: 2025-03-23 15:03:33
 * @LastEditTime: 2025-03-23 15:13:55
 * @FilePath: \C++\Algorithm\Xujoj\SWE23\1\3.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 已知一个字符串，要求保留元音字母字符（AEIOU及其小写）的位置不变，
 * 其他字符反序填入原字符串剩余的位置。
 *
 * 示例 1：
 *   输入：ABCDEFG
 *   输出：AGFDECB
 *   解释：保留元音字母E位置不变，其他字符反序填入
 *
 * 示例 2：
 *   输入：#uieXYZ@
 *   输出：@uieZYX#
 *   解释：保留元音字母uie位置不变，其他字符反序填入
 *
 * 提示：
 *   - 这是一道多组案例的题目
 *   - n表示案例数量，n<=100
 *   - 每组案例由一个字符串组成，长度不超过10000
 *   - 字符串不含空格和特殊字符
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

bool isVowel(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        stack<char> stk;
        for (auto c : s)
        {
            if (!isVowel(c))
            {
                stk.push(c);
            }
        }

        string result;
        for (auto c : s)
        {
            if (isVowel(c))
            {
                result += c;
            }
            else
            {
                result += stk.top();
                stk.pop();
            }
        }
        cout << result << endl;
    }
    return 0;
}