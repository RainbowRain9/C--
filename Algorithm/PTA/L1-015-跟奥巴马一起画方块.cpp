/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 19:23:57
 * @LastEditTime: 2025-04-02 19:27:30
 * @FilePath: \C++\Algorithm\PTA\L1-015-跟奥巴马一起画方块.cpp
 * @Description: https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805124398956544&page=0
 */
/**************************************************
 * 题目描述：
 * 美国总统奥巴马编写代码在屏幕上画一个正方形。现在要求你实现类似功能：
 * 输入正方形边长N和组成正方形边的字符C，输出由字符C画出的正方形。
 * 注意：为了让结果更像正方形，输出的行数实际上是列数的50%（四舍五入取整）。
 * 
 * 示例 1：
 *   输入：10 a
 *   输出：
 *   aaaaaaaaaa
 *   aaaaaaaaaa
 *   aaaaaaaaaa
 *   aaaaaaaaaa
 *   aaaaaaaaaa
 *   解释：边长为10，字符为a，行数为5（10的50%四舍五入）
 * 
 * 示例 2：
 *   输入：7 @
 *   输出：
 *   @@@@@@@
 *   @@@@@@@
 *   @@@@@@@
 *   @@@@@@@
 *   解释：边长为7，字符为@，行数为4（7的50%四舍五入）
 * 
 * 提示：
 *   - 3 ≤ N ≤ 21
 *   - 输入格式：N C，中间用空格分隔
 *   - 行数计算需要四舍五入
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
    int n;
    char c;
    cin >> n >> c;
    int rows = round(n / 2.0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            cout << c;
        }
        cout << endl;
    }
    

    return 0;
}