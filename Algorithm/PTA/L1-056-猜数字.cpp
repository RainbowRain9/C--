/*
 * @Author: RainbowRain9
 * @Date: 2025-04-09 17:12:44
 * @LastEditTime: 2025-04-09 17:23:05
 * @FilePath: \C++\Algorithm\PTA\L1-056-猜数字.cpp
 * @Description: 
 */

/**************************************************
 * 题目描述：
 * 一群人坐在一起，每人猜一个 100 以内的数，谁的数字最接近大家平均数的一半就赢。
 * 本题就要求你找出其中的赢家。
 * 
 * 示例 1：
 *   输入：
 *   7
 *   Bob 35
 *   Amy 28
 *   James 98
 *   Alice 11
 *   Jack 45
 *   Smith 33
 *   Chris 62
 *   输出：
 *   22 Amy
 *   解释：
 *   平均数为 (35+28+98+11+45+33+62)/7 = 44.57
 *   平均数的一半为 22.285，取整为 22
 *   Amy 猜的数字 28 最接近 22
 * 
 * 提示：
 *   - 输入人数 N ≤ 10^4
 *   - 玩家名字由不超过8个英文字母组成
 *   - 猜的数字 ≤ 100
 *   - 题目保证赢家是唯一的
 **************************************************/

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
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
    cin >> n;
    vector<pair<string, int>> nums(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first >> nums[i].second;
        sum += nums[i].second;
    }
    int avg = sum / n / 2;
    vector<int> peo(n);
    for (int i = 0; i < n; i++) {
        peo[i] = abs(avg - nums[i].second);
    }
    int min_idx = distance(peo.begin(), min_element(peo.begin(), peo.end())); // 查找数组最小值
    cout << avg << " " << nums[min_idx].first;

    return 0;
}