/*
 * @Author: RainbowRain9
 * @Date: 2025-04-10 15:52:22
 * @LastEditTime: 2025-04-10 16:35:34
 * @FilePath: \C++\Algorithm\PTA\L1-085-试试手气.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 给定6个骰子的初始点数和摇骰子的次数n(1≤n≤5)，每次摇骰子时需满足:
 * 1. 每个骰子摇出的点数都与之前任何一次出现的点数不同
 * 2. 在满足条件1的前提下，每次都让每个骰子得到可能的最大点数
 * 求第n次摇出的结果。
 *
 * 示例 1：
 *   输入：3 6 5 4 1 4
 *        3
 *   输出：4 3 3 3 4 3
 *   解释：这3次摇出的结果依次为：
 *        6 5 6 6 6 6
 *        5 4 4 5 5 5
 *        4 3 3 3 4 3
 *
 * 提示：
 *   - 骰子点数范围为[1,6]
 *   - 每个骰子每次摇出的点数必须与之前所有次数都不同
 *   - 在满足条件的情况下要取最大可能值
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
// TODO 2025-04-10: 
using namespace std;

int main() {
    vector<int> dice(6);
    vector<vector<int>> history;
    
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
    }
    history.push_back(dice);
    
    int n;
    cin >> n;
    
    while (n--) {
        vector<int> roll(6);
        for (int i = 0; i < 6; i++) {
            for (int val = 6; val >= 1; val--) {
                bool used = false;
                for (const auto& prev : history) {
                    if (prev[i] == val) {
                        used = true;
                        break;
                    }
                }
                if (!used) {
                    roll[i] = val;
                    break;
                }
            }
        }
        history.push_back(roll);
        dice = roll;
    }
    
    for (int i = 0; i < 6; i++) {
        cout << dice[i];
        if (i < 5) cout << " ";
    }
    
    return 0;
}
