/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 21:48:01
 * @LastEditTime: 2025-04-09 22:01:10
 * @FilePath: \C++\Algorithm\PTA\L1-061-新胖子公式.cpp
 * @Description: 
 */

/**************************************************
 * 题目描述：
 * 根据钱江晚报官方微博的报导，最新的肥胖计算方法为：
 * 体重(kg) / 身高(m) 的平方。如果超过 25，就是胖子。
 * 编写程序自动判断一个人到底算不算胖子。
 * 
 * 示例 1：
 *   输入：100.1 1.74
 *   输出：33.1
 *        PANG
 *   解释：体重100.1kg，身高1.74m，计算得到BMI为33.1，大于25，输出PANG
 * 
 * 示例 2：
 *   输入：65 1.70
 *   输出：22.5
 *        Hai Xing
 *   解释：体重65kg，身高1.70m，计算得到BMI为22.5，不大于25，输出Hai Xing
 * 
 * 提示：
 *   - 体重不超过1000 kg
 *   - 身高不超过3.0 m
 *   - BMI结果保留一位小数
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
    double w, h, ans;
    cin >> w >> h;
    ans = w / (h * h);
    printf("%0.1f\n", ans);
    if (ans <= 25) {
        cout << "Hai Xing" << endl;
    }
    else {
        cout << "PANG" << endl;
    }

    return 0;
}