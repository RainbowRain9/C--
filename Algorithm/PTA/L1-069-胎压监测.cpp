/*
 * @Author: RainbowRain9
 * @Date: 2025-04-10 16:40:40
 * @LastEditTime: 2025-04-10 16:57:36
 * @FilePath: \C++\Algorithm\PTA\L1-069-胎压监测.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 小轿车中有一个系统随时监测四个车轮的胎压。四个车轮(左前轮、右前轮、右后轮、左后轮)
 * 顺次编号为1、2、3、4。需要编写一个监测程序，根据以下规则给出报警信息：
 * 1. 如果所有轮胎压力值与最大值误差在阈值内，且都不低于最低报警胎压，则正常不报警
 * 2. 如果一个轮胎压力值与最大值误差超过阈值，或低于最低报警胎压，则报警并指出位置
 * 3. 如果两个及以上轮胎出现上述问题，则报警检查所有轮胎
 *
 * 示例 1：
 *   输入：242 251 231 248 230 20
 *   输出：Normal
 *   解释：所有轮胎压力与最大值251的差值都在20以内，且都大于最低报警胎压230
 *
 * 示例 2：
 *   输入：242 251 232 248 230 10
 *   输出：Warning: please check #3!
 *   解释：3号轮胎压力232与最大值251的差值19超过阈值10
 *
 * 示例 3：
 *   输入：240 251 232 248 240 10
 *   输出：Warning: please check all the tires!
 *   解释：有多个轮胎压力与最大值251的差值超过阈值10
 *
 * 提示：
 *   - 输入6个整数：4个轮胎胎压、最低报警胎压、胎压差阈值
 *   - 所有输入整数范围在[0, 400]内
 *   - 需要同时考虑胎压过低和胎压差过大两种情况
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

int main()
{
    vector<int> a(4);
    for (int& i : a) {
        cin >> i;
    }
    int m, n;
    cin >> m >> n;
    int cnt = 0;
    int f;
    int maxVal = *max_element(a.begin(), a.end());
    for (int i = 0; i < 4; i++) {
        if (a[i] < m || abs(maxVal - a[i]) > n) {
            f = i + 1;
            cnt++;
        }
    }
    if (cnt > 1) {
        cout << "Warning: please check all the tires!";
    } else if (cnt == 1) {
        cout << "Warning: please check #" << f << "!";
    } else {
        cout << "Normal";
    }

    return 0;
}