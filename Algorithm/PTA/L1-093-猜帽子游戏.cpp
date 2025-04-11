/*
 * @Author: RainbowRain9
 * @Date: 2025-04-10 17:20:04
 * @LastEditTime: 2025-04-10 17:31:52
 * @FilePath: \C++\Algorithm\PTA\L1-093-猜帽子游戏.cpp
 * @Description:
 */

/**************************************************
 * 题目描述：
 * 宝宝们在玩猜帽子游戏。每人头上戴一顶黑色或黄色帽子，每个人可以看到别人的帽子颜色，
 * 但看不到自己的。每个人可以猜自己帽子的颜色或弃权。如果没有人猜错且至少有一人猜对，
 * 所有人获得大奖。如果所有人都不猜，或有人猜错，则没有奖。
 *
 * 示例 1：
 *   输入：
 *   5
 *   1 1 2 1 2
 *   3
 *   0 1 2 0 0
 *   0 0 0 0 0
 *   1 2 2 0 2
 *   输出：
 *   Da Jiang!!!
 *   Ai Ya
 *   Ai Ya
 *   解释：
 *   第一组猜测中，第2个人猜对了(1)，第3个人猜对了(2)，其他人弃权，所以获得大奖
 *   第二组全部弃权，无法获奖
 *   第三组中第3个人猜错了(实际是2，猜成2)，所以无法获奖
 *
 * 提示：
 *   - 2 < N ≤ 100，N为帽子数量
 *   - K ≤ 10，K为测试组数
 *   - 1表示黑色帽子，2表示黄色帽子，0表示弃权
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
    int n;
    cin >> n;
    vector<int> hat(n);
    for (int& i : hat) {
        cin >> i;
    }
    int k;
    cin >> k;
    while (k--) {
        vector<int> ans(n);
        for (int& i : ans) {
            cin >> i;
        }
        bool f = false, a = false;
        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {
                continue;
            }
            if (ans[i] != hat[i]) {
                cout << "Ai Ya" << endl;
                f = true;
                a = false;
                break;
            } else {
                a = true;
                f = true;
            }
        }
        if (!f) {
            cout << "Ai Ya" << endl;
        }
        if (a) {
            cout << "Da Jiang!!!" << endl;
        }
    }

    return 0;
}