/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 15:36:44
 * @LastEditTime: 2025-04-02 15:45:11
 * @FilePath: \C++\Algorithm\PTA\L1-007-念数字.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出fu字。
 *
 * 示例 1：
 *   输入：-600
 *   输出：fu liu ling ling
 *   解释：负号输出为"fu"，6输出为"liu"，两个0都输出为"ling"
 *
 * 示例 2：
 *   输入：1234
 *   输出：yi er san si
 *   解释：每个数字依次输出对应的拼音
 *
 * 提示：
 *   - 整数包括负数、零和正数
 *   - 每个数字的拼音之间用空格分开
 *   - 行末没有最后的空格
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
    vector<string> nums = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string num;
    cin >> num;
    bool first = true;
    for (auto c : num)
    {
        if (!first)
        {
            cout << " ";
        }
        if (c == '-')
        {
            cout << "fu";
        }
        else
        {
            cout << nums[c - '0'];
        }
        first = false;
    }
    cout << endl;
    return 0;
}