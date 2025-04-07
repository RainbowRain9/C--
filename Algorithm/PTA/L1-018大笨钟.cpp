/*
 * @Author: RainbowRain9
 * @Date: 2025-04-02 22:03:12
 * @LastEditTime: 2025-04-02 22:20:38
 * @FilePath: \C++\Algorithm\PTA\L1-018大笨钟.cpp
 * @Description:
 */
/**************************************************
 * 题目描述：
 * 大笨钟根据当前时间敲钟，规则如下：
 * 1. 只在12:01到23:59期间敲钟
 * 2. 整点敲钟次数等于整点数
 * 3. 非整点敲钟次数等于下一个整点数
 * 4. 敲钟时间只敲1~12下（即13:00敲1下，14:00敲2下，...，23:00敲11下，00:00敲12下）
 *
 * 示例 1：
 *   输入：19:05
 *   输出：DangDangDangDangDangDangDangDang
 *   解释：19:05属于敲钟期，且过了19点整，需要敲8下
 *
 * 示例 2：
 *   输入：07:05
 *   输出：Only 07:05.  Too early to Dang.
 *   解释：07:05不在敲钟期，输出提示信息
 *
 * 提示：
 *   - 时间格式为hh:mm，hh在00-23之间，mm在00-59之间
 *   - 输出格式要严格匹配题目要求
 *   - 注意处理边界情况（如23:59, 12:00等）
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
    string time;
    cin >> time;

    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    if (h < 12 || h == 12 && m == 0)
    {
        cout << "Only " << time << ".  Too early to Dang.";
    }
    else
    {
        int dangCount = h - 12;
        if (m > 0)
        {
            dangCount++;
        }
        for (int i = 0; i < dangCount; i++)
        {
            cout << "Dang";
        }
    }

    return 0;
}