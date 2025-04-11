/*
 * @Author: RainbowRain9
 * @Date: 2025-04-08 08:35:40
 * @LastEditTime: 2025-04-08 09:15:43
 * @FilePath: \C++\Algorithm\PTA\L1-039-古风排版.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：古风排版
 * 中国的古人写文字是从右向左竖向排版的。本题要求编写程序，把一段文字按古风排版。
 *
 * 输入格式：
 * 第一行给出一个正整数N（<100），是每一列的字符数。
 * 第二行给出一个长度不超过1000的非空字符串，以回车结束。
 *
 * 输出格式：
 * 按古风格式排版给定的字符串，每列N个字符（除了最后一列可能不足N个）。
 *
 * 示例 1：
 *   输入：
 *   4
 *   This is a test case
 *   输出：
 *   asa T
 *   st ih
 *   e tsi
 *    ce s
 *
 * 提示：
 *   - 注意处理字符串长度不是N的倍数的情况
 *   - 输出时从右向左逐列输出
 *   - 每列字符从上到下排列
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
// TODO 2025-04-08: 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    int len = s.length();
    int cols = (len + n - 1) / n;

    vector<vector<char>> grid(n, vector<char>(cols, ' '));

    int index = 0;
    for (int col = cols - 1; col >= 0; col--) {
        for (int row = 0; row < n; row++) {
            if (index < len) {
                grid[row][col] = s[index++];
            } else {
                grid[row][col] = ' ';
            }
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < cols; col++) {
            cout << grid[row][col];
        }
        cout << endl;
    }

    return 0;
}