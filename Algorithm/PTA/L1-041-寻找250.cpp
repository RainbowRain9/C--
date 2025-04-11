/*
 * @Author: RainbowRain9
 * @Date: 2025-04-08 09:21:04
 * @LastEditTime: 2025-04-08 09:24:26
 * @FilePath: \C++\Algorithm\PTA\L1-041-寻找250.cpp
 * @Description: 
 */

/**************************************************
 * 题目描述：
 * 对方不想和你说话，并向你扔了一串数…… 而你必须从这一串数字中找到“250”这个高大上的感人数字。
 * 
 * 输入格式：
 * 输入在一行中给出不知道多少个绝对值不超过1000的整数，其中保证至少存在一个“250”。
 * 
 * 输出格式：
 * 在一行中输出第一次出现的“250”是对方扔过来的第几个数字（计数从1开始）。
 * 
 * 输入样例：
 * 888 666 123 -233 250 13 250 -222
 * 
 * 输出样例：
 * 5
 * 
 * 提示：
 * - 题目保证输出的数字在整型范围内
 * - 代码长度限制：16 KB
 * - 时间限制：400 ms
 * - 内存限制：64 MB
 * - 栈限制：8192 KB
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
    int n, cnt = 0;
    while (cin >> n){
        cnt++;
        if (n == 250){
            break;
        }
    }
    cout << cnt << endl;

    return 0;
}